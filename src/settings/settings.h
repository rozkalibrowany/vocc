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
#include "../connections.h"

namespace Ui {
    class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Settings - constructs Settings object and takes two arguments
     * @param parent - QWidget parent object
     * @param connection - pointer to Connections object
     */
    explicit Settings(QWidget *parent, Connections *connection);
    ~Settings();

public slots:
    /**
     * @brief enableRadioButtons - method called to enable/disable radio buttons pool
     * @param enable
     */
    void enableRadioButtons(bool enable);

private slots:
    /**
     * @brief onConnectionsCanBaudChange - method called when can baudrate changed
     * @param value - is an int value representing can baudrate
     */
    void onConnectionsCanBaudChange(int value);
    /**
     * @brief onClearConsoleButtonClicked - method called when clear console button clicked
     */
    void onClearConsoleButtonClicked(void);
    /**
     * @brief onConnectionsSetConsoleState - method called to enable/disable console output
     * @param state
     */
    void onConnectionsSetConsoleState(int state);
    /**
     * @brief onConnectionsSetCanModeToggled - method called to change can mode
     * @param mode
     */
    void onConnectionsSetCanModeToggled(bool mode);
    /**
     * @brief onContrastSliderValueChanged - method called to change contrast of GUI backgroud
     * @param value
     */
    void onContrastSliderValueChanged(int value);
    /**
     * @brief onSetDefaultsButtonClicked - method called to restore default settings
     */
    void onSetDefaultsButtonClicked(void);
    /**
     * @brief onFontSizeChanged - method called to change font size
     * @param index
     */
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
     * @brief consolePrintMessage - method that prints message to output console
     * @param string
     * @param level
     */
    void consolePrintMessage(QString string, int level);
    /**
     * @brief stripBaudRateToInt - method that strips and convert QString baudrate to int
     * @param baud
     * @return
     */
    int stripBaudRateToInt(QString baud);

    int index;
    QString lastMessage;
    Connections *con;
    Ui::Settings *settings;
};

#endif // SETTINGS_H
