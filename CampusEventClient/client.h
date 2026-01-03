#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    static Client* getInstance() {
        static Client instance;
        return &instance;
    }

    bool isConnected();
    void sendGetActivityCategoriesRequest();
    // void sendGetAnnouncementsRequest();

private:
    explicit Client(QObject *parent = nullptr);
    Client(Client const&) = delete;
    void operator=(Client const&) = delete;

    QTcpSocket *m_clientSocket;

signals:
    void connected();
    void disconnected();
    void jsonReceived(const QJsonObject &docObj);

public slots:
    void onReadyRead();
    void sendMessage(const QString &text,const QString &type = "message");
    void connectToServer(const QHostAddress &address,quint16 port);
    void disconnectFromHost();
};

#endif // CLIENT_H
