#include <QStringList>
#include <QByteArrayList>
#include "connections.h"
#include "logger.h"
#include "parameters.h"

#define CLASS_INFO      "connections"

Connections::Connections(RpmWidget *m_rpm, Alerts *m_alerts)
{
    LOG (LOG_CONNECTIONS, "%s - in contructor", CLASS_INFO);

    rpm = m_rpm;
    alerts = m_alerts;

    initializeSignalsAndSlots();
}


Connections::~Connections()
{
    LOG (LOG_CONNECTIONS, "%s - in destructor", CLASS_INFO);

    process->close();
    delete process;
}


void Connections::initializeSignalsAndSlots(void)
{
    LOG (LOG_CONNECTIONS, "%s - initializing signals", CLASS_INFO);

    connect (this, &Connections::updateRpmSpeed,
             [=](quint16 speed) { rpm->updateWidget(speed); });

    connect (this, &Connections::updateAlerts,
             [=](char errors[16]) { alerts->updateAlertsState(errors); });
}


void Connections::initializeConnection(void)
{
    LOG (LOG_CONNECTIONS, "%s - initializing connection: %s", CLASS_INFO, isConnected ? "false" : "true");

    if (getConnectionStatus()) {
        closeConnection();
        return;
    }

    process = new QProcess();
    connect(process, &QProcess::readyReadStandardOutput,
            this, &Connections::readLine);
    establishConnection();
}


void Connections::initializeCan(void)
{
    LOG (LOG_CONNECTIONS, "%s - initializing CAN bus", CLASS_INFO);

    QString command;

    QProcess *can = new QProcess();
    command = "ip link set can0 up type can bitrate";
    command = command + " " + canBaud;
    can->start(command);
    /* TODO: check operation status */
}


void Connections::closeConnection(void)
{
    process->close();
    isConnected = false;
    avgRpm.clear();
    avgCurrent.clear();
    avgVoltage.clear();
    delete process;
    emit setConnectionStateButton(getConnectionStatus());
    emit enableRadioButtons(true);
    emit setAlertsButtonState(-1);
}


void Connections::baudRateChanged(int value)
{
    LOG (LOG_CONNECTIONS, "%s - baud rate changed %d", CLASS_INFO, value);
}


void Connections::establishConnection(void)
{
    LOG (LOG_CONNECTIONS, "%s - establishing CAN connection", CLASS_INFO);

    process->setProcessChannelMode(process->MergedChannels);
    process->start(getCanMode());
    if (process->pid() != 0)
        setConnectionStatus(true);
    LOG (LOG_CONNECTIONS, "%s - process PID: %d", CLASS_INFO, process->pid());
    emit setConnectionStateButton(getConnectionStatus());
    emit enableRadioButtons(false);
}


