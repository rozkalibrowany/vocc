#include "statistics.h"
#include "ui_statistics.h"
#include "../common/logger.h"
#include <QTableWidgetItem>

#define CLASS_INFO      "stats"


Statistics::Statistics(QWidget *parent, Connections *connection) :
    QWidget(parent),
    ui(new Ui::Statistics)
{
    LOG (LOG_STATS, "%s - in constructor", CLASS_INFO);

    ui->setupUi(this);
    con = connection;

    chartUpper = new Chart;
    chartUpper->setTitle("Dynamic Battery Current Data");
    chartUpper->legend()->hide();
    chartUpper->setAnimationOptions(QChart::AllAnimations);
    viewUpper = new QChartView(chartUpper, ui->currentChartWidget);
    viewUpper->setRenderHint(QPainter::Antialiasing, true);
    ui->layoutCurrentChart->addWidget(viewUpper);
    chartUpper->setAxisYRange(0, 200);
    chartUpper->setTheme(QChart::ChartThemeDark);
    chartUpper->setPenWidth(4);

    chartBottom = new Chart;
    chartBottom->setTitle("Dynamic Battery Voltage Data");
    chartBottom->legend()->hide();
    chartBottom->setAnimationOptions(QChart::AllAnimations);
    viewBottom = new QChartView(chartBottom, ui->powerChartWidget);
    viewBottom->setRenderHint(QPainter::Antialiasing, true);
    ui->layoutPowerChart->addWidget(viewBottom);
    chartBottom->setAxisYRange(0, 120);
    chartBottom->setTheme(QChart::ChartThemeDark);
    chartBottom->setPenWidth(4);

}

void Statistics::enableChartData(void)
{
    LOG (LOG_STATS, "%s - connected chart data", CLASS_INFO);

    connect (con, &Connections::updateBatteryCurrent, chartUpper,
             [=] (quint16 value) { chartUpper->updateChart(value); });

    connect (con, &Connections::updateBatteryVoltage, chartBottom,
             [=] (quint16 value) { chartBottom->updateChart(value); });

}

void Statistics::disableChartData(void)
{
    LOG (LOG_STATS, "%s - disconnected chart data", CLASS_INFO);

    if (QObject::disconnect(con, 0, chartUpper, 0))
        LOG (LOG_STATS, "%s - disconnected upper chart data", CLASS_INFO);
    if (QObject::disconnect(con, 0, chartBottom, 0))
        LOG (LOG_STATS, "%s - disconnected bottom chart data", CLASS_INFO);

}

Statistics::~Statistics()
{
    LOG (LOG_STATS, "%s - in destructor", CLASS_INFO);

    delete ui;
}
