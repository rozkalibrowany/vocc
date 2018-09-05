#include <QLabel>
#include "alerts.h"
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
    LOG (LOG_ALERTS, "%s - in destructor", CLASS_INFO);

    if (con != NULL)
        delete con;
    if (bat != NULL)
        delete bat;
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
                led->setCheckable(false);
                /* add object names to qlist */
                if (widget->objectName() == "controllerWidget")
                    controllerLeds.append(led);
                else if (widget->objectName() == "batteryWidget")
                    batteryLeds.append(led);

            } else if (ledSlots.at(i)->objectName().contains("label_err", Qt::CaseSensitive)) {

                LOG (LOG_ALERTS, "%s - found %s", CLASS_INFO, \
                     ledSlots.at(i)->objectName().toStdString().c_str());
                if (widget->objectName() == "controllerWidget") {
                    ledNumber = ledSlots.at(i)->objectName().replace("label_err", "").toInt();
                    QLabel *label = qobject_cast<QLabel *>(ledSlots.at(i));
                    label->setText(con->controllerErrors[ledNumber]);
                } else if (widget->objectName() == "batteryWidget") {
                    ledNumber = ledSlots.at(i)->objectName().replace("label_err", "").toInt();
                    QLabel *label = qobject_cast<QLabel *>(ledSlots.at(i));
                    label->setText(bat->batteryErrors[ledNumber]);
                }
            }
        }
    }
}


void Alerts::updateAlertsState(char alerts[16])
{
    int it = 0, n_err = 0;

    for (int i = 0; i < 16; ++i) {
        if (con->controllerErrors[i] != "RESERVED") {
            if (alerts[i] == '0') { /* found errors */
                controllerLeds.at(it)->setCheckable(true);
                controllerLeds.at(it)->setChecked(false);
                controllerLeds.at(it)->setDown(false);
                batteryLeds.at(it)->setCheckable(true);
                batteryLeds.at(it)->setChecked(false);
                batteryLeds.at(it)->setDown(false);
                n_err++;
            } else { /* did not found errors */
                controllerLeds.at(it)->setCheckable(true);
                controllerLeds.at(it)->setChecked(true);
                controllerLeds.at(it)->setDown(true);
                batteryLeds.at(it)->setCheckable(true);
                batteryLeds.at(it)->setChecked(true);
                batteryLeds.at(it)->setDown(true);
            }
            it++;
        }
    }
    emit setAlertsButtonState(n_err);

    if (n_err > 0)
        LOG (LOG_ALERTS, "%s - found %d alerts!", CLASS_INFO, n_err);

}

