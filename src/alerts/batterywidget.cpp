#include "batterywidget.h"
#include "ui_batterywidget.h"
#include "../common/logger.h"
#include "../settings/settings.h"

#define CLASS_INFO  "battery widget"

BatteryWidget::BatteryWidget(QWidget *parent)
    : QWidget(parent),
      bat(new Ui::BatteryWidget)
{
    LOG (LOG_ALERTS, "%s - in contructor", CLASS_INFO);

    bat->setupUi(this);
    initBatteryErrors();
}


void BatteryWidget::initBatteryErrors(void)
{
    LOG (LOG_ALERTS, "%s - initializing controller errors", CLASS_INFO);

    for (int i = 0; i <= 15; i++) {
        batteryErrors[i] = "BMS UNPLUGGED";
    }
}
