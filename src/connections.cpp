#include "connections.h"
#include "logger.h"
#include "parameters.h"

#define CLASS_INFO      "connections"

Connections::Connections()
{
    LOG (LOG_CONNECTIONS, "%s - in contructor", CLASS_INFO);

    isConnected = false;
}


Connections::~Connections()
{
    delete process;
}


void Connections::initializeConnection(void)
{
    LOG (LOG_CONNECTIONS, "%s - initializing connection: %s", CLASS_INFO, isConnected ? "false" : "true");

    if (isConnected) {
        process->close();
        isConnected = false;
        delete process;
        emit setConnectionState(isConnected);
        return;
    }

    process = new QProcess();
    connect(process, &QProcess::readyReadStandardOutput,
            this, &Connections::readLine);
    establishConnection();
}


void Connections::establishConnection(void)
{
    LOG (LOG_CONNECTIONS, "%s - establishing CAN connection", CLASS_INFO);

    process->setProcessChannelMode(process->MergedChannels);
    process->start(RUN_LOCAL_CMD);
    if (process->pid() != 0)
        isConnected = true;
    LOG (LOG_CONNECTIONS, "%s - process PID: %d", CLASS_INFO, process->pid());
    emit setConnectionState(isConnected);
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
