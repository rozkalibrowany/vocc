#include "batterywidget.h"
#include "ui_batterywidget.h"
#include "logger.h"

#define CLASS_INFO  "battery widget"

BatteryWidget::BatteryWidget(QWidget *parent)
    : QWidget(parent),
      bat(new Ui::BatteryWidget)
{
    LOG (LOG_ALERTS, "%s - in contructor", CLASS_INFO);

    bat->setupUi(this);
}