void Connections::readLine()
{
    /* read output (unsplitted line) */
    QByteArray data_Uns(process->readAllStandardOutput().simplified());
    LOG (LOG_CONNECTIONS_DATA, "%s - got line - %s", CLASS_INFO, \
             data_Uns.toStdString().c_str());

    /* split data */
    QString data_s (data_Uns);
    QStringList data(data_s.split(' '));

    if (data[0] != "can0")
        return;

    /* remove first element (interface name - can0) */
    data.removeFirst();

    int lsb, msb;
    bool valid_l, valid_m;

    if (data[0] == MESSAGE_1) {

        /* remove first 2 elements (no of bytes and address */
        for (int i = 0; i <= 1; i++)
            data.removeFirst();
        /* read rpm speed (base 16) */
        lsb = data[0].toUInt(&valid_l, 16);
        msb = data[1].toUInt(&valid_m, 16);
        quint16 rpm = msb*256 + lsb;
        if (valid_l && valid_m) /* update rpm widget (3 samples) */
            emit updateRpmSpeed(calculateAvg(avgRpm, rpm, 3));
        /* read battery current (base 16) */
        lsb = data[2].toUInt(&valid_l, 16);
        msb = data[3].toUInt(&valid_m, 16);
        quint16 current = (msb*256 + lsb)/10;
        if (valid_l && valid_m) /* update current (6 samples) */
            emit updateBatteryCurrent(calculateAvg(avgCurrent, current, 6));
        /* read battery voltage (base 16) */
        lsb = data[4].toUInt(&valid_l, 16);
        msb = data[5].toUInt(&valid_m, 16);
        quint16 voltage = (msb*256 + lsb)/10;
        if (valid_l && valid_m) /* update voltage (5 samples) */
            emit updateBatteryVoltage(calculateAvg(avgVoltage, voltage, 5));
        /* calculate power */
        float power = current * voltage;
        power = power/1000; /* update power (5 samples) */
        emit updatePower(calculateAvg(avgPower, power, 5));

        /* read converter alerts */
        lsb = data[6].toUInt(&valid_l, 16);
        msb = data[7].toUInt(&valid_m, 16);
        char array[16];
        for (int i = 0; i < 8; ++i) {
            array[i] = (lsb >> i) & 1;
            array[i+8] = (msb >> i) & 1;
        }
        if (valid_l && valid_m)
            emit updateAlerts(array);

        LOG (LOG_CONNECTIONS_DATA, "%s - %s - rpm: %d\t current: %d\t voltage: %d\t power: %.2f",
             CLASS_INFO, MESSAGE_1, rpm, current, voltage, power);

    } else if (data[0] == MESSAGE_2) {

        /* remove first 2 elements (no of bytes and address */
        for (int i = 0; i <= 1; i++)
            data.removeFirst();
        /* read throttle signal (base 16) */
        lsb = data[0].toUInt(&valid_l, 16);
        quint16 throttle = lsb/2.55;
        if (valid_l)
            emit updateThrottle(throttle);
        /* read controller temperature (base 16) */
        lsb = data[1].toUInt(&valid_l, 16);
        quint16 controllerTemp = lsb - 40;
        if (valid_l)
            emit updateControllerTemp(controllerTemp);
        /* read motor temperature (base 16) */
        lsb = data[2].toUInt(&valid_l, 16);
        quint16 motorTemp = lsb - 30;
        if (valid_l)
            emit updateMotorTemp(motorTemp);

        LOG (LOG_CONNECTIONS_DATA, "%s - %s - throttle: %d\t cont temp: %d\t motor temp: %d",
             CLASS_INFO, MESSAGE_2, throttle, controllerTemp, motorTemp);
    }
}


template <typename T> T Connections::calculateAvg(QVector<T> &container, T value, quint16 _size)
{
    if (value == 0)
        return 0;

    T avgValue = 0;
    container.resize(_size);

    for (int i = 0 ; i < container.size(); ++i) {
        avgValue = avgValue + container.at(i);
        if (container.at(i) == 0) {
            container.insert(i, value);
            break;
        } else if (i == container.size()-1){
            container.insert(i+1, value);
            container.pop_front();
            break;
        }
    }

    avgValue = avgValue / container.size();

    return avgValue;
}


bool Connections::getConnectionStatus()
{
    return isConnected;
}


QString Connections::getCanMode(void)
{
    LOG (LOG_CONNECTIONS, "%s - CAN mode - %s", CLASS_INFO,
             canMode ? "converter mode" : "test mode");

    if (canMode)
        return RUN_CAN_CMD;
    else
        return RUN_TEST_CMD;
}


void Connections::setCanMode(bool mode)
{
   LOG (LOG_CONNECTIONS, "%s - CAN mode set - %s", CLASS_INFO,
            mode ? "converter mode" : "test mode");

   canMode = mode;
}


int Connections::getCanBaudrate(void)
{
    return canBaud;
}


void Connections::setCanBaudrate(int value)
{
   LOG (LOG_CONNECTIONS, "%s - CAN baud rate - %d", CLASS_INFO, value);

   canBaud = value;

}


void Connections::setConnectionStatus(bool value)
{
    isConnected = value;
}
