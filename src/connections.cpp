#include <QStringList>
#include <QByteArrayList>
#include "connections.h"
#include "logger.h"
#include "parameters.h"

#define CLASS_INFO      "connections"

Connections::Connections()
{
    LOG (LOG_CONNECTIONS, "%s - in contructor", CLASS_INFO);
    LOG (LOG_CONNECTIONS, "%s - can baud: %d", CLASS_INFO, canBaud);
}


Connections::~Connections()
{
    LOG (LOG_CONNECTIONS, "%s - in destructor", CLASS_INFO);

    process->close();
    delete process;
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
    delete process;
    emit setConnectionStateButton(getConnectionStatus());
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
            /* read rpm speed */
            lsb = data[0].toUInt(&valid_l, 16);
            msb = data[1].toUInt(&valid_m, 16);
            quint16 rpm = msb*256 + lsb;

    }

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
