#include <QStringList>
#include <QStringListModel>
#include <QSize>
#include <QObject>
#include <QTime>
#include <QFile>
#include <QString>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "settings.h"
#include "ui_settings.h"
#include "../common/parameters.h"
#include "../common/logger.h"
#include "../settings/parser.h"


#define CLASS_INFO      "settings"
#define FILE_NAME       "settings.conf"
#define DEF_URL         "http://www.google.com"

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
    initializeSignalsAndSlots();
    /* set default CAN mode (test) */
    settings->testRadioBtn->setChecked(true);
    /* set default output of CAN data */
    settings->canDataCheck->setChecked(false);
    /* set default settings */
    onSetDefaultsButtonClicked();
    /* enable console output (default) */
    onConnectionsSetConsoleState(1);
    /* initialize timers */
    initializeTimers();

}


Settings::~Settings()
{
    LOG (LOG_SETTINGS, "%s - in destructor", CLASS_INFO);

    saveConfigFile();
    conf_exit();
    delete settings;
}


void Settings::connectionsFillCanBaudComboBox(void)
{
    LOG (LOG_SETTINGS, "%s - added can baud rates", CLASS_INFO);

    QStringList list;
    QStringListModel *model = new QStringListModel();

    /* add can baudrates */
    list << "125 kbit/s" << "250 kbit/s" << "500 kbit/s" << "1000 kbit/s";
    /* fill QComboBox */
    model->setStringList(list);
    settings->canBaud->setModel(model);
}


void Settings::initializeSignalsAndSlots(void)
{
    LOG (LOG_SETTINGS, "%s - initializing connection settings signals", CLASS_INFO);

    /* signal activated when message to print appears */
    connect (con, &Connections::printMessage,
                [=](QString msg, int level) { consolePrintExternalMessage(msg,level); });
    /* signal activated when can baud changed */
    connect (settings->canBaud, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
                [=](int value) { onConnectionsCanBaudChange(value); });
    /* signal activated when font size changed */
    connect (settings->fontSizeBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
                [=](int index) { onFontSizeChanged(index); });
    /* signal activated when clear console button clicked */
    connect (settings->clearConsoleBtn, &QPushButton::clicked,
                this, &Settings::onClearConsoleButtonClicked);
    /* signal activated when console check box clicked */
    connect (settings->consoleCheck, &QCheckBox::stateChanged,
                [=](int state) { onConnectionsSetConsoleState(state); });
    /* signal activated when CAN data check box clicked */
    connect (settings->canDataCheck, &QCheckBox::stateChanged,
                [=](int state) { onConnectionsSetCanCheckBox(state); });
    /* signal activated to enable CAN output to console */
    connect (this, &Settings::enableCanToConsole, con,
                [=](bool enable) { con->setCanDataToConsole(enable); });
    /* signal activated when can mode changed */
    connect (settings->convRadioBtn, &QRadioButton::toggled,
                [=](bool checked) { onConnectionsSetCanModeToggled(checked);} );
    /* signal activated when value of background color slider changed */
    connect (settings->colorSlider, &QSlider::valueChanged,
                [=](int value) { onContrastSliderValueChanged(value); });
    /* signal used to set can mode in connections class */
    connect (this, &Settings::connectionsSetCanMode,
                [=](bool mode) { con->setCanMode(mode); });
    /* signal used to set can baudrate in connections class */
    connect (this, &Settings::connectionsChangeCanBaud,
                [=](int value) { con->setCanBaudrate(value); });
    /* signal activated when connection established or closed */
    connect (con, &Connections::enableRadioButtons,
                [=](bool enable) { enableRadioButtons(enable); });
    /* signal activated when set defaults button clicked */
    connect (settings->setDefaultsBtn, &QPushButton::clicked,
                this, &Settings::onSetDefaultsButtonClicked);
    /* signal activated when quit button clicked */
    connect (settings->quitBtn, &QPushButton::clicked,
                this, &Settings::onQuitButtonClicked);
    /* signal activated when shutdown button clicked */
    connect (settings->shutdownBtn, &QPushButton::clicked,
                this, &Settings::onShutdownButtonClicked);

}


void Settings::initializeTimers(void)
{
    QTimer *checkConnection = new QTimer();

    checkConnection->setInterval(5000);
    checkConnection->start();

    connect (checkConnection, &QTimer::timeout,
                this, &Settings::checkInternetConnection);

}


void Settings::enableRadioButtons(bool enable)
{
    LOG (LOG_SETTINGS, "%s - can mode buttons blocked: %s", CLASS_INFO,
            enable ? "false" : "true");

    settings->convRadioBtn->setEnabled(enable);
    settings->testRadioBtn->setEnabled(enable);
}


