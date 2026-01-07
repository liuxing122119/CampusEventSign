#include "studentview.h"
#include "ui_studentview.h"
#include "idatabase.h"

StudentView::StudentView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentView)
{
    ui->setupUi(this);

    ui->listWidget->setCurrentRow(0);
    ui->stackedWidget->setCurrentWidget(ui->actscanpage);

    m_client = Client::getInstance();

    QStringList categoryList = m_client->getActivityCategories();
    ui->acttype->clear();
    ui->acttype->addItem("全部");
    ui->acttype->addItems(categoryList);

    ui->myacttype->clear();
    ui->myacttype->addItem("全部");
    ui->myacttype->addItems(categoryList);

    ui->acttableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->acttableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->acttableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->acttableView->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if (iDatabase.initActivityModel()) {
        ui->acttableView->setModel(iDatabase.activityTabModel);
        ui->acttableView->setSelectionModel(iDatabase.theActivitySelection);
        iDatabase.searchActivity("STATUS = '已通过'");
        int statusCol = iDatabase.activityTabModel->fieldIndex("STATUS");
        ui->acttableView->hideColumn(statusCol);
    }

    ui->btSign->setEnabled(false);
    connect(iDatabase.theActivitySelection,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(onSelectionChanged()));

    ui->myacttableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->myacttableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->myacttableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->myacttableView->setAlternatingRowColors(true);

    if (iDatabase.initSignRecordModel()) {
        ui->myacttableView->setModel(iDatabase.signRecordTabModel);
        ui->myacttableView->setSelectionModel(iDatabase.theSignRecordSelection);
    }

    ui->btCancelSign->setEnabled(false);
    ui->btCancelWait->setEnabled(false);
    connect(iDatabase.theSignRecordSelection,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(onSelectionChanged()));

    m_conflictThread = new Thread(this);
    connect(m_conflictThread,&Thread::conflictCheckResult,this,&StudentView::onConflictCheckResult);
}

StudentView::~StudentView()
{
    delete ui;
}

void StudentView::setCurrentStudentName(const QString &studentName) {
    m_curStudentName = studentName;
    IDatabase::getInstance().searchSignRecord(QString("STUDENT = '%1'").arg(m_curStudentName));
}

void StudentView::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (item->text() == "活动浏览")
        ui->stackedWidget->setCurrentWidget(ui->actscanpage);
    else if (item->text() == "我的活动")
        ui->stackedWidget->setCurrentWidget(ui->myactpage);
}

void StudentView::on_btSign_clicked()
{
    QString actName = getSelectedActName();
    m_conflictThread->doCheck(m_curStudentName,actName);
}

void StudentView::on_btSearch_clicked()
{
    QString type = ui->acttype->currentText();
    QString name = ui->searchEdit->text().trimmed();

    QStringList filters;
    filters << QString("STATUS = '已通过'");
    if (type != "全部")
        filters << QString("TYPE = '%1'").arg(type);
    if (!name.isEmpty())
        filters << QString("ACTNAME LIKE '%%1%'").arg(name);

    QString filter = filters.join(" AND ");
    IDatabase::getInstance().searchActivity(filter);
}

void StudentView::on_btReset_clicked()
{
    ui->searchEdit->clear();
    ui->acttype->setCurrentIndex(0);

    IDatabase::getInstance().activityTabModel->setFilter("");
    IDatabase::getInstance().activityTabModel->select();
    IDatabase::getInstance().searchActivity("STATUS = '已通过'");
}

void StudentView::on_btCancelSign_clicked()
{
    QModelIndexList selectedIndexes = ui->myacttableView->selectionModel()->selectedRows();
    IDatabase::getInstance().deleteCurrentSignRecord();
    IDatabase::getInstance().theSignRecordSelection->clearSelection();
    onSelectionChanged();
}

void StudentView::on_btCancelWait_clicked()
{
    QModelIndexList selectedIndexes = ui->myacttableView->selectionModel()->selectedRows();
    IDatabase::getInstance().deleteCurrentSignRecord();
    IDatabase::getInstance().theSignRecordSelection->clearSelection();
    onSelectionChanged();
}

void StudentView::on_searchButton_clicked()
{
    QString type = ui->myacttype->currentText();
    QString signStatus = ui->signstatus->currentText();
    QString name = ui->inputSearch->text().trimmed();

    QStringList filters;
    filters << QString("STUDENT = '%1'").arg(m_curStudentName);
    filters << QString("ACTIVITY IN (select ACTNAME from activity where STATUS = '已通过')");
    if (type != "全部")
        filters << QString("ACTIVITY IN (select ACTNAME from activity where TYPE = '%1')").arg(type);
    if (signStatus != "全部")
        filters << QString("SIGNSTATUS = '%1'").arg(signStatus);
    if (!name.isEmpty())
        filters << QString("ACTIVITY LIKE '%%1%'").arg(name);

    QString filter = filters.join(" AND ");
    IDatabase::getInstance().searchSignRecord(filter);
}

