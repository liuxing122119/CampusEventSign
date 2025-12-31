#include "studentview.h"
#include "ui_studentview.h"

StudentView::StudentView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentView)
{
    ui->setupUi(this);

    ui->listWidget->setCurrentRow(0);
    ui->stackedWidget->setCurrentWidget(ui->actscanpage);
}

StudentView::~StudentView()
{
    delete ui;
}

void StudentView::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (item->text() == "活动浏览") {
        ui->stackedWidget->setCurrentWidget(ui->actscanpage);
    } else if (item->text() == "我的活动") {
        ui->stackedWidget->setCurrentWidget(ui->myactpage);
    }
}
