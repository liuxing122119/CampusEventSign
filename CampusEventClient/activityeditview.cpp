#include "activityeditview.h"
#include "ui_activityeditview.h"
#include "idatabase.h"
#include "client.h"
#include <QSqlTableModel>

ActivityEditView::ActivityEditView(QWidget *parent, int index)
    : QWidget(parent)
    , ui(new Ui::ActivityEditView)
{
    ui->setupUi(this);

    m_client = Client::getInstance();
    if (m_client) {
        connect(m_client, SIGNAL(jsonReceived(QJsonObject)), this, SLOT(onJsonReceived(QJsonObject)));
        connect(m_client, SIGNAL(connected()), this, SLOT(onClientConnected()));
        if (m_client->isConnected()) {
            m_client->sendGetActivityCategoriesRequest();
        }
    }

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

void ActivityEditView::onJsonReceived(const QJsonObject &docObj)
{
    QString responseType = docObj["type"].toString();
    qDebug() << "收到服务器响应：" << responseType;

    if (responseType == "activity_categories_response") {
        QJsonArray categoryArr = docObj["categories"].toArray();
        qDebug() << "获取到活动类别数量：" << categoryArr.size();
        ui->acttype->clear();
        for (int i = 0; i < categoryArr.size(); ++i) {
            QJsonObject cateObj = categoryArr[i].toObject();
            QString cateName = cateObj["category"].toString();
            ui->acttype->addItem(cateName);
            qDebug() << "添加活动类别：" << cateName;
        }

        dataMapper->setCurrentIndex(dataMapper->currentIndex());
        QSqlTableModel *model = IDatabase::getInstance().activityTabModel;
        QModelIndex typeIndex = model->index(dataMapper->currentIndex(), model->fieldIndex("TYPE"));
        model->setData(typeIndex, ui->acttype->currentText());
    }

    // // 2. 解析公告（以填充QTextEdit为例，你可替换为你的公告组件）
    // if (responseType == "announcements_response") {
    //     QJsonArray annoArr = docObj["announcements"].toArray();
    //     // 假设你有一个名为annoTextEdit的QTextEdit控件，用于显示公告
    //     if (ui->annoTextEdit) {
    //         ui->annoTextEdit->clear();
    //         for (int i = 0; i < annoArr.size(); ++i) {
    //             QJsonObject annoObj = annoArr[i].toObject();
    //             QString title = annoObj["title"].toString();
    //             QString content = annoObj["content"].toString();
    //             ui->annoTextEdit->append(QString("【%1】\n%2\n").arg(title).arg(content));
    //         }
    //     }
    // }
}

void ActivityEditView::onClientConnected()
{
    qDebug() << "客户端连接建立，发送获取活动类别请求";
    if (m_client) {
        m_client->sendGetActivityCategoriesRequest();
    }
}

