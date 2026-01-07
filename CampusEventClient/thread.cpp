#include "thread.h"
#include "idatabase.h"

Thread::Thread(QObject *parent)
    : QThread{parent}
{

}

void Thread::run()
{
    QString msg;
    bool success = IDatabase::getInstance().exportData(m_actName,m_savePath,m_exportType,msg);
    emit exportFinished(success,msg);
}

void Thread::doCheck(const QString &studentName,const QString &actName)
{
    QString conflictMsg;
    bool hasConflict = IDatabase::getInstance().checkSignConflict(studentName,actName,conflictMsg);
    emit conflictCheckResult(!hasConflict,conflictMsg);
}

void Thread::startExport(const QString &actName,const QString &savePath,const QString &exportType)
{
    m_actName = actName;
    m_savePath = savePath;
    m_exportType = exportType;
    start();
}