void Settings::checkInternetConnection(void)
{
    LOG (LOG_SETTINGS, "%s - checking internet connection", CLASS_INFO);

    QNetworkAccessManager name;

    QNetworkRequest req(QUrl(DEF_URL));

    QNetworkReply *reply = name.get(req);

    QEventLoop loop;

    connect (reply, &QNetworkReply::finished,
                &loop, &QEventLoop::quit);

    loop.exec();
    if (reply->bytesAvailable()) {
        LOG (LOG_SETTINGS, "%s - internet connection OK", CLASS_INFO);

        settings->internetIcon->setProperty("connected", true);
        settings->internetIcon->style()->unpolish(settings->internetIcon);
        settings->internetIcon->style()->polish(settings->internetIcon);
        settings->internetIcon->update();
        settings->internetTxt->setText("Internet available");
    } else {
        LOG (LOG_SETTINGS, "%s - NO internet connection", CLASS_INFO);

        settings->internetIcon->setProperty("connected", false);
        settings->internetIcon->style()->unpolish(settings->internetIcon);
        settings->internetIcon->style()->polish(settings->internetIcon);
        settings->internetIcon->update();
        settings->internetTxt->setText("Internet unavailable");
    }

}


/* returns:
 *          0 - TEST mode
 *          1 - CONVERTER mode
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
            mode ? "converter mode" : "test mode");

    /* if connection is inactive change mode*/
    if (!con->getConnectionStatus()) {
        emit connectionsSetCanMode(mode);
        consolePrintMessage("CAN mode changed succesfully", 0);
    }
    /* if connection is active print message */
    else {
        consolePrintMessage("Cannot change mode while connection is active!", 1);
    }
}


void Settings::readConfigFile() 
{
    LOG (LOG_SETTINGS, "%s - reading config file", CLASS_INFO);
    consolePrintMessage("loading settings from config file", 0);

    char *value;

    int key = conf_find_key(GLOBAL, "Output console", NULL);
    int key2 = conf_get_value(key, &value);
    if (key != -1 && key2 != 0)
            onConnectionsSetConsoleState(atoi(value));

    key = conf_find_key(GLOBAL, "Font size", NULL);
    key2 = conf_get_value(key, &value);
    if (key != -1 && key2 != 0) {
        int index = settings->fontSizeBox->findText(value);
        if (index != -1) {
            onFontSizeChanged(index);
            settings->fontSizeBox->setCurrentIndex(index);
        }
    }
    key = conf_find_key(GLOBAL, "Font type", NULL);
    key2 = conf_get_value(key, &value);
    if (key != -1 && key2 != 0) {
    /* TODO */
    }
    key = conf_find_key(GLOBAL, "Background contrast", NULL);
    key2 = conf_get_value(key, &value);
    if (key != -1 && key2 != 0) {
        onContrastSliderValueChanged(atoi(value));
        settings->colorSlider->setValue(atoi(value));
        consolePrintMessage("background contrast", 0);
    }
    key = conf_find_key(GLOBAL, "CAN baudrate", NULL);
    key2 = conf_get_value(key, &value);
    if (key != -1 && key2 != 0) {
        int index = settings->canBaud->findText(value);
        if (index != -1) {
            onConnectionsCanBaudChange(index);
            settings->canBaud->setCurrentIndex(index);
        }
    }
    key = conf_find_key(GLOBAL, "CAN mode", NULL);
    key2 = conf_get_value(key, &value);
    if (key != -1 && key2 != 0) {
        if (strcmp(value, "CONVERTER") == 0) {
            settings->convRadioBtn->setChecked(true);
        } else {
            settings->testRadioBtn->setChecked(true);
        }
    }
    key = conf_find_key(GLOBAL, "Output data", NULL);
    key2 = conf_get_value(key, &value);
    if (key != -1 && key2 != 0)
        onConnectionsSetCanCheckBox(atoi(value));
}


void Settings::saveConfigFile(void)
{
    LOG (LOG_SETTINGS, "%s - saving config file", CLASS_INFO);

    QFile file(FILE_NAME);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream out(&file);

        out << "# File generated automatically by application. Do not make changes.\n";
        out << "\n";
        out << "|Font size| = |" << settings->fontSizeBox->currentText() << "|\n";
        out << "|Font type| = |" << settings->fontTypeBox->currentText() << "|\n";
        out << "|Background contrast| = |" << settings->colorSlider->value() << "|\n";
        out << "|CAN baudrate| = |" << settings->canBaud->currentText() << "|\n";
        if (settings->testRadioBtn->isChecked())
            out << "|CAN mode| = |" << settings->testRadioBtn->text() << "|\n";
        else
            out << "|CAN mode| = |" << settings->convRadioBtn->text() << "|\n";
        out << "|Output console| = |" << settings->consoleCheck->isChecked() << "|\n";
        out << "|Output data| = |" << settings->canDataCheck->isChecked() << "|\n";

        file.close();
    } else {
        LOG (LOG_SETTINGS, "%s - could not save config file", CLASS_INFO);
    }
}


