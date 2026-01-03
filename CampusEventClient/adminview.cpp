#include "adminview.h"
#include "ui_adminview.h"

AdminView::AdminView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminView)
{
    ui->setupUi(this);

    ui->listWidget->setCurrentRow(0);
    ui->stackedWidget->setCurrentWidget(ui->checkpage);

    m_client = Client::getInstance();

    QStringList categoryList = m_client->getActivityCategories();
    ui->acttype->clear();
    ui->acttype->addItem("全部");
    ui->acttype->addItems(categoryList);
}

AdminView::~AdminView()
{
    delete ui;
}

void AdminView::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (item->text() == "活动审核") {
        ui->stackedWidget->setCurrentWidget(ui->checkpage);
    } else if (item->text() == "用户管理") {
        ui->stackedWidget->setCurrentWidget(ui->userpage);
    }
}

