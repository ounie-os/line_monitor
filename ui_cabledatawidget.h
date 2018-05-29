/********************************************************************************
** Form generated from reading UI file 'cabledatawidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CABLEDATAWIDGET_H
#define UI_CABLEDATAWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <trendplot.h>

QT_BEGIN_NAMESPACE

class Ui_CableDataWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_deviceID;
    QLabel *label_2;
    QLabel *label_deviceName;
    QLabel *label_3;
    QLabel *label_IP;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget_data;
    QWidget *tab_data;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QLabel *label_34;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_41;
    QLabel *label_46;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_37;
    QLabel *label_38;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_45;
    QLabel *label_42;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_ReadRtData;
    QCheckBox *checkBox;
    QLabel *label_4;
    QSpinBox *spinBox;
    QLabel *label_12;
    QTableWidget *tableWidget;
    QWidget *tab;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_8;
    QTabWidget *tabWidget_chart_2;
    trendPlot *tab_groundCable_2;
    QTabWidget *tabWidget_chart;
    trendPlot *tab_groundCable;
    trendPlot *tab_mainCable;
    QWidget *tab_alarm_value;
    QHBoxLayout *horizontalLayout_23;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QHBoxLayout *horizontalLayout_26;
    QHBoxLayout *horizontalLayout_25;
    QTableWidget *tableWidget_alarm_value;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_35;
    QSpinBox *spinBox_alarm_value;
    QLabel *label_36;
    QCheckBox *checkBox_alarm_value;
    QPushButton *pushButton_read_alarm_value;
    QHBoxLayout *horizontalLayout_27;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pushButton_save_alarm_value;
    QPushButton *pushButton_clear_alarm_value;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_para;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QDateTimeEdit *rtcReadDateTimeEdit;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *rtcTimingPushButton;
    QPushButton *rtcReadPushButton;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_20;
    QLabel *label_5;
    QSpinBox *sampleSecSpinBox;
    QLabel *label_11;
    QLabel *label_6;
    QSpinBox *statisticCycleSpinBox;
    QLabel *label_17;
    QLabel *label_7;
    QSpinBox *statisticCountSpinBox;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *statisticArgumentSetPushButton;
    QPushButton *statisticArgumentReadPushButton;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_21;
    QLabel *label_22;
    QSpinBox *SpinBox_Temp_SampleSec;
    QLabel *label_23;
    QLabel *label_24;
    QSpinBox *SpinBox_Temp_StatisticCycle;
    QLabel *label_25;
    QLabel *label_26;
    QSpinBox *SpinBox_Temp_StatisticCount;
    QLabel *label_27;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *PushButton_Temp_SetStatisticArgument;
    QPushButton *PushButton_Read_StatisticArgument;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QComboBox *thresholdTypeComboBox;
    QDoubleSpinBox *thresholdValueDoubleSpinBox;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *thresholdSetPushButton;
    QPushButton *thresholdReadPushButton;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_19;
    QComboBox *comboBox_TempThresholdType;
    QDoubleSpinBox *doubleSpinBox_Temp_Threshold;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_setTempThreashold;
    QPushButton *pushButton_readTempThreshold;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_33;
    QSpinBox *spinBox_CurChangerateCycle;
    QLabel *label_40;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_Set_CurChangerateCycle;
    QPushButton *pushButton_Read_CurChangerateCycle;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_28;
    QComboBox *comboBox_CurChangeRate_Threshold;
    QDoubleSpinBox *doubleSpinBox_CurChangeRate_Threshold;
    QLabel *label_39;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_SetCurChangeRate_Threshold;
    QPushButton *pushButton_ReadCurChangeRate_Threshold;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_29;
    QComboBox *comboBox_Vibate_Threshold;
    QDoubleSpinBox *doubleSpinBox_Vibrate_Threshold;
    QLabel *label_32;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_SetVibrate_Threshold;
    QPushButton *pushButton_ReadVibrate_Threshold;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_30;
    QSpinBox *spinBox_VibrateStatisticTime;
    QLabel *label_31;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_Set_VibrateStatisticTime;
    QPushButton *pushButton_Read_VibrateStatisticTime;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QComboBox *ctTypeComboBox;
    QDoubleSpinBox *ctValueDoubleSpinBox;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *ctSetPushButton;
    QPushButton *ctReadPushButton;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_16;
    QComboBox *channelTypeComboBox;
    QCheckBox *phaseMainControlbitsCheckBox;
    QCheckBox *phaseAControlbitsCheckBox;
    QCheckBox *phaseBControlbitsCheckBox;
    QCheckBox *phaseCControlbitsCheckBox;
    QCheckBox *phaseNControlbitsCheckBox;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *channelControlSetPushButton;
    QPushButton *channelControlReadPushButton;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *supperRootOperationPushButton;

    void setupUi(QWidget *CableDataWidget)
    {
        if (CableDataWidget->objectName().isEmpty())
            CableDataWidget->setObjectName(QString::fromUtf8("CableDataWidget"));
        CableDataWidget->resize(1036, 603);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CableDataWidget->sizePolicy().hasHeightForWidth());
        CableDataWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(CableDataWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollArea = new QScrollArea(CableDataWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1016, 583));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        label_deviceID = new QLabel(scrollAreaWidgetContents);
        label_deviceID->setObjectName(QString::fromUtf8("label_deviceID"));

        horizontalLayout_2->addWidget(label_deviceID);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label_deviceName = new QLabel(scrollAreaWidgetContents);
        label_deviceName->setObjectName(QString::fromUtf8("label_deviceName"));

        horizontalLayout_2->addWidget(label_deviceName);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        label_IP = new QLabel(scrollAreaWidgetContents);
        label_IP->setObjectName(QString::fromUtf8("label_IP"));

        horizontalLayout_2->addWidget(label_IP);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tabWidget_data = new QTabWidget(scrollAreaWidgetContents);
        tabWidget_data->setObjectName(QString::fromUtf8("tabWidget_data"));
        tab_data = new QWidget();
        tab_data->setObjectName(QString::fromUtf8("tab_data"));
        verticalLayout = new QVBoxLayout(tab_data);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea_2 = new QScrollArea(tab_data);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 970, 490));
        layoutWidget = new QWidget(scrollAreaWidgetContents_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(22, 6, 591, 361));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_14->addWidget(label_14);

        label_34 = new QLabel(layoutWidget);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_14->addWidget(label_34);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_43 = new QLabel(layoutWidget);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        horizontalLayout_13->addWidget(label_43);

        label_44 = new QLabel(layoutWidget);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        horizontalLayout_13->addWidget(label_44);

        label_41 = new QLabel(layoutWidget);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_13->addWidget(label_41);

        label_46 = new QLabel(layoutWidget);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        horizontalLayout_13->addWidget(label_46);


        verticalLayout_3->addLayout(horizontalLayout_13);


        horizontalLayout_15->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_37 = new QLabel(layoutWidget);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        horizontalLayout_5->addWidget(label_37);

        label_38 = new QLabel(layoutWidget);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout_5->addWidget(label_38);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_45 = new QLabel(layoutWidget);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        horizontalLayout_6->addWidget(label_45);

        label_42 = new QLabel(layoutWidget);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        horizontalLayout_6->addWidget(label_42);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_15->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(horizontalLayout_15);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_ReadRtData = new QPushButton(layoutWidget);
        pushButton_ReadRtData->setObjectName(QString::fromUtf8("pushButton_ReadRtData"));

        horizontalLayout_4->addWidget(pushButton_ReadRtData);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_4->addWidget(checkBox);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy3);
        spinBox->setMinimum(1);
        spinBox->setMaximum(99999);
        spinBox->setValue(3);

        horizontalLayout_4->addWidget(spinBox);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_4->addWidget(label_12);


        verticalLayout_7->addLayout(horizontalLayout_4);

        tableWidget = new QTableWidget(layoutWidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem12);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem13->setBackground(brush1);
        __qtablewidgetitem13->setForeground(brush);
        tableWidget->setItem(0, 0, __qtablewidgetitem13);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::NoBrush);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setBackground(brush3);
        __qtablewidgetitem14->setForeground(brush2);
        tableWidget->setItem(0, 1, __qtablewidgetitem14);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::NoBrush);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::NoBrush);
        QFont font;
        font.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font);
        __qtablewidgetitem15->setBackground(brush5);
        __qtablewidgetitem15->setForeground(brush4);
        tableWidget->setItem(1, 0, __qtablewidgetitem15);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::NoBrush);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setBackground(brush7);
        __qtablewidgetitem16->setForeground(brush6);
        tableWidget->setItem(6, 0, __qtablewidgetitem16);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setMidLineWidth(0);
        tableWidget->horizontalHeader()->setDefaultSectionSize(104);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout_7->addWidget(tableWidget);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea_2);

        tabWidget_data->addTab(tab_data, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(31, 20, 721, 401));
        verticalLayout_8 = new QVBoxLayout(layoutWidget1);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        tabWidget_chart_2 = new QTabWidget(layoutWidget1);
        tabWidget_chart_2->setObjectName(QString::fromUtf8("tabWidget_chart_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tabWidget_chart_2->sizePolicy().hasHeightForWidth());
        tabWidget_chart_2->setSizePolicy(sizePolicy4);
        tabWidget_chart_2->setMinimumSize(QSize(150, 150));
        tab_groundCable_2 = new trendPlot();
        tab_groundCable_2->setObjectName(QString::fromUtf8("tab_groundCable_2"));
        tabWidget_chart_2->addTab(tab_groundCable_2, QString());

        verticalLayout_8->addWidget(tabWidget_chart_2);

        tabWidget_chart = new QTabWidget(layoutWidget1);
        tabWidget_chart->setObjectName(QString::fromUtf8("tabWidget_chart"));
        sizePolicy4.setHeightForWidth(tabWidget_chart->sizePolicy().hasHeightForWidth());
        tabWidget_chart->setSizePolicy(sizePolicy4);
        tabWidget_chart->setMinimumSize(QSize(150, 150));
        tab_groundCable = new trendPlot();
        tab_groundCable->setObjectName(QString::fromUtf8("tab_groundCable"));
        tabWidget_chart->addTab(tab_groundCable, QString());
        tab_mainCable = new trendPlot();
        tab_mainCable->setObjectName(QString::fromUtf8("tab_mainCable"));
        tabWidget_chart->addTab(tab_mainCable, QString());

        verticalLayout_8->addWidget(tabWidget_chart);

        verticalLayout_8->setStretch(0, 1);
        verticalLayout_8->setStretch(1, 1);
        tabWidget_data->addTab(tab, QString());
        tab_alarm_value = new QWidget();
        tab_alarm_value->setObjectName(QString::fromUtf8("tab_alarm_value"));
        horizontalLayout_23 = new QHBoxLayout(tab_alarm_value);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        scrollArea_3 = new QScrollArea(tab_alarm_value);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 970, 490));
        horizontalLayout_26 = new QHBoxLayout(scrollAreaWidgetContents_3);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        tableWidget_alarm_value = new QTableWidget(scrollAreaWidgetContents_3);
        if (tableWidget_alarm_value->columnCount() < 2)
            tableWidget_alarm_value->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_alarm_value->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_alarm_value->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        if (tableWidget_alarm_value->rowCount() < 26)
            tableWidget_alarm_value->setRowCount(26);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(6, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(7, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(8, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(9, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(10, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(11, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(12, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(13, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(14, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(15, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(16, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(17, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(18, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(19, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(20, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(21, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(22, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(23, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(24, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_alarm_value->setVerticalHeaderItem(25, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(0, 0, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(0, 1, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(1, 0, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(1, 1, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(2, 0, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(2, 1, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(3, 0, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(3, 1, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(4, 0, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(4, 1, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(5, 0, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(5, 1, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(6, 0, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(6, 1, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(7, 0, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(7, 1, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(8, 0, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(8, 1, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(9, 0, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(9, 1, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(10, 0, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(10, 1, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(11, 0, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(11, 1, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(12, 0, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(12, 1, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(13, 0, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(13, 1, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(14, 0, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(14, 1, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(15, 0, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(15, 1, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(16, 0, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(16, 1, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(17, 0, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(17, 1, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(18, 0, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(18, 1, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(19, 0, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(19, 1, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(20, 0, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(20, 1, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(21, 0, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(21, 1, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(22, 0, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(22, 1, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(23, 0, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(23, 1, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(24, 0, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(24, 1, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(25, 0, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        tableWidget_alarm_value->setItem(25, 1, __qtablewidgetitem96);
        tableWidget_alarm_value->setObjectName(QString::fromUtf8("tableWidget_alarm_value"));
        tableWidget_alarm_value->horizontalHeader()->setDefaultSectionSize(200);

        horizontalLayout_25->addWidget(tableWidget_alarm_value);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_35 = new QLabel(scrollAreaWidgetContents_3);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_24->addWidget(label_35);

        spinBox_alarm_value = new QSpinBox(scrollAreaWidgetContents_3);
        spinBox_alarm_value->setObjectName(QString::fromUtf8("spinBox_alarm_value"));
        spinBox_alarm_value->setMinimum(1);
        spinBox_alarm_value->setMaximum(99999);
        spinBox_alarm_value->setValue(3);

        horizontalLayout_24->addWidget(spinBox_alarm_value);

        label_36 = new QLabel(scrollAreaWidgetContents_3);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        horizontalLayout_24->addWidget(label_36);

        checkBox_alarm_value = new QCheckBox(scrollAreaWidgetContents_3);
        checkBox_alarm_value->setObjectName(QString::fromUtf8("checkBox_alarm_value"));

        horizontalLayout_24->addWidget(checkBox_alarm_value);

        pushButton_read_alarm_value = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_read_alarm_value->setObjectName(QString::fromUtf8("pushButton_read_alarm_value"));

        horizontalLayout_24->addWidget(pushButton_read_alarm_value);


        verticalLayout_6->addLayout(horizontalLayout_24);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        horizontalSpacer_15 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_15);

        pushButton_save_alarm_value = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_save_alarm_value->setObjectName(QString::fromUtf8("pushButton_save_alarm_value"));

        horizontalLayout_27->addWidget(pushButton_save_alarm_value);

        pushButton_clear_alarm_value = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_clear_alarm_value->setObjectName(QString::fromUtf8("pushButton_clear_alarm_value"));

        horizontalLayout_27->addWidget(pushButton_clear_alarm_value);


        verticalLayout_6->addLayout(horizontalLayout_27);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        horizontalLayout_25->addLayout(verticalLayout_6);


        horizontalLayout_26->addLayout(horizontalLayout_25);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout_23->addWidget(scrollArea_3);

        tabWidget_data->addTab(tab_alarm_value, QString());
        tab_para = new QWidget();
        tab_para->setObjectName(QString::fromUtf8("tab_para"));
        groupBox_2 = new QGroupBox(tab_para);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 671, 371));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        rtcReadDateTimeEdit = new QDateTimeEdit(groupBox_2);
        rtcReadDateTimeEdit->setObjectName(QString::fromUtf8("rtcReadDateTimeEdit"));

        horizontalLayout_7->addWidget(rtcReadDateTimeEdit);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        rtcTimingPushButton = new QPushButton(groupBox_2);
        rtcTimingPushButton->setObjectName(QString::fromUtf8("rtcTimingPushButton"));

        horizontalLayout_7->addWidget(rtcTimingPushButton);

        rtcReadPushButton = new QPushButton(groupBox_2);
        rtcReadPushButton->setObjectName(QString::fromUtf8("rtcReadPushButton"));

        horizontalLayout_7->addWidget(rtcReadPushButton);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_8->addWidget(label_20);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_8->addWidget(label_5);

        sampleSecSpinBox = new QSpinBox(groupBox_2);
        sampleSecSpinBox->setObjectName(QString::fromUtf8("sampleSecSpinBox"));
        sampleSecSpinBox->setMinimum(5);
        sampleSecSpinBox->setMaximum(127);

        horizontalLayout_8->addWidget(sampleSecSpinBox);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_8->addWidget(label_11);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        statisticCycleSpinBox = new QSpinBox(groupBox_2);
        statisticCycleSpinBox->setObjectName(QString::fromUtf8("statisticCycleSpinBox"));
        statisticCycleSpinBox->setMinimum(1);
        statisticCycleSpinBox->setMaximum(90);

        horizontalLayout_8->addWidget(statisticCycleSpinBox);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_8->addWidget(label_17);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        statisticCountSpinBox = new QSpinBox(groupBox_2);
        statisticCountSpinBox->setObjectName(QString::fromUtf8("statisticCountSpinBox"));
        statisticCountSpinBox->setMinimum(1);
        statisticCountSpinBox->setMaximum(48);

        horizontalLayout_8->addWidget(statisticCountSpinBox);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_8->addWidget(label_18);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        statisticArgumentSetPushButton = new QPushButton(groupBox_2);
        statisticArgumentSetPushButton->setObjectName(QString::fromUtf8("statisticArgumentSetPushButton"));

        horizontalLayout_8->addWidget(statisticArgumentSetPushButton);

        statisticArgumentReadPushButton = new QPushButton(groupBox_2);
        statisticArgumentReadPushButton->setObjectName(QString::fromUtf8("statisticArgumentReadPushButton"));

        horizontalLayout_8->addWidget(statisticArgumentReadPushButton);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_17->addWidget(label_21);

        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_17->addWidget(label_22);

        SpinBox_Temp_SampleSec = new QSpinBox(groupBox_2);
        SpinBox_Temp_SampleSec->setObjectName(QString::fromUtf8("SpinBox_Temp_SampleSec"));
        SpinBox_Temp_SampleSec->setMinimum(5);
        SpinBox_Temp_SampleSec->setMaximum(127);

        horizontalLayout_17->addWidget(SpinBox_Temp_SampleSec);

        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_17->addWidget(label_23);

        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_17->addWidget(label_24);

        SpinBox_Temp_StatisticCycle = new QSpinBox(groupBox_2);
        SpinBox_Temp_StatisticCycle->setObjectName(QString::fromUtf8("SpinBox_Temp_StatisticCycle"));
        SpinBox_Temp_StatisticCycle->setMinimum(1);
        SpinBox_Temp_StatisticCycle->setMaximum(90);

        horizontalLayout_17->addWidget(SpinBox_Temp_StatisticCycle);

        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_17->addWidget(label_25);

        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_17->addWidget(label_26);

        SpinBox_Temp_StatisticCount = new QSpinBox(groupBox_2);
        SpinBox_Temp_StatisticCount->setObjectName(QString::fromUtf8("SpinBox_Temp_StatisticCount"));
        SpinBox_Temp_StatisticCount->setMinimum(1);
        SpinBox_Temp_StatisticCount->setMaximum(48);

        horizontalLayout_17->addWidget(SpinBox_Temp_StatisticCount);

        label_27 = new QLabel(groupBox_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_17->addWidget(label_27);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_10);

        PushButton_Temp_SetStatisticArgument = new QPushButton(groupBox_2);
        PushButton_Temp_SetStatisticArgument->setObjectName(QString::fromUtf8("PushButton_Temp_SetStatisticArgument"));

        horizontalLayout_17->addWidget(PushButton_Temp_SetStatisticArgument);

        PushButton_Read_StatisticArgument = new QPushButton(groupBox_2);
        PushButton_Read_StatisticArgument->setObjectName(QString::fromUtf8("PushButton_Read_StatisticArgument"));

        horizontalLayout_17->addWidget(PushButton_Read_StatisticArgument);


        verticalLayout_5->addLayout(horizontalLayout_17);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        thresholdTypeComboBox = new QComboBox(groupBox_2);
        thresholdTypeComboBox->setObjectName(QString::fromUtf8("thresholdTypeComboBox"));

        horizontalLayout_9->addWidget(thresholdTypeComboBox);

        thresholdValueDoubleSpinBox = new QDoubleSpinBox(groupBox_2);
        thresholdValueDoubleSpinBox->setObjectName(QString::fromUtf8("thresholdValueDoubleSpinBox"));
        thresholdValueDoubleSpinBox->setMaximum(1e+06);

        horizontalLayout_9->addWidget(thresholdValueDoubleSpinBox);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_9->addWidget(label_13);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        thresholdSetPushButton = new QPushButton(groupBox_2);
        thresholdSetPushButton->setObjectName(QString::fromUtf8("thresholdSetPushButton"));

        horizontalLayout_9->addWidget(thresholdSetPushButton);

        thresholdReadPushButton = new QPushButton(groupBox_2);
        thresholdReadPushButton->setObjectName(QString::fromUtf8("thresholdReadPushButton"));

        horizontalLayout_9->addWidget(thresholdReadPushButton);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_16->addWidget(label_19);

        comboBox_TempThresholdType = new QComboBox(groupBox_2);
        comboBox_TempThresholdType->setObjectName(QString::fromUtf8("comboBox_TempThresholdType"));

        horizontalLayout_16->addWidget(comboBox_TempThresholdType);

        doubleSpinBox_Temp_Threshold = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_Temp_Threshold->setObjectName(QString::fromUtf8("doubleSpinBox_Temp_Threshold"));
        doubleSpinBox_Temp_Threshold->setMaximum(100000);

        horizontalLayout_16->addWidget(doubleSpinBox_Temp_Threshold);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_16->addWidget(label_15);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_9);

        pushButton_setTempThreashold = new QPushButton(groupBox_2);
        pushButton_setTempThreashold->setObjectName(QString::fromUtf8("pushButton_setTempThreashold"));

        horizontalLayout_16->addWidget(pushButton_setTempThreashold);

        pushButton_readTempThreshold = new QPushButton(groupBox_2);
        pushButton_readTempThreshold->setObjectName(QString::fromUtf8("pushButton_readTempThreshold"));

        horizontalLayout_16->addWidget(pushButton_readTempThreshold);


        verticalLayout_5->addLayout(horizontalLayout_16);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_33 = new QLabel(groupBox_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        horizontalLayout_21->addWidget(label_33);

        spinBox_CurChangerateCycle = new QSpinBox(groupBox_2);
        spinBox_CurChangerateCycle->setObjectName(QString::fromUtf8("spinBox_CurChangerateCycle"));
        spinBox_CurChangerateCycle->setMinimum(1);
        spinBox_CurChangerateCycle->setMaximum(2048);
        spinBox_CurChangerateCycle->setValue(1);

        horizontalLayout_21->addWidget(spinBox_CurChangerateCycle);

        label_40 = new QLabel(groupBox_2);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        horizontalLayout_21->addWidget(label_40);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_14);

        pushButton_Set_CurChangerateCycle = new QPushButton(groupBox_2);
        pushButton_Set_CurChangerateCycle->setObjectName(QString::fromUtf8("pushButton_Set_CurChangerateCycle"));

        horizontalLayout_21->addWidget(pushButton_Set_CurChangerateCycle);

        pushButton_Read_CurChangerateCycle = new QPushButton(groupBox_2);
        pushButton_Read_CurChangerateCycle->setObjectName(QString::fromUtf8("pushButton_Read_CurChangerateCycle"));

        horizontalLayout_21->addWidget(pushButton_Read_CurChangerateCycle);


        verticalLayout_5->addLayout(horizontalLayout_21);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_18->addWidget(label_28);

        comboBox_CurChangeRate_Threshold = new QComboBox(groupBox_2);
        comboBox_CurChangeRate_Threshold->setObjectName(QString::fromUtf8("comboBox_CurChangeRate_Threshold"));

        horizontalLayout_18->addWidget(comboBox_CurChangeRate_Threshold);

        doubleSpinBox_CurChangeRate_Threshold = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_CurChangeRate_Threshold->setObjectName(QString::fromUtf8("doubleSpinBox_CurChangeRate_Threshold"));

        horizontalLayout_18->addWidget(doubleSpinBox_CurChangeRate_Threshold);

        label_39 = new QLabel(groupBox_2);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        horizontalLayout_18->addWidget(label_39);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_11);

        pushButton_SetCurChangeRate_Threshold = new QPushButton(groupBox_2);
        pushButton_SetCurChangeRate_Threshold->setObjectName(QString::fromUtf8("pushButton_SetCurChangeRate_Threshold"));

        horizontalLayout_18->addWidget(pushButton_SetCurChangeRate_Threshold);

        pushButton_ReadCurChangeRate_Threshold = new QPushButton(groupBox_2);
        pushButton_ReadCurChangeRate_Threshold->setObjectName(QString::fromUtf8("pushButton_ReadCurChangeRate_Threshold"));

        horizontalLayout_18->addWidget(pushButton_ReadCurChangeRate_Threshold);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_29 = new QLabel(groupBox_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_19->addWidget(label_29);

        comboBox_Vibate_Threshold = new QComboBox(groupBox_2);
        comboBox_Vibate_Threshold->setObjectName(QString::fromUtf8("comboBox_Vibate_Threshold"));

        horizontalLayout_19->addWidget(comboBox_Vibate_Threshold);

        doubleSpinBox_Vibrate_Threshold = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_Vibrate_Threshold->setObjectName(QString::fromUtf8("doubleSpinBox_Vibrate_Threshold"));
        doubleSpinBox_Vibrate_Threshold->setMaximum(999.99);

        horizontalLayout_19->addWidget(doubleSpinBox_Vibrate_Threshold);

        label_32 = new QLabel(groupBox_2);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_19->addWidget(label_32);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_12);

        pushButton_SetVibrate_Threshold = new QPushButton(groupBox_2);
        pushButton_SetVibrate_Threshold->setObjectName(QString::fromUtf8("pushButton_SetVibrate_Threshold"));

        horizontalLayout_19->addWidget(pushButton_SetVibrate_Threshold);

        pushButton_ReadVibrate_Threshold = new QPushButton(groupBox_2);
        pushButton_ReadVibrate_Threshold->setObjectName(QString::fromUtf8("pushButton_ReadVibrate_Threshold"));

        horizontalLayout_19->addWidget(pushButton_ReadVibrate_Threshold);


        verticalLayout_5->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_30 = new QLabel(groupBox_2);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_20->addWidget(label_30);

        spinBox_VibrateStatisticTime = new QSpinBox(groupBox_2);
        spinBox_VibrateStatisticTime->setObjectName(QString::fromUtf8("spinBox_VibrateStatisticTime"));

        horizontalLayout_20->addWidget(spinBox_VibrateStatisticTime);

        label_31 = new QLabel(groupBox_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_20->addWidget(label_31);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_13);

        pushButton_Set_VibrateStatisticTime = new QPushButton(groupBox_2);
        pushButton_Set_VibrateStatisticTime->setObjectName(QString::fromUtf8("pushButton_Set_VibrateStatisticTime"));

        horizontalLayout_20->addWidget(pushButton_Set_VibrateStatisticTime);

        pushButton_Read_VibrateStatisticTime = new QPushButton(groupBox_2);
        pushButton_Read_VibrateStatisticTime->setObjectName(QString::fromUtf8("pushButton_Read_VibrateStatisticTime"));

        horizontalLayout_20->addWidget(pushButton_Read_VibrateStatisticTime);


        verticalLayout_5->addLayout(horizontalLayout_20);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_10->addWidget(label_10);

        ctTypeComboBox = new QComboBox(groupBox_2);
        ctTypeComboBox->setObjectName(QString::fromUtf8("ctTypeComboBox"));

        horizontalLayout_10->addWidget(ctTypeComboBox);

        ctValueDoubleSpinBox = new QDoubleSpinBox(groupBox_2);
        ctValueDoubleSpinBox->setObjectName(QString::fromUtf8("ctValueDoubleSpinBox"));
        ctValueDoubleSpinBox->setDecimals(0);
        ctValueDoubleSpinBox->setMinimum(1);
        ctValueDoubleSpinBox->setMaximum(1e+07);

        horizontalLayout_10->addWidget(ctValueDoubleSpinBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        ctSetPushButton = new QPushButton(groupBox_2);
        ctSetPushButton->setObjectName(QString::fromUtf8("ctSetPushButton"));

        horizontalLayout_10->addWidget(ctSetPushButton);

        ctReadPushButton = new QPushButton(groupBox_2);
        ctReadPushButton->setObjectName(QString::fromUtf8("ctReadPushButton"));

        horizontalLayout_10->addWidget(ctReadPushButton);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_11->addWidget(label_16);

        channelTypeComboBox = new QComboBox(groupBox_2);
        channelTypeComboBox->setObjectName(QString::fromUtf8("channelTypeComboBox"));

        horizontalLayout_11->addWidget(channelTypeComboBox);

        phaseMainControlbitsCheckBox = new QCheckBox(groupBox_2);
        phaseMainControlbitsCheckBox->setObjectName(QString::fromUtf8("phaseMainControlbitsCheckBox"));

        horizontalLayout_11->addWidget(phaseMainControlbitsCheckBox);

        phaseAControlbitsCheckBox = new QCheckBox(groupBox_2);
        phaseAControlbitsCheckBox->setObjectName(QString::fromUtf8("phaseAControlbitsCheckBox"));

        horizontalLayout_11->addWidget(phaseAControlbitsCheckBox);

        phaseBControlbitsCheckBox = new QCheckBox(groupBox_2);
        phaseBControlbitsCheckBox->setObjectName(QString::fromUtf8("phaseBControlbitsCheckBox"));

        horizontalLayout_11->addWidget(phaseBControlbitsCheckBox);

        phaseCControlbitsCheckBox = new QCheckBox(groupBox_2);
        phaseCControlbitsCheckBox->setObjectName(QString::fromUtf8("phaseCControlbitsCheckBox"));

        horizontalLayout_11->addWidget(phaseCControlbitsCheckBox);

        phaseNControlbitsCheckBox = new QCheckBox(groupBox_2);
        phaseNControlbitsCheckBox->setObjectName(QString::fromUtf8("phaseNControlbitsCheckBox"));

        horizontalLayout_11->addWidget(phaseNControlbitsCheckBox);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_8);

        channelControlSetPushButton = new QPushButton(groupBox_2);
        channelControlSetPushButton->setObjectName(QString::fromUtf8("channelControlSetPushButton"));

        horizontalLayout_11->addWidget(channelControlSetPushButton);

        channelControlReadPushButton = new QPushButton(groupBox_2);
        channelControlReadPushButton->setObjectName(QString::fromUtf8("channelControlReadPushButton"));

        horizontalLayout_11->addWidget(channelControlReadPushButton);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);

        supperRootOperationPushButton = new QPushButton(groupBox_2);
        supperRootOperationPushButton->setObjectName(QString::fromUtf8("supperRootOperationPushButton"));

        horizontalLayout_12->addWidget(supperRootOperationPushButton);


        verticalLayout_5->addLayout(horizontalLayout_12);

        tabWidget_data->addTab(tab_para, QString());

        verticalLayout_4->addWidget(tabWidget_data);


        horizontalLayout_3->addLayout(verticalLayout_4);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

#ifndef QT_NO_SHORTCUT
#endif // QT_NO_SHORTCUT

        retranslateUi(CableDataWidget);

        tabWidget_data->setCurrentIndex(0);
        tabWidget_chart_2->setCurrentIndex(0);
        tabWidget_chart->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CableDataWidget);
    } // setupUi

    void retranslateUi(QWidget *CableDataWidget)
    {
        CableDataWidget->setWindowTitle(QApplication::translate("CableDataWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CableDataWidget", "\350\256\276\345\244\207ID:", 0, QApplication::UnicodeUTF8));
        label_deviceID->setText(QApplication::translate("CableDataWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CableDataWidget", "\350\256\276\345\244\207\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_deviceName->setText(QApplication::translate("CableDataWidget", "TextLabe1l", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CableDataWidget", "\350\256\276\345\244\207IP\345\234\260\345\235\200:", 0, QApplication::UnicodeUTF8));
        label_IP->setText(QString());
        label_14->setText(QApplication::translate("CableDataWidget", "\350\277\220\350\241\214\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_34->setText(QString());
        label_43->setText(QApplication::translate("CableDataWidget", "\347\216\257\345\242\203\346\270\251\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_44->setText(QString());
        label_41->setText(QApplication::translate("CableDataWidget", "\346\234\254\346\234\272\346\270\251\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_46->setText(QString());
        label_37->setText(QApplication::translate("CableDataWidget", "UPS\347\224\265\345\216\213\357\274\232", 0, QApplication::UnicodeUTF8));
        label_38->setText(QString());
        label_45->setText(QApplication::translate("CableDataWidget", "\346\271\277\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_42->setText(QString());
        pushButton_ReadRtData->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226\345\256\236\346\227\266\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("CableDataWidget", "\350\207\252\345\212\250\350\216\267\345\217\226\345\256\236\346\227\266\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CableDataWidget", "    \350\256\276\347\275\256\351\227\264\351\232\224\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("CableDataWidget", "\347\247\222", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CableDataWidget", "\344\270\273\347\274\206", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CableDataWidget", "A\347\233\270", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CableDataWidget", "B\347\233\270", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CableDataWidget", "C\347\233\270", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("CableDataWidget", "N\347\233\270", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("CableDataWidget", "\346\216\245\345\234\260\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("CableDataWidget", "\346\216\245\345\244\264\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("CableDataWidget", "\347\224\265\346\265\201\345\217\230\345\214\226\347\216\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("CableDataWidget", "\347\224\265\347\274\206\346\214\257\345\212\250", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("CableDataWidget", "x\350\275\264\345\247\277\346\200\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem10->setText(QApplication::translate("CableDataWidget", "y\350\275\264\345\247\277\346\200\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("CableDataWidget", "z\350\275\264\345\247\277\346\200\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem12->setText(QApplication::translate("CableDataWidget", "\350\241\250\351\235\242\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        tabWidget_data->setTabText(tabWidget_data->indexOf(tab_data), QApplication::translate("CableDataWidget", "\346\230\276\347\244\272\345\256\236\346\227\266\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        tabWidget_chart_2->setTabText(tabWidget_chart_2->indexOf(tab_groundCable_2), QApplication::translate("CableDataWidget", "\346\216\245\345\234\260\347\224\265\347\274\206\346\216\245\345\244\264\346\270\251\345\272\246\345\233\276", 0, QApplication::UnicodeUTF8));
        tabWidget_chart->setTabText(tabWidget_chart->indexOf(tab_groundCable), QApplication::translate("CableDataWidget", "\346\216\245\345\234\260\347\224\265\347\274\206\346\212\244\345\261\202\347\224\265\346\265\201\345\233\276", 0, QApplication::UnicodeUTF8));
        tabWidget_chart->setTabText(tabWidget_chart->indexOf(tab_mainCable), QApplication::translate("CableDataWidget", "\344\270\273\347\274\206\347\224\265\346\265\201\345\233\276", 0, QApplication::UnicodeUTF8));
        tabWidget_data->setTabText(tabWidget_data->indexOf(tab), QApplication::translate("CableDataWidget", "\345\256\236\346\227\266\346\225\260\346\215\256\346\233\262\347\272\277", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_alarm_value->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("CableDataWidget", "\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_alarm_value->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("CableDataWidget", "\346\212\245\350\255\246\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_alarm_value->verticalHeaderItem(0);
        ___qtablewidgetitem15->setText(QApplication::translate("CableDataWidget", "\344\270\273\347\274\206\347\224\265\346\265\201\346\212\245\350\255\246\345\200\274(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_alarm_value->verticalHeaderItem(1);
        ___qtablewidgetitem16->setText(QApplication::translate("CableDataWidget", "A\347\233\270\347\224\265\346\265\201\346\212\245\350\255\246\345\200\274(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_alarm_value->verticalHeaderItem(2);
        ___qtablewidgetitem17->setText(QApplication::translate("CableDataWidget", "B\347\233\270\347\224\265\346\265\201\346\212\245\350\255\246\345\200\274(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_alarm_value->verticalHeaderItem(3);
        ___qtablewidgetitem18->setText(QApplication::translate("CableDataWidget", "C\347\233\270\347\224\265\346\265\201\346\212\245\350\255\246\345\200\274(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_alarm_value->verticalHeaderItem(4);
        ___qtablewidgetitem19->setText(QApplication::translate("CableDataWidget", "N\347\233\270\347\224\265\346\265\201\346\212\245\350\255\246\345\200\274(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_alarm_value->verticalHeaderItem(5);
        ___qtablewidgetitem20->setText(QApplication::translate("CableDataWidget", "A\347\233\270\346\270\251\345\272\246\346\212\245\350\255\246\345\200\274(\342\204\203)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_alarm_value->verticalHeaderItem(6);
        ___qtablewidgetitem21->setText(QApplication::translate("CableDataWidget", "B\347\233\270\346\270\251\345\272\246\346\212\245\350\255\246\345\200\274(\342\204\203)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_alarm_value->verticalHeaderItem(7);
        ___qtablewidgetitem22->setText(QApplication::translate("CableDataWidget", "C\347\233\270\346\270\251\345\272\246\346\212\245\350\255\246\345\200\274(\342\204\203)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_alarm_value->verticalHeaderItem(8);
        ___qtablewidgetitem23->setText(QApplication::translate("CableDataWidget", "N\347\233\270\346\270\251\345\272\246\346\212\245\350\255\246\345\200\274(\342\204\203)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_alarm_value->verticalHeaderItem(9);
        ___qtablewidgetitem24->setText(QApplication::translate("CableDataWidget", "A\347\233\270\346\214\257\345\212\250\346\212\245\350\255\246\345\200\274(\346\254\241/\347\247\222)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_alarm_value->verticalHeaderItem(10);
        ___qtablewidgetitem25->setText(QApplication::translate("CableDataWidget", "B\347\233\270\346\214\257\345\212\250\346\212\245\350\255\246\345\200\274(\346\254\241/\347\247\222)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_alarm_value->verticalHeaderItem(11);
        ___qtablewidgetitem26->setText(QApplication::translate("CableDataWidget", "C\347\233\270\346\214\257\345\212\250\346\212\245\350\255\246\345\200\274(\346\254\241/\347\247\222)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_alarm_value->verticalHeaderItem(12);
        ___qtablewidgetitem27->setText(QApplication::translate("CableDataWidget", "N\347\233\270\346\214\257\345\212\250\346\212\245\350\255\246\345\200\274(\346\254\241/\347\247\222)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_alarm_value->verticalHeaderItem(13);
        ___qtablewidgetitem28->setText(QApplication::translate("CableDataWidget", "A\347\233\270\347\224\265\346\265\201\350\264\237\350\215\267\346\212\245\350\255\246\345\200\274(%)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_alarm_value->verticalHeaderItem(14);
        ___qtablewidgetitem29->setText(QApplication::translate("CableDataWidget", "B\347\233\270\347\224\265\346\265\201\350\264\237\350\215\267\346\212\245\350\255\246\345\200\274(%)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_alarm_value->verticalHeaderItem(15);
        ___qtablewidgetitem30->setText(QApplication::translate("CableDataWidget", "C\347\233\270\347\224\265\346\265\201\350\264\237\350\215\267\346\212\245\350\255\246\345\200\274(%)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_alarm_value->verticalHeaderItem(16);
        ___qtablewidgetitem31->setText(QApplication::translate("CableDataWidget", "N\347\233\270\347\224\265\346\265\201\350\264\237\350\215\267\346\212\245\350\255\246\345\200\274(%)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_alarm_value->verticalHeaderItem(17);
        ___qtablewidgetitem32->setText(QApplication::translate("CableDataWidget", "A\347\233\270\347\224\265\346\265\201\345\244\247\345\260\217\346\257\224\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_alarm_value->verticalHeaderItem(18);
        ___qtablewidgetitem33->setText(QApplication::translate("CableDataWidget", "B\347\233\270\347\224\265\346\265\201\345\244\247\345\260\217\346\257\224\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_alarm_value->verticalHeaderItem(19);
        ___qtablewidgetitem34->setText(QApplication::translate("CableDataWidget", "C\347\233\270\347\224\265\346\265\201\345\244\247\345\260\217\346\257\224\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_alarm_value->verticalHeaderItem(20);
        ___qtablewidgetitem35->setText(QApplication::translate("CableDataWidget", "N\347\233\270\347\224\265\346\265\201\345\244\247\345\260\217\346\257\224\346\212\245\350\255\246\345\200\274", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_alarm_value->verticalHeaderItem(21);
        ___qtablewidgetitem36->setText(QApplication::translate("CableDataWidget", "\344\270\273\347\274\206\347\224\265\346\265\201\345\217\230\345\214\226\347\216\207\346\212\245\350\255\246\345\200\274(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_alarm_value->verticalHeaderItem(22);
        ___qtablewidgetitem37->setText(QApplication::translate("CableDataWidget", "A\347\233\270\347\224\265\346\265\201\345\217\230\345\214\226\347\216\207\346\212\245\350\255\246\345\200\274(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_alarm_value->verticalHeaderItem(23);
        ___qtablewidgetitem38->setText(QApplication::translate("CableDataWidget", "B\347\233\270\347\224\265\346\265\201\345\217\230\345\214\226\347\216\207\346\212\245\350\255\246\345\200\274(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_alarm_value->verticalHeaderItem(24);
        ___qtablewidgetitem39->setText(QApplication::translate("CableDataWidget", "C\347\233\270\347\224\265\346\265\201\345\217\230\345\214\226\347\216\207\346\212\245\350\255\246\345\200\274(A)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_alarm_value->verticalHeaderItem(25);
        ___qtablewidgetitem40->setText(QApplication::translate("CableDataWidget", "N\347\233\270\347\224\265\346\265\201\345\217\230\345\214\226\347\216\207\346\212\245\350\255\246\345\200\274(A)", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = tableWidget_alarm_value->isSortingEnabled();
        tableWidget_alarm_value->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_alarm_value->item(0, 0);
        ___qtablewidgetitem41->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_alarm_value->item(0, 1);
        ___qtablewidgetitem42->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_alarm_value->item(1, 0);
        ___qtablewidgetitem43->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget_alarm_value->item(1, 1);
        ___qtablewidgetitem44->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_alarm_value->item(2, 0);
        ___qtablewidgetitem45->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_alarm_value->item(2, 1);
        ___qtablewidgetitem46->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_alarm_value->item(3, 0);
        ___qtablewidgetitem47->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_alarm_value->item(3, 1);
        ___qtablewidgetitem48->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_alarm_value->item(4, 0);
        ___qtablewidgetitem49->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_alarm_value->item(4, 1);
        ___qtablewidgetitem50->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget_alarm_value->item(5, 0);
        ___qtablewidgetitem51->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget_alarm_value->item(5, 1);
        ___qtablewidgetitem52->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget_alarm_value->item(6, 0);
        ___qtablewidgetitem53->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget_alarm_value->item(6, 1);
        ___qtablewidgetitem54->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget_alarm_value->item(7, 0);
        ___qtablewidgetitem55->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget_alarm_value->item(7, 1);
        ___qtablewidgetitem56->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget_alarm_value->item(8, 0);
        ___qtablewidgetitem57->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget_alarm_value->item(8, 1);
        ___qtablewidgetitem58->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget_alarm_value->item(9, 0);
        ___qtablewidgetitem59->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget_alarm_value->item(9, 1);
        ___qtablewidgetitem60->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget_alarm_value->item(10, 0);
        ___qtablewidgetitem61->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget_alarm_value->item(10, 1);
        ___qtablewidgetitem62->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget_alarm_value->item(11, 0);
        ___qtablewidgetitem63->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget_alarm_value->item(11, 1);
        ___qtablewidgetitem64->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget_alarm_value->item(12, 0);
        ___qtablewidgetitem65->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem66 = tableWidget_alarm_value->item(12, 1);
        ___qtablewidgetitem66->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem67 = tableWidget_alarm_value->item(13, 0);
        ___qtablewidgetitem67->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem68 = tableWidget_alarm_value->item(13, 1);
        ___qtablewidgetitem68->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem69 = tableWidget_alarm_value->item(14, 0);
        ___qtablewidgetitem69->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem70 = tableWidget_alarm_value->item(14, 1);
        ___qtablewidgetitem70->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem71 = tableWidget_alarm_value->item(15, 0);
        ___qtablewidgetitem71->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem72 = tableWidget_alarm_value->item(15, 1);
        ___qtablewidgetitem72->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem73 = tableWidget_alarm_value->item(16, 0);
        ___qtablewidgetitem73->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem74 = tableWidget_alarm_value->item(16, 1);
        ___qtablewidgetitem74->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem75 = tableWidget_alarm_value->item(17, 0);
        ___qtablewidgetitem75->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem76 = tableWidget_alarm_value->item(17, 1);
        ___qtablewidgetitem76->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem77 = tableWidget_alarm_value->item(18, 0);
        ___qtablewidgetitem77->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem78 = tableWidget_alarm_value->item(18, 1);
        ___qtablewidgetitem78->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem79 = tableWidget_alarm_value->item(19, 0);
        ___qtablewidgetitem79->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem80 = tableWidget_alarm_value->item(19, 1);
        ___qtablewidgetitem80->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem81 = tableWidget_alarm_value->item(20, 0);
        ___qtablewidgetitem81->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem82 = tableWidget_alarm_value->item(20, 1);
        ___qtablewidgetitem82->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem83 = tableWidget_alarm_value->item(21, 0);
        ___qtablewidgetitem83->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem84 = tableWidget_alarm_value->item(21, 1);
        ___qtablewidgetitem84->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem85 = tableWidget_alarm_value->item(22, 0);
        ___qtablewidgetitem85->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem86 = tableWidget_alarm_value->item(22, 1);
        ___qtablewidgetitem86->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem87 = tableWidget_alarm_value->item(23, 0);
        ___qtablewidgetitem87->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem88 = tableWidget_alarm_value->item(23, 1);
        ___qtablewidgetitem88->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem89 = tableWidget_alarm_value->item(24, 0);
        ___qtablewidgetitem89->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem90 = tableWidget_alarm_value->item(24, 1);
        ___qtablewidgetitem90->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem91 = tableWidget_alarm_value->item(25, 0);
        ___qtablewidgetitem91->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem92 = tableWidget_alarm_value->item(25, 1);
        ___qtablewidgetitem92->setText(QApplication::translate("CableDataWidget", "\346\227\240\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        tableWidget_alarm_value->setSortingEnabled(__sortingEnabled1);

        label_35->setText(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256\351\227\264\351\232\224\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("CableDataWidget", "\347\247\222", 0, QApplication::UnicodeUTF8));
        checkBox_alarm_value->setText(QApplication::translate("CableDataWidget", "\350\207\252\345\212\250\350\216\267\345\217\226\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        pushButton_read_alarm_value->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226\346\212\245\350\255\246\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        pushButton_save_alarm_value->setText(QApplication::translate("CableDataWidget", "\344\277\235\345\255\230\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        pushButton_clear_alarm_value->setText(QApplication::translate("CableDataWidget", "\346\270\205\351\231\244\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        tabWidget_data->setTabText(tabWidget_data->indexOf(tab_alarm_value), QApplication::translate("CableDataWidget", "\346\230\276\347\244\272\346\212\245\350\255\246\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("CableDataWidget", "\346\227\266\351\222\237\357\274\232", 0, QApplication::UnicodeUTF8));
        rtcTimingPushButton->setText(QApplication::translate("CableDataWidget", "\346\240\241\346\227\266", 0, QApplication::UnicodeUTF8));
        rtcReadPushButton->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("CableDataWidget", "\347\224\265\346\265\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CableDataWidget", "\351\207\207\346\240\267\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("CableDataWidget", "\347\247\222 ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CableDataWidget", "\347\273\237\350\256\241\345\221\250\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("CableDataWidget", "\345\210\206\351\222\237", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CableDataWidget", "\347\273\237\350\256\241\344\270\252\346\225\260", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("CableDataWidget", "\344\270\252", 0, QApplication::UnicodeUTF8));
        statisticArgumentSetPushButton->setText(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        statisticArgumentReadPushButton->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("CableDataWidget", "\346\270\251\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("CableDataWidget", "\351\207\207\346\240\267\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("CableDataWidget", "\347\247\222 ", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("CableDataWidget", "\347\273\237\350\256\241\345\221\250\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("CableDataWidget", "\345\210\206\351\222\237", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("CableDataWidget", "\347\273\237\350\256\241\344\270\252\346\225\260", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("CableDataWidget", "\344\270\252", 0, QApplication::UnicodeUTF8));
        PushButton_Temp_SetStatisticArgument->setText(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        PushButton_Read_StatisticArgument->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("CableDataWidget", "\347\224\265\346\265\201\351\230\200\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        thresholdTypeComboBox->clear();
        thresholdTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("CableDataWidget", "\344\270\273\347\274\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "A\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "B\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "C\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "N\347\233\270", 0, QApplication::UnicodeUTF8)
        );
        label_13->setText(QApplication::translate("CableDataWidget", "A", 0, QApplication::UnicodeUTF8));
        thresholdSetPushButton->setText(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        thresholdReadPushButton->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("CableDataWidget", "\346\270\251\345\272\246\351\230\200\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_TempThresholdType->clear();
        comboBox_TempThresholdType->insertItems(0, QStringList()
         << QApplication::translate("CableDataWidget", "A\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "B\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "C\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "N\347\233\270", 0, QApplication::UnicodeUTF8)
        );
        label_15->setText(QApplication::translate("CableDataWidget", "\342\204\203", 0, QApplication::UnicodeUTF8));
        pushButton_setTempThreashold->setText(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_readTempThreshold->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("CableDataWidget", "\347\224\265\346\265\201\345\217\230\345\214\226\346\243\200\346\265\213\345\221\250\346\234\237\357\274\232", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("CableDataWidget", "\345\210\206\351\222\237", 0, QApplication::UnicodeUTF8));
        pushButton_Set_CurChangerateCycle->setText(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_Read_CurChangerateCycle->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("CableDataWidget", "\347\224\265\346\265\201\345\217\230\345\214\226\347\216\207\351\230\200\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_CurChangeRate_Threshold->clear();
        comboBox_CurChangeRate_Threshold->insertItems(0, QStringList()
         << QApplication::translate("CableDataWidget", "\344\270\273\347\274\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "A\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "B\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "C\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "N\347\233\270", 0, QApplication::UnicodeUTF8)
        );
        label_39->setText(QApplication::translate("CableDataWidget", "A", 0, QApplication::UnicodeUTF8));
        pushButton_SetCurChangeRate_Threshold->setText(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_ReadCurChangeRate_Threshold->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("CableDataWidget", "\346\214\257\345\212\250\351\230\200\345\200\274\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_Vibate_Threshold->clear();
        comboBox_Vibate_Threshold->insertItems(0, QStringList()
         << QApplication::translate("CableDataWidget", "A\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "B\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "C\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "N\347\233\270", 0, QApplication::UnicodeUTF8)
        );
        label_32->setText(QApplication::translate("CableDataWidget", "\346\254\241/\347\247\222", 0, QApplication::UnicodeUTF8));
        pushButton_SetVibrate_Threshold->setText(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_ReadVibrate_Threshold->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("CableDataWidget", "\346\214\257\345\212\250\347\273\237\350\256\241\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("CableDataWidget", "\347\247\222", 0, QApplication::UnicodeUTF8));
        pushButton_Set_VibrateStatisticTime->setText(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_Read_VibrateStatisticTime->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("CableDataWidget", "CT\345\217\230\346\257\224\357\274\232", 0, QApplication::UnicodeUTF8));
        ctTypeComboBox->clear();
        ctTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("CableDataWidget", "\344\270\273\347\274\206", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "A\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "B\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "C\347\233\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "N\347\233\270", 0, QApplication::UnicodeUTF8)
        );
        ctSetPushButton->setText(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        ctReadPushButton->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("CableDataWidget", "\351\200\232\351\201\223\344\275\277\350\203\275", 0, QApplication::UnicodeUTF8));
        channelTypeComboBox->clear();
        channelTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("CableDataWidget", "\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CableDataWidget", "\346\214\257\345\212\250", 0, QApplication::UnicodeUTF8)
        );
        phaseMainControlbitsCheckBox->setText(QApplication::translate("CableDataWidget", "Main", 0, QApplication::UnicodeUTF8));
        phaseAControlbitsCheckBox->setText(QApplication::translate("CableDataWidget", "A", 0, QApplication::UnicodeUTF8));
        phaseBControlbitsCheckBox->setText(QApplication::translate("CableDataWidget", "B", 0, QApplication::UnicodeUTF8));
        phaseCControlbitsCheckBox->setText(QApplication::translate("CableDataWidget", "C", 0, QApplication::UnicodeUTF8));
        phaseNControlbitsCheckBox->setText(QApplication::translate("CableDataWidget", "N ", 0, QApplication::UnicodeUTF8));
        channelControlSetPushButton->setText(QApplication::translate("CableDataWidget", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        channelControlReadPushButton->setText(QApplication::translate("CableDataWidget", "\350\257\273\345\217\226", 0, QApplication::UnicodeUTF8));
        supperRootOperationPushButton->setText(QApplication::translate("CableDataWidget", "\347\256\241\347\220\206\345\221\230\346\223\215\344\275\234", 0, QApplication::UnicodeUTF8));
        tabWidget_data->setTabText(tabWidget_data->indexOf(tab_para), QApplication::translate("CableDataWidget", "\350\256\276\347\275\256\350\256\276\345\244\207\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CableDataWidget: public Ui_CableDataWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CABLEDATAWIDGET_H
