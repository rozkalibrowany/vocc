#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QObject>
#include <QDebug>
#include <QFrame>
#include <QList>
#include <QPushButton>
#include <QString>
#include <QTimer>
#include "connections.h"
#include "rpmwidget.h"
#include "alerts/alerts.h"
#include "settings/settings.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    template <typename T> void lcdStyleUpdate(T *widget, quint16 value, quint16 limit, quint16 max, bool isChanged);
    void buttonStyleUpdate(QFrame *frame, bool isChanged);
    void centerOnScreen(void);
    void initializeFunctionButtons(void);
    void initializeLapTimer(void);
    void initializeTimerForDateTime(void);
    void menuButtonChanged(QFrame *frame);
    void setNewPage(int index);
    void setLapTimerTime(void);

    bool lapTimerStarted;
    int s, m, ms;
    QMap<QString, int> map;
    QFrame *lastButtonObject;
    QString date, time, lapTime;
    QTimer *lapTimer, *sleepTimer;
    QDesktopWidget resolution;
    Ui::MainWindow *ui;  
    Settings *settings;
    Alerts *alerts;
    Connections *connection;
    RpmWidget *rpm;

protected:
    template <typename T> void buttonStyleUpdate(T *widget, const char* property, bool isChanged);

public slots:
    void setStateConnectionButton(bool isConnected);
    void updateBatteryCurrent(quint16 current);
    void updateBatteryVoltage(quint16 voltage);
    void updatePower(float power);
    void updateThrottle(quint16 throttle);
    void updateControllerTemp(quint16 temp);
    void updateMotorTemp(quint16 temp);

private slots:
    void setSystemDateSlot(void);
    void startLapTimerSlot(void);
    void updateLapTimerSlot(void);
    void resetLapTimerSlot(void);

};

#endif // MAINWINDOW_H
