#ifndef SPONSORVIEW_H
#define SPONSORVIEW_H

#include <QWidget>
#include <QListWidgetItem>
#include "client.h"
#include "thread.h"

namespace Ui {
class SponsorView;
}

class SponsorView : public QWidget
{
    Q_OBJECT

public:
    explicit SponsorView(QWidget *parent = nullptr);
    ~SponsorView();

    void setCurrentSponsorName(const QString &sponsorName);

    QString getSelectedActName();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_btAdd_clicked();

    void on_btUpdate_clicked();

    void on_btSearch_clicked();

    void on_btReset_clicked();

    void onSelectionChanged();

    void on_btExport_clicked();

    void onExportFinished(bool success,const QString &msg);

signals:
    void goActivityEditView(int index);

private:
    Ui::SponsorView *ui;
    QString m_currentSponsorname;
    Client *m_client;
    Thread *m_exportThread;
};

#endif // SPONSORVIEW_H
