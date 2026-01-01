#include "loginview.h"
#include "ui_loginview.h"
#include "idatabase.h"
#include "client.h"

LoginView::LoginView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginView)
{
    ui->setupUi(this);

    m_client = new Client(this);
    connect(m_client, &Client::connected, this, &LoginView::connectedToServer);
    connect(m_client, &Client::jsonReceived, this, &LoginView::jsonReceived);
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

void LoginView::connectedToServer()
{
    qDebug() << "已连接到服务器，发送登录请求";
    QString username = ui->usernameEdit->text().trimmed();
    m_client->sendMessage(username, "login");
}

void LoginView::jsonReceived(const QJsonObject &docObj)
{

}

