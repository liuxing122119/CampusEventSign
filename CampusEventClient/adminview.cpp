#include "adminview.h"
#include "ui_adminview.h"
#include "idatabase.h"

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

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().activityTabModel;
    dataMapper->setModel(IDatabase::getInstance().activityTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if (iDatabase.initActivityModel()){
        ui->tableView->setModel(iDatabase.activityTabModel);
        ui->tableView->setSelectionModel(iDatabase.theActivitySelection);
    }

    ui->btReject->setEnabled(false);
    ui->btPass->setEnabled(false);
    connect(iDatabase.theActivitySelection, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(onSelectionChanged()));
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


void AdminView::on_btReject_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    QSqlTableModel *activityModel = IDatabase::getInstance().activityTabModel;
    int statusColumn = activityModel->fieldIndex("STATUS");

    QModelIndex statusIndex = activityModel->index(selectedIndexes.first().row(), statusColumn);
    activityModel->setData(statusIndex, "未通过");

    dataMapper->submit();
    IDatabase::getInstance().submitActivityEdit();
}


void AdminView::on_btPass_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    QSqlTableModel *activityModel = IDatabase::getInstance().activityTabModel;
    int statusColumn = activityModel->fieldIndex("STATUS");

    QModelIndex statusIndex = activityModel->index(selectedIndexes.first().row(), statusColumn);
    activityModel->setData(statusIndex, "已通过");

    dataMapper->submit();
    IDatabase::getInstance().submitActivityEdit();
}


void AdminView::on_btSearch_clicked()
{

}


void AdminView::on_btReset_clicked()
{

}


void AdminView::on_btAdd_clicked()
{

}


void AdminView::on_btUpdate_clicked()
{

}


void AdminView::on_btDelete_clicked()
{

}


void AdminView::on_searchButton_clicked()
{

}


void AdminView::on_resetButton_clicked()
{

}


void AdminView::onSelectionChanged()
{
    QItemSelectionModel *selectionModel = IDatabase::getInstance().theActivitySelection;
    bool hasSelectedRow = selectionModel->hasSelection();
    ui->btReject->setEnabled(hasSelectedRow);
    ui->btPass->setEnabled(hasSelectedRow);
}
