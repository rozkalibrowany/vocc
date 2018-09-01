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
    int index;

private slots:
    void onConnectionsCanBaudChange(int value);
    void onClearConsoleButtonClicked(void);
    void onConnectionsSetConsoleState(int state);
    void onConnectionsSetCanMode(bool mode);

signals:
    void connectionsChangeCanBaud(int);

private:
    void connectionsFillCanBaudComboBox(void);
    void connectionsInitializeSignals(void);
    bool connectionsGetConsoleState(void);
    bool connectionsGetCanModeState(void);
    int connectionsGetCurrentBaudIndex(void);
    void connectionsSetCurrentBaudIndex(int value);
    void consolePrintMessage(QString string, int level);

    QString lastMessage;
    Connections *con;
    Ui::Settings *settings;
};

#endif // SETTINGS_H
