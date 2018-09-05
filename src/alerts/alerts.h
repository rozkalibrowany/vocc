/**
 * \class Alerts
 *
 * \brief
 *
 * This class is used display vehicle alerts state
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
    /**
     * @brief Alerts - construct an object with two widget passed as arguments
     * @param controllerWidget - pointer to QWidget object
     * @param batteryWidget - pointer to QWidget object
     */
    explicit Alerts(QWidget *controllerWidget, QWidget *batteryWidget);
    ~Alerts();

public slots:
    /**
     * @brief updateAlertsState - method that receives data about alerts
     * @param alerts - is a char array
     */
    void updateAlertsState(char alerts[16]);

signals:
    /**
     * @brief setAlertsButtonState - is a signal passing information about number of errors
     */
    void setAlertsButtonState(int);

private:
    ControllerWidget *con; /// - is a pointer of ControllerWidget object
    BatteryWidget *bat; /// - is a pointer of BatteryWidget object
    LedIndicator *led; /// - is a pointer of LedIndicator object
    QList<QFrame *> ledSlots; /// - is a QList object keeping pointers of QFrame objects
    QList<LedIndicator *> controllerLeds, batteryLeds; /// - are a QLists objects keeping pointers of LedIndicator objects

protected:
    /**
     * @brief initWidget - is a method initializing QWidgets
     * @param widget - argument of QWidget
     */
    void initWidget(QWidget *widget);

};

#endif // ALERTS_H
