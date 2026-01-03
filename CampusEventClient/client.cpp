#include "client.h"
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

Client::Client(QObject *parent)
    : QObject{parent}
{
    m_clientSocket = new QTcpSocket(this);

    connect(m_clientSocket,&QTcpSocket::connected,this,&Client::connected);
    connect(m_clientSocket,&QTcpSocket::readyRead,this,&Client::onReadyRead);
    connect(m_clientSocket, &QTcpSocket::disconnected, this, &Client::disconnected);
    connect(this, &Client::connected, this, &Client::onClientConnected);
}

bool Client::isConnected()
{
    if (!m_clientSocket)
        return false;
    return (m_clientSocket->state() == QAbstractSocket::ConnectedState);
}

void Client::sendGetActivityCategoriesRequest()
{
    if (!isConnected()) {
        return;
    }
    QJsonObject request;
    request["type"] = "get_activity_categories";
    QDataStream serverStream(m_clientSocket);
    serverStream.setVersion(QDataStream::Qt_5_12);
    QByteArray jsonData = QJsonDocument(request).toJson(QJsonDocument::Compact);
    serverStream << jsonData;
    qDebug() << "已发送获取活动类别请求";
}

QStringList Client::getActivityCategories()
{
    return m_activityCategories;
}

// void Client::sendGetAnnouncementsRequest()
// {
//     if (!isConnected()) {
//         return;
//     }
//     QJsonObject request;
//     request["type"] = "get_announcements";
//     QDataStream serverStream(m_clientSocket);
//     serverStream.setVersion(QDataStream::Qt_5_12);
//     QByteArray jsonData = QJsonDocument(request).toJson(QJsonDocument::Compact);
//     serverStream << jsonData;
// }

void Client::onReadyRead()
{
    QByteArray jsonData;
    QDataStream socketStream(m_clientSocket);
    socketStream.setVersion(QDataStream::Qt_5_12);
    for (;;) {
        socketStream.startTransaction();
        socketStream >> jsonData;
        if (socketStream.commitTransaction()) {
            QJsonParseError parseError;
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData,&parseError);
            if (parseError.error == QJsonParseError::NoError) {
                if (jsonDoc.isObject()) {
                    QJsonObject docObj = jsonDoc.object();
                    emit jsonReceived(docObj);
                    // emit jsonReceived(jsonDoc.object());

                    QString responseType = docObj["type"].toString();
                    if (responseType == "activity_categories_response") {
                        QJsonArray categoryArr = docObj["categories"].toArray();
                        m_activityCategories.clear();
                        qDebug() << "获取到活动类别数量：" << categoryArr.size();
                        for (int i = 0; i < categoryArr.size(); ++i) {
                            QJsonObject cateObj = categoryArr[i].toObject();
                            QString cateName = cateObj["category"].toString();
                            m_activityCategories.append(cateName);
                            qDebug() << "添加活动类别：" << cateName;
                        }
                    }
                }
            }
        } else {
            break;
        }
    }
}

void Client::connectToServer(const QHostAddress &address, quint16 port)
{
    m_clientSocket->connectToHost(address,port);
}

void Client::disconnectFromHost()
{
    m_clientSocket->disconnectFromHost();
}

void Client::onClientConnected()
{
    this->sendGetActivityCategoriesRequest();
}
