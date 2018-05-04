/********************************************************************************
** Form generated from reading UI file 'cablehistorydatawidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CABLEHISTORYDATAWIDGET_H
#define UI_CABLEHISTORYDATAWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "historydataplot.h"

QT_BEGIN_NAMESPACE

class Ui_cableHistoryDataWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QDateTimeEdit *beginDateTimeEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QDateTimeEdit *endDateTimeEdit;
    QComboBox *queryDevicceIdComboBox;
    QComboBox *queryDataTypeComboBox;
    QPushButton *queryPushButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearCurvesPushButton;
    QPushButton *clearDBPushButton;
    historyDataPlot *widget;

    void setupUi(QWidget *cableHistoryDataWidget)
    {
        if (cableHistoryDataWidget->objectName().isEmpty())
            cableHistoryDataWidget->setObjectName(QString::fromUtf8("cableHistoryDataWidget"));
        cableHistoryDataWidget->resize(1011, 572);
        horizontalLayout = new QHBoxLayout(cableHistoryDataWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollArea = new QScrollArea(cableHistoryDataWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 255, 255);\n"
"background-color: rgb(176, 194, 200);"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(false);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 961, 507));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_8->addWidget(label_3);

        beginDateTimeEdit = new QDateTimeEdit(scrollAreaWidgetContents);
        beginDateTimeEdit->setObjectName(QString::fromUtf8("beginDateTimeEdit"));

        horizontalLayout_8->addWidget(beginDateTimeEdit);


        horizontalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_9->addWidget(label_4);

        endDateTimeEdit = new QDateTimeEdit(scrollAreaWidgetContents);
        endDateTimeEdit->setObjectName(QString::fromUtf8("endDateTimeEdit"));

        horizontalLayout_9->addWidget(endDateTimeEdit);


        horizontalLayout_2->addLayout(horizontalLayout_9);

        queryDevicceIdComboBox = new QComboBox(scrollAreaWidgetContents);
        queryDevicceIdComboBox->setObjectName(QString::fromUtf8("queryDevicceIdComboBox"));

        horizontalLayout_2->addWidget(queryDevicceIdComboBox);

        queryDataTypeComboBox = new QComboBox(scrollAreaWidgetContents);
        queryDataTypeComboBox->setObjectName(QString::fromUtf8("queryDataTypeComboBox"));

        horizontalLayout_2->addWidget(queryDataTypeComboBox);

        queryPushButton = new QPushButton(scrollAreaWidgetContents);
        queryPushButton->setObjectName(QString::fromUtf8("queryPushButton"));

        horizontalLayout_2->addWidget(queryPushButton);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_2->addItem(verticalSpacer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        clearCurvesPushButton = new QPushButton(scrollAreaWidgetContents);
        clearCurvesPushButton->setObjectName(QString::fromUtf8("clearCurvesPushButton"));

        horizontalLayout_2->addWidget(clearCurvesPushButton);

        clearDBPushButton = new QPushButton(scrollAreaWidgetContents);
        clearDBPushButton->setObjectName(QString::fromUtf8("clearDBPushButton"));

        horizontalLayout_2->addWidget(clearDBPushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        widget = new historyDataPlot(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 500));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(104, 163, 200);"));

        verticalLayout->addWidget(widget);


        horizontalLayout_3->addLayout(verticalLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(cableHistoryDataWidget);

        QMetaObject::connectSlotsByName(cableHistoryDataWidget);
    } // setupUi

    void retranslateUi(QWidget *cableHistoryDataWidget)
    {
        cableHistoryDataWidget->setWindowTitle(QApplication::translate("cableHistoryDataWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("cableHistoryDataWidget", "From", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("cableHistoryDataWidget", "To", 0, QApplication::UnicodeUTF8));
        queryDataTypeComboBox->clear();
        queryDataTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("cableHistoryDataWidget", "MainCable AVG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("cableHistoryDataWidget", "Ground Cable A AVG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("cableHistoryDataWidget", "Ground Cable B AVG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("cableHistoryDataWidget", "Ground Cable C AVG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("cableHistoryDataWidget", "Ground Cable N AVG", 0, QApplication::UnicodeUTF8)
        );
        queryPushButton->setText(QApplication::translate("cableHistoryDataWidget", "Query", 0, QApplication::UnicodeUTF8));
        clearCurvesPushButton->setText(QApplication::translate("cableHistoryDataWidget", "Clear", 0, QApplication::UnicodeUTF8));
        clearDBPushButton->setText(QApplication::translate("cableHistoryDataWidget", "Clear DB", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class cableHistoryDataWidget: public Ui_cableHistoryDataWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CABLEHISTORYDATAWIDGET_H
