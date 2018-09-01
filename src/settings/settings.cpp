#include <QStringList>
#include <QStringListModel>
#include <QSize>
#include <QObject>
#include "settings.h"
#include "ui_settings.h"
#include "../logger.h"

#define CLASS_INFO      "settings"

Settings::Settings(QWidget *parent, Connections *connection) :
    QWidget(parent),
    settings(new Ui::Settings)
{
    LOG (LOG_SETTINGS, "%s - in contructor", CLASS_INFO);

    settings->setupUi(this);
    con = connection;
    /* set CAN baud rates */
    connectionsFillCanBaudComboBox();
    /* connect connection signals */
    connectionsInitializeSignals();
    /* enable console output (default) */
    connectionsSetConsoleState(true);
}

Settings::~Settings()
{
    delete settings;
}


void Settings::connectionsFillCanBaudComboBox(void)
{
    LOG (LOG_SETTINGS, "%s - added can baud rates", CLASS_INFO);

    QStringList list;
    QStringListModel *model = new QStringListModel();

    /* add can baudrates */
    list << "125 kbit/s" << "250 kbit/s" << "500 kbit/s" << "1 Mbit/s";
    /* fill QComboBox */
    model->setStringList(list);
    settings->canSpeedCombo->setModel(model);
    /* set default baudrate */
    connectionsSetCurrentBaudIndex(1);
    settings->canSpeedCombo->setCurrentIndex(connectionsGetCurrentBaudIndex());
}

void Settings::connectionsInitializeSignals(void)
{
    LOG (LOG_SETTINGS, "%s - initializing connection settings signals", CLASS_INFO);

    /* signal activated when can baud changed */
    connect (settings->canSpeedCombo, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
                [=](int value) { onConnectionsCanBaudChange(value); });
    /* signal activated when clear console button clicked */
    connect (settings->clearConsoleBtn, &QPushButton::clicked,
                this, &Settings::onClearConsoleButtonClicked);
}


void Settings::connectionsSetConsoleState(bool isChecked)
{
    LOG (LOG_SETTINGS, "%s - console enabled: %s", CLASS_INFO,
            isChecked ? "true" : "false");

    settings->consoleCheck->setChecked(isChecked);
}

bool Settings::connectionsGetConsoleState(void)
{
    return settings->consoleCheck->isChecked();
}


int Settings::connectionsGetCurrentBaudIndex(void)
{
    if (index != -1)
        return index;
}


void Settings::connectionsSetCurrentBaudIndex(int value)
{
    index = value;
}


void Settings::onConnectionsCanBaudChange(int value)
{
    LOG (LOG_SETTINGS, "%s - can baud changed: %s", CLASS_INFO,
            settings->canSpeedCombo->itemText(value).toStdString().c_str());

    LOG (LOG_SETTINGS, "connectionStatus: %d", con->getConnectionStatus());

    /* check whether connection is active */
    if (!con->getConnectionStatus()) {
        emit connectionsChangeCanBaud(value);
        connectionsSetCurrentBaudIndex(value);
        LOG (LOG_SETTINGS, "DUPA1");
    }
    /* if connection is active set old index */
    else {
        consolePrintMessage("Cannot set baudrate while connection is active");
        settings->canSpeedCombo->setCurrentIndex(connectionsGetCurrentBaudIndex());
        LOG (LOG_SETTINGS, "DUPA2");
    }
}


void Settings::onClearConsoleButtonClicked(void)
{
    LOG (LOG_SETTINGS, "%s - cleaning console", CLASS_INFO);

    settings->outputConsole->clear();
}


void Settings::consolePrintMessage(const QString string)
{
    if (connectionsGetConsoleState()) {
        LOG (LOG_SETTINGS, "%s - printing message to output: %s", CLASS_INFO,
                string.toStdString().c_str());
        QString outputMessage;

        outputMessage = "> " + string;
        settings->outputConsole->append(outputMessage);
    }
}
