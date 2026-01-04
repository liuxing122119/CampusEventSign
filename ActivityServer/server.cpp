#include "server.h"
#include "serverworker.h"
#include <QJsonValue>
#include <QJsonObject>

Server::Server(QObject *parent): QTcpServer(parent)
{

}

int Server::clientCount()
{
    return m_clients.size();
}

QJsonArray Server::getActivityCategories()
{
    QJsonArray categoryArray;
    QStringList categories = {"德育教育","创新创业","特色体育","高雅美育","劳动教育","知行活动"};
    for (const QString &cate: categories) {
        QJsonObject obj;
        obj["category"] = cate;
        categoryArray.append(obj);
    }
    return categoryArray;
}

// QJsonArray Server::getAnnouncements()
// {
//     return IDatabase::getInstance().getAnnouncements();
// }

void Server::incomingConnection(qintptr socketDescriptor)
{
    ServerWorker *worker = new ServerWorker(this);
    if (!worker->setSocketDescriptor(socketDescriptor)) {
        worker->deleteLater();
        emit logMessage("客户端连接失败");
        return;
    }
    connect(worker,&ServerWorker::logMessage,this,&Server::logMessage);
    connect(worker,&ServerWorker::jsonReceived,this,&Server::jsonReceived);
    connect(worker,&ServerWorker::disconnectedFromClient,this,
            std::bind(&Server::userDisconnected,this,worker));
    m_clients.append(worker);
    emit logMessage("客户端连接成功");
}

void Server::stopServer()
{
    this->close();
    for (ServerWorker *worker: m_clients) {
        disconnect(worker,&ServerWorker::disconnectedFromClient,this,nullptr);
        if (worker->m_serverSocket->state() == QAbstractSocket::ConnectedState) {
            worker->m_serverSocket->disconnectFromHost();
        }
        worker->disconnect();
        worker->deleteLater();
    }
    m_clients.clear();
}

void Server::userDisconnected(ServerWorker *sender)
{
    emit logMessage("客户端断开连接");
    m_clients.removeOne(sender);
    sender->deleteLater();
}

void Server::jsonReceived(ServerWorker *sender,const QJsonObject &docObj)
{
    QString requestType = docObj["type"].toString();
    QJsonObject response;

    // 处理获取活动类别请求
    if (requestType == "get_activity_categories") {
        emit logMessage("收到客户端请求：获取活动类别");
        response["type"] = "activity_categories_response";
        response["categories"] = this->getActivityCategories();// 返回活动类别数据
        sender->sendJson(response);
        return;
    }

    // // 处理获取公告请求
    // if (requestType == "get_announcements") {
    //     emit logMessage("收到客户端请求：获取公告");
    //     response["type"] = "announcements_response";
    //     response["announcements"] = this->getAnnouncements();// 返回公告数据
    //     sender->sendJson(response);
    //     return;
    // }
}

