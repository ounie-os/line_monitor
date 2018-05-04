#include "trendplot.h"
#include "qwt_legend.h"
#include "qwt_legend_label.h"

#include <QDebug>
trendPlot::trendPlot(QWidget *parent) :
    QwtPlot(parent)
{
    //this->setPalette(QPalette(Qt::black));
    this->baseTime = QDateTime::currentDateTime();
    TimeScaleDraw *scale = new TimeScaleDraw(this->baseTime);
    scale->setTimeShowStyle("yyyy-MM-dd\nhh:mm:ss");
    this->setAxisScaleDraw(QwtPlot::xBottom, scale);
    this->setAxisAutoScale(QwtPlot::xBottom);

    this->setAxisAutoScale(QwtPlot::yLeft, true);
    this->setAxisAutoScale(QwtPlot::xBottom, true);

    this->setAxisTitle(QwtPlot::yLeft, tr("Current Value"));

    this->showPntNumber = 30;

    this->legend = new QwtLegend();
    legend->setDefaultItemMode(QwtLegendData::Checkable);
    this->insertLegend(legend, QwtPlot::RightLegend);

    connect(legend, SIGNAL(checked(QVariant,bool,int)), this, SLOT(showCurveItem(QVariant,bool,int)));
    this->show();
}

trendPlot::~trendPlot()
{
    for(int i = 0 ; i < this->curveList.length(); i++)
    {
        delete this->curveList.value(i);
    }
}

void trendPlot::showCurveItem(const QVariant &itemInfo, bool on, int index)
{
    QwtPlotItem *item = this->infoToItem(itemInfo);

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

void trendPlot::initCurves(int curveCnt, QStringList curveTitleList, QList<QColor> colorList)
{
    for(int i = 0 ; i < curveCnt; i++)
    {
        QwtPlotCurve *curve = new QwtPlotCurve(curveTitleList.value(i));
        curve->setRenderHint(QwtPlotItem::RenderAntialiased);
        curve->setLegendAttribute(QwtPlotCurve::LegendShowLine, true);
        curve->setPen(QPen(colorList.value(i),3.0));
        curve->setStyle(QwtPlotCurve::Dots);//点形式
        curve->attach(this);

        this->curveList.append(curve);
        curveXY curve_xy;
        this->curveXYList.append(curve_xy);

    }

    QwtPlotItemList qwtItems = this->itemList(QwtPlotItem::Rtti_PlotCurve);
    for(int i = 0 ; i < qwtItems.size(); i++)
    {
        const QVariant itemInfo = itemToInfo(qwtItems[i]);
        ((QwtLegendLabel*)(legend->legendWidget(itemInfo)))->setChecked(true);
        ((QwtLegendLabel*)(legend->legendWidget(itemInfo)))->setPalette(QPalette(Qt::white));
    }
}

void trendPlot::addData(int curveNum, QDateTime time, double data)
{
    if(curveNum < 0 || curveNum >= this->curveList.length())
        return;

    int passedSec;
    passedSec = this->baseTime.secsTo(time);

    curveXY curve_xy = this->curveXYList.value(curveNum);

    if(curve_xy.x.size() >= showPntNumber)
    {
        curve_xy.x.pop_front();
        curve_xy.y.pop_front();
    }

    curve_xy.x.push_back(passedSec);
    curve_xy.y.push_back(data);

    this->curveXYList.replace(curveNum, curve_xy);
    this->curveList.value(curveNum)->setSamples(curve_xy.x, curve_xy.y);

    this->replot();
}

void trendPlot::setCurveEnable(int curveNum, bool flag)
{
    if(curveNum < 0 || curveNum >= this->curveList.length())
        return;

    if(flag)
    {
        this->curveList.value(curveNum)->attach(this);
    }
    else
    {
        this->curveList.value(curveNum)->detach();
    }

    this->replot();
}

void trendPlot::clearAllCurves()
{
    for(int i = 0 ; i < this->curveXYList.length(); i++)
    {
        curveXY curve_xy = this->curveXYList.value(i);


        curve_xy.x.clear();
        curve_xy.y.clear();

        this->curveXYList.replace(i, curve_xy);
        this->curveList.value(i)->setSamples(curve_xy.x, curve_xy.y);

    }
    this->replot();
}




