#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <QObject>
#include <QProcess>
#include <QDebug>

class Connections : public QObject
{
    Q_OBJECT

public:
    Connections();
    ~Connections();

private:
    QProcess *process;

    bool isConnected;

    bool getConnectionStatus();

signals:
    void readyReadStandardOutput();

public slots:
    void readLine();
};

#endif // CONNECTIONS_H
