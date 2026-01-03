#include "loginview.h"
#include "ui_loginview.h"
#include "idatabase.h"

LoginView::LoginView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginView)
{
    ui->setupUi(this);

    m_client = Client::getInstance();
    connect(m_client, &Client::connected, this, &LoginView::connectedToServer);
    connect(m_client, &Client::disconnected, this, &LoginView::onServerDisconnected);
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_loginButton_clicked()
{
    if (m_isServerConnected) {
        QString username = ui->usernameEdit->text().trimmed();
        QString password = ui->passwordEdit->text().trimmed();
        QString status = IDatabase::getInstance().userLogin(username, password);
        if (status == "loginOK"){
            emit loginSuccess(username);
        }
        return;
    }
    m_client->connectToServer(QHostAddress::LocalHost, 1967);
}

void LoginView::connectedToServer()
{
    qDebug() << "已连接到服务器";
    m_isServerConnected = true;
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text().trimmed();
    if (!username.isEmpty() && !password.isEmpty()) {
        QString status = IDatabase::getInstance().userLogin(username, password);
        if (status == "loginOK"){
            emit loginSuccess(username);
        }
    }
}

void LoginView::onServerDisconnected()
{
    qDebug() << "服务器断开连接";
    m_isServerConnected = false;
}

