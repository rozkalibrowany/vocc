#include "alerts.h"
#include "ui_alerts.h"

Alerts::Alerts(QWidget *parent) :
    QWidget(parent),
    controller(new Ui::Alerts)
{
    controller->setupUi(this);
}

Alerts::~Alerts()
{
    delete controller;
}
