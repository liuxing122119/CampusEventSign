#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QWidget>
#include <QListWidgetItem>
#include "client.h"
#include "thread.h"

namespace Ui {
class StudentView;
}

class StudentView : public QWidget
{
    Q_OBJECT

public:
    explicit StudentView(QWidget *parent = nullptr);
    ~StudentView();

    void setCurrentStudentName(const QString &studentName);

    QString getSelectedActName();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_btSign_clicked();

    void on_btSearch_clicked();

    void on_btReset_clicked();

    void on_btCancelSign_clicked();

    void on_btCancelWait_clicked();

    void on_searchButton_clicked();

    void on_resetButton_clicked();

    int getTargetSignRecordRow(const QString &stuName,const QString &actName);
    void onConflictCheckResult(bool isOk,QString msg);
    void autoWaitSign(const QString &actName);
    void onSelectionChanged();

private:
    Ui::StudentView *ui;
    Client *m_client;
    QString m_curStudentName;
    Thread *m_conflictThread;
};

#endif // STUDENTVIEW_H
