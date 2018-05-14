/********************************************************************************
** Form generated from reading UI file 'dialog_set_interval_time.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SET_INTERVAL_TIME_H
#define UI_DIALOG_SET_INTERVAL_TIME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_set_interval_time
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_RT;
    QSpinBox *spinBox_RT;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_ST;
    QSpinBox *spinBox_ST;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_AL;
    QSpinBox *spinBox_AL;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_enter;

    void setupUi(QDialog *Dialog_set_interval_time)
    {
        if (Dialog_set_interval_time->objectName().isEmpty())
            Dialog_set_interval_time->setObjectName(QString::fromUtf8("Dialog_set_interval_time"));
        Dialog_set_interval_time->resize(207, 140);
        horizontalLayout_2 = new QHBoxLayout(Dialog_set_interval_time);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkBox_RT = new QCheckBox(Dialog_set_interval_time);
        checkBox_RT->setObjectName(QString::fromUtf8("checkBox_RT"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(5);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox_RT->sizePolicy().hasHeightForWidth());
        checkBox_RT->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(checkBox_RT);

        spinBox_RT = new QSpinBox(Dialog_set_interval_time);
        spinBox_RT->setObjectName(QString::fromUtf8("spinBox_RT"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox_RT->sizePolicy().hasHeightForWidth());
        spinBox_RT->setSizePolicy(sizePolicy1);
        spinBox_RT->setMinimum(1);
        spinBox_RT->setMaximum(99999);
        spinBox_RT->setValue(3);

        horizontalLayout_4->addWidget(spinBox_RT);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        checkBox_ST = new QCheckBox(Dialog_set_interval_time);
        checkBox_ST->setObjectName(QString::fromUtf8("checkBox_ST"));

        horizontalLayout_5->addWidget(checkBox_ST);

        spinBox_ST = new QSpinBox(Dialog_set_interval_time);
        spinBox_ST->setObjectName(QString::fromUtf8("spinBox_ST"));
        spinBox_ST->setMinimum(60);
        spinBox_ST->setMaximum(99999);

        horizontalLayout_5->addWidget(spinBox_ST);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        checkBox_AL = new QCheckBox(Dialog_set_interval_time);
        checkBox_AL->setObjectName(QString::fromUtf8("checkBox_AL"));

        horizontalLayout_6->addWidget(checkBox_AL);

        spinBox_AL = new QSpinBox(Dialog_set_interval_time);
        spinBox_AL->setObjectName(QString::fromUtf8("spinBox_AL"));
        spinBox_AL->setMinimum(1);
        spinBox_AL->setMaximum(99999);
        spinBox_AL->setValue(3);

        horizontalLayout_6->addWidget(spinBox_AL);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_cancel = new QPushButton(Dialog_set_interval_time);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);

        pushButton_enter = new QPushButton(Dialog_set_interval_time);
        pushButton_enter->setObjectName(QString::fromUtf8("pushButton_enter"));

        horizontalLayout->addWidget(pushButton_enter);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(Dialog_set_interval_time);

        QMetaObject::connectSlotsByName(Dialog_set_interval_time);
    } // setupUi

    void retranslateUi(QDialog *Dialog_set_interval_time)
    {
        Dialog_set_interval_time->setWindowTitle(QApplication::translate("Dialog_set_interval_time", "\350\256\276\347\275\256\350\207\252\345\212\250\350\216\267\345\217\226\346\227\266\351\227\264\351\227\264\351\232\224", 0, QApplication::UnicodeUTF8));
        checkBox_RT->setText(QApplication::translate("Dialog_set_interval_time", "\350\207\252\345\212\250\350\216\267\345\217\226\345\256\236\346\227\266\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        checkBox_ST->setText(QApplication::translate("Dialog_set_interval_time", "\350\207\252\345\212\250\350\216\267\345\217\226\347\273\237\350\256\241\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        checkBox_AL->setText(QApplication::translate("Dialog_set_interval_time", "\350\207\252\345\212\250\350\216\267\345\217\226\346\212\245\350\255\246\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("Dialog_set_interval_time", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton_enter->setText(QApplication::translate("Dialog_set_interval_time", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_set_interval_time: public Ui_Dialog_set_interval_time {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SET_INTERVAL_TIME_H
