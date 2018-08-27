#include "connections.h"
#include "logger.h"

#define CLASS_INFO      "connections"

Connections::Connections()
{
    process = new QProcess();
    connect(process, &QProcess::readyReadStandardOutput,
            this, &Connections::readLine);
}


Connections::~Connections()
{

}


/* Function to read input from source */
void Connections::readLine()
{
    qDebug() << "Started reading lines";
    while(process->canReadLine()) {
        qDebug() << process->readLine();
    }
}

bool Connections::getConnectionStatus()
{
    return isConnected;
}
