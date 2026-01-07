#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QDataWidgetMapper>

class IDatabase : public QObject
{
    Q_OBJECT
public:
    static IDatabase& getInstance()
    {
        static IDatabase instance;
        return instance;
    }

    QString userLogin(QString useName,QString password);
    QString getUserRole(QString useName);

signals:

private:
    explicit IDatabase(QObject *parent = nullptr);
    IDatabase(IDatabase const&) = delete;
    void operator=(IDatabase const&) = delete;

    QSqlDatabase database;

    void initDatabase();

public:
    bool initActivityModel();
    int addNewActivity(const QString &username);
    bool submitActivityEdit();
    void revertActivityEdit();
    bool searchActivity(QString filter);

    QSqlTableModel *activityTabModel;
    QItemSelectionModel *theActivitySelection;

    bool initUserModel();
    int addNewUser();
    bool deleteCurrentUser();
    bool submitUserEdit();
    void revertUserEdit();
    bool searchUser(QString filter);

    QSqlTableModel *userTabModel;
    QItemSelectionModel *theUserSelection;

    bool initSignRecordModel();
    int addNewSignRecord(const QString &studentName,const QString &actName);
    bool deleteCurrentSignRecord();
    bool submitSignRecordEdit();
    void revertSignRecordEdit();
    bool searchSignRecord(QString filter);

    QSqlTableModel *signRecordTabModel;
    QItemSelectionModel *theSignRecordSelection;

    bool checkSignConflict(const QString &studentName,const QString &actName,QString &conflictMsg);
    QString getExportData(const QString &actName,const QString &exportType,bool &success,QString &msg);
    bool exportData(const QString &savePath,const QString &data,QString &msg);
};

#endif // IDATABASE_H
