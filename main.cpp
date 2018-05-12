#include "monitormainwindow.h"
#include <QApplication>
#include "debuggerprinter.h"
#include "electriccablemetadata.h"
Q_DECLARE_METATYPE(electricCableMetaData)
DebuggerPrinter printer;
void outputMessage(QtMsgType type, const char *msg)
{
    static QMutex mutex;
    mutex.lock();
    printer.printDebug(type, QString(msg));
    mutex.unlock();
}

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("./plugins");
    QApplication a(argc, argv);
    qRegisterMetaType<electricCableMetaData>("electricCableMetaData");
    qRegisterMetaType<electricCableMetaData>("electricCableMetaData&");
    qRegisterMetaType<CableCurrent>("CableCurrent");
    qRegisterMetaType<CableCurrent>("CableCurrent&");
    myHelper::SetUTF8Code();
    myHelper::SetPlastiqueStyle();
    MonitorMainWindow w;
    QObject::connect(&printer, SIGNAL(sendToPrintDevice(int,QString)), &w, SLOT(printDebug(int,QString)));
    qInstallMsgHandler(outputMessage);
    w.init();
    w.show();
//    qDebug() << QString("main thread id:") << QThread::currentThreadId();
    return a.exec();
}
