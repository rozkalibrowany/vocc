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
    bool getConnectionStatus();
    void setConnectionStatus(bool value);

private:
    QProcess *process;
    void establishConnection(void);

signals:
    void readyReadStandardOutput();
    void setConnectionStateButton(bool);

public slots:
    void readLine();
    void initializeConnection(void);
    void baudRateChanged(int value);
    void setCanMode(bool mode);
};

#endif // CONNECTIONS_H
