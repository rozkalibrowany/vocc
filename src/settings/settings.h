/**
 * \class Settings
 *
 * \brief
 *
 * This class is used display settings widget
 *
 * \author Karol Siegieda
 *
 * \version 1.0
 *
 * \date 2018/09/05 14:16:20
 *
 * Contact: karolsiegied@gmail.com
 *
 */
#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QString>
#include <QDialog>
#include "progressIndicator.h"
#include "../connections/connections.h"

namespace Ui {
    class Settings;
}


class Settings : public QWidget
{
    Q_OBJECT

public:
    /// constructs Settings object and takes two arguments
    explicit Settings(QWidget *parent, Connections *connection);
    ~Settings();

    /// method that prints message to output console
    void consolePrintMessage(QString msg, int level);
    /// method that reads saved settings from file
    void readConfigFile(void);

public slots:
    /// method called to enable/disable radio buttons pool
    void enableRadioButtons(bool enable);
    /// calls a local method to print message
    void consolePrintExternalMessage(QString msg, int level);

private slots:
    /// check internet connection on timeout
    void checkInternetConnection(void);
    /// reads response (json) from server
    void getResponseFromServer(void);
    /// method called when can baudrate changed
    void onConnectionsCanBaudChange(int value);
    /// method called when clear console button clicked
    void onClearConsoleButtonClicked(void);
    /// method called to enable/disable console output
    void onConnectionsSetConsoleState(int state);
    /// method called to enable/disable CAN data to console
    void onConnectionsSetCanCheckBox(int state);
    /// method called to change can mode
    void onConnectionsSetCanModeToggled(bool mode);
    /// method called to change contrast of GUI backgroud
    void onContrastSliderValueChanged(int value);
    /// method called to restore default settings
    void onSetDefaultsButtonClicked(void);
    /// method called to change font size
    void onFontSizeChanged(int index);
    /// method called when quit button clicked
    void onQuitButtonClicked(void);
    /// method called when shutdown button clicked
    void onShutdownButtonClicked(void);
    /// method called when check updates button clicked
    void checkForUpdates(void);

signals:
    /// signal emitted when can baudrate changed
    void connectionsChangeCanBaud(int);
    /// signal emitted when can mode changed
    void connectionsSetCanMode(bool);
    /// signal emitted when background contrast changed
    void updateBackgroundContrast(int);
    /// signal emitted when font size changed
    void updateFontSize(QString);
    /// signal emitted when CAN data check box changed
    void enableCanToConsole(bool);
    /// signal emitted to close app
    void quitApplication();
    /// signal emitted to shutdown system
    void shutdownSystem();

private:
    /// method which fills canbaud combobox with values
    void connectionsFillCanBaudComboBox(void);
    /// method that connects signals and slots
    void initializeSignalsAndSlots(void);
    /// initializing timers
    void initializeTimers(void);
    /// method that returns console state enable/disable
    bool connectionsGetConsoleState(void);
    /// method that returns can mode state
    bool connectionsGetCanModeState(void);
    /// method that returns current baudrate index
    int connectionsGetCurrentBaudIndex(void);
    /// method that strips and convert QString baudrate to int
    int stripBaudRateToInt(QString baud);
    /// saving file
    void saveConfigFile(void);
    /// set stylesheet
    template <typename T>
    void setWidgetStyleSheet(T &widget, const char* property, bool set);

    int index;
    QProgressIndicator *mPi;
    QString mVersion;
    Connections *con;
    Ui::Settings *settings;
};


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);

    QLabel *mLabel;

private:
    void setButtonStyleSheet(QPushButton &pb);

};

#endif // SETTINGS_H
