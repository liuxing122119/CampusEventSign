#include "thread.h"
#include "idatabase.h"

Thread::Thread(QObject *parent)
    : QThread{parent}
{

}

void Thread::run()
{
    QString msg;
    bool success = false;
    success = IDatabase::getInstance().exportData(m_savePath,m_exportData,msg);
    emit exportFinished(success,msg);

}

void Thread::doCheck(const QString &studentName,const QString &actName)
{
    QString conflictMsg;
    bool hasConflict = IDatabase::getInstance().checkSignConflict(studentName,actName,conflictMsg);
    emit conflictCheckResult(!hasConflict,conflictMsg);
}

void Thread::startExport(const QString &savePath,const QString &exportData)
{
    m_savePath = savePath;
    m_exportData = exportData;
    start();
}
