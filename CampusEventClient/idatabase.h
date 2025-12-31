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

    QString userLogin(QString useName, QString password);
    QString getUserRole(QString useName);

    QSqlTableModel *activityTabModel;
    QItemSelectionModel *theActivitySelection;

    bool initActivityModel();
    int addNewActivity(const QString &username);
    bool submitActivityEdit();
    void revertActivityEdit();
    bool searchActivity(QString filter);

signals:

private:
    explicit IDatabase(QObject *parent = nullptr);
    IDatabase(IDatabase const&) = delete;
    void operator=(IDatabase const&) = delete;

    QSqlDatabase database;

    void ininDatabase();
};

#endif // IDATABASE_H
