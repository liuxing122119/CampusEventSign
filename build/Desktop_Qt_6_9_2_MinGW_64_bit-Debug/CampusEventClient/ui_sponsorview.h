/********************************************************************************
** Form generated from reading UI file 'sponsorview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPONSORVIEW_H
#define UI_SPONSORVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SponsorView
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *managepage;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QComboBox *acttype;
    QLabel *label_7;
    QComboBox *actstatus;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *searchEdit;
    QPushButton *btSearch;
    QPushButton *btReset;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btAdd;
    QPushButton *btRedo;
    QPushButton *btUpdate;

    void setupUi(QWidget *SponsorView)
    {
        if (SponsorView->objectName().isEmpty())
            SponsorView->setObjectName("SponsorView");
        SponsorView->resize(1050, 400);
        gridLayout = new QGridLayout(SponsorView);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        listWidget = new QListWidget(SponsorView);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(listWidget);

        stackedWidget = new QStackedWidget(SponsorView);
        stackedWidget->setObjectName("stackedWidget");
        managepage = new QWidget();
        managepage->setObjectName("managepage");
        verticalLayout = new QVBoxLayout(managepage);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_8 = new QLabel(managepage);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_8);

        acttype = new QComboBox(managepage);
        acttype->addItem(QString());
        acttype->addItem(QString());
        acttype->addItem(QString());
        acttype->addItem(QString());
        acttype->addItem(QString());
        acttype->addItem(QString());
        acttype->setObjectName("acttype");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(acttype->sizePolicy().hasHeightForWidth());
        acttype->setSizePolicy(sizePolicy1);
        acttype->setMinimumSize(QSize(90, 0));

        horizontalLayout_2->addWidget(acttype);

        label_7 = new QLabel(managepage);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_7);

        actstatus = new QComboBox(managepage);
        actstatus->addItem(QString());
        actstatus->addItem(QString());
        actstatus->addItem(QString());
        actstatus->addItem(QString());
        actstatus->addItem(QString());
        actstatus->setObjectName("actstatus");
        sizePolicy1.setHeightForWidth(actstatus->sizePolicy().hasHeightForWidth());
        actstatus->setSizePolicy(sizePolicy1);
        actstatus->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(actstatus);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        searchEdit = new QLineEdit(managepage);
        searchEdit->setObjectName("searchEdit");

        horizontalLayout_2->addWidget(searchEdit);

        btSearch = new QPushButton(managepage);
        btSearch->setObjectName("btSearch");

        horizontalLayout_2->addWidget(btSearch);

        btReset = new QPushButton(managepage);
        btReset->setObjectName("btReset");

        horizontalLayout_2->addWidget(btReset);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(managepage);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_3 = new QSpacerItem(500, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btAdd = new QPushButton(managepage);
        btAdd->setObjectName("btAdd");

        horizontalLayout_3->addWidget(btAdd);

        btRedo = new QPushButton(managepage);
        btRedo->setObjectName("btRedo");

        horizontalLayout_3->addWidget(btRedo);

        btUpdate = new QPushButton(managepage);
        btUpdate->setObjectName("btUpdate");

        horizontalLayout_3->addWidget(btUpdate);


        verticalLayout->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(managepage);

        horizontalLayout->addWidget(stackedWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(SponsorView);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SponsorView);
    } // setupUi

    void retranslateUi(QWidget *SponsorView)
    {
        SponsorView->setWindowTitle(QCoreApplication::translate("SponsorView", "\345\217\221\350\265\267\344\272\272", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("SponsorView", "\346\210\221\347\232\204\346\264\273\345\212\250", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_8->setText(QCoreApplication::translate("SponsorView", "\346\264\273\345\212\250\347\261\273\345\236\213\357\274\232", nullptr));
        acttype->setItemText(0, QCoreApplication::translate("SponsorView", "\345\205\250\351\203\250", nullptr));
        acttype->setItemText(1, QCoreApplication::translate("SponsorView", "\345\276\267\350\202\262\346\225\231\350\202\262", nullptr));
        acttype->setItemText(2, QCoreApplication::translate("SponsorView", "\345\210\233\346\226\260\345\210\233\344\270\232", nullptr));
        acttype->setItemText(3, QCoreApplication::translate("SponsorView", "\347\211\271\350\211\262\344\275\223\350\202\262", nullptr));
        acttype->setItemText(4, QCoreApplication::translate("SponsorView", "\351\253\230\351\233\205\347\276\216\350\202\262", nullptr));
        acttype->setItemText(5, QCoreApplication::translate("SponsorView", "\345\212\263\345\212\250\346\225\231\350\202\262", nullptr));

        label_7->setText(QCoreApplication::translate("SponsorView", "\346\264\273\345\212\250\347\212\266\346\200\201\357\274\232", nullptr));
        actstatus->setItemText(0, QCoreApplication::translate("SponsorView", "\345\205\250\351\203\250", nullptr));
        actstatus->setItemText(1, QCoreApplication::translate("SponsorView", "\345\276\205\345\256\241\346\240\270", nullptr));
        actstatus->setItemText(2, QCoreApplication::translate("SponsorView", "\346\234\252\351\200\232\350\277\207", nullptr));
        actstatus->setItemText(3, QCoreApplication::translate("SponsorView", "\345\267\262\351\200\232\350\277\207", nullptr));
        actstatus->setItemText(4, QCoreApplication::translate("SponsorView", "\345\267\262\346\222\244\345\233\236", nullptr));

        searchEdit->setPlaceholderText(QCoreApplication::translate("SponsorView", "\350\257\267\350\276\223\345\205\245\346\264\273\345\212\250\345\220\215\347\247\260\350\277\233\350\241\214\346\237\245\350\257\242", nullptr));
        btSearch->setText(QCoreApplication::translate("SponsorView", "\346\220\234\347\264\242", nullptr));
        btReset->setText(QCoreApplication::translate("SponsorView", "\351\207\215\347\275\256", nullptr));
        btAdd->setText(QCoreApplication::translate("SponsorView", "\346\267\273\345\212\240", nullptr));
        btRedo->setText(QCoreApplication::translate("SponsorView", "\346\222\244\345\233\236", nullptr));
        btUpdate->setText(QCoreApplication::translate("SponsorView", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SponsorView: public Ui_SponsorView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPONSORVIEW_H
