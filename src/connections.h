#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include "rpmwidget.h"

class Connections : public QObject
{
    Q_OBJECT

public:
    Connections(RpmWidget *rpm);
    ~Connections();
    bool isConnected;
    bool getConnectionStatus();
    void setConnectionStatus(bool value);

private:

    void initializeCan(void);
    void closeConnection(void);
    void establishConnection(void);
    int getCanBaudrate(void);

    bool canMode;
    int canBaud;
    QProcess *process;
    QString getCanMode(void);
    RpmWidget *mRpm;

signals:
    void readyReadStandardOutput();
    void setConnectionStateButton(bool);
    void updateRpmSpeed(quint16);
    void updateBatteryCurrent(quint16);
    void updateBatteryVoltage(quint16);
    void updatePower(float);

public slots:
    void readLine();
    void initializeConnection(void);
    void baudRateChanged(int value);
    void setCanMode(bool mode);
    void setCanBaudrate(int value);
};

#endif // CONNECTIONS_H
