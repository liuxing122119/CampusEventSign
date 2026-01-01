#include "sponsorview.h"
#include "ui_sponsorview.h"
#include "idatabase.h"
#include <QFileDialog>

SponsorView::SponsorView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SponsorView)
{
    ui->setupUi(this);

    ui->listWidget->setCurrentRow(0);
    ui->stackedWidget->setCurrentWidget(ui->managepage);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if (iDatabase.initActivityModel()){
        ui->tableView->setModel(iDatabase.activityTabModel);
        ui->tableView->setSelectionModel(iDatabase.theActivitySelection);
    }

    ui->btUpdate->setEnabled(false);
    connect(iDatabase.theActivitySelection, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(onSelectionChanged()));
}

SponsorView::~SponsorView()
{
    delete ui;
}

void SponsorView::setCurrentUsername(const QString &username)
{
    m_currentUsername = username;
}

void SponsorView::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (item->text() == "我的活动") {
        ui->stackedWidget->setCurrentWidget(ui->managepage);
    }
}

void SponsorView::on_btAdd_clicked()
{
    int curRow = IDatabase::getInstance().addNewActivity(m_currentUsername);
    emit goActivityEditView(curRow);
}


void SponsorView::on_btUpdate_clicked()
{
    QModelIndex curIndex = IDatabase::getInstance().theActivitySelection->currentIndex();
    emit goActivityEditView(curIndex.row());
    onSelectionChanged();
}


void SponsorView::on_btSearch_clicked()
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
        filters << QString("ACTNAME LIKE '%%1%'").arg(name);

    QString filter = filters.join(" AND ");
    IDatabase::getInstance().searchActivity(filter);
    IDatabase::getInstance().searchActivity(filter);
}


void SponsorView::on_btReset_clicked()
{
    ui->searchEdit->clear();
    ui->acttype->setCurrentIndex(0);
    ui->actstatus->setCurrentIndex(0);

    IDatabase::getInstance().activityTabModel->setFilter("");
    IDatabase::getInstance().activityTabModel->select();
}

void SponsorView::onSelectionChanged()
{
    bool hasSelectedRow = IDatabase::getInstance().theActivitySelection->hasSelection();
    ui->btUpdate->setEnabled(hasSelectedRow);
}

