#include "connections.h"
#include "logger.h"
#include "parameters.h"

#define CLASS_INFO      "connections"

Connections::Connections()
{
    LOG (LOG_CONNECTIONS, "%s - in contructor", CLASS_INFO);

    process = new QProcess();
    connect(process, &QProcess::readyReadStandardOutput,
            this, &Connections::readLine);

    initializeConnection();
}


Connections::~Connections()
{

}


void Connections::initializeConnection(void)
{
    LOG (LOG_CONNECTIONS, "%s - initializing CAN connection", CLASS_INFO);

    process->kill();
    process->setProcessChannelMode(process->MergedChannels);
    process->start(RUN_LOCAL_CMD);
}


void Connections::readLine()
{
    LOG (LOG_CONNECTIONS, "%s - started reading lines", CLASS_INFO);
    while(process->canReadLine()) {
        LOG (LOG_CONNECTIONS, "%s - data - %s", CLASS_INFO, process->readLine().toStdString().c_str());
    }
}


bool Connections::getConnectionStatus()
{
    return isConnected;
}
