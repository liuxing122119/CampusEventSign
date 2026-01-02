#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QJsonArray>
#include "serverworker.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    int clientCount();

    QJsonArray getActivityCategories();
    QJsonArray getAnnouncements();

protected:
    void incomingConnection(qintptr socketDescriptor) override;
    QVector<ServerWorker *>m_clients;

signals:
    void logMessage(const QString &msg);

public slots:
    void stopServer();
    void userDisconnected(ServerWorker *sender);
    void jsonReceived(ServerWorker *sender,const QJsonObject &docObj);
};

#endif // SERVER_H
