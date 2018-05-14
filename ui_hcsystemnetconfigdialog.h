/********************************************************************************
** Form generated from reading UI file 'hcsystemnetconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HCSYSTEMNETCONFIGDIALOG_H
#define UI_HCSYSTEMNETCONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_hcSystemNetConfigDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *ipAdressLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *portLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *hcSystemNetConfigDialog)
    {
        if (hcSystemNetConfigDialog->objectName().isEmpty())
            hcSystemNetConfigDialog->setObjectName(QString::fromUtf8("hcSystemNetConfigDialog"));
        hcSystemNetConfigDialog->resize(268, 99);
        horizontalLayout_4 = new QHBoxLayout(hcSystemNetConfigDialog);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(hcSystemNetConfigDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        ipAdressLineEdit = new QLineEdit(hcSystemNetConfigDialog);
        ipAdressLineEdit->setObjectName(QString::fromUtf8("ipAdressLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ipAdressLineEdit->sizePolicy().hasHeightForWidth());
        ipAdressLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(ipAdressLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(hcSystemNetConfigDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        portLineEdit = new QLineEdit(hcSystemNetConfigDialog);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        sizePolicy.setHeightForWidth(portLineEdit->sizePolicy().hasHeightForWidth());
        portLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(portLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        okPushButton = new QPushButton(hcSystemNetConfigDialog);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));

        horizontalLayout_3->addWidget(okPushButton);

        cancelPushButton = new QPushButton(hcSystemNetConfigDialog);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        horizontalLayout_3->addWidget(cancelPushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(hcSystemNetConfigDialog);

        QMetaObject::connectSlotsByName(hcSystemNetConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *hcSystemNetConfigDialog)
    {
        hcSystemNetConfigDialog->setWindowTitle(QApplication::translate("hcSystemNetConfigDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("hcSystemNetConfigDialog", "IP Address:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("hcSystemNetConfigDialog", "Port:", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("hcSystemNetConfigDialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelPushButton->setText(QApplication::translate("hcSystemNetConfigDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class hcSystemNetConfigDialog: public Ui_hcSystemNetConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HCSYSTEMNETCONFIGDIALOG_H
