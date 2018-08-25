#ifndef ALERTS_H
#define ALERTS_H

#include <QObject>
#include <QWidget>
#include <QList>
#include <QFrame>
#include "ledindicator.h"
#include <QMap>

namespace Ui {
    class Alerts;
}

class Alerts : public QWidget
{
    Q_OBJECT

public:
    explicit Alerts(QWidget *parent = 0);
    ~Alerts();

private:
    void initControllerWidget(void);
    void initControllerErrors(void);

    QMap<int, QString> controllerErrors;
    LedIndicator *led;
    QList<QFrame *> ledSlots;
    QList<QString> leds;
    Ui::Alerts *controller;
};

#endif // ALERTS_H
