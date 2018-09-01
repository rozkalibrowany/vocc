#include "connections.h"
#include "logger.h"
#include "parameters.h"

#define CLASS_INFO      "connections"

Connections::Connections()
{
    LOG (LOG_CONNECTIONS, "%s - in contructor", CLASS_INFO);

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
        process->close();
        isConnected = false;
        delete process;
        emit setConnectionStateButton(getConnectionStatus());
        return;
    }

    process = new QProcess();
    connect(process, &QProcess::readyReadStandardOutput,
            this, &Connections::readLine);
    establishConnection();
}


void Connections::baudRateChanged(int value)
{
    LOG (LOG_CONNECTIONS, "%s - baud rate changed %d", CLASS_INFO, value);
}
void Connections::establishConnection(void)
{
    LOG (LOG_CONNECTIONS, "%s - establishing CAN connection", CLASS_INFO);

    process->setProcessChannelMode(process->MergedChannels);
    process->start(RUN_LOCAL_CMD);
    if (process->pid() != 0)
        setConnectionStatus(true);
    LOG (LOG_CONNECTIONS, "%s - process PID: %d", CLASS_INFO, process->pid());
    emit setConnectionStateButton(getConnectionStatus());
}


void Connections::readLine()
{
   LOG (LOG_CONNECTIONS_DATA, "%s - got line - ", CLASS_INFO, \
        process->readLine().toStdString().c_str() );

}


bool Connections::getConnectionStatus()
{
    return isConnected;
}


void Connections::setConnectionStatus(bool value)
{
    isConnected = value;
}
