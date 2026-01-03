/********************************************************************************
** Form generated from reading UI file 'adminview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINVIEW_H
#define UI_ADMINVIEW_H

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

class Ui_AdminView
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *checkpage;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QComboBox *acttype;
    QLabel *label;
    QComboBox *actstatus;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *searchEdit;
    QPushButton *btSearch;
    QPushButton *btReset;
    QPushButton *btExport;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btReject;
    QPushButton *btPass;
    QWidget *userpage;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *usertype;
    QLabel *label_4;
    QComboBox *userstatus;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *usersearchEdit;
    QPushButton *searchButton;
    QPushButton *resetButton;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btAdd;
    QPushButton *btUpdate;
    QPushButton *btDelete;

    void setupUi(QWidget *AdminView)
    {
        if (AdminView->objectName().isEmpty())
            AdminView->setObjectName("AdminView");
        AdminView->resize(1050, 400);
        gridLayout = new QGridLayout(AdminView);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        listWidget = new QListWidget(AdminView);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(listWidget);

        stackedWidget = new QStackedWidget(AdminView);
        stackedWidget->setObjectName("stackedWidget");
        checkpage = new QWidget();
        checkpage->setObjectName("checkpage");
        verticalLayout_2 = new QVBoxLayout(checkpage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(checkpage);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_4->addWidget(label_2);

        acttype = new QComboBox(checkpage);
        acttype->setObjectName("acttype");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(acttype->sizePolicy().hasHeightForWidth());
        acttype->setSizePolicy(sizePolicy1);
        acttype->setMinimumSize(QSize(90, 0));

        horizontalLayout_4->addWidget(acttype);

        label = new QLabel(checkpage);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_4->addWidget(label);

        actstatus = new QComboBox(checkpage);
        actstatus->addItem(QString());
        actstatus->addItem(QString());
        actstatus->addItem(QString());
        actstatus->addItem(QString());
        actstatus->setObjectName("actstatus");
        sizePolicy1.setHeightForWidth(actstatus->sizePolicy().hasHeightForWidth());
        actstatus->setSizePolicy(sizePolicy1);
        actstatus->setMinimumSize(QSize(80, 0));

        horizontalLayout_4->addWidget(actstatus);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        searchEdit = new QLineEdit(checkpage);
        searchEdit->setObjectName("searchEdit");

        horizontalLayout_4->addWidget(searchEdit);

        btSearch = new QPushButton(checkpage);
        btSearch->setObjectName("btSearch");

        horizontalLayout_4->addWidget(btSearch);

        btReset = new QPushButton(checkpage);
        btReset->setObjectName("btReset");

        horizontalLayout_4->addWidget(btReset);

        btExport = new QPushButton(checkpage);
        btExport->setObjectName("btExport");

        horizontalLayout_4->addWidget(btExport);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tableView = new QTableView(checkpage);
        tableView->setObjectName("tableView");

        verticalLayout_2->addWidget(tableView);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer = new QSpacerItem(500, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btReject = new QPushButton(checkpage);
        btReject->setObjectName("btReject");

        horizontalLayout_5->addWidget(btReject);

        btPass = new QPushButton(checkpage);
        btPass->setObjectName("btPass");

        horizontalLayout_5->addWidget(btPass);


        verticalLayout_2->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(checkpage);
        userpage = new QWidget();
        userpage->setObjectName("userpage");
        verticalLayout = new QVBoxLayout(userpage);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(userpage);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        usertype = new QComboBox(userpage);
        usertype->addItem(QString());
        usertype->addItem(QString());
        usertype->addItem(QString());
        usertype->setObjectName("usertype");

        horizontalLayout_2->addWidget(usertype);

        label_4 = new QLabel(userpage);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        userstatus = new QComboBox(userpage);
        userstatus->addItem(QString());
        userstatus->addItem(QString());
        userstatus->addItem(QString());
        userstatus->setObjectName("userstatus");
        sizePolicy1.setHeightForWidth(userstatus->sizePolicy().hasHeightForWidth());
        userstatus->setSizePolicy(sizePolicy1);
        userstatus->setMinimumSize(QSize(70, 0));

        horizontalLayout_2->addWidget(userstatus);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        usersearchEdit = new QLineEdit(userpage);
        usersearchEdit->setObjectName("usersearchEdit");

        horizontalLayout_2->addWidget(usersearchEdit);

        searchButton = new QPushButton(userpage);
        searchButton->setObjectName("searchButton");

        horizontalLayout_2->addWidget(searchButton);

        resetButton = new QPushButton(userpage);
        resetButton->setObjectName("resetButton");

        horizontalLayout_2->addWidget(resetButton);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView_2 = new QTableView(userpage);
        tableView_2->setObjectName("tableView_2");

        verticalLayout->addWidget(tableView_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_4 = new QSpacerItem(500, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        btAdd = new QPushButton(userpage);
        btAdd->setObjectName("btAdd");

        horizontalLayout_3->addWidget(btAdd);

        btUpdate = new QPushButton(userpage);
        btUpdate->setObjectName("btUpdate");

        horizontalLayout_3->addWidget(btUpdate);

        btDelete = new QPushButton(userpage);
        btDelete->setObjectName("btDelete");

        horizontalLayout_3->addWidget(btDelete);


        verticalLayout->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(userpage);

        horizontalLayout->addWidget(stackedWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(AdminView);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AdminView);
    } // setupUi

    void retranslateUi(QWidget *AdminView)
    {
        AdminView->setWindowTitle(QCoreApplication::translate("AdminView", "\347\256\241\347\220\206\345\221\230", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("AdminView", "\346\264\273\345\212\250\345\256\241\346\240\270", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("AdminView", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_2->setText(QCoreApplication::translate("AdminView", "\346\264\273\345\212\250\347\261\273\345\236\213\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("AdminView", "\346\264\273\345\212\250\347\212\266\346\200\201\357\274\232", nullptr));
        actstatus->setItemText(0, QCoreApplication::translate("AdminView", "\345\205\250\351\203\250", nullptr));
        actstatus->setItemText(1, QCoreApplication::translate("AdminView", "\345\276\205\345\256\241\346\240\270", nullptr));
        actstatus->setItemText(2, QCoreApplication::translate("AdminView", "\345\267\262\351\200\232\350\277\207", nullptr));
        actstatus->setItemText(3, QCoreApplication::translate("AdminView", "\346\234\252\351\200\232\350\277\207", nullptr));

        searchEdit->setPlaceholderText(QCoreApplication::translate("AdminView", "\350\257\267\350\276\223\345\205\245\346\264\273\345\212\250\345\220\215\347\247\260/\345\217\221\350\265\267\344\272\272\350\277\233\350\241\214\346\237\245\350\257\242", nullptr));
        btSearch->setText(QCoreApplication::translate("AdminView", "\346\220\234\347\264\242", nullptr));
        btReset->setText(QCoreApplication::translate("AdminView", "\351\207\215\347\275\256", nullptr));
        btExport->setText(QCoreApplication::translate("AdminView", "\345\257\274\345\207\272", nullptr));
        btReject->setText(QCoreApplication::translate("AdminView", "\346\213\222\347\273\235", nullptr));
        btPass->setText(QCoreApplication::translate("AdminView", "\351\200\232\350\277\207", nullptr));
        label_3->setText(QCoreApplication::translate("AdminView", "\347\224\250\346\210\267\347\261\273\345\236\213\357\274\232", nullptr));
        usertype->setItemText(0, QCoreApplication::translate("AdminView", "\345\205\250\351\203\250", nullptr));
        usertype->setItemText(1, QCoreApplication::translate("AdminView", "\345\255\246\347\224\237", nullptr));
        usertype->setItemText(2, QCoreApplication::translate("AdminView", "\345\217\221\350\265\267\344\272\272", nullptr));

        label_4->setText(QCoreApplication::translate("AdminView", "\347\224\250\346\210\267\347\212\266\346\200\201\357\274\232", nullptr));
        userstatus->setItemText(0, QCoreApplication::translate("AdminView", "\345\205\250\351\203\250", nullptr));
        userstatus->setItemText(1, QCoreApplication::translate("AdminView", "\346\255\243\345\270\270", nullptr));
        userstatus->setItemText(2, QCoreApplication::translate("AdminView", "\347\246\201\347\224\250", nullptr));

        usersearchEdit->setPlaceholderText(QCoreApplication::translate("AdminView", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\350\277\233\350\241\214\346\237\245\350\257\242", nullptr));
        searchButton->setText(QCoreApplication::translate("AdminView", "\346\220\234\347\264\242", nullptr));
        resetButton->setText(QCoreApplication::translate("AdminView", "\351\207\215\347\275\256", nullptr));
        btAdd->setText(QCoreApplication::translate("AdminView", "\346\226\260\345\242\236", nullptr));
        btUpdate->setText(QCoreApplication::translate("AdminView", "\344\277\256\346\224\271", nullptr));
        btDelete->setText(QCoreApplication::translate("AdminView", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminView: public Ui_AdminView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINVIEW_H
