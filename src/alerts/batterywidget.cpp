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

    batteryErrors[0] = "Cell balancing failure";
    batteryErrors[1] = "Low SOH of Battery";
    batteryErrors[2] = "Too high voltage";
    batteryErrors[3] = "RESERVED";
    batteryErrors[4] = "Too low voltage";
    batteryErrors[5] = "Internal volts fault";
    batteryErrors[6] = "Too high temperature on cell";
    batteryErrors[7] = "Too low temperature on cell";
    batteryErrors[8] = "RESERVED";
    batteryErrors[9] = "Internal reset";
    batteryErrors[10] = "Charge controller error";
    batteryErrors[11] = "Battery isolation failure";
    batteryErrors[12] = "RESERVED";
    batteryErrors[13] = "RESERVED";
    batteryErrors[14] = "Pre-charge error";
    batteryErrors[15] = "Electrolyte breakdown";
}
