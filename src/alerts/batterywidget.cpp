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

    batteryErrors[0] = "BMS NOT CONNECTED";
    batteryErrors[4] = "BMS NOT CONNECTED";
    batteryErrors[5] = "BMS NOT CONNECTED";
    batteryErrors[6] = "BMS NOT CONNECTED";
    batteryErrors[7] = "BMS NOT CONNECTED";
    batteryErrors[8] = "BMS NOT CONNECTED";
    batteryErrors[9] = "BMS NOT CONNECTED";
    batteryErrors[10] = "BMS NOT CONNECTED";
    batteryErrors[11] = "BMS NOT CONNECTED";
    batteryErrors[12] = "BMS NOT CONNECTED";
    batteryErrors[13] = "BMS NOT CONNECTED";
    batteryErrors[14] = "BMS NOT CONNECTED";
    batteryErrors[15] = "BMS NOT CONNECTED";
}
