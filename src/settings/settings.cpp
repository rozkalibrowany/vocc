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
    lastMessage = "";

    /* set CAN baud rates */
    connectionsFillCanBaudComboBox();
    /* connect connection signals */
    connectionsInitializeSignals();
    /* enable console output (default) */
    onConnectionsSetConsoleState(1);
    /* set default CAN mode (test) */
    settings->testRadioBtn->setChecked(true);

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
    /* signal activated when console check box clicked */
    connect (settings->consoleCheck, &QCheckBox::stateChanged,
                [=](int state) { onConnectionsSetConsoleState(state); });
    /* signal activated when can mode changed */
    connect (settings->convRadioBtn, &QRadioButton::toggled,
                [=](bool checked) { onConnectionsSetCanModeToggled(checked);} );
    /* signal used to set can mode in connections class */
    connect (this, &Settings::connectionsSetCanMode,
                [=](bool mode) { con->setCanMode(mode); });
}


/* returns:
 *          0 - CONVERTER MODE
 *          1 - TEST mode_t
 */
bool Settings::connectionsGetCanModeState(void)
{
    if (settings->testRadioBtn->isChecked())
        return 1;
    else
        return 0;
}


void Settings::onConnectionsSetCanModeToggled(bool mode)
{
    LOG (LOG_SETTINGS, "%s - CAN mode changed: %s", CLASS_INFO,
            mode ? "test mode" : "converter mode");

    emit connectionsSetCanMode(mode);
    consolePrintMessage("CAN mode changed succesfully", 0);
}


void Settings::onConnectionsSetConsoleState(int state)
{
    LOG (LOG_SETTINGS, "%s - console enabled: %s", CLASS_INFO,
            state ? "true" : "false");

    settings->consoleCheck->setChecked(state);
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

    /* check whether connection is inactive */
    if (!con->getConnectionStatus()) {
        emit connectionsChangeCanBaud(value);
        connectionsSetCurrentBaudIndex(value);
        consolePrintMessage("Baud rate changed successfully", 0);
    }
    /* if connection is active set old index */
    else {
        settings->canSpeedCombo->setCurrentIndex(connectionsGetCurrentBaudIndex());
        consolePrintMessage("Cannot set baudrate while connection is active!", 1);
    }
}


void Settings::onClearConsoleButtonClicked(void)
{
    LOG (LOG_SETTINGS, "%s - cleaning console", CLASS_INFO);

    settings->outputConsole->clear();
}


void Settings::consolePrintMessage(QString string, int level)
{

    /* printing message to output console */
    if (connectionsGetConsoleState()) {
        LOG (LOG_SETTINGS, "%s - message: %s", CLASS_INFO,
                string.toStdString().c_str());

        lastMessage = string;
        QString colorStr;
        /* defining text alerts colors */
        switch(level) {
            case 0: colorStr = "#99ff99"; break; /* green */
            case 1: colorStr = "#ffff99"; break; /* yellow */
            case 2: colorStr = "#ff4d4d"; break; /* red */
            default: colorStr = "#00ffc1"; break;
        }
        QColor color(colorStr);
        settings->outputConsole->setTextColor(color);
        string = "> " + string;
        settings->outputConsole->append(string);
    }
}
