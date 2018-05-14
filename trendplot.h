#ifndef TRENDPLOT_H
#define TRENDPLOT_H

#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include "qwt_legend.h"
#include "timescaledraw.h"

#include <QDateTime>
#include <QList>
#include <QStringList>

typedef struct
{
    QVector<double> x;
    QVector<double> y;
}curveXY;

class trendPlot : public QwtPlot
{
    Q_OBJECT
public:
    explicit trendPlot(QWidget *parent = 0);
    ~trendPlot();
signals:

private slots:
    void showCurveItem(const QVariant &itemInfo, bool on, int index);
public slots:
    void initCurves(int curveCnt, QStringList curveTitleList, QList<QColor> colorList);
    void addData(int curveNum, QDateTime time, double data);
    void setCurveEnable(int curveNum, bool flag);

    void clearAllCurves();
private:
    QDateTime baseTime;
    int showPntNumber;

    QList<QwtPlotCurve *> curveList;
    QList<curveXY> curveXYList;
    QwtLegend *legend;
};
class trendPlotfz : public QwtPlot
{
    Q_OBJECT
public:
    explicit trendPlotfz(QWidget *parent = 0);
    ~trendPlotfz();
signals:

private slots:
    void showCurveItem(const QVariant &itemInfo, bool on, int index);
public slots:
    void initCurves(int curveCnt, QStringList curveTitleList, QList<QColor> colorList);
    void addData(int curveNum, QDateTime time, double data);
    void setCurveEnable(int curveNum, bool flag);

    void clearAllCurvesfz();
private:
    QDateTime baseTime;
    int showPntNumber;

    QList<QwtPlotCurve *> curveList;
    QList<curveXY> curveXYList;
    QwtLegend *legend;
};

#endif // TRENDPLOT_H
