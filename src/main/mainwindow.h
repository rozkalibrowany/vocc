/**
 * \class MainWindow
 *
 * \brief
 *
 * This class construct UI window and construct other objects
 *
 *
 * \author $Author: bv $
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2018/09/05 14:16:20 $
 *
 * Contact: karolsiegied@gmail.com
 *
 */

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
#include "rpmwidget.h"
#include "../connections/connections.h"
#include "../alerts/alerts.h"
#include "../settings/settings.h"
#include "../stats/statistics.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// creates a MainWindow
    MainWindow(QWidget *parent = 0);
    /// destructs a MainWindow
    ~MainWindow();

signals:
    /// signal emitted when timer stopped
    void addLapTime(QString);

private:
    /// This method is used to change property of panel LCD objects in MainWindow
    template <typename T> void lcdStyleUpdate(T &widget, quint16 value, quint16 limit, quint16 max, bool isChanged);
    /// This method updates style of type T widget
    template <typename T> void styleUpdate(T *widget, const char* property, bool isChanged);
    /// This method is used to find childs of menu buttons panel
    void buttonStyleUpdate(QFrame &frame, bool isChanged);
    /// This method is used to center the window in screen
    void centerOnScreen(void);
    /// This method is used to connect signals with slots from main buttons
    void initializeFunctionButtons(void);
    /// This method is called to connect other signals and slots
    void initializeSignalsAndSlots(void);
    /// This method is used to create QTimer objects needed for lap timer tool
    void initializeLapTimer(void);
    /// This method is used to create QTimer object for flash timer
    void initializeFlashTimer(void);
    /// In this method we create new QTimer object and set timeout
    void initializeTimerForDateTime(void);
    /// This method is called when page in QStackedWidget is changed
    void menuButtonChanged(QFrame &frame);
    /// This method set new page in UI (for example: alerts, settings, etc..)
    void setNewPage(int index);
    /// This method is called when lap timer button is clicked
    void setLapTimerTime(void);
    /// This method is called to set flashing button
    void setButtonFlashing(QFrame &frame, bool start);
    /// Method called to froze mainwindow data
    void disableDataRefreshing(void);


    bool lapTimerStarted; /// keeps information whether lap timer has started or not
    bool setFlash; /// keeps information whether timer for flashing button started
    int s, m, ms; /// keeps information about lap (minutes, seconds, miliseconds)
    QMap<QString, int> map; /// mapper for menu buttons page index (for example main: 0, settings: 1)
    QFrame *lastButtonObject; /// keeps information about last active pressed object
    QString date, time, lapTime; /// keeps information about time, date and lap time
    QString flashingObject; /// keeps information about flashing object
    QTimer *lapTimer, *sleepTimer, *flashTimer; /// pointers of QTimer class
    QDesktopWidget resolution; /// keeps information about screen resolution
    Ui::MainWindow *ui; /// pointer to UI of MainWindow
    Settings *settings; /// pointer to Settings class
    Alerts *alerts; /// pointer to Alerts class
    Connections *connection; /// pointer to Connections class
    RpmWidget *rpm; /// pointer to RpmWidget class
    Statistics *stats; /// pointer to Statistics class

public slots:
    /// This method is called when connection is established or closed
    void setStateConnectionButton(bool isConnected);
    /// This method is called when new data income
    void updateBatteryCurrent(quint16 current);
    /// This method is called when new data income
    void updateBatteryVoltage(quint16 voltage);
    /// This method is called when new data income
    void updatePower(float power);
    /// This method is called when new data income
    void updateThrottle(quint16 throttle);
    /// This method is called when new data income
    void updateControllerTemp(quint16 temp);
    /// This method is called when new data income
    void updateMotorTemp(quint16 temp);
    /// This method is called when new data income
    void updateAlertsStatus(int err);
    /// This method is called when contrast has changed in Settings class
    void updateBackgroundContrast(int value);
    /// This method is called when font size has changed in Settings class
    void updateFontSize(QString size);

private slots:
    /// This method is called when time has changed
    void setSystemDateSlot(void);
    /// This method is called when start lap timer button was pressed
    void startLapTimerSlot(void);
    /// This method is called when timeout occured
    void updateLapTimerSlot(void);
    /// This method is called when we stop lap timer
    void resetLapTimerSlot(void);
    /// Method called to shutdown system
    void shutdownSystem(void);
    /// Method called to enable main window data refreshing
    void enableDataRefreshing(void);
    void rebootSystem(void);

signals:
    void statsMenuDisabled();
};

#endif // MAINWINDOW_H
