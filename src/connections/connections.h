/**
 * \class Connections
 *
 * \brief
 *
 * This class is used to provide communication via Controlled Area Network
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

#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QVector>
#include "../main/rpmwidget.h"
#include "../alerts/alerts.h"

class Connections : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Connections - creates an object of Connection class
     * @param m_rpm - is pointer to RpmWidget object
     * @param m_alerts - is pointer to Alerts object
     */
    Connections(RpmWidget *m_rpm, Alerts *m_alerts);
    ~Connections();

    bool isConnected; /// - keeps information whether connection is established or not
    /**
     * @brief getConnectionStatus - is a method providing information whether connection is established or not
     * @return - returns a bool value
     */
    bool getConnectionStatus();
    /**
     * @brief setConnectionStatus - is a setter method changing value of isConnected property
     * @param value - is a bool value
     */
    void setConnectionStatus(bool value);

private:
    /**
     * @brief calculateAvg - is a method calculating average value of container
     */
    template <typename T> T calculateAvg(QVector<T> &container, T value, quint16 _size);
    /**
     * @brief initializeCan - is a method initializing system CAN bus
     */
    void initializeCan(void);
    /**
     * @brief initializeSignalsAndSlots - is a method initializing signals and slots
     */
    void initializeSignalsAndSlots(void);
    /**
     * @brief closeConnection - is a method for killing QProcess and closing connection
     */
    void closeConnection(void);
    /**
     * @brief establishConnection - is a method that establish connection
     */
    void establishConnection(void);
    /**
     * @brief getCanBaudrate - method that provides information about current can baudrate
     * @return
     */
    int getCanBaudrate(void);
    /**
     * @brief getCanMode - method that provides information about current can mode
     * @return
     */
    QString getCanMode(void);

    bool canMode; /// - keeps an information about can mode (0-Converter, 1-Simulation)
    int canBaud; /// - keeps an information about can baudrate (125, 250, 500, 1000 kbit/s)
    QVector <quint16> avgRpm; /// - container that keeps samples of rpm value
    QVector <quint16> avgCurrent; /// - container that keeps samples of current
    QVector <quint16> avgVoltage; /// - container that keeps samples of voltage
    QVector <float> avgPower; /// - container that keeps samples of power
    QProcess *process; /// - pointer of QProcess class
    RpmWidget *rpm; /// - pointer of RpmWidget class
    Alerts *alerts; /// - pointer of Alerts class

signals:
    /**
     * @brief enableRadioButtons - signal emitted when connection closed or before establishing connection
     */
    void enableRadioButtons(bool);
    /**
     * @brief readyReadStandardOutput - signal emitted when standard output data is ready to read
     */
    void readyReadStandardOutput();
    /**
     * @brief setConnectionStateButton - signal emitted when >Connect< button clicked
     */
    void setConnectionStateButton(bool);
    /**
     * @brief setAlertsButtonState - signal emitted when alerts data icome
     */
    void setAlertsButtonState(int);
    /**
     * @brief updateRpmSpeed - signal emitted when rpm data income
     */
    void updateRpmSpeed(quint16);
    /**
     * @brief updateBatteryCurrent - signal emitted when battery current data icome
     */
    void updateBatteryCurrent(quint16);
    /**
     * @brief updateBatteryVoltage - signal emitted when battery voltage data income
     */
    void updateBatteryVoltage(quint16);
    /**
     * @brief updatePower - signal emitted when power data income
     */
    void updatePower(float);
    /**
     * @brief updateThrottle - signal emitted when throttle data income
     */
    void updateThrottle(quint16);
    /**
     * @brief updateControllerTemp- signal emitted when controller temp data income
     */
    void updateControllerTemp(quint16);
    /**
     * @brief updateMotorTemp - signal emitted when motor temp data income
     */
    void updateMotorTemp(quint16);
    /**
     * @brief updateAlerts - signal emitted when alerts data income
     */
    void updateAlerts(char[]);

public slots:
    /**
     * @brief readLine - method called when data is ready to read
     */
    void readLine();
    /**
     * @brief initializeConnection - method called when >Connect< button clicked
     */
    void initializeConnection(void);
    /**
     * @brief baudRateChanged - method called when can baud rate changed
     * @param value - is an int value
     */
    void baudRateChanged(int value);
    /**
     * @brief setCanMode - method called when can mode changed
     * @param mode - is an bool value (0 - Converter mode, 1 - simulation mode)
     */
    void setCanMode(bool mode);
    /**
     * @brief setCanBaudrate - method called to set can baudrate
     * @param value - is an int value
     */
    void setCanBaudrate(int value);
};

#endif // CONNECTIONS_H
