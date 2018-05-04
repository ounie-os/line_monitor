#include "timescaledraw.h"

TimeScaleDraw::TimeScaleDraw()
{
    this->baseTime = QDateTime::currentDateTime();
    this->timeShowStyle = "hh:mm:ss";
}

TimeScaleDraw::TimeScaleDraw(const QDateTime &base)
{
    this->baseTime = base;
}

TimeScaleDraw::~TimeScaleDraw()
{

}

void TimeScaleDraw::setBaseTime(QDateTime &base)
{
    this->baseTime = base;
}

void TimeScaleDraw::setTimeShowStyle(QString style)
{
    this->timeShowStyle = style;
}

QwtText TimeScaleDraw::label(double v) const
{
    QDateTime upTime = baseTime.addSecs((int)v);

    return upTime.toString(timeShowStyle);
}
