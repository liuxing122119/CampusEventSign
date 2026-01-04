#include "studentview.h"
#include "ui_studentview.h"
#include "idatabase.h"

SignConflictCheckThread::SignConflictCheckThread(QObject *parent)
    : QThread(parent)
{

}

SignConflictCheckThread::~SignConflictCheckThread()
{
    wait();
}

void SignConflictCheckThread::doCheck(const QString &studentName,const QString &actName)
{
    QString conflictMsg;
    bool hasConflict = IDatabase::getInstance().checkSignConflict(studentName,actName,conflictMsg);
    emit conflictCheckResult(!hasConflict,conflictMsg);
}

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
    if (iDatabase.initActivityModel()){
        ui->acttableView->setModel(iDatabase.activityTabModel);
        ui->acttableView->setSelectionModel(iDatabase.theActivitySelection);
        iDatabase.searchActivity("STATUS = '已通过'");
    }

    ui->myacttableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->myacttableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->myacttableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->myacttableView->setAlternatingRowColors(true);

    if (iDatabase.initSignRecordModel()){
        ui->myacttableView->setModel(iDatabase.signRecordTabModel);
        ui->myacttableView->setSelectionModel(iDatabase.theSignRecordSelection);
    }

    // connect(iDatabase.theActivitySelection,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(onSelectionChanged()));

    m_conflictThread = new SignConflictCheckThread(this);
    connect(m_conflictThread,&SignConflictCheckThread::conflictCheckResult,
            this,&StudentView::onConflictCheckResult);
}

StudentView::~StudentView()
{
    delete ui;
}

void StudentView::setCurrentStudentName(const QString &studentName)
{
    m_curStudentName = studentName;
    IDatabase &iDatabase = IDatabase::getInstance();
    iDatabase.searchSignRecord(QString("STUDENT = '%1'").arg(m_curStudentName));
}

QString StudentView::getSelectedActName()
{
    QModelIndexList selectedIndexes = ui->acttableView->selectionModel()->selectedRows();
    IDatabase &iDatabase = IDatabase::getInstance();
    QModelIndex actNameIndex = ui->acttableView->model()->index(selectedIndexes.first().row(),
                                                                iDatabase.activityTabModel->fieldIndex("ACTNAME"));
    return ui->acttableView->model()->data(actNameIndex).toString();
}

int StudentView::getTargetSignRecordRow(const QString &stuName, const QString &actName)
{
    IDatabase &iDatabase = IDatabase::getInstance();
    QSqlTableModel *signModel = iDatabase.signRecordTabModel;
    int stuCol = signModel->fieldIndex("STUDENT");
    int actCol = signModel->fieldIndex("ACTIVITY");
    int targetRow = -1;

    for (int i = 0; i < signModel->rowCount(); i++) {
        QString curStuName = signModel->data(signModel->index(i, stuCol)).toString();
        QString curActName = signModel->data(signModel->index(i, actCol)).toString();
        if (curStuName == stuName && curActName == actName) {
            targetRow = i;
            break;
        }
    }

    if (targetRow == -1) {
        targetRow = iDatabase.addNewSignRecord(stuName, actName);
    }
    return targetRow;
}

void StudentView::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (item->text() == "活动浏览") {
        ui->stackedWidget->setCurrentWidget(ui->actscanpage);
    } else if (item->text() == "我的活动") {
        ui->stackedWidget->setCurrentWidget(ui->myactpage);
        IDatabase &iDatabase = IDatabase::getInstance();
        if (!m_curStudentName.isEmpty()) {
            iDatabase.searchSignRecord(QString("STUDENT = '%1'").arg(m_curStudentName));
        }
    }
}

void StudentView::on_btSign_clicked()
{
    QString actName = getSelectedActName();
    m_conflictThread->doCheck(m_curStudentName, actName);
}


