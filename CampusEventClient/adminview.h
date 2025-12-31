#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class AdminView;
}

class AdminView : public QWidget
{
    Q_OBJECT

public:
    explicit AdminView(QWidget *parent = nullptr);
    ~AdminView();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::AdminView *ui;
};

#endif // ADMINVIEW_H
