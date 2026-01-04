/********************************************************************************
** Form generated from reading UI file 'usereditview.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USEREDITVIEW_H
#define UI_USEREDITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserEditView
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *useridEdit;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QComboBox *userRole;
    QLineEdit *createtimeEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *UserEditView)
    {
        if (UserEditView->objectName().isEmpty())
            UserEditView->setObjectName("UserEditView");
        UserEditView->resize(1050, 400);
        gridLayout = new QGridLayout(UserEditView);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(20, 68, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(335, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(UserEditView);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(UserEditView);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_2);

        label_5 = new QLabel(UserEditView);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_5);

        label_3 = new QLabel(UserEditView);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(UserEditView);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        useridEdit = new QLineEdit(UserEditView);
        useridEdit->setObjectName("useridEdit");

        verticalLayout_2->addWidget(useridEdit);

        usernameEdit = new QLineEdit(UserEditView);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout_2->addWidget(usernameEdit);

        passwordEdit = new QLineEdit(UserEditView);
        passwordEdit->setObjectName("passwordEdit");

        verticalLayout_2->addWidget(passwordEdit);

        userRole = new QComboBox(UserEditView);
        userRole->addItem(QString());
        userRole->addItem(QString());
        userRole->setObjectName("userRole");

        verticalLayout_2->addWidget(userRole);

        createtimeEdit = new QLineEdit(UserEditView);
        createtimeEdit->setObjectName("createtimeEdit");

        verticalLayout_2->addWidget(createtimeEdit);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        submitButton = new QPushButton(UserEditView);
        submitButton->setObjectName("submitButton");

        horizontalLayout->addWidget(submitButton);

        cancelButton = new QPushButton(UserEditView);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_3, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(335, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 67, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);


        retranslateUi(UserEditView);

        QMetaObject::connectSlotsByName(UserEditView);
    } // setupUi

    void retranslateUi(QWidget *UserEditView)
    {
        UserEditView->setWindowTitle(QCoreApplication::translate("UserEditView", "\347\274\226\350\276\221\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("UserEditView", "\347\224\250\346\210\267\345\272\217\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("UserEditView", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("UserEditView", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("UserEditView", "\347\224\250\346\210\267\350\247\222\350\211\262\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("UserEditView", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        userRole->setItemText(0, QCoreApplication::translate("UserEditView", "\345\217\221\350\265\267\344\272\272", nullptr));
        userRole->setItemText(1, QCoreApplication::translate("UserEditView", "\345\255\246\347\224\237", nullptr));

        submitButton->setText(QCoreApplication::translate("UserEditView", "\346\217\220\344\272\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("UserEditView", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserEditView: public Ui_UserEditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USEREDITVIEW_H
