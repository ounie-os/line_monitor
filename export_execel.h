#ifndef EXPORT_EXECEL_H
#define EXPORT_EXECEL_H
#include <QThread>
#include <QAxObject>
#include <QDir>
class Export_Execel : public QThread
{
    Q_OBJECT
public:
    explicit Export_Execel(QObject *parent = 0);
    ~Export_Execel();
private slots:
    void export_data(int row,QString path,QStringList list_data);
private:
    int row;
    QString path;
    QStringList list_data;
};
#endif // EXPORT_EXECEL_H
