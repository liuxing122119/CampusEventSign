#include "loginview.h"
#include "ui_loginview.h"
#include "idatabase.h"

LoginView::LoginView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginView)
{
    ui->setupUi(this);
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_loginButton_clicked()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString status = IDatabase::getInstance().userLogin(username, ui->passwordEdit->text());
    if (status == "loginOK"){
        emit loginSuccess(username);
    }
}

