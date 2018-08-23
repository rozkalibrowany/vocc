#ifndef ALERTS_H
#define ALERTS_H

#include <QObject>
#include <QWidget>

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
    Ui::Alerts *controller;
};

#endif // ALERTS_H
