#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include "client.h"

namespace Ui {
class LoginView;
}

class LoginView : public QWidget
{
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = nullptr);
    ~LoginView();

signals:
    void loginSuccess(QString username);

private slots:
    void on_loginButton_clicked();

    void connectedToServer();
    void onServerDisconnected();

private:
    Ui::LoginView *ui;
    Client *m_client;
    bool m_isServerConnected = false;
};

#endif // LOGINVIEW_H
