#include "idatabase.h"

IDatabase::IDatabase(QObject *parent)
    : QObject{parent}
{
    ininDatabase();
}

void IDatabase::ininDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    QString aFile = "D:/code/QT/exp/CampusEventSign/exp.db";
    database.setDatabaseName(aFile);

    if (!database.open()) {
        qDebug() << "failed to open database";
    } else
        qDebug() << "open database is ok" << database.connectionName();
}


QString IDatabase::userLogin(QString useName, QString password)
{
    QSqlQuery query;
    query.prepare("select username, password from user where username = :USER");
    query.bindValue(":USER", useName);
    query.exec();
    qDebug() << query.lastQuery() << query.first();

    if (query.first() && query.value("username").isValid()) {
        QString passwd = query.value("password").toString();
        if (passwd == password) {
            qDebug() << "login ok";
            return "loginOK";
        } else {
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
    query.bindValue(":USER", useName);
    query.exec();

    if (query.first() && query.value("role").isValid()) {
        int roleInt = query.value("role").toInt();
        switch (roleInt) {
        case 1:
            return "admin";
        case 2:
            return "sponsor";
        case 3:
            return "student";
        default:
            return "invalidRole";
        }
    } else {
        return "invalidRole";
    }
}

bool IDatabase::initActivityModel()
{
    activityTabModel = new QSqlTableModel(this, database);
    activityTabModel->setTable("activity");
    activityTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    activityTabModel->setSort(activityTabModel->fieldIndex("ACTID"), Qt::AscendingOrder);
    if (!(activityTabModel->select()))
        return false;
    theActivitySelection = new QItemSelectionModel(activityTabModel);
    return true;
}

int IDatabase::addNewActivity(const QString &username)
{
    activityTabModel->insertRow(activityTabModel->rowCount(), QModelIndex());
    QModelIndex curIndex = activityTabModel->index(activityTabModel->rowCount()-1, 1);

    int curRecNo = curIndex.row();
    QSqlRecord curRec = activityTabModel->record(curRecNo);

    // 自动生成活动ID（自增+1）
    QSqlQuery query;
    query.exec("SELECT MAX(ACTID) FROM activity");
    int maxId = 0;
    if (query.first() && query.value(0).isValid())
        maxId = query.value(0).toInt();
    curRec.setValue("ACTID", maxId + 1);
    // 自动生成创建时间
    curRec.setValue("CREATETIME", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    curRec.setValue("SPONSOR", username);

    activityTabModel->setRecord(curRecNo, curRec);
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

QJsonArray IDatabase::getActivityCategories()
{
    QJsonArray categoryArr;
    QSqlQuery query(database);
    query.exec("SELECT DISTINCT category FROM activity WHERE category IS NOT NULL");
    while (query.next()) {
        QJsonObject obj;
        obj["category"] = query.value(0).toString();
        categoryArr.append(obj);
    }
    return categoryArr;
}

// QJsonArray IDatabase::getAnnouncements()
// {
//     QJsonArray annoArr;
//     QSqlQuery query(database);
//     query.exec("SELECT title, content FROM announcement ORDER BY id DESC");
//     while (query.next()) {
//         QJsonObject obj;
//         obj["title"] = query.value(0).toString();
//         obj["content"] = query.value(1).toString();
//         annoArr.append(obj);
//     }
//     return annoArr;
// }
