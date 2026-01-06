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
    connect(iDatabase.theActivitySelection,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(onSelectionChanged()));
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
    if (hasSelectedRow) {
        QModelIndex curIndex = selectionModel->currentIndex();
        QSqlTableModel *activityModel = IDatabase::getInstance().activityTabModel;
        int statusColumn = activityModel->fieldIndex("STATUS");
        QModelIndex statusIndex = activityModel->index(curIndex.row(),statusColumn);
        QString activityStatus = activityModel->data(statusIndex).toString();
        if (activityStatus == "待审核")
            canEdit = true;
    }
    ui->btUpdate->setEnabled(canEdit);
}

void SponsorView::on_btExport_clicked()
{
    QString actName = getSelectedActName();
    if (actName.isEmpty()) {
        qDebug() << "[导出提示] 请先选中要导出数据的活动！";
        return;
    }

    QStringList exportTypes;
    exportTypes << "报名名单(CSV)" << "统计报表(CSV)";
    bool isOk;
    QString selectType = QInputDialog::getItem(this,"选择导出类型",
                                               "请选择导出内容：",exportTypes,0,false,&isOk);
    if (!isOk || selectType.isEmpty()) {
        qDebug() << "[导出提示] 用户取消选择导出类型！";
        return;// 用户取消选择
    }

    // 选择保存路径
    QString savePath = QFileDialog::getSaveFileName(
        this,
        "选择CSV文件保存路径",
        "",
        "CSV文件 (*.csv);;所有文件 (*)"
        );
    if (savePath.isEmpty()) {
        qDebug() << "[导出提示] 用户取消选择保存路径！";
        return;// 用户取消保存
    }

    if (!savePath.endsWith(".csv",Qt::CaseInsensitive)) {
        savePath += ".csv";
        qDebug() << "[导出提示] 自动补充.csv后缀，最终路径：" << savePath;
    }

    // 打开文件 + 设置 UTF-8 编码
    QFile file(savePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "[导出错误] 文件打开失败：" << file.errorString();
        return;
    }
    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out << "\xef\xbb\xbf";

    // 导出报名名单
    if (selectType == "报名名单(CSV)") {
        out << "学生姓名,活动名称,报名状态,报名时间,候补排名\n";

        // 查询该活动的所有报名记录
        QSqlQuery query;
        query.prepare("select STUDENT,ACTIVITY,SIGNSTATUS,SIGNTIME,WAITRANK from signrecord where ACTIVITY = :actName");
        query.bindValue(":actName",actName);
        if (!query.exec()) {
            qDebug() << "[导出错误] 查询报名数据失败：" << query.lastError().text();
            file.close();
            return;
        }

        // 遍历写入每条报名记录
        int recordCount = 0;
        while (query.next()) {
            QString student = query.value(0).toString().trimmed();
            QString activity = query.value(1).toString().trimmed();
            QString status = query.value(2).toString().trimmed();
            QString waitRank = query.value(3).toInt() > 0 ? query.value(3).toString() : "无";
            QString signTime = query.value(4).toString().trimmed();

            out << student << "," << activity << "," << status << "," << waitRank << "," << signTime << "\n";
            recordCount++;
        }

        if (recordCount > 0) {
            qDebug() << "[导出成功] 报名名单导出完成！共导出" << recordCount << "条记录，文件路径：" << savePath;
        } else {
            qDebug() << "[导出提示] 该活动暂无报名数据，已生成空CSV文件，文件路径：" << savePath;
        }
    }
    // 导出统计报表（汇总数据）
    else if (selectType == "统计报表(CSV)") {
        out << "统计项,数值\n";

        // 总报名人数
        int total = 0;
        QSqlQuery qTotal;
        qTotal.exec(QString("SELECT COUNT(*) FROM signrecord WHERE ACTIVITY = '%1'").arg(actName));
        if (qTotal.next()) total = qTotal.value(0).toInt();
        out << "总报名人数," << total << "\n";

        // 已报名人数
        int signedNum = 0;
        QSqlQuery qSigned;
        qSigned.exec(QString("SELECT COUNT(*) FROM signrecord WHERE ACTIVITY = '%1' AND SIGNSTATUS = '已报名'").arg(actName));
        if (qSigned.next()) signedNum = qSigned.value(0).toInt();
        out << "已报名人数," << signedNum << "\n";

        // 候补人数
        int waitNum = 0;
        QSqlQuery qWait;
        qWait.exec(QString("SELECT COUNT(*) FROM signrecord WHERE ACTIVITY = '%1' AND SIGNSTATUS = '候补中'").arg(actName));
        if (qWait.next()) waitNum = qWait.value(0).toInt();
        out << "候补人数," << waitNum << "\n";

        // 活动最大名额
        int maxQuota = 0;
        QSqlQuery qQuota;
        qQuota.exec(QString("SELECT MAXCOUNT FROM activity WHERE ACTNAME = '%1'").arg(actName));
        if (qQuota.next()) maxQuota = qQuota.value(0).toInt();
        out << "活动最大名额," << maxQuota << "\n";

        // 名额使用率（百分比）
        double usageRate = maxQuota > 0 ? (signedNum * 100.0 / maxQuota) : 0;
        out << "名额使用率," << QString::asprintf("%.1f%%",usageRate) << "\n";

        qDebug() << "[导出成功] 统计报表导出完成！文件路径：" << savePath;
    }

    // 关闭文件
    file.close();
}

QString SponsorView::getSelectedActName()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    QSqlTableModel *activityModel = IDatabase::getInstance().activityTabModel;
    int actNameCol = activityModel->fieldIndex("ACTNAME");// 活动名字段
    QModelIndex actNameIndex = activityModel->index(selectedIndexes.first().row(),actNameCol);

    return activityModel->data(actNameIndex).toString().trimmed();
}
