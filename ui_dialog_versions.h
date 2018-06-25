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
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Versions
{
public:

    void setupUi(QDialog *Dialog_Versions)
    {
        if (Dialog_Versions->objectName().isEmpty())
            Dialog_Versions->setObjectName(QString::fromUtf8("Dialog_Versions"));
        Dialog_Versions->resize(541, 311);
        Dialog_Versions->setStyleSheet(QString::fromUtf8("image: url(:/ad/20180625161448.png);"));

        retranslateUi(Dialog_Versions);

        QMetaObject::connectSlotsByName(Dialog_Versions);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Versions)
    {
        Dialog_Versions->setWindowTitle(QApplication::translate("Dialog_Versions", "HCCMonitor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Versions: public Ui_Dialog_Versions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_VERSIONS_H
