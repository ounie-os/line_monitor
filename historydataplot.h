#ifndef HISTORYDATAPLOT_H
#define HISTORYDATAPLOT_H

#include <QDateTime>
#include <QList>
#include "dataconf.h"
#include "electriccablemetadata.h"

#include "timescaledraw.h"
#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include "qwt_legend.h"
#include "qwt_legend_label.h"
#include "cabledatawidget.h"



class historyDataPlot : public QwtPlot
{
    Q_OBJECT
public:
    explicit historyDataPlot(QWidget *parent = 0);
    ~historyDataPlot();
    void clearChat(void);
signals:
private slots:
    void showCurveItem(const QVariant &itemInfo, bool on, int index);
public slots:
    void setScaleBaseTime(QDateTime time);
    void addDataCurve(QList<CableCurrent> datalist, QString curveTitle, QColor curveColor);
    void clearAllCurves();
private:
    QDateTime baseTime;
    TimeScaleDraw *scale;
    QList<QwtPlotCurve *> curveList;
    QwtLegend *legend;
    QHash<QString,QwtPlotCurve*> *chatList;
};

#endif // HISTORYDATAPLOT_H
