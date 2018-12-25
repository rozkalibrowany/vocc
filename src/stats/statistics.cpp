#include "statistics.h"
#include "ui_statistics.h"
#include "../common/logger.h"
#include <QTableWidgetItem>
#include <QStyle>
#include <QString>

#define CLASS_INFO          "stats"
#define MAX_CURRENT         200
#define MAX_POWER           30
#define MAX_THROTTLE        100
#define MAX_VOLTAGE         110
#define MAX_TEMP            100
#define MAX_RPM             6000

Statistics::Statistics(QWidget *parent, Connections *connection) :
    QWidget(parent),
    ui(new Ui::Statistics)
{
    LOG (LOG_STATS, "%s - in constructor", CLASS_INFO);

    ui->setupUi(this);
    con = connection;

    lastUpperButtonObject = NULL;
    lastBottomButtonObject = NULL;

    initializeButtonSignals();

    chartUpper = new Chart;
    chartUpper->legend()->hide();
    chartUpper->setAnimationOptions(QChart::AllAnimations);
    viewUpper = new QChartView(chartUpper, ui->currentChartWidget);
    viewUpper->setRenderHint(QPainter::Antialiasing, true);
    ui->layoutCurrentChart->addWidget(viewUpper);
    chartUpper->setTheme(QChart::ChartThemeDark);
    chartUpper->setPenWidth(4);

    chartBottom = new Chart;
    chartBottom->legend()->hide();
    chartBottom->setAnimationOptions(QChart::AllAnimations);
    viewBottom = new QChartView(chartBottom, ui->powerChartWidget);
    viewBottom->setRenderHint(QPainter::Antialiasing, true);
    ui->layoutPowerChart->addWidget(viewBottom);
    chartBottom->setTheme(QChart::ChartThemeDark);
    chartBottom->setPenWidth(4);

}

void Statistics::initializeButtonSignals(void)
{
    LOG (LOG_STATS, "%s - initializing function buttons", CLASS_INFO);

    connect (ui->currentChartBtn, &QPushButton::clicked, this,
                [=] { chartButtonChanged(*ui->currentChartBtn); });
    connect (ui->currentChartBtn, &QPushButton::clicked, this,
                [=] { switchUpperChartData(*ui->currentChartBtn); });

    connect (ui->powerChartBtn, &QPushButton::clicked, this,
                [=] { chartButtonChanged(*ui->powerChartBtn); });
    connect (ui->powerChartBtn, &QPushButton::clicked, this,
                [=] { switchUpperChartData(*ui->powerChartBtn); });

    connect (ui->throttleChartBtn, &QPushButton::clicked, this,
                [=] { chartButtonChanged(*ui->throttleChartBtn); });
    connect (ui->throttleChartBtn, &QPushButton::clicked, this,
                [=] { switchUpperChartData(*ui->throttleChartBtn); });

    connect (ui->voltageChartBtn, &QPushButton::clicked, this,
                [=] { chartButtonChanged(*ui->voltageChartBtn); });
    connect (ui->voltageChartBtn, &QPushButton::clicked, this,
                [=] { switchBottomChartData(*ui->voltageChartBtn); });

    connect (ui->tempChartBtn, &QPushButton::clicked, this,
                [=] { chartButtonChanged(*ui->tempChartBtn); });
    connect (ui->tempChartBtn, &QPushButton::clicked, this,
                [=] { switchBottomChartData(*ui->tempChartBtn); });

    connect (ui->rpmChartBtn, &QPushButton::clicked, this,
                [=] { chartButtonChanged(*ui->rpmChartBtn); });
    connect (ui->rpmChartBtn, &QPushButton::clicked, this,
                [=] { switchBottomChartData(*ui->rpmChartBtn); });


}

void Statistics::chartButtonChanged(QPushButton &button)
{
    if ( !QString::compare(button.objectName(), "currentChartBtn") ||
         !QString::compare(button.objectName(), "powerChartBtn") ||
         !QString::compare(button.objectName(), "throttleChartBtn")) {
        if (lastUpperButtonObject == NULL) {
            lastUpperButtonObject = &button;
            styleUpdate(&button, true);
        } else if (lastUpperButtonObject != &button) {
            styleUpdate(&button, true);
            styleUpdate(lastUpperButtonObject, false);
            lastUpperButtonObject = &button;
        }
    } else {
        if (lastBottomButtonObject == NULL) {
            lastBottomButtonObject = &button;
            styleUpdate(&button, true);
        } else if (lastBottomButtonObject != &button) {
            styleUpdate(&button, true);
            styleUpdate(lastBottomButtonObject, false);
            lastBottomButtonObject = &button;
        }
    }
}

