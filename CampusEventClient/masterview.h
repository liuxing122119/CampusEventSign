#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QWidget>
#include "loginview.h"
#include "adminview.h"
#include "sponsorview.h"
#include "studentview.h"
#include "activityeditview.h"
#include "usereditview.h"
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MasterView;
}
QT_END_NAMESPACE

class MasterView : public QWidget
{
    Q_OBJECT

public:
    MasterView(QWidget *parent = nullptr);
    ~MasterView();

public slots:
    void goLoginView();
    void goPreviousView();
    void goAdminView();
    void goSponsorView(const QString &username);
    void goStudentView();
    void goActivityEditView(int rowNo);
    void goUserEditView(int rowNo);

    void onLoginSuccess(QString username);
    void onClientDisconnected();
    void delayCreateRoleView();

private slots:
    void on_btBack_clicked();

    void on_btLogout_clicked();

    void on_stackedWidget_currentChanged(int arg1);

private:
    void pushWidgetToStackView(QWidget *widget);

    Ui::MasterView *ui;

    LoginView *loginView;
    AdminView *adminView;
    SponsorView *sponsorView;
    StudentView *studentView;
    ActivityEditView *activityEditView;
    UserEditView *userEditView;

    Client *m_client;
    QString m_Username;
    QString m_UserRole;
};
#endif // MASTERVIEW_H
