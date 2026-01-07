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

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if (iDatabase.initActivityModel()) {
        ui->tableView->setModel(iDatabase.activityTabModel);
        ui->tableView->setSelectionModel(iDatabase.theActivitySelection);
    }

    ui->btReject->setEnabled(false);
    ui->btPass->setEnabled(false);
    connect(iDatabase.theActivitySelection,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(onSelectionChanged()));

    ui->usertableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->usertableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->usertableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->usertableView->setAlternatingRowColors(true);

    if (iDatabase.initUserModel()) {
        ui->usertableView->setModel(iDatabase.userTabModel);
        ui->usertableView->setSelectionModel(iDatabase.theUserSelection);
    }

    ui->btUpdate->setEnabled(false);
    ui->btDelete->setEnabled(false);
    connect(iDatabase.theUserSelection,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(onSelectionChanged()));
}

AdminView::~AdminView()
{
    delete ui;
}

void AdminView::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (item->text() == "活动审核")
        ui->stackedWidget->setCurrentWidget(ui->checkpage);
    else if (item->text() == "用户管理")
        ui->stackedWidget->setCurrentWidget(ui->userpage);
}

void AdminView::on_btReject_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    QSqlTableModel *activityModel = IDatabase::getInstance().activityTabModel;
    activityModel->setData(activityModel->index(selectedIndexes.first().row(),
                                                activityModel->fieldIndex("STATUS")),"未通过");
    IDatabase::getInstance().submitActivityEdit();
    IDatabase::getInstance().theActivitySelection->clearSelection();
    onSelectionChanged();
}

void AdminView::on_btPass_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    QSqlTableModel *activityModel = IDatabase::getInstance().activityTabModel;
    activityModel->setData(activityModel->index(selectedIndexes.first().row(),
                                                activityModel->fieldIndex("STATUS")),"已通过");
    IDatabase::getInstance().submitActivityEdit();
    IDatabase::getInstance().theActivitySelection->clearSelection();
    onSelectionChanged();
}

void AdminView::on_btSearch_clicked()
{
    QString type = ui->acttype->currentText();
    QString status = ui->actstatus->currentText();
    QString name = ui->searchEdit->text().trimmed();

    QStringList filters;
    if (type != "全部")
        filters << QString("TYPE = '%1'").arg(type);
    if (status != "全部")
        filters << QString("STATUS = '%1'").arg(status);
    if (!name.isEmpty())
        filters << QString("(ACTNAME LIKE '%%1%' OR SPONSOR LIKE '%%1%')").arg(name);

    QString filter = filters.join(" AND ");
    IDatabase::getInstance().searchActivity(filter);
}

void AdminView::on_btReset_clicked()
{
    ui->searchEdit->clear();
    ui->acttype->setCurrentIndex(0);
    ui->actstatus->setCurrentIndex(0);

    IDatabase::getInstance().activityTabModel->setFilter("");
    IDatabase::getInstance().activityTabModel->select();
}

void AdminView::on_btAdd_clicked()
{
    int currow = IDatabase::getInstance().addNewUser();
    emit goUserEditView(currow);
}

void AdminView::on_btUpdate_clicked()
{
    QModelIndex curIndex = IDatabase::getInstance().theUserSelection->currentIndex();
    emit goUserEditView(curIndex.row());
    IDatabase::getInstance().theUserSelection->clearSelection();
    onSelectionChanged();
}

void AdminView::on_btDelete_clicked()
{
    IDatabase::getInstance().deleteCurrentUser();
    IDatabase::getInstance().theUserSelection->clearSelection();
    onSelectionChanged();
}

void AdminView::on_searchButton_clicked()
{
    QString role = ui->userrole->currentText();
    QString name = ui->usersearchEdit->text().trimmed();

    QStringList filters;
    if (role != "全部")
        filters << QString("ROLE = '%1'").arg(role);
    if (!name.isEmpty())
        filters << QString("USERNAME LIKE '%%1%'").arg(name);

    QString filter = filters.join(" AND ");
    IDatabase::getInstance().searchUser(filter);
}

void AdminView::on_resetButton_clicked()
{
    ui->usersearchEdit->clear();
    ui->userrole->setCurrentIndex(0);

    IDatabase::getInstance().userTabModel->setFilter("");
    IDatabase::getInstance().userTabModel->select();
}

void AdminView::onSelectionChanged()
{
    if (ui->stackedWidget->currentWidget() == ui->checkpage) {
        QItemSelectionModel *selectionModel = IDatabase::getInstance().theActivitySelection;
        bool hasSelectedRow = selectionModel->hasSelection();
        bool canEdit = false;
        if (hasSelectedRow) {
            QModelIndex curIndex = selectionModel->currentIndex();
            QSqlTableModel *activityModel = IDatabase::getInstance().activityTabModel;
            int statusColumn = activityModel->fieldIndex("STATUS");
            QModelIndex statusIndex = activityModel->index(curIndex.row(),statusColumn);
            QString activityStatus = activityModel->data(statusIndex).toString();
            if (activityStatus == "待审核")
                canEdit = true;
        }
        ui->btReject->setEnabled(canEdit);
        ui->btPass->setEnabled(canEdit);
    } else if (ui->stackedWidget->currentWidget() == ui->userpage) {
        QItemSelectionModel *userSelectionModel = IDatabase::getInstance().theUserSelection;
        bool hasSelectedUser = userSelectionModel->hasSelection();
        bool canUpdateUser = hasSelectedUser;
        if (hasSelectedUser) {
            QModelIndex curUserIndex = userSelectionModel->currentIndex();
            QSqlTableModel *userModel = IDatabase::getInstance().userTabModel;
            int roleColumn = userModel->fieldIndex("ROLE");
            QModelIndex roleIndex = userModel->index(curUserIndex.row(),roleColumn);
            QString userRole = userModel->data(roleIndex).toString().trimmed();
            if (userRole == "管理员")
                canUpdateUser = false;
        }
        ui->btUpdate->setEnabled(canUpdateUser);
        ui->btDelete->setEnabled(canUpdateUser);
    }
}
