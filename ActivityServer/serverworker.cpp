#include "serverworker.h"
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>

ServerWorker::ServerWorker(QObject *parent)
    : QObject{parent}
{
    m_serverSocket = new QTcpSocket(this);
    connect(m_serverSocket,&QTcpSocket::readyRead,this,&ServerWorker::onReadyRead);
    connect(m_serverSocket,&QTcpSocket::disconnected,this,&ServerWorker::disconnectedFromClient);
}

bool ServerWorker::setSocketDescriptor(qintptr socketDescriptor)
{
    return m_serverSocket->setSocketDescriptor(socketDescriptor);
}

QString ServerWorker::userName()
{
    return m_userName;
}

void ServerWorker::setUserName(QString user)
{
    m_userName = user;
}

void ServerWorker::onReadyRead()
{
    QByteArray jsonData;
    QDataStream socketStream(m_serverSocket);
    socketStream.setVersion(QDataStream::Qt_5_12);
    for (;;) {
        socketStream.startTransaction();
        socketStream >> jsonData;
        if (socketStream.commitTransaction()) {
            QJsonParseError parseError;
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData,&parseError);
            if (parseError.error == QJsonParseError::NoError && jsonDoc.isObject()) {
                emit logMessage(QString("接收客户端数据：%1")
                                    .arg(QString::fromUtf8(jsonDoc.toJson(QJsonDocument::Compact))));
                emit jsonReceived(this,jsonDoc.object());
            }
        } else {
            break;
        }
    }
}

void ServerWorker::sendMessage(const QString &text,const QString &type)
{
    if (m_serverSocket->state() != QAbstractSocket::ConnectedState) {
        emit logMessage("发送失败：客户端已断开连接");
        return;
    }
    QJsonObject message;
    message["type"] = type;
    message["text"] = text.trimmed();
    this->sendJson(message);
}

void ServerWorker::sendJson(const QJsonObject &json)
{
    const QByteArray jsonData = QJsonDocument(json).toJson(QJsonDocument::Compact);
    emit logMessage(QString("发送给客户端数据：%1")
                        .arg(QString::fromUtf8(jsonData)));
    QDataStream socketStream(m_serverSocket);
    socketStream.setVersion(QDataStream::Qt_5_12);
    socketStream << jsonData;
}

