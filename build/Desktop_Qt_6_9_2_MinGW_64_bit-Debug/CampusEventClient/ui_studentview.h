/********************************************************************************
** Form generated from reading UI file 'studentview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTVIEW_H
#define UI_STUDENTVIEW_H

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

class Ui_StudentView
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *myactpage;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *myacttype;
    QLabel *label_6;
    QComboBox *signstatus;
    QSpacerItem *horizontalSpacer;
    QLineEdit *inputSearch;
    QPushButton *searchButton;
    QPushButton *resetButton;
    QTableView *myacttableView;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btCancelSign;
    QPushButton *btCancelWait;
    QWidget *actscanpage;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *acttype;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *searchEdit;
    QPushButton *btSearch;
    QPushButton *btReset;
    QTableView *acttableView;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btSign;

    void setupUi(QWidget *StudentView)
    {
        if (StudentView->objectName().isEmpty())
            StudentView->setObjectName("StudentView");
        StudentView->resize(1050, 400);
        gridLayout = new QGridLayout(StudentView);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        listWidget = new QListWidget(StudentView);
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

        stackedWidget = new QStackedWidget(StudentView);
        stackedWidget->setObjectName("stackedWidget");
        myactpage = new QWidget();
        myactpage->setObjectName("myactpage");
        verticalLayout = new QVBoxLayout(myactpage);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_5 = new QLabel(myactpage);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_5);

        myacttype = new QComboBox(myactpage);
        myacttype->setObjectName("myacttype");
        myacttype->setMinimumSize(QSize(90, 0));

        horizontalLayout_2->addWidget(myacttype);

        label_6 = new QLabel(myactpage);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_6);

        signstatus = new QComboBox(myactpage);
        signstatus->addItem(QString());
        signstatus->addItem(QString());
        signstatus->addItem(QString());
        signstatus->setObjectName("signstatus");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(signstatus->sizePolicy().hasHeightForWidth());
        signstatus->setSizePolicy(sizePolicy1);
        signstatus->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(signstatus);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        inputSearch = new QLineEdit(myactpage);
        inputSearch->setObjectName("inputSearch");

        horizontalLayout_2->addWidget(inputSearch);

        searchButton = new QPushButton(myactpage);
        searchButton->setObjectName("searchButton");

        horizontalLayout_2->addWidget(searchButton);

        resetButton = new QPushButton(myactpage);
        resetButton->setObjectName("resetButton");

        horizontalLayout_2->addWidget(resetButton);


        verticalLayout->addLayout(horizontalLayout_2);

        myacttableView = new QTableView(myactpage);
        myacttableView->setObjectName("myacttableView");

        verticalLayout->addWidget(myacttableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(500, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btCancelSign = new QPushButton(myactpage);
        btCancelSign->setObjectName("btCancelSign");

        horizontalLayout_3->addWidget(btCancelSign);

        btCancelWait = new QPushButton(myactpage);
        btCancelWait->setObjectName("btCancelWait");

        horizontalLayout_3->addWidget(btCancelWait);


        verticalLayout->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(myactpage);
        actscanpage = new QWidget();
        actscanpage->setObjectName("actscanpage");
        verticalLayout_2 = new QVBoxLayout(actscanpage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label = new QLabel(actscanpage);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_4->addWidget(label);

        acttype = new QComboBox(actscanpage);
        acttype->setObjectName("acttype");
        sizePolicy1.setHeightForWidth(acttype->sizePolicy().hasHeightForWidth());
        acttype->setSizePolicy(sizePolicy1);
        acttype->setMinimumSize(QSize(90, 0));
        acttype->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(acttype);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        searchEdit = new QLineEdit(actscanpage);
        searchEdit->setObjectName("searchEdit");

        horizontalLayout_4->addWidget(searchEdit);

        btSearch = new QPushButton(actscanpage);
        btSearch->setObjectName("btSearch");

        horizontalLayout_4->addWidget(btSearch);

        btReset = new QPushButton(actscanpage);
        btReset->setObjectName("btReset");

        horizontalLayout_4->addWidget(btReset);


        verticalLayout_2->addLayout(horizontalLayout_4);

        acttableView = new QTableView(actscanpage);
        acttableView->setObjectName("acttableView");

        verticalLayout_2->addWidget(acttableView);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(500, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        btSign = new QPushButton(actscanpage);
        btSign->setObjectName("btSign");

        horizontalLayout_5->addWidget(btSign);


        verticalLayout_2->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(actscanpage);

        horizontalLayout->addWidget(stackedWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(StudentView);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StudentView);
    } // setupUi

    void retranslateUi(QWidget *StudentView)
    {
        StudentView->setWindowTitle(QCoreApplication::translate("StudentView", "\345\255\246\347\224\237", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("StudentView", "\346\264\273\345\212\250\346\265\217\350\247\210", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("StudentView", "\346\210\221\347\232\204\346\264\273\345\212\250", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_5->setText(QCoreApplication::translate("StudentView", "\346\264\273\345\212\250\347\261\273\345\210\253\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("StudentView", "\346\212\245\345\220\215\347\212\266\346\200\201\357\274\232", nullptr));
        signstatus->setItemText(0, QCoreApplication::translate("StudentView", "\345\205\250\351\203\250", nullptr));
        signstatus->setItemText(1, QCoreApplication::translate("StudentView", "\345\267\262\346\212\245\345\220\215", nullptr));
        signstatus->setItemText(2, QCoreApplication::translate("StudentView", "\345\200\231\350\241\245\344\270\255", nullptr));

        inputSearch->setPlaceholderText(QCoreApplication::translate("StudentView", "\350\257\267\350\276\223\345\205\245\346\264\273\345\212\250\345\220\215\347\247\260\350\277\233\350\241\214\346\237\245\350\257\242", nullptr));
        searchButton->setText(QCoreApplication::translate("StudentView", "\346\220\234\347\264\242", nullptr));
        resetButton->setText(QCoreApplication::translate("StudentView", "\351\207\215\347\275\256", nullptr));
        btCancelSign->setText(QCoreApplication::translate("StudentView", "\345\217\226\346\266\210\346\212\245\345\220\215", nullptr));
        btCancelWait->setText(QCoreApplication::translate("StudentView", "\345\217\226\346\266\210\345\200\231\350\241\245", nullptr));
        label->setText(QCoreApplication::translate("StudentView", "\346\264\273\345\212\250\347\261\273\345\210\253\357\274\232", nullptr));
        acttype->setCurrentText(QString());
        searchEdit->setPlaceholderText(QCoreApplication::translate("StudentView", "\350\257\267\350\276\223\345\205\245\346\264\273\345\212\250\345\220\215\347\247\260\350\277\233\350\241\214\346\237\245\350\257\242", nullptr));
        btSearch->setText(QCoreApplication::translate("StudentView", "\346\220\234\347\264\242", nullptr));
        btReset->setText(QCoreApplication::translate("StudentView", "\351\207\215\347\275\256", nullptr));
        btSign->setText(QCoreApplication::translate("StudentView", "\346\212\245\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentView: public Ui_StudentView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTVIEW_H
