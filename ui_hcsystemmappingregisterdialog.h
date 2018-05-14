/********************************************************************************
** Form generated from reading UI file 'hcsystemmappingregisterdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HCSYSTEMMAPPINGREGISTERDIALOG_H
#define UI_HCSYSTEMMAPPINGREGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_hcSystemMappingRegisterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_13;
    QComboBox *devicceIdComboBox;
    QComboBox *phaseComboBox;
    QLineEdit *hcIdLineEdit;
    QPushButton *systemMappingSetPushButton;
    QPushButton *systemMappingDeletePushButton;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *systemMappingShowTableWidget;

    void setupUi(QDialog *hcSystemMappingRegisterDialog)
    {
        if (hcSystemMappingRegisterDialog->objectName().isEmpty())
            hcSystemMappingRegisterDialog->setObjectName(QString::fromUtf8("hcSystemMappingRegisterDialog"));
        hcSystemMappingRegisterDialog->resize(650, 210);
        verticalLayout = new QVBoxLayout(hcSystemMappingRegisterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        devicceIdComboBox = new QComboBox(hcSystemMappingRegisterDialog);
        devicceIdComboBox->setObjectName(QString::fromUtf8("devicceIdComboBox"));

        horizontalLayout_13->addWidget(devicceIdComboBox);

        phaseComboBox = new QComboBox(hcSystemMappingRegisterDialog);
        phaseComboBox->setObjectName(QString::fromUtf8("phaseComboBox"));

        horizontalLayout_13->addWidget(phaseComboBox);

        hcIdLineEdit = new QLineEdit(hcSystemMappingRegisterDialog);
        hcIdLineEdit->setObjectName(QString::fromUtf8("hcIdLineEdit"));

        horizontalLayout_13->addWidget(hcIdLineEdit);

        systemMappingSetPushButton = new QPushButton(hcSystemMappingRegisterDialog);
        systemMappingSetPushButton->setObjectName(QString::fromUtf8("systemMappingSetPushButton"));

        horizontalLayout_13->addWidget(systemMappingSetPushButton);

        systemMappingDeletePushButton = new QPushButton(hcSystemMappingRegisterDialog);
        systemMappingDeletePushButton->setObjectName(QString::fromUtf8("systemMappingDeletePushButton"));

        horizontalLayout_13->addWidget(systemMappingDeletePushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_13);

        systemMappingShowTableWidget = new QTableWidget(hcSystemMappingRegisterDialog);
        systemMappingShowTableWidget->setObjectName(QString::fromUtf8("systemMappingShowTableWidget"));

        verticalLayout->addWidget(systemMappingShowTableWidget);


        retranslateUi(hcSystemMappingRegisterDialog);

        QMetaObject::connectSlotsByName(hcSystemMappingRegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *hcSystemMappingRegisterDialog)
    {
        hcSystemMappingRegisterDialog->setWindowTitle(QApplication::translate("hcSystemMappingRegisterDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        phaseComboBox->clear();
        phaseComboBox->insertItems(0, QStringList()
         << QApplication::translate("hcSystemMappingRegisterDialog", "\344\270\273\347\274\206\347\224\265\346\265\201\345\256\236\346\227\266\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "\344\270\273\347\274\206\347\224\265\346\265\201\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "A\347\233\270\347\224\265\346\265\201\345\256\236\346\227\266\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "A\347\233\270\347\224\265\346\265\201\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "A\347\233\270\346\270\251\345\272\246\345\256\236\346\227\266\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "A\347\233\270\346\270\251\345\272\246\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "B\347\233\270\347\224\265\346\265\201\345\256\236\346\227\266\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "B\347\233\270\347\224\265\346\265\201\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "B\347\233\270\346\270\251\345\272\246\345\256\236\346\227\266\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "B\347\233\270\346\270\251\345\272\246\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "C\347\233\270\347\224\265\346\265\201\345\256\236\346\227\266\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "C\347\233\270\347\224\265\346\265\201\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "C\347\233\270\346\270\251\345\272\246\345\256\236\346\227\266\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "C\347\233\270\346\270\251\345\272\246\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "N\347\233\270\347\224\265\346\265\201\345\256\236\346\227\266\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "N\347\233\270\347\224\265\346\265\201\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "N\347\233\270\346\270\251\345\272\246\345\256\236\346\227\266\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("hcSystemMappingRegisterDialog", "N\347\233\270\346\270\251\345\272\246\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8)
        );
        systemMappingSetPushButton->setText(QApplication::translate("hcSystemMappingRegisterDialog", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        systemMappingDeletePushButton->setText(QApplication::translate("hcSystemMappingRegisterDialog", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class hcSystemMappingRegisterDialog: public Ui_hcSystemMappingRegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HCSYSTEMMAPPINGREGISTERDIALOG_H
