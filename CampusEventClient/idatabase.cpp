#include "idatabase.h"

IDatabase::IDatabase(QObject *parent)
    : QObject{parent}
{
    initDatabase();
}

void IDatabase::initDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    QString aFile = "D:/code/QT/exp/CampusEventSign/exp.db";
    database.setDatabaseName(aFile);

    if (!database.open())
        qDebug() << "failed to open database";
    else
        qDebug() << "open database is ok" << database.connectionName();
}

QString IDatabase::userLogin(QString useName,QString password)
{
    QSqlQuery query;
    query.prepare("select username,password from user where username = :USER");
    query.bindValue(":USER",useName);
    query.exec();
    qDebug() << query.lastQuery() << query.first();

    if (query.first() && query.value("username").isValid()) {
        QString passwd = query.value("password").toString();
        if (passwd == password)
            return "loginOK";
        else {
            qDebug() << "wrong password";
            return "wrongPassword";
        }
    } else {
        qDebug() << "no such user";
        return "wrongUsername";
    }
}

QString IDatabase::getUserRole(QString useName)
{
    QSqlQuery query;
    query.prepare("select role from user where username = :USER");
    query.bindValue(":USER",useName);
    query.exec();

    if (query.first() && query.value("role").isValid())
        return query.value("role").toString().trimmed();
    else
        return "invalidRole";
}

bool IDatabase::initActivityModel()
{
    activityTabModel = new QSqlTableModel(this,database);
    activityTabModel->setTable("activity");
    activityTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    activityTabModel->setSort(activityTabModel->fieldIndex("ACTID"),Qt::AscendingOrder);
    if (!(activityTabModel->select()))
        return false;
    theActivitySelection = new QItemSelectionModel(activityTabModel);
    return true;
}

