#include "alerts.h"
#include "ui_alerts.h"
#include "logger.h"

#define CLASS_INFO  "alerts"


Alerts::Alerts(QWidget *parent) :
    QWidget(parent),
    controller(new Ui::Alerts)
{
    LOG (LOG_RPM, "%s - in contructor", CLASS_INFO);

    controller->setupUi(this);
    this->initControllerWidget();

}

Alerts::~Alerts()
{
    delete controller;
}

void Alerts::initControllerWidget(void)
{
    LOG (LOG_RPM, "%s - initializing controller widget", CLASS_INFO);

    ledSlots = this->findChildren<QFrame *>();
    for (int i = 0; i < ledSlots.size(); ++i) {
        if (ledSlots.at(i) != NULL) {
            bool match = ledSlots.at(i)->objectName().contains("led_err", Qt::CaseSensitive);
//            if (match) {

//            }
        }
    }
}