void StudentView::on_btWait_clicked()
{
    QString actName = getSelectedActName();
    IDatabase &iDatabase = IDatabase::getInstance();
    QSqlTableModel *signModel = iDatabase.signRecordTabModel;

    int targetRow = getTargetSignRecordRow(m_curStudentName, actName);

    int maxWaitRank = 0;
    QSqlQuery query;
    query.exec(QString("SELECT MAX(WAITRANK) FROM signrecord WHERE ACTIVITY = '%1' AND SIGNSTATUS = '候补中'").arg(actName));
    if (query.first() && query.value(0).isValid()) {
        maxWaitRank = query.value(0).toInt();
    }

    int statusCol = signModel->fieldIndex("SIGNSTATUS");
    int waitRankCol = signModel->fieldIndex("WAITRANK");
    signModel->setData(signModel->index(targetRow, statusCol), "候补中");
    signModel->setData(signModel->index(targetRow, waitRankCol), maxWaitRank + 1);

    iDatabase.submitSignRecordEdit();
    iDatabase.theSignRecordSelection->clearSelection();
    iDatabase.searchSignRecord(QString("STUDENT = '%1'").arg(m_curStudentName));
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
    IDatabase &iDatabase = IDatabase::getInstance();
    QSqlTableModel *signModel = iDatabase.signRecordTabModel;

    int targetRow = selectedIndexes.first().row();
    int statusCol = signModel->fieldIndex("SIGNSTATUS");
    int waitRankCol = signModel->fieldIndex("WAITRANK");

    signModel->setData(signModel->index(targetRow, statusCol), "未报名");
    signModel->setData(signModel->index(targetRow, waitRankCol), 0);

    iDatabase.submitSignRecordEdit();
    iDatabase.theSignRecordSelection->clearSelection();
    iDatabase.searchSignRecord(QString("STUDENT = '%1'").arg(m_curStudentName));
}


void StudentView::on_btCancelWait_clicked()
{
    QModelIndexList selectedIndexes = ui->myacttableView->selectionModel()->selectedRows();
    IDatabase &iDatabase = IDatabase::getInstance();
    QSqlTableModel *signModel = iDatabase.signRecordTabModel;

    int targetRow = selectedIndexes.first().row();
    int statusCol = signModel->fieldIndex("SIGNSTATUS");
    int waitRankCol = signModel->fieldIndex("WAITRANK");

    signModel->setData(signModel->index(targetRow, statusCol), "未报名");
    signModel->setData(signModel->index(targetRow, waitRankCol), 0);

    iDatabase.submitSignRecordEdit();
    iDatabase.theSignRecordSelection->clearSelection();
    iDatabase.searchSignRecord(QString("STUDENT = '%1'").arg(m_curStudentName));
}


void StudentView::on_searchButton_clicked()
{
    QString type = ui->myacttype->currentText();
    QString signStatus = ui->signstatus->currentText();
    QString name = ui->inputSearch->text().trimmed();

    QStringList filters;
    filters << QString("STUDENT = '%1'").arg(m_curStudentName);
    filters << QString("ACTIVITY IN (SELECT ACTNAME FROM activity WHERE STATUS = '已通过')");
    if (type != "全部")
        filters << QString("ACTIVITY IN (SELECT ACTNAME FROM activity WHERE TYPE = '%1')").arg(type);
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
    ui->acttype->setCurrentIndex(0);
    ui->signstatus->setCurrentIndex(0);

    IDatabase::getInstance().activityTabModel->setFilter("");
    IDatabase::getInstance().activityTabModel->select();
}

void StudentView::onConflictCheckResult(bool isOk,QString msg)
{
    IDatabase &iDatabase = IDatabase::getInstance();
    QSqlTableModel *signModel = iDatabase.signRecordTabModel;

    QString actName = getSelectedActName();

    int targetRow = getTargetSignRecordRow(m_curStudentName, actName);

    int statusCol = signModel->fieldIndex("SIGNSTATUS");
    int waitRankCol = signModel->fieldIndex("WAITRANK");
    signModel->setData(signModel->index(targetRow, statusCol),"已报名");
    signModel->setData(signModel->index(targetRow, waitRankCol),0);

    iDatabase.submitSignRecordEdit();
    iDatabase.theSignRecordSelection->clearSelection();
    iDatabase.searchSignRecord(QString("STUDENT = '%1'").arg(m_curStudentName));
}

void StudentView::onSelectionChanged()
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
    // ui->btUpdate->setEnabled(canEdit);
}

