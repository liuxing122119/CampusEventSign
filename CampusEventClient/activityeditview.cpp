#include "activityeditview.h"
#include "ui_activityeditview.h"
#include "idatabase.h"
#include <QSqlTableModel>

ActivityEditView::ActivityEditView(QWidget *parent, int index)
    : QWidget(parent)
    , ui(new Ui::ActivityEditView)
{
    ui->setupUi(this);

    m_client = Client::getInstance();

    QStringList categoryList = m_client->getActivityCategories();
    ui->acttype->clear();
    ui->acttype->addItems(categoryList);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().activityTabModel;
    dataMapper->setModel(IDatabase::getInstance().activityTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->actidEdit, tabModel->fieldIndex("ACTID"));
    dataMapper->addMapping(ui->actnameEdit, tabModel->fieldIndex("ACTNAME"));
    dataMapper->addMapping(ui->acttype, tabModel->fieldIndex("TYPE"));
    dataMapper->addMapping(ui->actstatus, tabModel->fieldIndex("STATUS"));
    dataMapper->addMapping(ui->acttimeEdit, tabModel->fieldIndex("ACTTIME"));
    dataMapper->addMapping(ui->actaddressEdit, tabModel->fieldIndex("ACTADDRESS"));
    dataMapper->addMapping(ui->maxcountEdit, tabModel->fieldIndex("MAXCOUNT"));
    dataMapper->addMapping(ui->starttimeEdit, tabModel->fieldIndex("STARTTIME"));
    dataMapper->addMapping(ui->endtimeEdit, tabModel->fieldIndex("ENDTIME"));
    dataMapper->addMapping(ui->createtimeEdit, tabModel->fieldIndex("CREATETIME"));
    dataMapper->addMapping(ui->lineEdit, tabModel->fieldIndex("SPONSOR"));

    dataMapper->setCurrentIndex(index);

    ui->actidEdit->setEnabled(false);
    ui->createtimeEdit->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->actstatus->setEnabled(false);
}

ActivityEditView::~ActivityEditView()
{
    delete ui;
}

void ActivityEditView::on_submitButton_clicked()
{
    dataMapper->submit();
    IDatabase::getInstance().submitActivityEdit();
    emit goPreviousView();
}


void ActivityEditView::on_cancelButton_clicked()
{
    IDatabase::getInstance().revertActivityEdit();
    emit goPreviousView();
}

