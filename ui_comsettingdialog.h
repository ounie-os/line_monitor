/********************************************************************************
** Form generated from reading UI file 'comsettingdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMSETTINGDIALOG_H
#define UI_COMSETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_comSettingDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comPortComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *buadRateComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *dataBitComboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *stopBitComboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_7;
    QComboBox *parityComboBox;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *comSettingSavePushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_comControl;

    void setupUi(QDialog *comSettingDialog)
    {
        if (comSettingDialog->objectName().isEmpty())
            comSettingDialog->setObjectName(QString::fromUtf8("comSettingDialog"));
        comSettingDialog->resize(225, 215);
        verticalLayout_3 = new QVBoxLayout(comSettingDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(comSettingDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        comPortComboBox = new QComboBox(comSettingDialog);
        comPortComboBox->setObjectName(QString::fromUtf8("comPortComboBox"));

        horizontalLayout->addWidget(comPortComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(comSettingDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        buadRateComboBox = new QComboBox(comSettingDialog);
        buadRateComboBox->setObjectName(QString::fromUtf8("buadRateComboBox"));

        horizontalLayout_2->addWidget(buadRateComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(comSettingDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        dataBitComboBox = new QComboBox(comSettingDialog);
        dataBitComboBox->setObjectName(QString::fromUtf8("dataBitComboBox"));

        horizontalLayout_3->addWidget(dataBitComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(comSettingDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        stopBitComboBox = new QComboBox(comSettingDialog);
        stopBitComboBox->setObjectName(QString::fromUtf8("stopBitComboBox"));

        horizontalLayout_4->addWidget(stopBitComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(comSettingDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        parityComboBox = new QComboBox(comSettingDialog);
        parityComboBox->setObjectName(QString::fromUtf8("parityComboBox"));

        horizontalLayout_7->addWidget(parityComboBox);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));

        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        verticalLayout->addLayout(horizontalLayout_9);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comSettingSavePushButton = new QPushButton(comSettingDialog);
        comSettingSavePushButton->setObjectName(QString::fromUtf8("comSettingSavePushButton"));

        horizontalLayout_5->addWidget(comSettingSavePushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_comControl = new QPushButton(comSettingDialog);
        pushButton_comControl->setObjectName(QString::fromUtf8("pushButton_comControl"));

        horizontalLayout_5->addWidget(pushButton_comControl);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(comSettingDialog);

        QMetaObject::connectSlotsByName(comSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *comSettingDialog)
    {
        comSettingDialog->setWindowTitle(QApplication::translate("comSettingDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("comSettingDialog", "\344\270\262\345\217\243\345\217\267", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("comSettingDialog", "\346\263\242\347\211\271\347\216\207", 0, QApplication::UnicodeUTF8));
        buadRateComboBox->clear();
        buadRateComboBox->insertItems(0, QStringList()
         << QApplication::translate("comSettingDialog", "300", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "57600", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("comSettingDialog", "\346\225\260\346\215\256\344\275\215", 0, QApplication::UnicodeUTF8));
        dataBitComboBox->clear();
        dataBitComboBox->insertItems(0, QStringList()
         << QApplication::translate("comSettingDialog", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "8", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("comSettingDialog", "\345\201\234\346\255\242\344\275\215", 0, QApplication::UnicodeUTF8));
        stopBitComboBox->clear();
        stopBitComboBox->insertItems(0, QStringList()
         << QApplication::translate("comSettingDialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "2", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("comSettingDialog", "\345\245\207\345\201\266\346\240\241\351\252\214", 0, QApplication::UnicodeUTF8));
        parityComboBox->clear();
        parityComboBox->insertItems(0, QStringList()
         << QApplication::translate("comSettingDialog", "\346\227\240", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "\345\245\207\346\240\241\351\252\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("comSettingDialog", "\345\201\266\346\240\241\351\252\214", 0, QApplication::UnicodeUTF8)
        );
        comSettingSavePushButton->setText(QApplication::translate("comSettingDialog", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        pushButton_comControl->setText(QApplication::translate("comSettingDialog", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class comSettingDialog: public Ui_comSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMSETTINGDIALOG_H
