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
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Versions
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_Versions)
    {
        if (Dialog_Versions->objectName().isEmpty())
            Dialog_Versions->setObjectName(QString::fromUtf8("Dialog_Versions"));
        Dialog_Versions->resize(453, 264);
        Dialog_Versions->setStyleSheet(QString::fromUtf8("image: url(:/ADD file/2018061310063525666.jpg);"));
        pushButton = new QPushButton(Dialog_Versions);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 230, 75, 23));

        retranslateUi(Dialog_Versions);

        QMetaObject::connectSlotsByName(Dialog_Versions);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Versions)
    {
        Dialog_Versions->setWindowTitle(QApplication::translate("Dialog_Versions", "HCCMonitor", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog_Versions", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Versions: public Ui_Dialog_Versions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_VERSIONS_H
