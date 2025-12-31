#ifndef ACTIVITYEDITVIEW_H
#define ACTIVITYEDITVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>

namespace Ui {
class ActivityEditView;
}

class ActivityEditView : public QWidget
{
    Q_OBJECT

public:
    explicit ActivityEditView(QWidget *parent = nullptr, int index = 0);
    ~ActivityEditView();

private slots:
    void on_submitButton_clicked();

    void on_cancelButton_clicked();

signals:
    void goPreviousView();

private:
    Ui::ActivityEditView *ui;
    QDataWidgetMapper *dataMapper;
};

#endif // ACTIVITYEDITVIEW_H
