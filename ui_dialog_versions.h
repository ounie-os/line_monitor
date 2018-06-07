/********************************************************************************
** Form generated from reading UI file 'dialog_versions.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_VERSIONS_H
#define UI_DIALOG_VERSIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Versions
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *label_Verision;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLabel *label_data_change;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_Versions)
    {
        if (Dialog_Versions->objectName().isEmpty())
            Dialog_Versions->setObjectName(QString::fromUtf8("Dialog_Versions"));
        Dialog_Versions->resize(292, 141);
        horizontalLayout_4 = new QHBoxLayout(Dialog_Versions);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(Dialog_Versions);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        label_Verision = new QLabel(Dialog_Versions);
        label_Verision->setObjectName(QString::fromUtf8("label_Verision"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_Verision->setFont(font);

        horizontalLayout->addWidget(label_Verision);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(Dialog_Versions);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        label_data_change = new QLabel(Dialog_Versions);
        label_data_change->setObjectName(QString::fromUtf8("label_data_change"));

        horizontalLayout_2->addWidget(label_data_change);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton = new QPushButton(Dialog_Versions);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(Dialog_Versions);

        QMetaObject::connectSlotsByName(Dialog_Versions);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Versions)
    {
        Dialog_Versions->setWindowTitle(QApplication::translate("Dialog_Versions", "\345\205\263\344\272\216HCCMonitor", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog_Versions", "HCCMonitor Verision", 0, QApplication::UnicodeUTF8));
        label_Verision->setText(QApplication::translate("Dialog_Versions", "0.1.2", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog_Versions", "\344\277\256\346\224\271\346\227\245\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_data_change->setText(QApplication::translate("Dialog_Versions", "2017-11-3", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog_Versions", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Versions: public Ui_Dialog_Versions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_VERSIONS_H