void Settings::onConnectionsSetConsoleState(int state)
{
    LOG (LOG_SETTINGS, "%s - console %s", CLASS_INFO,
            state ? "enabled" : "disabled");

    settings->consoleCheck->setChecked(state);
}


void Settings::onConnectionsSetCanCheckBox(int state)
{
    LOG (LOG_SETTINGS, "%s - CAN data to console %s", CLASS_INFO,
            state ? "enabled" : "disabled");

    settings->canDataCheck->setChecked(state);
    if (state)
        emit enableCanToConsole(true);
    else
        emit enableCanToConsole(false);
}

void Settings::onContrastSliderValueChanged(int value)
{
    LOG (LOG_SETTINGS, "%s - color changed %d", CLASS_INFO, value);

    QString style = "background-color: rgb(%1, %2, %3);";
    settings->gridFrame->setStyleSheet(style.arg(value).arg(value).arg(value));
    emit updateBackgroundContrast(value);
}


void Settings::onSetDefaultsButtonClicked(void)
{
    LOG (LOG_SETTINGS, "%s - restoring default settings", CLASS_INFO);

    settings->colorSlider->setValue(DEFAULT_BACKG_COLOR);
    settings->fontSizeBox->setCurrentIndex(2);
    settings->fontTypeBox->setCurrentIndex(0);
    consolePrintMessage("Default settings restored", 0);
}

void Settings::onFontSizeChanged(int index)
{
    LOG (LOG_SETTINGS, "%s - changing font to - %s", CLASS_INFO,
            settings->fontSizeBox->currentText().toStdString().c_str());

    emit updateFontSize(settings->fontSizeBox->currentText());
    QString size = settings->fontSizeBox->currentText();
    QString style = "font: 75 bold %1pt";
    settings->gridFrame->setStyleSheet(style.arg(size));
    consolePrintMessage("Font size changed", 0);

}


bool Settings::connectionsGetConsoleState(void)
{
    return settings->consoleCheck->isChecked();
}


int Settings::connectionsGetCurrentBaudIndex(void)
{
    return settings->canBaud->currentIndex();
}


void Settings::onConnectionsCanBaudChange(int value)
{
    LOG (LOG_SETTINGS, "%s - can baud changed: %s", CLASS_INFO,
            settings->canBaud->itemText(value).toStdString().c_str());

    /* if connection is inactive change baud rate */
    if (!con->getConnectionStatus()) {
        settings->canBaud->setCurrentIndex(value);
        emit connectionsChangeCanBaud(stripBaudRateToInt(settings->canBaud->currentText()));
        consolePrintMessage("CAN baudrate changed successfully", 0);
    }
    /* if connection is active set old index and print message */
    else {
        settings->canBaud->setCurrentIndex(connectionsGetCurrentBaudIndex());
        consolePrintMessage("Cannot set baudrate while connection is active!", 1);
    }
}


void Settings::onClearConsoleButtonClicked(void)
{
    LOG (LOG_SETTINGS, "%s - cleaning console", CLASS_INFO);

    settings->outputConsole->clear();
}


void Settings::consolePrintMessage(QString msg, int level)
{

    /* printing message to output console */
    if (connectionsGetConsoleState()) {
        LOG (LOG_SETTINGS, "%s - message: %s", CLASS_INFO, msg.toStdString().c_str());

        // TODO : static QString lastMessage = msg;
        QString colorStr;
        /* defining text alerts colors */
        switch(level) {
            case 0: colorStr = "#99ff99"; break; /* green */
            case 1: colorStr = "#ffff99"; break; /* yellow */
            case 2: colorStr = "#ff4d4d"; break; /* red */
            default: colorStr = "#00ffc1"; break;
        }
        QColor color(colorStr);
        QString time = QTime::currentTime().toString("[ hh:mm:ss ] - ");
        settings->outputConsole->setTextColor(color);
        msg = time + msg;
        settings->outputConsole->append(msg);
    }
}


void Settings::consolePrintExternalMessage(QString msg, int level)
{
    consolePrintMessage(msg, level);
}


int Settings::stripBaudRateToInt(QString baud)
{
    QString baudStripped;
    baudStripped = baud.mid(0, baud.indexOf(" "));

    return baudStripped.toInt();

}


void Settings::onQuitButtonClicked(void)
{
    emit quitApplication();
}


void Settings::onShutdownButtonClicked(void)
{
    emit shutdownSystem();
}
