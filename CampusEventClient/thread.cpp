#include "thread.h"
#include "idatabase.h"

Thread::Thread(QObject *parent)
    : QThread{parent}
{

}

void Thread::run()
{
    if (m_isCheck) {
        QString conflictMsg;
        bool hasConflict = IDatabase::getInstance().checkSignConflict(m_studentName, m_actName, conflictMsg);
        emit conflictCheckResult(!hasConflict, conflictMsg);
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
    m_studentName = studentName;
    m_actName = actName;
    start();
}

void Thread::startExport(const QString &savePath,const QString &exportData)
{
    m_savePath = savePath;
    m_exportData = exportData;
    start();
}
