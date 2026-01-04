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
    m_client = Client::getInstance();
    connect(m_client,SIGNAL(disconnected()),this,SLOT(onClientDisconnected()));
    pushWidgetToStackView(loginView);

    connect(loginView,SIGNAL(loginSuccess(QString)),this,SLOT(onLoginSuccess(QString)));
}

void MasterView::goPreviousView()
{
    int count = ui->stackedWidget->count();

    if(count > 1){
        if (IDatabase::getInstance().activityTabModel != nullptr) {
            IDatabase::getInstance().revertActivityEdit();
        }
        if (IDatabase::getInstance().userTabModel != nullptr) {
            IDatabase::getInstance().revertUserEdit();
        }

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

    connect(adminView,SIGNAL(goUserEditView(int)),this,SLOT(goUserEditView(int)));
}

void MasterView::goSponsorView(const QString &username)
{
    qDebug() << "goSponsorView";
    sponsorView = new SponsorView(this);
    sponsorView->setCurrentUsername(username);
    pushWidgetToStackView(sponsorView);

    connect(sponsorView,SIGNAL(goActivityEditView(int)),this,SLOT(goActivityEditView(int)));
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
    activityEditView = new ActivityEditView(this,rowNo);
    pushWidgetToStackView(activityEditView);

    connect(activityEditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goUserEditView(int rowNo)
{
    qDebug() << "goUserEditView";
    userEditView = new UserEditView(this,rowNo);
    pushWidgetToStackView(userEditView);

    connect(userEditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::onLoginSuccess(QString username)
{
    qDebug() << "login success,username:" << username;
    QString userRole = IDatabase::getInstance().getUserRole(username);

    m_Username = username;
    m_UserRole = userRole;

    QTimer *delayCreateTimer = new QTimer(this);
    delayCreateTimer->setSingleShot(true);
    connect(delayCreateTimer,SIGNAL(timeout()),this,SLOT(delayCreateRoleView()));
    delayCreateTimer->start(100);
}

void MasterView::onClientDisconnected()
{
    int stackCount = ui->stackedWidget->count();
    for (int i = stackCount - 1; i >= 0; i--) {
        QWidget *widget = ui->stackedWidget->widget(i);
        if (widget != loginView) {
            ui->stackedWidget->removeWidget(widget);
            delete widget;
        }
    }
}

void MasterView::delayCreateRoleView()
{
    if (m_UserRole == "管理员") {
        goAdminView();
    } else if (m_UserRole == "发起人") {
        goSponsorView(m_Username);
    } else if (m_UserRole == "学生") {
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
    if (m_client) {
        m_client->disconnectFromHost();
    }
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
