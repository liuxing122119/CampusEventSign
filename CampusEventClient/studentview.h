#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QWidget>
#include <QListWidgetItem>
#include <QThread>
#include "client.h"

class SignConflictCheckThread : public QThread
{
    Q_OBJECT
public:
    explicit SignConflictCheckThread(QObject *parent = nullptr);
    ~SignConflictCheckThread() override;

signals:
    void conflictCheckResult(bool isOk,QString msg);

public slots:
    void doCheck(const QString &studentName,const QString &actName);
};

namespace Ui {
class StudentView;
}

class StudentView : public QWidget
{
    Q_OBJECT

public:
    explicit StudentView(QWidget *parent = nullptr);
    ~StudentView();

    QString getSelectedActName();

    void setCurrentStudentName(const QString &studentName);
    int getTargetSignRecordRow(const QString &stuName,const QString &actName);
    void autoWaitSign(const QString &actName);

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_btSign_clicked();

    void on_btSearch_clicked();

    void on_btReset_clicked();

    void on_btCancelSign_clicked();

    void on_btCancelWait_clicked();

    void on_searchButton_clicked();

    void on_resetButton_clicked();

    void onConflictCheckResult(bool isOk,QString msg);
    void onSelectionChanged();

private:
    Ui::StudentView *ui;
    Client *m_client;
    QString m_curStudentName;
    SignConflictCheckThread *m_conflictThread;
};

#endif // STUDENTVIEW_H
