/********************************************************************************
** Form generated from reading UI file 'activityeditview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVITYEDITVIEW_H
#define UI_ACTIVITYEDITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActivityEditView
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_11;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *actidEdit;
    QLineEdit *actnameEdit;
    QComboBox *acttype;
    QComboBox *actstatus;
    QDateTimeEdit *acttimeEdit;
    QHBoxLayout *horizontalLayout_2;
    QDateTimeEdit *starttimeEdit;
    QLabel *label_9;
    QDateTimeEdit *endtimeEdit;
    QLineEdit *actaddressEdit;
    QLineEdit *maxcountEdit;
    QLineEdit *createtimeEdit;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *ActivityEditView)
    {
        if (ActivityEditView->objectName().isEmpty())
            ActivityEditView->setObjectName("ActivityEditView");
        ActivityEditView->resize(1050, 414);
        gridLayout = new QGridLayout(ActivityEditView);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 54, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(276, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_7 = new QLabel(ActivityEditView);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_7);

        label = new QLabel(ActivityEditView);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(ActivityEditView);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_2);

        label_11 = new QLabel(ActivityEditView);
        label_11->setObjectName("label_11");
        label_11->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_11);

        label_3 = new QLabel(ActivityEditView);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(ActivityEditView);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_4);

        label_6 = new QLabel(ActivityEditView);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_6);

        label_5 = new QLabel(ActivityEditView);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_5);

        label_8 = new QLabel(ActivityEditView);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_8);

        label_10 = new QLabel(ActivityEditView);
        label_10->setObjectName("label_10");
        label_10->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_10);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        actidEdit = new QLineEdit(ActivityEditView);
        actidEdit->setObjectName("actidEdit");

        verticalLayout_2->addWidget(actidEdit);

        actnameEdit = new QLineEdit(ActivityEditView);
        actnameEdit->setObjectName("actnameEdit");

        verticalLayout_2->addWidget(actnameEdit);

        acttype = new QComboBox(ActivityEditView);
        acttype->addItem(QString());
        acttype->addItem(QString());
        acttype->addItem(QString());
        acttype->addItem(QString());
        acttype->addItem(QString());
        acttype->setObjectName("acttype");

        verticalLayout_2->addWidget(acttype);

        actstatus = new QComboBox(ActivityEditView);
        actstatus->addItem(QString());
        actstatus->addItem(QString());
        actstatus->addItem(QString());
        actstatus->addItem(QString());
        actstatus->setObjectName("actstatus");

        verticalLayout_2->addWidget(actstatus);

        acttimeEdit = new QDateTimeEdit(ActivityEditView);
        acttimeEdit->setObjectName("acttimeEdit");

        verticalLayout_2->addWidget(acttimeEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        starttimeEdit = new QDateTimeEdit(ActivityEditView);
        starttimeEdit->setObjectName("starttimeEdit");

        horizontalLayout_2->addWidget(starttimeEdit);

        label_9 = new QLabel(ActivityEditView);
        label_9->setObjectName("label_9");

        horizontalLayout_2->addWidget(label_9);

        endtimeEdit = new QDateTimeEdit(ActivityEditView);
        endtimeEdit->setObjectName("endtimeEdit");

        horizontalLayout_2->addWidget(endtimeEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        actaddressEdit = new QLineEdit(ActivityEditView);
        actaddressEdit->setObjectName("actaddressEdit");

        verticalLayout_2->addWidget(actaddressEdit);

        maxcountEdit = new QLineEdit(ActivityEditView);
        maxcountEdit->setObjectName("maxcountEdit");

        verticalLayout_2->addWidget(maxcountEdit);

        createtimeEdit = new QLineEdit(ActivityEditView);
        createtimeEdit->setObjectName("createtimeEdit");

        verticalLayout_2->addWidget(createtimeEdit);

        lineEdit = new QLineEdit(ActivityEditView);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        submitButton = new QPushButton(ActivityEditView);
        submitButton->setObjectName("submitButton");

        horizontalLayout->addWidget(submitButton);

        cancelButton = new QPushButton(ActivityEditView);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_3, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(275, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 54, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);


        retranslateUi(ActivityEditView);

        QMetaObject::connectSlotsByName(ActivityEditView);
    } // setupUi

    void retranslateUi(QWidget *ActivityEditView)
    {
        ActivityEditView->setWindowTitle(QCoreApplication::translate("ActivityEditView", "\347\274\226\350\276\221\346\264\273\345\212\250\344\277\241\346\201\257", nullptr));
        label_7->setText(QCoreApplication::translate("ActivityEditView", "\346\264\273\345\212\250\345\272\217\345\217\267\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("ActivityEditView", "\346\264\273\345\212\250\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("ActivityEditView", "\346\264\273\345\212\250\347\261\273\345\236\213\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("ActivityEditView", "\346\264\273\345\212\250\347\212\266\346\200\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("ActivityEditView", "\346\264\273\345\212\250\346\227\266\351\227\264\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("ActivityEditView", "\346\212\245\345\220\215\346\227\266\351\227\264\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("ActivityEditView", "\346\264\273\345\212\250\345\234\260\347\202\271\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("ActivityEditView", "\346\234\200\345\244\247\346\212\245\345\220\215\345\220\215\351\242\235\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("ActivityEditView", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("ActivityEditView", "\345\217\221\350\265\267\344\272\272\357\274\232", nullptr));
        actnameEdit->setPlaceholderText(QCoreApplication::translate("ActivityEditView", "\350\257\267\350\276\223\345\205\245\346\264\273\345\212\250\345\220\215\347\247\260", nullptr));
        acttype->setItemText(0, QCoreApplication::translate("ActivityEditView", "\345\276\267\350\202\262\346\225\231\350\202\262", nullptr));
        acttype->setItemText(1, QCoreApplication::translate("ActivityEditView", "\345\210\233\346\226\260\345\210\233\344\270\232", nullptr));
        acttype->setItemText(2, QCoreApplication::translate("ActivityEditView", "\347\211\271\350\211\262\344\275\223\350\202\262", nullptr));
        acttype->setItemText(3, QCoreApplication::translate("ActivityEditView", "\351\253\230\351\233\205\347\276\216\350\202\262", nullptr));
        acttype->setItemText(4, QCoreApplication::translate("ActivityEditView", "\345\212\263\345\212\250\346\225\231\350\202\262", nullptr));

        actstatus->setItemText(0, QCoreApplication::translate("ActivityEditView", "\345\276\205\345\256\241\346\240\270", nullptr));
        actstatus->setItemText(1, QCoreApplication::translate("ActivityEditView", "\345\267\262\351\200\232\350\277\207", nullptr));
        actstatus->setItemText(2, QCoreApplication::translate("ActivityEditView", "\346\234\252\351\200\232\350\277\207", nullptr));
        actstatus->setItemText(3, QCoreApplication::translate("ActivityEditView", "\345\267\262\346\222\244\345\233\236", nullptr));

        label_9->setText(QCoreApplication::translate("ActivityEditView", "\350\207\263", nullptr));
        submitButton->setText(QCoreApplication::translate("ActivityEditView", "\346\217\220\344\272\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("ActivityEditView", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActivityEditView: public Ui_ActivityEditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVITYEDITVIEW_H
