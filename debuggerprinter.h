#ifndef DEBUGGERPRINTER_H
#define DEBUGGERPRINTER_H

#include <QObject>

class DebuggerPrinter : public QObject
{
    Q_OBJECT
public:
    explicit DebuggerPrinter(QObject *parent = 0);
    void printDebug(QtMsgType type, QString text);

    static QString showByteArray(QByteArray array);
signals:
    void sendToPrintDevice(int type, QString text);
public slots:

};

#endif // DEBUGGERPRINTER_H
