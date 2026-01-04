#include "usereditview.h"
#include "ui_usereditview.h"
#include "idatabase.h"

UserEditView::UserEditView(QWidget *parent,int index)
    : QWidget(parent)
    , ui(new Ui::UserEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().userTabModel;
    dataMapper->setModel(IDatabase::getInstance().userTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->useridEdit,tabModel->fieldIndex("USERID"));
    dataMapper->addMapping(ui->usernameEdit,tabModel->fieldIndex("USERNAME"));
    dataMapper->addMapping(ui->passwordEdit,tabModel->fieldIndex("PASSWORD"));
    dataMapper->addMapping(ui->userRole,tabModel->fieldIndex("ROLE"));
    dataMapper->addMapping(ui->createtimeEdit,tabModel->fieldIndex("CREATETIME"));

    dataMapper->setCurrentIndex(index);

    ui->useridEdit->setEnabled(false);
    ui->createtimeEdit->setEnabled(false);

    QSqlRecord userRec = tabModel->record(index);
    QString userName = userRec.value("USERNAME").toString().trimmed();
    if (userName.isEmpty()) {
        ui->userRole->setEnabled(true);
        ui->passwordEdit->setEnabled(false);
    } else {
        ui->userRole->setEnabled(false);
        ui->passwordEdit->setEnabled(true);
    }
}

UserEditView::~UserEditView()
{
    delete ui;
}

void UserEditView::on_submitButton_clicked()
{
    dataMapper->submit();
    IDatabase::getInstance().submitUserEdit();
    emit goPreviousView();
}


void UserEditView::on_cancelButton_clicked()
{
    IDatabase::getInstance().revertUserEdit();
    emit goPreviousView();
}

