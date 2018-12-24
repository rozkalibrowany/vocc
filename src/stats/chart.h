#ifndef CHART_H
#define CHART_H

#include <QtCharts>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE


class Chart: public QChart
{
    Q_OBJECT
public:
    Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    virtual ~Chart();

    void setAxisXRange(qreal min, qreal max);
    void setAxisYRange(qreal min, qreal max);
    void updateChart(qreal value);
    void setPenColor(QColor color);
    void setPenWidth(int width);
    void setChartSensitivity(int value);

private:
    int chartSensitivity, cnt;
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_step;
    qreal m_x;
    qreal m_y;
    QPen pen;
};

#endif /* CHART_H */
