#ifndef COMSETTINGDIALOG_H
#define COMSETTINGDIALOG_H

#include <QDialog>
#include "comsetting.h"

namespace Ui {
class comSettingDialog;
}

class comSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit comSettingDialog(QWidget *parent = 0);
    ~comSettingDialog();

    void setupComSetting(comSetting *setting);
    comSetting *getComSetting();

    bool comStatus;
signals:
    void comStatusSignal(bool comStatus);

public slots:
    void comSettingSavePushButtonClickedSlot();
private slots:
    void on_pushButton_comControl_clicked();

private:
    Ui::comSettingDialog *ui;
    comSetting *_setting;
    HKEY hKey;
    wchar_t keyName[256];   //键名数组
    char    keyValue[256];  //键值数组
    wchar_t subkey[80];
    int indexnum;
    DWORD keysize,type,valuesize;

    QString getPortNameWin(int index,QString keyorvalue); //windows下获取portName的方法
};

#endif // COMSETTINGDIALOG_H
