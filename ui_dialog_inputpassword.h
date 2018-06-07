/********************************************************************************
** Form generated from reading UI file 'dialog_inputpassword.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_INPUTPASSWORD_H
#define UI_DIALOG_INPUTPASSWORD_H

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

QT_BEGIN_NAMESPACE

class Ui_Dialog_InputPassWord
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_inputPassWord;
    QPushButton *pushButton_inputPassWord;

    void setupUi(QDialog *Dialog_InputPassWord)
    {
        if (Dialog_InputPassWord->objectName().isEmpty())
            Dialog_InputPassWord->setObjectName(QString::fromUtf8("Dialog_InputPassWord"));
        Dialog_InputPassWord->resize(303, 50);
        horizontalLayout_2 = new QHBoxLayout(Dialog_InputPassWord);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Dialog_InputPassWord);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_inputPassWord = new QLineEdit(Dialog_InputPassWord);
        lineEdit_inputPassWord->setObjectName(QString::fromUtf8("lineEdit_inputPassWord"));

        horizontalLayout->addWidget(lineEdit_inputPassWord);

        pushButton_inputPassWord = new QPushButton(Dialog_InputPassWord);
        pushButton_inputPassWord->setObjectName(QString::fromUtf8("pushButton_inputPassWord"));

        horizontalLayout->addWidget(pushButton_inputPassWord);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Dialog_InputPassWord);

        QMetaObject::connectSlotsByName(Dialog_InputPassWord);
    } // setupUi

    void retranslateUi(QDialog *Dialog_InputPassWord)
    {
        Dialog_InputPassWord->setWindowTitle(QApplication::translate("Dialog_InputPassWord", "\345\257\206\347\240\201\346\241\206", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog_InputPassWord", "\350\276\223\345\205\245\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_inputPassWord->setText(QApplication::translate("Dialog_InputPassWord", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_InputPassWord: public Ui_Dialog_InputPassWord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_INPUTPASSWORD_H
