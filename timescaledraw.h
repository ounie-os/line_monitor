#ifndef TIMESCALEDRAW_H
#define TIMESCALEDRAW_H

#include <QDateTime>
#include "qwt_scale_draw.h"

class TimeScaleDraw : public QwtScaleDraw
{
public:
    TimeScaleDraw();
    TimeScaleDraw(const QDateTime &base);
    ~TimeScaleDraw();

    void setBaseTime(QDateTime &base);
    void setTimeShowStyle(QString style);
protected:
    virtual QwtText label(double v) const;
private:
    QDateTime baseTime;
    QString timeShowStyle;
};

#endif // TIMESCALEDRAW_H
