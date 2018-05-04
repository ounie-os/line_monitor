#include "cablehistorydatawidget.h"
#include "ui_cablehistorydatawidget.h"

cableHistoryDataWidget::cableHistoryDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cableHistoryDataWidget)
{
    ui->setupUi(this);
}

cableHistoryDataWidget::~cableHistoryDataWidget()
{
    delete ui;
}
