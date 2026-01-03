#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QWidget>
#include <QListWidgetItem>
#include "client.h"

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
    Client *m_client;
};

#endif // STUDENTVIEW_H
