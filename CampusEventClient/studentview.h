#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class StudentView;
}

class StudentView : public QWidget
{
    Q_OBJECT

public:
    explicit StudentView(QWidget *parent = nullptr);
    ~StudentView();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::StudentView *ui;
};

#endif // STUDENTVIEW_H
