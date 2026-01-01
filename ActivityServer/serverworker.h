#ifndef SERVERWORKER_H
#define SERVERWORKER_H

#include <QObject>

class ServerWorker : public QObject
{
    Q_OBJECT
public:
    explicit ServerWorker(QObject *parent = nullptr);

signals:
};

#endif // SERVERWORKER_H
