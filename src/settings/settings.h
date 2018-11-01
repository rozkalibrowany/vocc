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

public slots:
    /// method called to enable/disable radio buttons pool
    void enableRadioButtons(bool enable);
    /// calls a local method to print message
    void consolePrintExternalMessage(QString msg, int level);

private slots:
    /// method called when can baudrate changed
    void onConnectionsCanBaudChange(int value);
    /// method called when clear console button clicked
    void onClearConsoleButtonClicked(void);
    /// method called to enable/disable console output
    void onConnectionsSetConsoleState(int state);
    /// method called to change can mode
    void onConnectionsSetCanModeToggled(bool mode);
    /// method called to change contrast of GUI backgroud
    void onContrastSliderValueChanged(int value);
    /// method called to restore default settings
    void onSetDefaultsButtonClicked(void);
    /// method called to change font size
    void onFontSizeChanged(int index);

signals:
    /**
     * @brief connectionsChangeCanBaud - signal emitted when can baudrate changed
     */
    void connectionsChangeCanBaud(int);
    /**
     * @brief connectionsSetCanMode - signal emitted when can mode changed
     */
    void connectionsSetCanMode(bool);
    /**
     * @brief updateBackgroundContrast - signal emitted when background contrast changed
     */
    void updateBackgroundContrast(int);
    /**
     * @brief updateFontSize - signal emitted when font size changed
     */
    void updateFontSize(QString);

private:
    /**
     * @brief connectionsFillCanBaudComboBox - method which fills canbaud combobox with values
     */
    void connectionsFillCanBaudComboBox(void);
    /**
     * @brief connectionsInitializeSignals - method that connects signals and slots
     */
    void connectionsInitializeSignals(void);
    /**
     * @brief connectionsGetConsoleState - method that returns console state enable/disable
     * @return 0 - disable or 1 - enable
     */
    bool connectionsGetConsoleState(void);
    /**
     * @brief connectionsGetCanModeState - method that returns can mode state
     * @return 0 - disabled or 1 - enabled
     */
    bool connectionsGetCanModeState(void);
    /**
     * @brief connectionsGetCurrentBaudIndex - method that returns current baudrate index
     * @return
     */
    int connectionsGetCurrentBaudIndex(void);

    /**
     * @brief stripBaudRateToInt - method that strips and convert QString baudrate to int
     * @param baud
     * @return
     */
    int stripBaudRateToInt(QString baud);

    int index;
    Connections *con;
    Ui::Settings *settings;
};

#endif // SETTINGS_H