int IDatabase::addNewActivity(const QString &username)
{
    activityTabModel->insertRow(activityTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = activityTabModel->index(activityTabModel->rowCount()-1,1);

    int curRecNo = curIndex.row();
    QSqlRecord curRec = activityTabModel->record(curRecNo);

    // 自动生成活动ID（自增+1）
    QSqlQuery query;
    query.exec("select MAX(ACTID) from activity");
    int maxId = 0;
    if (query.first() && query.value(0).isValid())
        maxId = query.value(0).toInt();
    curRec.setValue("ACTID",maxId + 1);
    // 自动生成创建时间
    curRec.setValue("CREATETIME",QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    curRec.setValue("SPONSOR",username);
    activityTabModel->setRecord(curRecNo,curRec);
    activityTabModel->setData(activityTabModel->index(curRecNo,
                                                      activityTabModel->fieldIndex("STATUS")),"待审核");
    return curIndex.row();
}

bool IDatabase::submitActivityEdit()
{
    return activityTabModel->submitAll();
}

void IDatabase::revertActivityEdit()
{
    activityTabModel->revertAll();
}

bool IDatabase::searchActivity(QString filter)
{
    activityTabModel->setFilter(filter);
    return activityTabModel->select();
}

bool IDatabase::initUserModel()
{
    userTabModel = new QSqlTableModel(this,database);
    userTabModel->setTable("user");
    userTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    userTabModel->setSort(userTabModel->fieldIndex("USERID"),Qt::AscendingOrder);
    if (!(userTabModel->select()))
        return false;
    theUserSelection = new QItemSelectionModel(userTabModel);
    return true;
}

int IDatabase::addNewUser()
{
    userTabModel->insertRow(userTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = userTabModel->index(userTabModel->rowCount()-1,1);

    int curRecNo = curIndex.row();
    QSqlRecord curRec = userTabModel->record(curRecNo);

    // 自动生成用户ID（自增+1）
    QSqlQuery query;
    query.exec("select MAX(USERID) from user");
    int maxId = 0;
    if (query.first() && query.value(0).isValid())
        maxId = query.value(0).toInt();
    curRec.setValue("USERID",maxId + 1);
    // 自动生成密码
    curRec.setValue("PASSWORD","123456");
    // 自动生成创建时间
    curRec.setValue("CREATETIME",QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));

    userTabModel->setRecord(curRecNo,curRec);
    return curIndex.row();
}

bool IDatabase::deleteCurrentUser()
{
    QModelIndex curIndex = theUserSelection->currentIndex();
    userTabModel->removeRow(curIndex.row());
    userTabModel->submitAll();
    userTabModel->select();
    return true;
}

bool IDatabase::submitUserEdit()
{
    return userTabModel->submitAll();
}

void IDatabase::revertUserEdit()
{
    userTabModel->revertAll();
}

bool IDatabase::searchUser(QString filter)
{
    userTabModel->setFilter(filter);
    return userTabModel->select();
}

bool IDatabase::initSignRecordModel()
{
    signRecordTabModel = new QSqlTableModel(this,database);
    signRecordTabModel->setTable("signrecord");
    signRecordTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    signRecordTabModel->setSort(signRecordTabModel->fieldIndex("SIGNID"),Qt::AscendingOrder);
    if (!(signRecordTabModel->select()))
        return false;
    theSignRecordSelection = new QItemSelectionModel(signRecordTabModel);
    return true;
}

int IDatabase::addNewSignRecord(const QString &studentName,const QString &actName)
{
    signRecordTabModel->insertRow(signRecordTabModel->rowCount(),QModelIndex());
    int newRow = signRecordTabModel->rowCount()-1;

    // 自动生成活动ID（自增+1）
    QSqlQuery query;
    query.exec("select MAX(SIGNID) from signrecord");
    int newSignId = (query.first() && query.value(0).isValid()) ? query.value(0).toInt() + 1 : 1;

    // 自动生成创建时间
    signRecordTabModel->setData(signRecordTabModel->index(newRow,signRecordTabModel->fieldIndex("SIGNID")),newSignId);
    signRecordTabModel->setData(signRecordTabModel->index(newRow,signRecordTabModel->fieldIndex("SIGNTIME")),
                                QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    signRecordTabModel->setData(signRecordTabModel->index(newRow,signRecordTabModel->fieldIndex("STUDENT")),studentName);
    signRecordTabModel->setData(signRecordTabModel->index(newRow,signRecordTabModel->fieldIndex("ACTIVITY")),actName);
    signRecordTabModel->setData(signRecordTabModel->index(newRow,signRecordTabModel->fieldIndex("SIGNSTATUS")),"已报名");
    signRecordTabModel->setData(signRecordTabModel->index(newRow,signRecordTabModel->fieldIndex("WAITRANK")),0);
    signRecordTabModel->setData(signRecordTabModel->index(newRow,signRecordTabModel->fieldIndex("CHECKSTATUS")),"未签到");

    return newRow;
}

bool IDatabase::deleteCurrentSignRecord()
{
    QModelIndex curIndex = theSignRecordSelection->currentIndex();
    signRecordTabModel->removeRow(curIndex.row());
    signRecordTabModel->submitAll();
    signRecordTabModel->select();
    return true;
}

bool IDatabase::submitSignRecordEdit()
{
    return signRecordTabModel->submitAll();
}

void IDatabase::revertSignRecordEdit()
{
    signRecordTabModel->revertAll();
}

bool IDatabase::searchSignRecord(QString filter)
{
    signRecordTabModel->setFilter(filter);
    return signRecordTabModel->select();
}

bool IDatabase::checkSignConflict(const QString &studentName,const QString &actName,QString &conflictMsg)
{
    QSqlQuery query;

    // 重复报名冲突
    QSqlQuery signQuery;
    // 查询该学生是否已正式报名该活动
    signQuery.prepare("select * from signrecord where STUDENT = :STUDENT and ACTIVITY = :ACTIVITY and SIGNSTATUS IN ('已报名','候补中')");
    signQuery.bindValue(":STUDENT",studentName);
    signQuery.bindValue(":ACTIVITY",actName);
    signQuery.exec();
    qDebug() << signQuery.lastQuery() << signQuery.first();

    // 判断是否存在已报名记录
    if (signQuery.first()) {
        conflictMsg = QString("【重复报名冲突】您已正式报名该活动《%1》").arg(actName);
        return true;
    }

    // 时间冲突（未到报名时间/报名已截止）
    query.prepare("select STARTTIME,ENDTIME,MAXCOUNT,ACTTIME from activity where ACTNAME = :ACTNAME");
    query.bindValue(":ACTNAME",actName);
    query.exec();
    qDebug() << query.lastQuery() << query.first();

    // 报名开始时间
    QString startTime;
    if (query.value("STARTTIME").isValid()) {
        startTime = query.value("STARTTIME").toString();
        startTime = startTime.split(".").first();
    }
    QDateTime applyStartTime = QDateTime::fromString(startTime,"yyyy-MM-ddTHH:mm:ss");
    QDateTime currentTime = QDateTime::currentDateTime();// 当前时间
    if (currentTime < applyStartTime) {
        conflictMsg = QString("【时间冲突】该活动报名尚未开始（开始时间：%1），无法报名").arg(applyStartTime.toString("yyyy-MM-dd HH:mm:ss"));
        return true;
    }

    // 报名截止时间
    QString endTime;
    if (query.value("ENDTIME").isValid()) {
        endTime = query.value("ENDTIME").toString();
        endTime = endTime.split(".").first();
    }
    QDateTime applyEndTime = QDateTime::fromString(endTime,"yyyy-MM-ddTHH:mm:ss");
    if (currentTime > applyEndTime) {
        conflictMsg = QString("【时间冲突】该活动报名已截止（截止时间：%1），无法报名").arg(applyEndTime.toString("yyyy-MM-dd HH:mm:ss"));
        return true;
    }

    // 名额冲突（名额已满）
    int currentSignCount = 0;
    QSqlQuery countQuery;
    countQuery.prepare("select COUNT(*) from signrecord where ACTIVITY = :ACTIVITY and WAITRANK = 0");
    countQuery.bindValue(":ACTIVITY",actName);
    countQuery.exec();

    if (countQuery.first() && countQuery.value(0).isValid())
        currentSignCount = countQuery.value(0).toInt();

    // 活动最大名额
    int maxCount = 0;
    if (query.value("MAXCOUNT").isValid())
        maxCount = query.value("MAXCOUNT").toInt();
    if (currentSignCount >= maxCount) {
        conflictMsg = QString("【名额冲突】该活动名额已爆满（当前：%1人/最大：%2人），进入候补队列").arg(currentSignCount).arg(maxCount);
        return true;
    }

    // 空间冲突（时间段重合）
    QDateTime targetActTime;
    if (query.value("ACTTIME").isValid()) {
        QString actTimeStr = query.value("ACTTIME").toString();
        actTimeStr = actTimeStr.split(".").first();
        targetActTime = QDateTime::fromString(actTimeStr,"yyyy-MM-ddTHH:mm:ss");
    }
    int activityDuration = 3600;// 目标活动持续时间（默认一小时）
    QDateTime targetActEndTime = targetActTime.addSecs(activityDuration);// 目标活动结束时间

    // 查询学生已报名的所有正式活动
    QSqlQuery existActQuery;
    existActQuery.prepare("select a.ACTNAME,a.ACTTIME from signrecord s "
                          "left join activity a ON s.ACTIVITY = a.ACTNAME where s.STUDENT = :STUDENT and s.WAITRANK = 0");
    existActQuery.bindValue(":STUDENT",studentName);
    existActQuery.exec();

    // 判断时间段是否重合
    while (existActQuery.next()) {
        QString existActName;
        QDateTime existActTime;
        if (existActQuery.value("ACTNAME").isValid() && existActQuery.value("ACTTIME").isValid()) {
            existActName = existActQuery.value("ACTNAME").toString();
            QString existActTimeStr = existActQuery.value("ACTTIME").toString();
            existActTimeStr = existActTimeStr.split(".").first();
            existActTime = QDateTime::fromString(existActTimeStr,"yyyy-MM-ddTHH:mm:ss");
        }

        QDateTime existActEndTime = existActTime.addSecs(activityDuration);// 已报名活动结束时间

        bool isTimeOverlap = (targetActTime >= existActTime && targetActTime < existActEndTime)
                             || (targetActEndTime > existActTime && targetActEndTime <= existActEndTime)
                             || (existActTime >= targetActTime && existActTime < targetActEndTime)
                             || (existActEndTime > targetActTime && existActEndTime <= targetActEndTime);

        if (isTimeOverlap) {
            conflictMsg = QString("【空间冲突】您已报名同时间段活动：《%1》（时间：%2-%3）").arg(existActName)
                              .arg(existActTime.toString("yyyy-MM-dd HH:mm:ss")).arg(existActEndTime.toString("HH:mm:ss"));
            return true;
        }
    }
    conflictMsg = QString("学生《%1》报名活动《%2》：报名成功").arg(studentName).arg(actName);
    return false;
}

QString IDatabase::getExportData(const QString &actName,const QString &exportType,bool &success,QString &msg)
{
    QString exportContent;
    success = false;

    // 报名名单
    if (exportType == "报名名单(CSV)") {
        exportContent = "学生姓名,活动名称,报名状态,报名时间,候补排名,签到状态\n";

        QSqlQuery query;
        query.prepare("select STUDENT,ACTIVITY,SIGNSTATUS,SIGNTIME,WAITRANK,CHECKSTATUS from signrecord where ACTIVITY = :actName");
        query.bindValue(":actName",actName);
        query.exec();

        int recordCount = 0;
        while (query.next()) {
            QString student = query.value(0).toString().trimmed();
            QString activity = query.value(1).toString().trimmed();
            QString status = query.value(2).toString().trimmed();
            QString signTime = query.value(3).toString().trimmed();
            QString waitRank = query.value(4).toString().trimmed();
            QString checkStatus = query.value(5).toString().trimmed();

            exportContent += QString("%1,%2,%3,%4,%5,%6\n").arg(student).arg(activity).arg(status)
                                 .arg(signTime).arg(waitRank).arg(checkStatus);
            recordCount++;
        }

        if (recordCount == 0)
            msg = "[导出提示] 该活动暂无报名数据";
        else {
            msg = QString("[导出成功] 报名名单共%1条记录").arg(recordCount);
            success = true;
        }
    }
    // 统计报表
    else if (exportType == "统计报表(CSV)") {
        exportContent = "统计项,数值\n";

        // 总报名人数
        int total = 0;
        QSqlQuery qTotal;
        qTotal.exec(QString("select COUNT(*) from signrecord where ACTIVITY = '%1'").arg(actName));
        if (qTotal.next())
            total = qTotal.value(0).toInt();
        exportContent += QString("总报名人数,%1\n").arg(total);

        // 已报名人数
        int signedNum = 0;
        QSqlQuery qSigned;
        qSigned.exec(QString("select COUNT(*) from signrecord where ACTIVITY = '%1' and SIGNSTATUS = '已报名'").arg(actName));
        if (qSigned.next())
            signedNum = qSigned.value(0).toInt();
        exportContent += QString("已报名人数,%1\n").arg(signedNum);

        // 候补人数
        int waitNum = 0;
        QSqlQuery qWait;
        qWait.exec(QString("select COUNT(*) from signrecord where ACTIVITY = '%1' and SIGNSTATUS = '候补中'").arg(actName));
        if (qWait.next())
            waitNum = qWait.value(0).toInt();
        exportContent += QString("候补人数,%1\n").arg(waitNum);

        // 活动最大名额
        int maxQuota = 0;
        QSqlQuery qQuota;
        qQuota.exec(QString("select MAXCOUNT from activity where ACTNAME = '%1'").arg(actName));
        if (qQuota.next())
            maxQuota = qQuota.value(0).toInt();
        exportContent += QString("活动最大名额,%1\n").arg(maxQuota);

        // 已签到人数
        int checkedNum = 0;
        QSqlQuery qChecked;
        qChecked.exec(QString("select COUNT(*) from signrecord where ACTIVITY = '%1' and SIGNSTATUS = '已报名' and CHECKSTATUS = '已签到'").arg(actName));
        if (qChecked.next())
            checkedNum = qChecked.value(0).toInt();
        exportContent += QString("已签到人数,%1\n").arg(checkedNum);

        // 未签到人数
        int unCheckedNum = 0;
        QSqlQuery qUnChecked;
        qUnChecked.exec(QString("select COUNT(*) from signrecord where ACTIVITY = '%1' and SIGNSTATUS = '已报名' "
                                "and (CHECKSTATUS = '未签到' or CHECKSTATUS IS NULL)").arg(actName));
        if (qUnChecked.next())
            unCheckedNum = qUnChecked.value(0).toInt();
        exportContent += QString("未签到人数,%1\n").arg(unCheckedNum);

        msg = "[导出成功] 统计报表查询完成";
        success = true;
    }
    return exportContent;
}

bool IDatabase::exportData(const QString &savePath,const QString &data,QString &msg)
{
    QFile file(savePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        msg = "文件打开失败：" + file.errorString();
        return false;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out << "\xef\xbb\xbf";
    out << data;// 写入数据

    file.close();
    msg = "文件写入成功，路径：" + savePath;
    return true;
}