void StudentView::on_resetButton_clicked()
{
    ui->inputSearch->clear();
    ui->myacttype->setCurrentIndex(0);
    ui->signstatus->setCurrentIndex(0);
    IDatabase::getInstance().activityTabModel->setFilter("");
    IDatabase::getInstance().activityTabModel->select();
    IDatabase::getInstance().searchSignRecord(QString("STUDENT = '%1'").arg(m_curStudentName));
}

int StudentView::getTargetSignRecordRow(const QString &stuName,const QString &actName) {
    QSqlTableModel *signModel = IDatabase::getInstance().signRecordTabModel;
    int stuCol = signModel->fieldIndex("STUDENT");
    int actCol = signModel->fieldIndex("ACTIVITY");
    int targetRow = -1;

    for (int i = 0;i < signModel->rowCount();i++) {
        QString curStuName = signModel->data(signModel->index(i,stuCol)).toString();
        QString curActName = signModel->data(signModel->index(i,actCol)).toString();
        if (curStuName == stuName && curActName == actName) {
            targetRow = i;
            break;
        }
    }

    if (targetRow == -1)
        targetRow = IDatabase::getInstance().addNewSignRecord(stuName,actName);
    return targetRow;
}

void StudentView::autoWaitSign(const QString &actName)
{
    QSqlTableModel *signModel = IDatabase::getInstance().signRecordTabModel;
    int targetRow = getTargetSignRecordRow(m_curStudentName,actName);
    int maxWaitRank = 0;

    QSqlQuery query;
    query.exec(QString("select MAX(WAITRANK) from signrecord where ACTIVITY = '%1' and SIGNSTATUS = '候补中'").arg(actName));
    if (query.first() && query.value(0).isValid())
        maxWaitRank = query.value(0).toInt();

    int statusCol = signModel->fieldIndex("SIGNSTATUS");
    int waitRankCol = signModel->fieldIndex("WAITRANK");
    signModel->setData(signModel->index(targetRow,statusCol),"候补中");
    signModel->setData(signModel->index(targetRow,waitRankCol),maxWaitRank + 1);

    IDatabase::getInstance().submitSignRecordEdit();
    IDatabase::getInstance().theSignRecordSelection->clearSelection();
}

void StudentView::onConflictCheckResult(bool isOk,QString msg) {
    QString actName = getSelectedActName();
    if (!isOk) {
        qDebug() << "failed to sign: " << msg;
        if (msg.startsWith("【名额冲突】"))
            autoWaitSign(actName);// 自动候补
        return;
    }

    QSqlTableModel *signModel = IDatabase::getInstance().signRecordTabModel;
    int targetRow = getTargetSignRecordRow(m_curStudentName,actName);
    int statusCol = signModel->fieldIndex("SIGNSTATUS");
    int waitRankCol = signModel->fieldIndex("WAITRANK");

    signModel->setData(signModel->index(targetRow,statusCol),"已报名");
    signModel->setData(signModel->index(targetRow,waitRankCol),0);
    qDebug() << "sign success";

    IDatabase::getInstance().submitSignRecordEdit();
    IDatabase::getInstance().theSignRecordSelection->clearSelection();
}

void StudentView::onSelectionChanged() {
    if (ui->stackedWidget->currentWidget() == ui->actscanpage) {
        QItemSelectionModel *selectionModel = IDatabase::getInstance().theActivitySelection;
        bool hasSelected = selectionModel->hasSelection();
        bool canSign = false;
        if (hasSelected)
            canSign = true;
        ui->btSign->setEnabled(canSign);
    } else if (ui->stackedWidget->currentWidget() == ui->myactpage) {
        QItemSelectionModel *userSelectionModel = IDatabase::getInstance().theSignRecordSelection;
        bool hasSelectedUser = userSelectionModel->hasSelection();
        bool canCancelSign = false;
        bool canCancelWait = false;
        if (hasSelectedUser) {
            QModelIndex curUserIndex = userSelectionModel->currentIndex();
            QSqlTableModel *signModel = IDatabase::getInstance().signRecordTabModel;
            int statusColumn = signModel->fieldIndex("SIGNSTATUS");
            QModelIndex roleIndex = signModel->index(curUserIndex.row(),statusColumn);
            QString signStatus = signModel->data(roleIndex).toString().trimmed();

            if (signStatus == "已报名")
                canCancelSign = true;
            else if (signStatus == "候补中")
                canCancelWait = true;
        }
        ui->btCancelSign->setEnabled(canCancelSign);
        ui->btCancelWait->setEnabled(canCancelWait);
    }
}

QString StudentView::getSelectedActName() {
    QModelIndexList selectedIndexes = ui->acttableView->selectionModel()->selectedRows();
    QModelIndex actNameIndex = ui->acttableView->model()->index(
        selectedIndexes.first().row(),
        IDatabase::getInstance().activityTabModel->fieldIndex("ACTNAME"));
    return ui->acttableView->model()->data(actNameIndex).toString().trimmed();
}
