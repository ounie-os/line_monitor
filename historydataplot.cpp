#include "historydataplot.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_magnifier.h"
#include "qwt_plot_panner.h"
#include <QDebug>

historyDataPlot::historyDataPlot(QWidget *parent) :
    QwtPlot(parent)
{
    this->scale = new TimeScaleDraw();
    this->scale->setTimeShowStyle("yyyy-MM-dd \nhh:mm:ss");

    this->setAxisScaleDraw(QwtPlot::xBottom, this->scale);
    this->setAxisAutoScale(QwtPlot::xBottom);

    this->setAxisAutoScale(QwtPlot::yLeft, true);
    this->setAxisAutoScale(QwtPlot::xBottom, true);

    this->setAxisTitle(QwtPlot::yLeft, tr("Current Value"));

    this->legend = new QwtLegend();
    legend->setDefaultItemMode(QwtLegendData::Checkable);
    this->insertLegend(legend, QwtPlot::RightLegend);

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->enableXMin(true);
    grid->setMajorPen(QPen(Qt::gray, 0 , Qt::DotLine));
    grid->setMinorPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach(this);

    (void)new QwtPlotMagnifier(this->canvas());
    (void)new QwtPlotPanner(this->canvas());

    connect(legend, SIGNAL(checked(QVariant,bool,int)), this, SLOT(showCurveItem(QVariant,bool,int)));
    this->chatList = new QHash<QString,QwtPlotCurve*>();
    this->show();
}

historyDataPlot::~historyDataPlot()
{
    clearChat();
//    delete this->scale;
    delete this->legend;
    delete this->chatList;
}

void historyDataPlot::clearChat()
{
    QHashIterator<QString,QwtPlotCurve*> tmp(*chatList);
    while(tmp.hasNext())
    {
        QString s = tmp.next().key();
        qDebug()<< "清除图"+s;
        this->chatList->value(s)->detach();
        delete  this->chatList->value(s);
        this->chatList->remove(s);
    }
    chatList->clear();
}

void historyDataPlot::showCurveItem(const QVariant &itemInfo, bool on, int index)
{
    QwtPlotItem *item = this->infoToItem(itemInfo);
    if(index <0)
    {
        return;
    }
    if(on)
    {
        item->show();
    }
    else
    {
        item->hide();
    }
    this->replot();

}

void historyDataPlot::setScaleBaseTime(QDateTime time)
{
    this->baseTime = time;
    this->scale->setBaseTime(time);

    this->replot();
}

void historyDataPlot::addDataCurve(QList<electricCableMetaData> datalist, QString curveTitle, QColor curveColor)
{
    if(datalist.length() <= 0)
    {
        qDebug() <<"没有历史数据";
        return;
    }
    if(this->chatList->contains(curveTitle))
    {
    }else
    {
        QwtPlotCurve *curve = new QwtPlotCurve(curveTitle);
        curve->setRenderHint(QwtPlotItem::RenderAntialiased);
        curve->setLegendAttribute(QwtPlotCurve::LegendShowLine, true);
        curve->setPen(QPen(curveColor,3.0));
        curve->setStyle(QwtPlotCurve::Dots);//点形式
        curve->attach(this);
        this->chatList->insert(curveTitle,curve);
        const QVariant iteminfo = itemToInfo(this->itemList(QwtPlotItem::Rtti_PlotCurve).last());
        ((QwtLegendLabel*)(legend->legendWidget(iteminfo)))->setChecked(true);
        this->baseTime = datalist.value(0).time;
        this->setScaleBaseTime(datalist.value(0).time);
    }

    QVector<double> x;
    QVector<double> y;

    for(int i = 0 ; i < datalist.length(); i++)
    {
        int passedSec = this->baseTime.secsTo(datalist.value(i).time);
        x.push_back(passedSec);
        y.push_back(datalist.value(i).value);
    }
    this->chatList->value(curveTitle)->setSamples(x,y);
    this->replot();

}

void historyDataPlot::clearAllCurves()
{
    clearChat();
    this->replot();
}







