#include "chart.h"
#include <QtCharts>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

static int cnt = 0;

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_step(0),
    m_x(75),
    m_y(1)
{
    m_series = new QSplineSeries(this);
    pen.setColor(Qt::red);
    pen.setWidth(3);
    m_series->setPen(pen);
    m_series->append(m_x, m_y);

    addSeries(m_series);

    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_axisX->setTickCount(20);
    m_axisX->setRange(0, 80);
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

void Chart::updateChart(qreal value)
{
    if (cnt != 4) {
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


