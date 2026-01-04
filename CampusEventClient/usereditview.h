#ifndef USEREDITVIEW_H
#define USEREDITVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>

namespace Ui {
class UserEditView;
}

class UserEditView : public QWidget
{
    Q_OBJECT

public:
    explicit UserEditView(QWidget *parent = nullptr,int index = 0);
    ~UserEditView();

signals:
    void goPreviousView();

private slots:
    void on_submitButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::UserEditView *ui;
    QDataWidgetMapper *dataMapper;
};

#endif // USEREDITVIEW_H
