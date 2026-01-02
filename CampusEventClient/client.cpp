#include "client.h"
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>

Client::Client(QObject *parent)
    : QObject{parent}
{
    m_clientSocket = new QTcpSocket(this);

    connect(m_clientSocket,&QTcpSocket::connected,this,&Client::connected);
    connect(m_clientSocket,&QTcpSocket::readyRead,this,&Client::onReadyRead);
    connect(m_clientSocket, &QTcpSocket::disconnected, this, &Client::disconnected);
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

void Client::sendGetAnnouncementsRequest()
{
    if (!isConnected()) {
        return;
    }
    QJsonObject request;
    request["type"] = "get_announcements";
    QDataStream serverStream(m_clientSocket);
    serverStream.setVersion(QDataStream::Qt_5_12);
    QByteArray jsonData = QJsonDocument(request).toJson(QJsonDocument::Compact);
    serverStream << jsonData;
}

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
                    emit jsonReceived(jsonDoc.object());
                }
            }
        } else {
            break;
        }
    }
}

void Client::sendMessage(const QString &text, const QString &type)
{
    if (!isConnected() || text.isEmpty())
        return;
    QDataStream serverStream(m_clientSocket);
    serverStream.setVersion(QDataStream::Qt_5_12);
    QJsonObject message;
    message["type"] = type;
    message["text"] = text;
    serverStream << QJsonDocument(message).toJson();
}

void Client::connectToServer(const QHostAddress &address, quint16 port)
{
    m_clientSocket->connectToHost(address,port);
}

void Client::disconnectFromHost()
{
    m_clientSocket->disconnectFromHost();
}
