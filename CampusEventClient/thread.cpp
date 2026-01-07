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
        bool hasConflict = IDatabase::getInstance().checkSignConflict(m_studentName,m_actName,conflictMsg);
        emit conflictCheckResult(!hasConflict,conflictMsg);
        m_isCheck = false;
    } else {
        bool querySuccess;
        QString msg;
        QString exportData = IDatabase::getInstance().getExportData(m_actName,m_exportType,querySuccess,msg);
        if (!querySuccess) {
            emit exportFinished(false,msg);
            return;
        }
        bool writeSuccess = IDatabase::getInstance().exportData(m_savePath,exportData,msg);
        emit exportFinished(writeSuccess,msg);
    }
}

void Thread::doCheck(const QString &studentName,const QString &actName)
{
    m_isCheck = true;
    m_studentName = studentName;
    m_actName = actName;
    start();
}

void Thread::startExport(const QString &actName,const QString &exportType,const QString &savePath)
{
    m_isCheck = false;
    m_actName = actName;
    m_exportType = exportType;
    m_savePath = savePath;
    start();
}
