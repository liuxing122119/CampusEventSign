#include "masterview.h"
#include "ui_masterview.h"
#include "idatabase.h"

MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);

    goLoginView();

    IDatabase::getInstance();
}

MasterView::~MasterView()
{
    delete ui;
}

void MasterView::goLoginView()
{
    qDebug() << "goLoginView";
    loginView = new LoginView(this);
    pushWidgetToStackView(loginView);

    connect(loginView, SIGNAL(loginSuccess(QString)), this, SLOT(onLoginSuccess(QString)));
}

void MasterView::goPreviousView()
{
    int count = ui->stackedWidget->count();

    if(count > 1){
        IDatabase::getInstance().revertActivityEdit();

        ui->stackedWidget->setCurrentIndex(count - 2);
        ui->titlelabel->setText(ui->stackedWidget->currentWidget()->windowTitle());

        QWidget *widget = ui->stackedWidget->widget(count - 1);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }
}

void MasterView::goAdminView()
{
    qDebug() << "goAdminView";
    adminView = new AdminView(this);
    pushWidgetToStackView(adminView);
}

void MasterView::goSponsorView(const QString &username)
{
    qDebug() << "goSponsorView";
    sponsorView = new SponsorView(this);
    sponsorView->setCurrentUsername(username);
    pushWidgetToStackView(sponsorView);

    connect(sponsorView, SIGNAL(goActivityEditView(int)), this, SLOT(goActivityEditView(int)));
}

void MasterView::goStudentView()
{
    qDebug() << "goStudentView";
    studentView = new StudentView(this);
    pushWidgetToStackView(studentView);
}

void MasterView::goActivityEditView(int rowNo)
{
    qDebug() << "goActivityEditView";
    activityEditView = new ActivityEditView(this, rowNo);
    pushWidgetToStackView(activityEditView);

    connect(activityEditView, SIGNAL(goPreviousView()), this, SLOT(goPreviousView()));
}

void MasterView::onLoginSuccess(QString username)
{
    qDebug() << "login success, username:" << username;
    QString userRole = IDatabase::getInstance().getUserRole(username);

    if (userRole == "admin") {
        goAdminView();
    } else if (userRole == "sponsor") {
        goSponsorView(username);
    } else if (userRole == "student") {
        goStudentView();
    } else {
        qDebug() << "invalid role";
    }
}

void MasterView::on_btBack_clicked()
{
    goPreviousView();
}

void MasterView::on_btLogout_clicked()
{
    goPreviousView();
}

void MasterView::on_stackedWidget_currentChanged(int arg1)
{
    int count = ui->stackedWidget->count();
    if (count > 1)
        ui->btBack->setEnabled(true);
    else
        ui->btBack->setEnabled(false);

    QString title = ui->stackedWidget->currentWidget()->windowTitle();

    if (title == "发起人" || title == "管理员" || title == "学生") {
        ui->btLogout->setEnabled(true);
        ui->btBack->setEnabled(false);
    }  else if (title == "登录") {
        ui->btLogout->setEnabled(false);
        ui->btBack->setEnabled(false);
    } else
        ui->btLogout->setEnabled(false);
}

void MasterView::pushWidgetToStackView(QWidget *widget)
{
    ui->stackedWidget->addWidget(widget);
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count - 1);
    ui->titlelabel->setText(widget->windowTitle());
}
