#include "sponsorview.h"
#include "ui_sponsorview.h"
#include "idatabase.h"
#include <QFileDialog>
#include <QInputDialog>

SponsorView::SponsorView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SponsorView)
{
    ui->setupUi(this);

    ui->listWidget->setCurrentRow(0);
    ui->stackedWidget->setCurrentWidget(ui->managepage);

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

    ui->btUpdate->setEnabled(false);
    ui->btExport->setEnabled(false);
    connect(iDatabase.theActivitySelection,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(onSelectionChanged()));

    m_exportThread = new Thread(this);
    connect(m_exportThread,&Thread::exportFinished,this,&SponsorView::onExportFinished);
}

SponsorView::~SponsorView()
{
    delete ui;
}

void SponsorView::setCurrentSponsorName(const QString &sponsorName)
{
    m_currentSponsorname = sponsorName;
    IDatabase::getInstance().searchActivity(QString("SPONSOR = '%1'").arg(m_currentSponsorname));
}

void SponsorView::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (item->text() == "我的活动")
        ui->stackedWidget->setCurrentWidget(ui->managepage);
}

void SponsorView::on_btAdd_clicked()
{
    int curRow = IDatabase::getInstance().addNewActivity(m_currentSponsorname);
    emit goActivityEditView(curRow);
}

void SponsorView::on_btUpdate_clicked()
{
    QModelIndex curIndex = IDatabase::getInstance().theActivitySelection->currentIndex();
    QSqlTableModel *activityModel = IDatabase::getInstance().activityTabModel;
    int statusColumn = activityModel->fieldIndex("STATUS");
    QModelIndex statusIndex = activityModel->index(curIndex.row(),statusColumn);
    QString activityStatus = activityModel->data(statusIndex).toString();
    emit goActivityEditView(curIndex.row());
    IDatabase::getInstance().theActivitySelection->clearSelection();
    onSelectionChanged();
}

void SponsorView::on_btSearch_clicked()
{
    QString type = ui->acttype->currentText();
    QString status = ui->actstatus->currentText();
    QString name = ui->searchEdit->text().trimmed();

    QStringList filters;
    filters << QString("SPONSOR = '%1'").arg(m_currentSponsorname);
    if (type != "全部")
        filters << QString("TYPE = '%1'").arg(type);
    if (status != "全部")
        filters << QString("STATUS = '%1'").arg(status);
    if (!name.isEmpty())
        filters << QString("ACTNAME LIKE '%%1%'").arg(name);

    QString filter = filters.join(" AND ");
    IDatabase::getInstance().searchActivity(filter);
}


void SponsorView::on_btReset_clicked()
{
    ui->searchEdit->clear();
    ui->acttype->setCurrentIndex(0);
    ui->actstatus->setCurrentIndex(0);

    IDatabase::getInstance().activityTabModel->setFilter("");
    IDatabase::getInstance().activityTabModel->select();
    IDatabase::getInstance().searchActivity(QString("SPONSOR = '%1'").arg(m_currentSponsorname));
}

void SponsorView::onSelectionChanged()
{
    QItemSelectionModel *selectionModel = IDatabase::getInstance().theActivitySelection;
    bool hasSelectedRow = selectionModel->hasSelection();
    bool canEdit = false;
    bool canExport = false;
    if (hasSelectedRow) {
        canExport = true;
        QModelIndex curIndex = selectionModel->currentIndex();
        QSqlTableModel *activityModel = IDatabase::getInstance().activityTabModel;
        int statusColumn = activityModel->fieldIndex("STATUS");
        QModelIndex statusIndex = activityModel->index(curIndex.row(),statusColumn);
        QString activityStatus = activityModel->data(statusIndex).toString();
        if (activityStatus == "待审核")
            canEdit = true;
    }
    ui->btUpdate->setEnabled(canEdit);
    ui->btExport->setEnabled(canExport);
}

void SponsorView::on_btExport_clicked()
{
    QString actName = getSelectedActName();

    // 选择导出类型
    QStringList exportTypes;
    exportTypes << "报名名单(CSV)" << "统计报表(CSV)";
    bool isOk;
    QString selectType = QInputDialog::getItem(this,"选择导出类型","请选择导出内容：",exportTypes,0,false,&isOk);
    if (!isOk || selectType.isEmpty()) {
        qDebug() << "[导出提示] 用户取消选择导出类型";
        return;
    }

    // 选择保存路径
    QString savePath = QFileDialog::getSaveFileName(this,"选择CSV文件保存路径","","CSV文件 (*.csv);;所有文件 (*)");
    if (savePath.isEmpty()) {
        qDebug() << "[导出提示] 用户取消选择保存路径";
        return;
    }

    bool querySuccess;
    QString msg;
    QString exportData = IDatabase::getInstance().getExportData(actName,selectType,querySuccess,msg);
    if (!querySuccess) {
        qDebug() << msg;
        return;
    }

    m_exportThread->startExport(savePath,exportData);
    qDebug() << "[导出提示] 后台导出线程已启动，处理活动：" << actName;
}

void SponsorView::onExportFinished(bool success,const QString &msg)
{
    if (success)
        qDebug() << "[导出成功] " << msg;
    else
        qDebug() << "[导出失败] " << msg;
}

QString SponsorView::getSelectedActName()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    QSqlTableModel *activityModel = IDatabase::getInstance().activityTabModel;
    int actNameCol = activityModel->fieldIndex("ACTNAME");// 活动名字段
    QModelIndex actNameIndex = activityModel->index(selectedIndexes.first().row(),actNameCol);
    return activityModel->data(actNameIndex).toString().trimmed();
}
