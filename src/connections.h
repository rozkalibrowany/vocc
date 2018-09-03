#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QVector>
#include "rpmwidget.h"
#include "alerts/alerts.h"

class Connections : public QObject
{
    Q_OBJECT

public:
    Connections(RpmWidget *m_rpm, Alerts *m_alerts);
    ~Connections();
    bool isConnected;
    bool getConnectionStatus();
    void setConnectionStatus(bool value);

private:
    template <typename T> T calculateAvg(QVector<T> &container, T value, quint16 _size);
    void initializeCan(void);
    void initializeSignalsAndSlots(void);
    void closeConnection(void);
    void establishConnection(void);
    int getCanBaudrate(void);
    QString getCanMode(void);

    bool canMode;
    int canBaud;
    QVector <quint16> avgRpm;
    QVector <quint16> avgCurrent;
    QVector <quint16> avgVoltage;
    QVector <float> avgPower;
    QProcess *process;
    RpmWidget *rpm;
    Alerts *alerts;

signals:
    void enableRadioButtons(bool);
    void readyReadStandardOutput();
    void setConnectionStateButton(bool);
    void setAlertsButtonState(int);
    void updateRpmSpeed(quint16);
    void updateBatteryCurrent(quint16);
    void updateBatteryVoltage(quint16);
    void updatePower(float);
    void updateThrottle(quint16);
    void updateControllerTemp(quint16);
    void updateMotorTemp(quint16);
    void updateAlerts(char[]);

public slots:
    void readLine();
    void initializeConnection(void);
    void baudRateChanged(int value);
    void setCanMode(bool mode);
    void setCanBaudrate(int value);
};

#endif // CONNECTIONS_H
