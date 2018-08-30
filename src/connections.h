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

    bool isConnected;

private:
    QProcess *process;

    void establishConnection(void);
    bool getConnectionStatus();

signals:
    void readyReadStandardOutput();
    void setConnectionState(bool);

public slots:
    void readLine();
    void initializeConnection(void);
};

#endif // CONNECTIONS_H
