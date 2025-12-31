/********************************************************************************
** Form generated from reading UI file 'masterview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASTERVIEW_H
#define UI_MASTERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MasterView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btBack;
    QSpacerItem *horizontalSpacer;
    QLabel *titlelabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btLogout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *MasterView)
    {
        if (MasterView->objectName().isEmpty())
            MasterView->setObjectName("MasterView");
        MasterView->resize(1050, 400);
        verticalLayout = new QVBoxLayout(MasterView);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btBack = new QPushButton(MasterView);
        btBack->setObjectName("btBack");

        horizontalLayout->addWidget(btBack);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        titlelabel = new QLabel(MasterView);
        titlelabel->setObjectName("titlelabel");

        horizontalLayout->addWidget(titlelabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btLogout = new QPushButton(MasterView);
        btLogout->setObjectName("btLogout");

        horizontalLayout->addWidget(btLogout);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(MasterView);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(MasterView);

        QMetaObject::connectSlotsByName(MasterView);
    } // setupUi

    void retranslateUi(QWidget *MasterView)
    {
        MasterView->setWindowTitle(QCoreApplication::translate("MasterView", "MasterView", nullptr));
        btBack->setText(QCoreApplication::translate("MasterView", "\350\277\224\345\233\236", nullptr));
        titlelabel->setText(QString());
        btLogout->setText(QCoreApplication::translate("MasterView", "\346\263\250\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MasterView: public Ui_MasterView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASTERVIEW_H
