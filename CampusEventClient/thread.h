#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = nullptr);

signals:
    void conflictCheckResult(bool isOk,QString msg);
    void exportFinished(bool success,const QString &msg);

protected:
    void run() override;

public slots:
    void doCheck(const QString &studentName,const QString &actName);
    void startExport(const QString &actName,const QString &exportType,const QString &savePath);

private:
    bool m_isCheck = false;
    QString m_studentName;
    QString m_actName;
    QString m_exportType;
    QString m_savePath;
    QString m_exportData;
};

#endif // THREAD_H
