#include "alerts.h"
#include "ui_alerts.h"
#include "../logger.h"

#define CLASS_INFO  "alerts"


Alerts::Alerts(QWidget *controllerWidget, QWidget *batteryWidget)
{
    LOG (LOG_ALERTS, "%s - in contructor", CLASS_INFO);

    con = new ControllerWidget(controllerWidget);
    bat = new BatteryWidget(batteryWidget);

    initWidget(controllerWidget);
    initWidget(batteryWidget);
}

Alerts::~Alerts()
{
}

void Alerts::initWidget(QWidget *widget)
{
    LOG (LOG_ALERTS, "%s - initializing widget %s", CLASS_INFO, \
         widget->objectName().toStdString().c_str());

    int ledNumber;

    ledSlots = widget->findChildren<QFrame *>();
    for (int i = 0; i < ledSlots.size(); ++i) {
        if (ledSlots.at(i) != NULL) {
            if (ledSlots.at(i)->objectName().contains("led_err", Qt::CaseSensitive)) {
                LOG (LOG_ALERTS, "%s - found %s", CLASS_INFO, \
                     ledSlots.at(i)->objectName().toStdString().c_str());
                /* draw new led */
                led = new LedIndicator(ledSlots.at(i));
                led->setGeometry(20, 0, 30, 30);
                /* add object name to qlist */
                if (widget->objectName() == "controllerWidget")
                    controllerLeds.append(ledSlots.at(i)->objectName());
                else if (widget->objectName() == "batteryWidget")
                    batteryLeds.append(ledSlots.at(i)->objectName());
            } else if (ledSlots.at(i)->objectName().contains("label_err", Qt::CaseSensitive)) {
                LOG (LOG_ALERTS, "%s - found %s", CLASS_INFO, \
                     ledSlots.at(i)->objectName().toStdString().c_str());
                ledNumber = ledSlots.at(i)->objectName().replace("label_err", "").toInt();
                QLabel *label = qobject_cast<QLabel *>(ledSlots.at(i));
                label->setText(con->controllerErrors[ledNumber]);
            }
        }
    }
}



