#include <QStringList>
#include <QByteArrayList>
#include <QDir>
#include <QFileInfo>
#include "connections.h"
#include "../common/logger.h"
#include "../common/parameters.h"

#define CLASS_INFO              "connections"
#define DEFAULT_CAN_MODE        0
#define DEFAULT_CAN_BAUD        250000



Connections::Connections(RpmWidget *m_rpm, Alerts *m_alerts)
{
    LOG (LOG_CONNECTIONS, "%s - in contructor", CLASS_INFO);

    rpm = m_rpm;
    alerts = m_alerts;

    initializeSignalsAndSlots();

    /* default CAN settings */
    mCanMode = DEFAULT_CAN_MODE;
    mCanBaud = DEFAULT_CAN_BAUD;

}


Connections::~Connections()
{
    LOG (LOG_CONNECTIONS, "%s - in destructor", CLASS_INFO);

    if (process != NULL) {
        process->close();
        delete process;
    }
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
    LOG (LOG_CONNECTIONS, "%s - %s connection", CLASS_INFO, isConnected ? "closing" : "initializing");

    int exitCode = 0;

    if (getConnectionStatus()) {
        closeConnection();
        LOG (LOG_CONNECTIONS, "%s - connection closed", CLASS_INFO);
        emit printMessage(QString("connection closed"), 1);
        return;
    }

    /* if CAN is in conv mode set iface */
    if (mCanMode)
        exitCode = initializeCanInterface();
    else /* else, initialize pythonic symulation */
        exitCode = initializeSimulation();

    if (exitCode) {
        LOG (LOG_CONNECTIONS, "%s - connection failed", CLASS_INFO);
        emit printMessage(QString("connection failed"), 2);
        return;
    }

    /* create new QProcess object */
    process = new QProcess();

    /* connect output to read by method */
    connect (process, &QProcess::readyReadStandardOutput,
             this, &Connections::readLine);

    establishConnection();

}


int Connections::initializeSimulation(void)
{
    LOG (LOG_CONNECTIONS, "%s - initializing python CAN simulation", CLASS_INFO);

    QString currentPath;

    QDir tmpCurrDir = QDir::current();
    bool dirPresent = tmpCurrDir.cdUp();

    if (dirPresent)
         currentPath = tmpCurrDir.path();
    else {
        LOG (LOG_CONNECTIONS, "%s - cannot find parent directory", CLASS_INFO);
        emit printMessage(QString("Cannot find parent directory"), 2);
        return 1;
    }

    mFilePath = currentPath + "/" + QString::fromUtf8(SIMULATION_FILE);

    QFileInfo checkFile(mFilePath);

    if (checkFile.exists() && checkFile.isFile()) {
        LOG (LOG_CONNECTIONS, "%s - file \"%s\" found", CLASS_INFO,
             mFilePath.toStdString().c_str());
        emit printMessage(QString("File %1 found").arg(mFilePath), 0);
        return 0;
    } else {
        LOG (LOG_CONNECTIONS, "%s - file \"%s\" not found", CLASS_INFO,
             QString::fromUtf8(SIMULATION_FILE).toStdString().c_str());
        emit printMessage(QString("File %1 not found").arg(mFilePath), 2);
        return 1;
    }

}


int Connections::initializeCanInterface(void)
{
    LOG (LOG_CONNECTIONS, "%s - initializing CAN interface", CLASS_INFO);

    QString ifaceCmd;

    QProcess *iface = new QProcess();

    ifaceCmd = QString::fromUtf8(CAN_INIT);
    ifaceCmd = ifaceCmd + " " + QString::number(getCanBaudrate());
    LOG (LOG_CONNECTIONS, "%s - CAN interface command \"%s\"", CLASS_INFO,
         ifaceCmd.toStdString().c_str());
    emit printMessage(QString("CAN interface command \"%1\"").arg(ifaceCmd), 0);

    iface->start(ifaceCmd);
    iface->waitForFinished();
    if (iface->exitCode()){
        QString msg = iface->readAllStandardError();
        LOG (LOG_CONNECTIONS, "%s - ERROR: %s", CLASS_INFO,
             msg.toStdString().c_str());
        emit printMessage(QString("ERROR: %1").arg(msg), 2);
    }

    return iface->exitCode();
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
    emit setAlertsButtonState(0x1A);
}


void Connections::establishConnection(void)
{
    LOG (LOG_CONNECTIONS, "%s - establishing CAN connection", CLASS_INFO);

    process->setProcessChannelMode(process->MergedChannels);
    if (getCanMode() == RUN_CAN_CMD)
        process->start(RUN_CAN_CMD);
    else {
        QString cmd = QString::fromUtf8(PYTHON_CMD) + " " + mFilePath;
        process->start(cmd);
    }
    if (process->pid() != 0) {
        setConnectionStatus(true);
        LOG (LOG_CONNECTIONS, "%s - process PID: %d", CLASS_INFO, process->pid());
        emit printMessage(QString("connection established, PID: %1").arg(process->pid()), 0);
    }
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

    if (data[0] != "can0") {
        LOG (LOG_CONNECTIONS_DATA, "%s - wrong CAN data - %s", CLASS_INFO, \
                 data_s.toStdString().c_str());
        emit printMessage(QString("wrong CAN data: %1").arg(data_s), 2);
        return;
    }

    if (mCanToConsole)
        emit printMessage(QString("Data: %1").arg(data_s), 1);

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
            emit updateRpmSpeed(calculateAvg(avgRpm, rpm, 8));
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


const QString Connections::getCanMode(void)
{
    LOG (LOG_CONNECTIONS, "%s - CAN mode - %s", CLASS_INFO,
             mCanMode ? "converter mode" : "test mode");

    if (mCanMode)
        return RUN_CAN_CMD;
    else
        return PYTHON_CMD;
}


bool Connections::isCanToConsoleEnabled(void)
{
    return mCanToConsole;
}


void Connections::setCanDataToConsole(bool enable)
{
    LOG (LOG_CONNECTIONS, "%s - CAN data to console %s", CLASS_INFO,
             enable ? "enabled" : "disabled");

    mCanToConsole = enable;
}


void Connections::setCanMode(bool mode)
{
   LOG (LOG_CONNECTIONS, "%s - CAN mode set - %s", CLASS_INFO,
            mode ? "converter mode" : "test mode");

   mCanMode = mode;
}


int Connections::getCanBaudrate(void)
{
    return mCanBaud;
}


void Connections::setCanBaudrate(int value)
{
   LOG (LOG_CONNECTIONS, "%s - CAN baud rate - %d", CLASS_INFO, value);

   mCanBaud = value * 1000;

}


void Connections::setConnectionStatus(bool value)
{
    isConnected = value;
}
