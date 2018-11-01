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

    /// is a method providing information whether connection is established or not
    bool getConnectionStatus();
    /// is a setter method changing value of isConnected property
    void setConnectionStatus(bool value);

private:
    /// is a method calculating average value of container
    template <typename T> T calculateAvg(QVector<T> &container, T value, quint16 _size);
    /// is a method initializing CAN bus interface
    int initializeCanInterface(void);
    /// is a method initializing signals and slots
    void initializeSignalsAndSlots(void);
    /// initializes pythonic can simulation
    int initializeSimulation(void);
    /// is a method for killing QProcess and closing connection
    void closeConnection(void);
    /// is a method that establish connection
    void establishConnection(void);
    /// method that provides information about current can baudrate
    int getCanBaudrate(void);
    /// method that provides information about current can mode
    const QString getCanMode(void);
    /// method that returns information about CAN data check box
    bool isCanToConsoleEnabled(void);

    bool mCanToConsole; /// - enable/disable output CAN data to console
    QString mFilePath; /// - keeps the path of python can simulation file
    bool mCanMode; /// - keeps an information about can mode (0-Converter, 1-Simulation)
    int mCanBaud; /// - keeps an information about can baudrate (125, 250, 500, 1000 kbit/s)
    QVector <quint16> avgRpm; /// - container that keeps samples of rpm value
    QVector <quint16> avgCurrent; /// - container that keeps samples of current
    QVector <quint16> avgVoltage; /// - container that keeps samples of voltage
    QVector <float> avgPower; /// - container that keeps samples of power
    QProcess *process; /// - pointer of QProcess class
    RpmWidget *rpm; /// - pointer of RpmWidget class
    Alerts *alerts; /// - pointer of Alerts class

signals:
    /// signal emitted when connection closed or before establishing connection
    void enableRadioButtons(bool);
    /// signal emitted when standard output data is ready to read
    void readyReadStandardOutput();
    /// signal emitted when >Connect< button clicked
    void setConnectionStateButton(bool);
    /// signal emitted when alerts data icome
    void setAlertsButtonState(int);
    /// signal emitted when rpm data income
    void updateRpmSpeed(quint16);
    /// signal emitted when battery current data icome
    void updateBatteryCurrent(quint16);
    /// signal emitted when battery voltage data income
    void updateBatteryVoltage(quint16);
    /// signal emitted when power data income
    void updatePower(float);
    /// signal emitted when throttle data income
    void updateThrottle(quint16);
    /// signal emitted when controller temp data income
    void updateControllerTemp(quint16);
    /// signal emitted when motor temp data income
    void updateMotorTemp(quint16);
    /// signal emitted when alerts data income
    void updateAlerts(char[]);
    /// signal emitted when connection error appears
    void printMessage(QString, int);

public slots:
    /// method called when data is ready to read
    void readLine();
    /// method called when >Connect< button clicked
    void initializeConnection(void);
    /// method called when can mode changed
    void setCanMode(bool mode);
    /// method called to set can baudrate
    void setCanBaudrate(int value);
    /// method called to enable/disable CAN data output to console
    void setCanDataToConsole(bool enable);

};

#endif // CONNECTIONS_H
