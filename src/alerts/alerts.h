#ifndef ALERTS_H
#define ALERTS_H

#include <QObject>
#include <QWidget>
#include <QList>
#include <QFrame>
#include <QMap>
#include "controllerwidget.h"
#include "batterywidget.h"
#include "ledindicator.h"


class Alerts : public QWidget
{
    Q_OBJECT

public:
    explicit Alerts(QWidget *controllerWidget, QWidget *batteryWidget);
    ~Alerts();

private:

    ControllerWidget *con;
    BatteryWidget *bat;
    LedIndicator *led;
    QList<QFrame *> ledSlots;
    QList<QString> controllerLeds, batteryLeds;

protected:
    void initWidget(QWidget *widget);

};

#endif // ALERTS_H
