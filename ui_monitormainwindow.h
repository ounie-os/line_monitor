/********************************************************************************
** Form generated from reading UI file 'monitormainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORMAINWINDOW_H
#define UI_MONITORMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "historydataplot.h"

QT_BEGIN_NAMESPACE

class Ui_MonitorMainWindow
{
public:
    QAction *action_data;
    QAction *action_history;
    QAction *action_register_device;
    QAction *action_connect_485;
    QAction *action_connect_network;
    QAction *action_show_info;
    QAction *action_set_map;
    QAction *action_connet_server;
    QAction *action_clearLog;
    QAction *action_cnt_com_failed;
    QAction *action_clearCnt;
    QAction *action_CableMonitor;
    QAction *action_auto_get_data;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_6;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *treeWidget_deviceList;
    QStackedWidget *stackedWidget_device;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_3;
    QWidget *page_3;
    QWidget *page1;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_histtory;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
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
    historyDataPlot *widget_historyPlot;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_4;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MonitorMainWindow)
    {
        if (MonitorMainWindow->objectName().isEmpty())
            MonitorMainWindow->setObjectName(QString::fromUtf8("MonitorMainWindow"));
        MonitorMainWindow->resize(1200, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MonitorMainWindow->sizePolicy().hasHeightForWidth());
        MonitorMainWindow->setSizePolicy(sizePolicy);
        MonitorMainWindow->setMinimumSize(QSize(1000, 600));
        MonitorMainWindow->setFocusPolicy(Qt::NoFocus);
        action_data = new QAction(MonitorMainWindow);
        action_data->setObjectName(QString::fromUtf8("action_data"));
        action_history = new QAction(MonitorMainWindow);
        action_history->setObjectName(QString::fromUtf8("action_history"));
        action_register_device = new QAction(MonitorMainWindow);
        action_register_device->setObjectName(QString::fromUtf8("action_register_device"));
        action_connect_485 = new QAction(MonitorMainWindow);
        action_connect_485->setObjectName(QString::fromUtf8("action_connect_485"));
        action_connect_network = new QAction(MonitorMainWindow);
        action_connect_network->setObjectName(QString::fromUtf8("action_connect_network"));
        action_show_info = new QAction(MonitorMainWindow);
        action_show_info->setObjectName(QString::fromUtf8("action_show_info"));
        action_show_info->setCheckable(true);
        action_set_map = new QAction(MonitorMainWindow);
        action_set_map->setObjectName(QString::fromUtf8("action_set_map"));
        action_connet_server = new QAction(MonitorMainWindow);
        action_connet_server->setObjectName(QString::fromUtf8("action_connet_server"));
        action_clearLog = new QAction(MonitorMainWindow);
        action_clearLog->setObjectName(QString::fromUtf8("action_clearLog"));
        action_cnt_com_failed = new QAction(MonitorMainWindow);
        action_cnt_com_failed->setObjectName(QString::fromUtf8("action_cnt_com_failed"));
        action_clearCnt = new QAction(MonitorMainWindow);
        action_clearCnt->setObjectName(QString::fromUtf8("action_clearCnt"));
        action_CableMonitor = new QAction(MonitorMainWindow);
        action_CableMonitor->setObjectName(QString::fromUtf8("action_CableMonitor"));
        action_auto_get_data = new QAction(MonitorMainWindow);
        action_auto_get_data->setObjectName(QString::fromUtf8("action_auto_get_data"));
        centralWidget = new QWidget(MonitorMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(20);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(1000, 600));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1182, 737));
        horizontalLayout_5 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_2);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(groupBox_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_2 = new QHBoxLayout(page);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        treeWidget_deviceList = new QTreeWidget(page);
        treeWidget_deviceList->setObjectName(QString::fromUtf8("treeWidget_deviceList"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeWidget_deviceList->sizePolicy().hasHeightForWidth());
        treeWidget_deviceList->setSizePolicy(sizePolicy2);
        treeWidget_deviceList->setColumnCount(2);

        horizontalLayout_2->addWidget(treeWidget_deviceList);

        stackedWidget_device = new QStackedWidget(page);
        stackedWidget_device->setObjectName(QString::fromUtf8("stackedWidget_device"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_3 = new QHBoxLayout(page_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        stackedWidget_device->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget_device->addWidget(page_3);

        horizontalLayout_2->addWidget(stackedWidget_device);

        stackedWidget->addWidget(page);
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        horizontalLayout = new QHBoxLayout(page1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_histtory = new QWidget(page1);
        widget_histtory->setObjectName(QString::fromUtf8("widget_histtory"));
        widget_histtory->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));
        horizontalLayout_10 = new QHBoxLayout(widget_histtory);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(widget_histtory);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_8->addWidget(label_3);

        beginDateTimeEdit = new QDateTimeEdit(widget_histtory);
        beginDateTimeEdit->setObjectName(QString::fromUtf8("beginDateTimeEdit"));

        horizontalLayout_8->addWidget(beginDateTimeEdit);


        horizontalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(widget_histtory);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_9->addWidget(label_4);

        endDateTimeEdit = new QDateTimeEdit(widget_histtory);
        endDateTimeEdit->setObjectName(QString::fromUtf8("endDateTimeEdit"));

        horizontalLayout_9->addWidget(endDateTimeEdit);


        horizontalLayout_7->addLayout(horizontalLayout_9);

        queryDevicceIdComboBox = new QComboBox(widget_histtory);
        queryDevicceIdComboBox->setObjectName(QString::fromUtf8("queryDevicceIdComboBox"));

        horizontalLayout_7->addWidget(queryDevicceIdComboBox);

        queryDataTypeComboBox = new QComboBox(widget_histtory);
        queryDataTypeComboBox->setObjectName(QString::fromUtf8("queryDataTypeComboBox"));

        horizontalLayout_7->addWidget(queryDataTypeComboBox);

        queryPushButton = new QPushButton(widget_histtory);
        queryPushButton->setObjectName(QString::fromUtf8("queryPushButton"));

        horizontalLayout_7->addWidget(queryPushButton);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_7->addItem(verticalSpacer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        clearCurvesPushButton = new QPushButton(widget_histtory);
        clearCurvesPushButton->setObjectName(QString::fromUtf8("clearCurvesPushButton"));

        horizontalLayout_7->addWidget(clearCurvesPushButton);

        clearDBPushButton = new QPushButton(widget_histtory);
        clearDBPushButton->setObjectName(QString::fromUtf8("clearDBPushButton"));

        horizontalLayout_7->addWidget(clearDBPushButton);


        verticalLayout_3->addLayout(horizontalLayout_7);

        widget_historyPlot = new historyDataPlot(widget_histtory);
        widget_historyPlot->setObjectName(QString::fromUtf8("widget_historyPlot"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_historyPlot->sizePolicy().hasHeightForWidth());
        widget_historyPlot->setSizePolicy(sizePolicy3);
        widget_historyPlot->setMinimumSize(QSize(0, 400));

        verticalLayout_3->addWidget(widget_historyPlot);


        horizontalLayout_10->addLayout(verticalLayout_3);


        horizontalLayout->addWidget(widget_histtory);

        stackedWidget->addWidget(page1);

        horizontalLayout_6->addWidget(stackedWidget);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_3);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(groupBox_3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy4);
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));

        horizontalLayout_4->addWidget(textBrowser);


        verticalLayout->addWidget(groupBox_3);


        horizontalLayout_5->addLayout(verticalLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        MonitorMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MonitorMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MonitorMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MonitorMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MonitorMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(action_data);
        menu->addAction(action_history);
        menu->addAction(action_show_info);
        menu_2->addAction(action_connect_485);
        menu_2->addAction(action_connect_network);
        menu_2->addAction(action_connet_server);
        menu_3->addAction(action_register_device);
        menu_3->addAction(action_set_map);
        menu_4->addAction(action_CableMonitor);
        mainToolBar->addAction(action_connect_485);
        mainToolBar->addAction(action_connect_network);
        mainToolBar->addAction(action_clearLog);
        mainToolBar->addAction(action_cnt_com_failed);
        mainToolBar->addAction(action_clearCnt);
        mainToolBar->addAction(action_auto_get_data);

        retranslateUi(MonitorMainWindow);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_device->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MonitorMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MonitorMainWindow)
    {
        MonitorMainWindow->setWindowTitle(QApplication::translate("MonitorMainWindow", "MonitorMainWindow", 0, QApplication::UnicodeUTF8));
        action_data->setText(QApplication::translate("MonitorMainWindow", "\345\256\236\346\227\266\346\225\260\346\215\256\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        action_history->setText(QApplication::translate("MonitorMainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        action_register_device->setText(QApplication::translate("MonitorMainWindow", "\346\263\250\345\206\214\350\256\276\345\244\207", 0, QApplication::UnicodeUTF8));
        action_connect_485->setText(QApplication::translate("MonitorMainWindow", "485\351\200\232\344\277\241\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        action_connect_network->setText(QApplication::translate("MonitorMainWindow", "\347\275\221\347\273\234\351\200\232\344\277\241\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        action_show_info->setText(QApplication::translate("MonitorMainWindow", "\350\260\203\350\257\225\344\277\241\346\201\257\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        action_set_map->setText(QApplication::translate("MonitorMainWindow", "\350\256\276\347\275\256\346\230\240\345\260\204\350\241\250", 0, QApplication::UnicodeUTF8));
        action_connet_server->setText(QApplication::translate("MonitorMainWindow", "\350\277\234\347\253\257\346\234\215\345\212\241\345\231\250\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_connet_server->setToolTip(QApplication::translate("MonitorMainWindow", "\346\234\215\345\212\241\345\231\250\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_clearLog->setText(QApplication::translate("MonitorMainWindow", "\346\270\205\351\231\244\346\227\245\345\277\227", 0, QApplication::UnicodeUTF8));
        action_cnt_com_failed->setText(QApplication::translate("MonitorMainWindow", "\351\200\232\344\277\241\345\244\261\350\264\245\350\256\241\346\225\2600\346\254\241", 0, QApplication::UnicodeUTF8));
        action_clearCnt->setText(QApplication::translate("MonitorMainWindow", "\346\270\205\351\231\244\350\256\241\346\225\260", 0, QApplication::UnicodeUTF8));
        action_CableMonitor->setText(QApplication::translate("MonitorMainWindow", "\345\205\263\344\272\216CableMonitor", 0, QApplication::UnicodeUTF8));
        action_auto_get_data->setText(QApplication::translate("MonitorMainWindow", "\350\207\252\345\212\250\350\216\267\345\217\226\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MonitorMainWindow", "\350\256\276\345\244\207\344\277\241\346\201\257\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_deviceList->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MonitorMainWindow", "\344\270\212\347\272\277", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MonitorMainWindow", "\350\256\276\345\244\207\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MonitorMainWindow", "From", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MonitorMainWindow", "To", 0, QApplication::UnicodeUTF8));
        queryDataTypeComboBox->clear();
        queryDataTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("MonitorMainWindow", "\344\270\273\347\274\206\347\224\265\346\265\201\345\271\263\345\235\207\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonitorMainWindow", "A\347\233\270\346\212\244\345\261\202\347\224\265\346\265\201\345\271\263\345\235\207\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonitorMainWindow", "B\347\233\270\346\212\244\345\261\202\347\224\265\346\265\201\345\271\263\345\235\207\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonitorMainWindow", "C\347\233\270\346\212\244\345\261\202\347\224\265\346\265\201\345\271\263\345\235\207\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonitorMainWindow", "N\347\233\270\346\212\244\345\261\202\347\224\265\346\265\201\345\271\263\345\235\207\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonitorMainWindow", "A\347\233\270\346\270\251\345\272\246\345\271\263\345\235\207\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonitorMainWindow", "B\347\233\270\346\270\251\345\272\246\345\271\263\345\235\207\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonitorMainWindow", "C\347\233\270\346\270\251\345\272\246\345\271\263\345\235\207\345\200\274", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonitorMainWindow", "N\347\233\270\346\270\251\345\272\246\345\271\263\345\235\207\345\200\274", 0, QApplication::UnicodeUTF8)
        );
        queryPushButton->setText(QApplication::translate("MonitorMainWindow", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        clearCurvesPushButton->setText(QApplication::translate("MonitorMainWindow", "\346\270\205\351\231\244\345\233\276\350\241\250", 0, QApplication::UnicodeUTF8));
        clearDBPushButton->setText(QApplication::translate("MonitorMainWindow", "\346\270\205\351\231\244\346\225\260\346\215\256\345\272\223", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MonitorMainWindow", "\350\260\203\350\257\225\344\277\241\346\201\257\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MonitorMainWindow", "\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MonitorMainWindow", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MonitorMainWindow", "\346\223\215\344\275\234", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("MonitorMainWindow", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MonitorMainWindow: public Ui_MonitorMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORMAINWINDOW_H
