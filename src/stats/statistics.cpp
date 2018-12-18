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

    initializeSignalsAndSlots();

    chartUpper = new Chart;
    chartUpper->setTitle("Dynamic Battery Current Data");
    chartUpper->legend()->hide();
    chartUpper->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartView = new QChartView(chartUpper, ui->currentChartWidget);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->layoutCurrentChart->addWidget(chartView);
    chartUpper->setAxisYRange(0, 200);


    chartBottom = new Chart;
    chartBottom->setTitle("Dynamic Battery Voltage Data");
    chartBottom->legend()->hide();
    chartBottom->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartView2 = new QChartView(chartBottom, ui->powerChartWidget);
    chartView2->setRenderHint(QPainter::Antialiasing);
    ui->layoutPowerChart->addWidget(chartView2);
    chartBottom->setAxisYRange(0, 120);
    chartBottom->setPenColor(Qt::green);
}

void Statistics::initializeSignalsAndSlots(void)
{
    connect (con, &Connections::updateBatteryCurrent,
             [=](quint16 value) { chartUpper->updateChart(value); });

    connect (con, &Connections::updateBatteryVoltage,
             [=](quint16 value) { chartBottom->updateChart(value); });
}

Statistics::~Statistics()
{
    LOG (LOG_STATS, "%s - in destructor", CLASS_INFO);

    delete ui;
}


void Statistics::setLapTime(QString lapTime)
{
    LOG (LOG_STATS, "%s - setting lap time - %s", CLASS_INFO,
            lapTime.toStdString().c_str());

    QTableWidgetItem *item = new QTableWidgetItem(lapTime);
    item->setTextAlignment(Qt::AlignCenter);
}
