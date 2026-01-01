#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "serverworker.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;
    QVector<ServerWorker *>m_clients;

signals:
    void logMessage(const QString &msg);

public slots:
    void stopServer();
    void jsonReceived(ServerWorker *sender, const QJsonObject &docObj);
    void userDisconnected(ServerWorker *sender);

private:
    QJsonArray getActivityCategories();
    QJsonArray getAnnouncements();
};

#endif // SERVER_H
