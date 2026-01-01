#include "server.h"
#include "serverworker.h"
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

Server::Server(QObject *parent): QTcpServer(parent)
{

}

void Server::incomingConnection(qintptr socketDescriptor)
{
    if (!isListening()) {
        emit logMessage("服务器未启动");
        return;
    }

    ServerWorker *worker = new ServerWorker(this);
    if (!worker->setSocketDescriptor(socketDescriptor)) {
        worker->deleteLater();
        emit logMessage("客户端连接失败");
        return;
    }

    connect(worker, &ServerWorker::logMessage, this, &Server::logMessage);
    connect(worker, &ServerWorker::jsonReceived, this, &Server::jsonReceived);
    connect(worker, &ServerWorker::disconnectedFromClient, this,
            std::bind(&Server::userDisconnected, this, worker));

    m_clients.append(worker);
    emit logMessage("客户端连接成功");
}

void Server::stopServer()
{
    close();
    for (ServerWorker *worker: m_clients) {
        worker->disconnect();
        worker->deleteLater();
    }
    m_clients.clear();
    emit logMessage("服务器已停止，断开所有连接");
}

void Server::jsonReceived(ServerWorker *sender, const QJsonObject &docObj)
{

}

void Server::userDisconnected(ServerWorker *sender)
{

}

QJsonArray Server::getActivityCategories()
{

}

QJsonArray Server::getAnnouncements()
{

}
