#ifndef CABLEHISTORYDATAWIDGET_H
#define CABLEHISTORYDATAWIDGET_H

#include <QWidget>
#include <QDateTime>
#include "deviceidtype.h"
#include "dataconf.h"
#include "cablemonitordevice.h"
#include "electriccablemetadata.h"
#include "databasemanager.h"
#include "QDebug"

namespace Ui {
class cableHistoryDataWidget;
}

class cableHistoryDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit cableHistoryDataWidget(QWidget *parent = 0);
    ~cableHistoryDataWidget();

private:
    Ui::cableHistoryDataWidget *ui;
};

#endif // CABLEHISTORYDATAWIDGET_H
