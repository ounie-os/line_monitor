#-------------------------------------------------
#
# Project created by QtCreator 2017-07-27T15:13:54
#
#-------------------------------------------------

QT       += core gui network sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HCCMonitor_1.1
TEMPLATE = app

#win32:LIBS += C:/Qwt-6.1.2/lib/libqwtd.a
#win32:QMAKE_POST_LINK = copy /Y C:\Qwt-6.1.2\lib\qwtd.dll $(DESTDIR)

#win32:LIBS += C:/Qwt-6.1.2/lib/libqwt.a
#win32:QMAKE_POST_LINK = copy /Y C:\Qwt-6.1.2\lib\qwt.dll $(DESTDIR)

CONFIG   += qwt
CONFIG   += qaxcontainer
DEFINES += QT_DLL QWT_DLL
#LIBS += -L"D:\Qt\4.8.6\lib" -lqwtd
LIBS += -L"D:\Qt\4.8.6\lib" -lqwt
INCLUDEPATH += D:\Qt\Qwt-6.1.2\include
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#VERSION = 0.1.3.1203
RC_FILE = myapp.rc

SOURCES += \
    cablehistorydatawidget.cpp \
    cabledatawidget.cpp \
    comsetting.cpp \
    comsettingdialog.cpp \
    comthread.cpp \
    debuggerprinter.cpp \
    main.cpp \
    monitormainwindow.cpp \
    qextserialbase.cpp \
    tcpserverdevice.cpp \
    tcpsocketdevice.cpp \
    win_qextserialport.cpp \
    deviceregisterdialog.cpp \
    deviceidtype.cpp \
    cablemonitordevice.cpp \
    comprotocol.cpp \
    electriccablemetadata.cpp \
    databasemanager.cpp \
    channelinfotype.cpp \
    timescaledraw.cpp \
    trendplot.cpp \
    historydataplot.cpp \
    hcnetmetadata.cpp \
    hcsystemmappingregisterdialog.cpp \
    hcsystemnetconfigdialog.cpp \
    apirequestserver.cpp \
    apirequestsocket.cpp \
    tcpclienttype.cpp \
    savetoserver.cpp \
    export_execel.cpp \
    dialog_inputpassword.cpp \
    dialog_versions.cpp \
    dialog_set_interval_time.cpp

FORMS += \
    cabledatawidget.ui \
    cablehistorydatawidget.ui \
    comsettingdialog.ui \
    deviceregisterdialog.ui \
    monitormainwindow.ui \
    hcsystemmappingregisterdialog.ui \
    hcsystemnetconfigdialog.ui \
    dialog_inputpassword.ui \
    dialog_versions.ui \
    dialog_set_interval_time.ui

DISTFILES += \
    config.ini \
    ICON.rc

RC_FILE = ICON.rc

HEADERS += \
    cabledatawidget.h \
    cablehistorydatawidget.h \
    comsetting.h \
    comsettingdialog.h \
    comthread.h \
    debuggerprinter.h \
    monitormainwindow.h \
    myhelper.h \
    qextserialbase.h \
    tcpserverdevice.h \
    tcpsocketdevice.h \
    win_qextserialport.h \
    deviceregisterdialog.h \
    deviceidtype.h \
    cablemonitordevice.h \
    comprotocol.h \
    dataconf.h \
    electriccablemetadata.h \
    databasemanager.h \
    channelinfotype.h \
    timescaledraw.h \
    trendplot.h \
    historydataplot.h \
    hcnetmetadata.h \
    hcsystemmappingregisterdialog.h \
    hcsystemnetconfigdialog.h \
    apirequestserver.h \
    apirequestsocket.h \
    tcpclienttype.h \
    savetoserver.h \
    export_execel.h \
    dialog_inputpassword.h \
    dialog_versions.h \
    myapp.rc \
    dialog_set_interval_time.h \
    ui_cabledatawidget.h \
    ui_cablehistorydatawidget.h \
    ui_comsettingdialog.h \
    ui_deviceregisterdialog.h \
    ui_dialog_inputpassword.h \
    ui_dialog_set_interval_time.h \
    ui_dialog_versions.h \
    ui_hcsystemmappingregisterdialog.h \
    ui_hcsystemnetconfigdialog.h \
    ui_monitormainwindow.h

RESOURCES += \
    qr.qrc
