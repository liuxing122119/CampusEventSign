#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QWidget>
#include <QListWidgetItem>
#include <QDataWidgetMapper>
#include "client.h"

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

    void on_btReject_clicked();

    void on_btPass_clicked();

    void on_btSearch_clicked();

    void on_btReset_clicked();

    void on_btAdd_clicked();

    void on_btUpdate_clicked();

    void on_btDelete_clicked();

    void on_searchButton_clicked();

    void on_resetButton_clicked();

    void onSelectionChanged();

private:
    Ui::AdminView *ui;
    QDataWidgetMapper *dataMapper;
    Client *m_client;
};

#endif // ADMINVIEW_H
