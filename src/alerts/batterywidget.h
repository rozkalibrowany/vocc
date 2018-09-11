/**
 * \class BatteryWidget
 *
 * \brief
 *
 * This class is used to display battery alerts (as QWidget)
 *
 * \author Karol Siegieda
 *
 * \version 1.0
 *
 * \date 2018/09/05 14:16:20
 *
 * Contact: karolsiegied@gmail.com
 *
 */
#ifndef BATTERYWIDGET_H
#define BATTERYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QMap>

namespace Ui {
class BatteryWidget;
}

class BatteryWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief BatteryWidget - construct ControllerWidget object
     * @param parent - parent QWidget
     */
    explicit BatteryWidget(QWidget *parent = 0);

    QMap<int, QString> batteryErrors; /// - container that keeps error description

private:
    /**
     * @brief initBatteryErrors - method used to map battery errors
     */
    void initBatteryErrors(void);
    Ui::BatteryWidget *bat; /// - pointer to UI object
};

#endif // BATTERYWIDGET_H
