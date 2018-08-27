#include "controllerwidget.h"
#include "ui_controllerwidget.h"
#include "../logger.h"

#define CLASS_INFO  "controller widget"

ControllerWidget::ControllerWidget(QWidget *parent)
    : QWidget(parent),
      con(new Ui::ControllerWidget)
{
    LOG (LOG_ALERTS, "%s - in contructor", CLASS_INFO);

    con->setupUi(this);
    initControllerErrors();

}

void ControllerWidget::initControllerErrors(void)
{
    LOG (LOG_ALERTS, "%s - initializing controller errors", CLASS_INFO);

    controllerErrors[0] = "Identification error";
    controllerErrors[1] = "Over Voltage";
    controllerErrors[2] = "Low Voltage";
    controllerErrors[3] = "RESERVED";
    controllerErrors[4] = "Motor provice speed feedback";
    controllerErrors[5] = "Internal volts fault";
    controllerErrors[6] = "Over temperature";
    controllerErrors[7] = "Throttle error at power-up";
    controllerErrors[8] = "RESERVED";
    controllerErrors[9] = "Internal reset";
    controllerErrors[10] = "Hall throttle open";
    controllerErrors[11] = "Angle sensor open";
    controllerErrors[12] = "RESERVED";
    controllerErrors[13] = "RESERVED";
    controllerErrors[14] = "Motor over temperature";
    controllerErrors[15] = "Hall Galvanometer sensor error";
}
