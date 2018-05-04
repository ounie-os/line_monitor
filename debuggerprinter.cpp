#include "debuggerprinter.h"

DebuggerPrinter::DebuggerPrinter(QObject *parent) :
    QObject(parent)
{
}

void DebuggerPrinter::printDebug(QtMsgType type,QString text)
{
    emit this->sendToPrintDevice(type ,text);
}

QString DebuggerPrinter::showByteArray(QByteArray array)
{
    QString showstr;

    for(int i = 0 ; i < array.length(); i++)
    {
        QString str;
        str.sprintf("%.2x ", (quint8)(array.at(i)));
        showstr += str;
    }

    return showstr;
}
