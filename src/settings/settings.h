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
    explicit Settings(QWidget *parent, Connections *connection);
    ~Settings();

public slots:
    void enableRadioButtons(bool enable);

private slots:
    void onConnectionsCanBaudChange(int value);
    void onClearConsoleButtonClicked(void);
    void onConnectionsSetConsoleState(int state);
    void onConnectionsSetCanModeToggled(bool mode);
    void onContrastSliderValueChanged(int value);
    void onSetDefaultsButtonClicked(void);
    void onFontSizeChanged(int index);

signals:
    void connectionsChangeCanBaud(int);
    void connectionsSetCanMode(bool);
    void updateBackgroundContrast(int);
    void updateFontSize(QString);

private:
    void connectionsFillCanBaudComboBox(void);
    void connectionsInitializeSignals(void);
    bool connectionsGetConsoleState(void);
    bool connectionsGetCanModeState(void);
    int connectionsGetCurrentBaudIndex(void);
    void consolePrintMessage(QString string, int level);
    int stripBaudRateToInt(QString baud);

    int index;
    QString lastMessage;
    Connections *con;
    Ui::Settings *settings;
};

#endif // SETTINGS_H
