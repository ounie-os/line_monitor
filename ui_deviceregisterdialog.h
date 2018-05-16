/********************************************************************************
** Form generated from reading UI file 'deviceregisterdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEREGISTERDIALOG_H
#define UI_DEVICEREGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_deviceRegisterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *deviceIdLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *deviceNameLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *userSelectComboBox;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *createPushButton;
    QPushButton *removePushButton;
    QTableWidget *deviceTableShowTableWidget;

    void setupUi(QDialog *deviceRegisterDialog)
    {
        if (deviceRegisterDialog->objectName().isEmpty())
            deviceRegisterDialog->setObjectName(QString::fromUtf8("deviceRegisterDialog"));
        deviceRegisterDialog->resize(625, 388);
        verticalLayout = new QVBoxLayout(deviceRegisterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(deviceRegisterDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deviceIdLineEdit = new QLineEdit(deviceRegisterDialog);
        deviceIdLineEdit->setObjectName(QString::fromUtf8("deviceIdLineEdit"));

        horizontalLayout->addWidget(deviceIdLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(deviceRegisterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        deviceNameLineEdit = new QLineEdit(deviceRegisterDialog);
        deviceNameLineEdit->setObjectName(QString::fromUtf8("deviceNameLineEdit"));

        horizontalLayout_2->addWidget(deviceNameLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(deviceRegisterDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_3);

        userSelectComboBox = new QComboBox(deviceRegisterDialog);
        userSelectComboBox->setObjectName(QString::fromUtf8("userSelectComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(userSelectComboBox->sizePolicy().hasHeightForWidth());
        userSelectComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(userSelectComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        createPushButton = new QPushButton(deviceRegisterDialog);
        createPushButton->setObjectName(QString::fromUtf8("createPushButton"));

        horizontalLayout_4->addWidget(createPushButton);

        removePushButton = new QPushButton(deviceRegisterDialog);
        removePushButton->setObjectName(QString::fromUtf8("removePushButton"));

        horizontalLayout_4->addWidget(removePushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        deviceTableShowTableWidget = new QTableWidget(deviceRegisterDialog);
        deviceTableShowTableWidget->setObjectName(QString::fromUtf8("deviceTableShowTableWidget"));

        verticalLayout->addWidget(deviceTableShowTableWidget);


        retranslateUi(deviceRegisterDialog);

        QMetaObject::connectSlotsByName(deviceRegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *deviceRegisterDialog)
    {
        deviceRegisterDialog->setWindowTitle(QApplication::translate("deviceRegisterDialog", "\345\210\233\345\273\272\350\256\276\345\244\207", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("deviceRegisterDialog", "\350\256\276\345\244\207 ID:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("deviceRegisterDialog", "\350\256\276\345\244\207\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("deviceRegisterDialog", "\350\256\276\345\244\207\347\224\250\346\210\267:", 0, QApplication::UnicodeUTF8));
        createPushButton->setText(QApplication::translate("deviceRegisterDialog", "\345\210\233\345\273\272", 0, QApplication::UnicodeUTF8));
        removePushButton->setText(QApplication::translate("deviceRegisterDialog", "\347\247\273\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class deviceRegisterDialog: public Ui_deviceRegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEREGISTERDIALOG_H