void Statistics::switchUpperChartData(QPushButton &button)
{
    LOG (LOG_STATS, "%s - switched upper chart data to %s", CLASS_INFO,
         button.objectName().toStdString().c_str());

    if (!mEnableChartData)
        return;

    if (QObject::disconnect(con, 0, chartUpper, 0))
        LOG (LOG_STATS, "%s - disconnected upper chart data", CLASS_INFO);

    if (!QString::compare(button.objectName(), "currentChartBtn")) {
        chartUpper->setTitle("Dynamic Battery Current Data [A]");
        chartUpper->setAxisYRange(0, MAX_CURRENT);

        connect (con, &Connections::updateBatteryCurrent, chartUpper,
                 [=] (quint16 value) { chartUpper->updateChart(value); });
    } else if (!QString::compare(button.objectName(), "powerChartBtn")) {
        chartUpper->setTitle("Dynamic Battery Power Data [kW]");
        chartUpper->setAxisYRange(0, MAX_POWER);

        connect (con, &Connections::updatePower, chartUpper,
                 [=] (quint16 value) { chartUpper->updateChart(value); });
    } else {
        chartUpper->setTitle("Dynamic Throttle Data [%]");
        chartUpper->setAxisYRange(0, MAX_THROTTLE);

        connect (con, &Connections::updateThrottle, chartUpper,
                 [=] (quint16 value) { chartUpper->updateChart(value); });
    }

}

void Statistics::switchBottomChartData(QPushButton &button)
{
    LOG (LOG_STATS, "%s - switched bottom chart data to %s", CLASS_INFO,
         button.objectName().toStdString().c_str());

    if (!mEnableChartData)
        return;

    if (QObject::disconnect(con, 0, chartBottom, 0))
        LOG (LOG_STATS, "%s - disconnected upper chart data", CLASS_INFO);

    if (!QString::compare(button.objectName(), "voltageChartBtn")) {
        chartBottom->setTitle("Dynamic Battery Voltage Data [V]");
        chartBottom->setAxisYRange(0, MAX_VOLTAGE);

        connect (con, &Connections::updateBatteryVoltage, chartBottom,
                 [=] (quint16 value) { chartBottom->updateChart(value); });
    } else if (!QString::compare(button.objectName(), "tempChartBtn")) {
        chartBottom->setTitle("Dynamic Controller Temperatures Data [C]");
        chartBottom->setAxisYRange(0, MAX_TEMP);

        connect (con, &Connections::updateControllerTemp, chartBottom,
                 [=] (quint16 value) { chartBottom->updateChart(value); });
    } else {
        chartBottom->setTitle("Dynamic Motor Speed Data [rpm]");
        chartBottom->setAxisYRange(0, MAX_RPM);

        connect (con, &Connections::updateRpmSpeed, chartBottom,
                 [=] (quint16 value) { chartBottom->updateChart(value); });
    }
}

void Statistics::styleUpdate(QPushButton *button, bool isChanged)
{

    LOG (LOG_STATS, "%s - %s - %s", CLASS_INFO, Q_FUNC_INFO, \
         button->objectName().toStdString().c_str());

    button->setProperty("chosen", isChanged);
    button->style()->unpolish(button);
    button->style()->polish(button);
    button->update();

}

void Statistics::enableChartData(void)
{
    LOG (LOG_STATS, "%s - connected chart data", CLASS_INFO);

    mEnableChartData = true;

//    connect (con, &Connections::updateBatteryCurrent, chartUpper,
//             [=] (quint16 value) { chartUpper->updateChart(value); });

//    connect (con, &Connections::updateBatteryVoltage, chartBottom,
//             [=] (quint16 value) { chartBottom->updateChart(value); });

}

void Statistics::disableChartData(void)
{
    LOG (LOG_STATS, "%s - disconnected chart data", CLASS_INFO);

    if (QObject::disconnect(con, 0, chartUpper, 0))
        LOG (LOG_STATS, "%s - disconnected upper chart data", CLASS_INFO);
    if (QObject::disconnect(con, 0, chartBottom, 0))
        LOG (LOG_STATS, "%s - disconnected bottom chart data", CLASS_INFO);

    mEnableChartData = false;

}

Statistics::~Statistics()
{
    LOG (LOG_STATS, "%s - in destructor", CLASS_INFO);

    delete ui;
}
