#include "chart.h"
#include <QtCharts>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_step(0),
    m_x(80),
    m_y(1),
    cnt(0),
    chartSensitivity(3)
{
    m_series = new QSplineSeries(this);
    pen.setColor(QColor(74,178,143));
    pen.setWidth(4);
    m_series->setPen(pen);
    m_series->append(m_x, m_y);

    addSeries(m_series);

    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_axisX->setTickCount(15);
    m_axisX->setRange(0, 100);
    m_axisY->setRange(-5, 10);
}

Chart::~Chart()
{

}

void Chart::setAxisXRange(qreal min, qreal max)
{
    m_axisX->setRange(min, max);
}

void Chart::setAxisYRange(qreal min, qreal max)
{
    m_axisY->setRange(min, max);
}

void Chart::setPenColor(QColor color)
{
    pen.setColor(color);
    m_series->setPen(pen);
}

void Chart::setPenWidth(int width)
{
    if (width > 0) {
        pen.setWidth(width);
        m_series->setPen(pen);
    }
}

void Chart::setChartSensitivity(int value)
{
    chartSensitivity = value;
}

void Chart::updateChart(qreal value)
{
    if (cnt != chartSensitivity) {
        cnt++;
        return;
    } else {
        cnt = 0;
        qreal x = plotArea().width() / m_axisX->tickCount();
        qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
        m_x += y;
        m_y = value;
        m_series->append(m_x, m_y);
        scroll(x, 0);
//        if (m_x == 100)
//            m_timer.stop();
    }
}


