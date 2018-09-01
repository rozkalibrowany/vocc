#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
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
    int index;

private slots:
    void onConnectionsCanBaudChange(int value);
    void onClearConsoleButtonClicked(void);

signals:
    void connectionsChangeCanBaud(int);

private:
    void connectionsFillCanBaudComboBox(void);
    void connectionsInitializeSignals(void);
    bool connectionsGetConsoleState(void);
    void connectionsSetConsoleState(bool isChecked);
    int connectionsGetCurrentBaudIndex(void);
    void connectionsSetCurrentBaudIndex(int value);
    void consolePrintMessage(const QString string);

    Connections *con;
    Ui::Settings *settings;
};

#endif // SETTINGS_H
