#include "thread.h"
#include "idatabase.h"

Thread::Thread(QObject *parent)
    : QThread{parent}
{

}

void Thread::run()
{
    if (m_isCheck) {
        emit conflictCheckResult(!m_hasConflict,m_conflictMsg);
        m_isCheck = false;
    } else {
        QString msg;
        bool success = IDatabase::getInstance().exportData(m_savePath,m_exportData,msg);
        emit exportFinished(success,msg);
    }
}

void Thread::doCheck(const QString &studentName,const QString &actName)
{
    m_isCheck = true;
    m_hasConflict = IDatabase::getInstance().checkSignConflict(studentName,actName,m_conflictMsg);
    start();
}

void Thread::startExport(const QString &savePath,const QString &exportData)
{
    m_savePath = savePath;
    m_exportData = exportData;
    start();
}
