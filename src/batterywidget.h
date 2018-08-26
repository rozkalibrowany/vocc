#ifndef BATTERYWIDGET_H
#define BATTERYWIDGET_H

#include <QObject>
#include <QWidget>

namespace Ui {
class BatteryWidget;
}

class BatteryWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BatteryWidget(QWidget *parent = 0);

private:
    Ui::BatteryWidget *bat;
};

#endif // BATTERYWIDGET_H
