#ifndef ALERTS_H
#define ALERTS_H

#include <QObject>
#include <QWidget>
#include <QList>
#include <QFrame>
#include "ledindicator.h"

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

    LedIndicator *led;
    QList<QFrame *> ledSlots;
    Ui::Alerts *controller;
};

#endif // ALERTS_H
