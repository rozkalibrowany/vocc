#include <QStringList>
#include <QStringListModel>
#include <QSize>
#include <QObject>
#include <QTime>
#include <QString>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDialogButtonBox>
#include "settings.h"
#include "ui_settings.h"
#include "../common/parameters.h"
#include "../common/logger.h"
#include "../settings/parser.h"

#define CLASS_INFO      "settings"
#define FILE_NAME       "settings.conf"
#define TMP_PATH        "/tmp/"
#define APP_REPO        "vocc-0.1.0.tar.gz"
#define MB              1024

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
    /* check internet connection */
    checkInternetConnection();
    /* set updates status label */
    setUpdatesStatusLabel();

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
    /* signal activated when check updates button clicked */
    connect (settings->checkUpdatesBtn, &QPushButton::clicked,
                this, &Settings::checkForUpdates);

}


void Settings::initializeTimers(void)
{
    mCheckConnection = new QTimer();

    mCheckConnection->setInterval(5000);
    mCheckConnection->start();

    connect (mCheckConnection, &QTimer::timeout,
                this, &Settings::checkInternetConnection);

}


void Settings::enableRadioButtons(bool enable)
{
    LOG (LOG_SETTINGS, "%s - can mode buttons blocked: %s", CLASS_INFO,
            enable ? "false" : "true");

    settings->convRadioBtn->setEnabled(enable);
    settings->testRadioBtn->setEnabled(enable);
}


bool Settings::checkInternetConnection(void)
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

        setWidgetStyleSheet(settings->internetIcon, "connected", true);
        settings->internetTxt->setText("Internet available");
        if (!settings->checkUpdatesBtn->isEnabled()) {
            settings->checkUpdatesBtn->setDisabled(false);
            setWidgetStyleSheet(settings->checkUpdatesBtn, "notActive", false);
        }
        return true;
    } else {
        LOG (LOG_SETTINGS, "%s - NO internet connection", CLASS_INFO);

        setWidgetStyleSheet(settings->internetIcon, "connected", false);
        settings->internetTxt->setText("Internet unavailable");
        if (settings->checkUpdatesBtn->isEnabled()) {
            settings->checkUpdatesBtn->setDisabled(true);
            setWidgetStyleSheet(settings->checkUpdatesBtn, "notActive", true);
        }
        return false;
    }

}


void Settings::checkForUpdates(void)
{
    LOG (LOG_SETTINGS, "%s - checking for updates...", CLASS_INFO);

    mPi = new QProgressIndicator(settings->updatesIndicator);

    if (mUpdateStatus == NULL)
        setUpdatesStatusLabel();

    mUpdateStatus->setText("Searching updates...");

    mPi->startAnimation();
    mPi->show();

    if (GIT_VERSION == NULL) {

    } else {
        QNetworkAccessManager name;

        QNetworkRequest req(QUrl(UPDATES_SERVER));

        QEventLoop loop;

        QNetworkReply *reply = name.get(req);

        connect (reply, &QNetworkReply::finished,
                    &loop, &QEventLoop::quit);

        connect (reply, &QNetworkReply::finished,
                    this, &Settings::getResponseFromServer);

        loop.exec();
    }

}


void Settings::getResponseFromServer(void)
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(QObject::sender());

    if (reply->error() != QNetworkReply::NoError) {
        LOG (LOG_SETTINGS, "%s - error connecting to server", CLASS_INFO);
        consolePrintMessage("error connecting to server", 2);
        return;
    }

    LOG (LOG_SETTINGS, "%s - got server response!", CLASS_INFO);
    consolePrintMessage("got server response!", 0);

    reply->deleteLater();

    QString strReply = (QString)reply->readAll();
    /* parse json */
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

    QJsonArray jsonArray = jsonResponse.array();

    foreach (const QJsonValue &value, jsonArray) {
        QJsonObject jsonObj = value.toObject();
        mVersion = jsonObj["name"].toString();
    }

    if (QString::compare(mVersion, GIT_VERSION)) {
        LOG (LOG_SETTINGS, "%s - this is the newest version - %s", CLASS_INFO, mVersion);
        consolePrintMessage(QString("This is the newest version: %1").arg(mVersion), 0);

        //settings->updatesLabel->setText("App is up to date");
    } else {
        LOG (LOG_SETTINGS, "%s - found new version - %s", CLASS_INFO, mVersion);
        consolePrintMessage(QString("Found new app version: %1").arg(mVersion), 0);

        //settings->updatesLabel->setText("Found updates");

        Dialog *dialog = new Dialog(this);
        connect (dialog, &QDialog::finished,
                    [=](int result) { this->onUpdatesDialogResult(result); });
        dialog->show();
        dialog->setWindowTitle("Update info");
        dialog->mLabel->setText(QString("Install new version %1? \n (current is %2)").arg(mVersion).arg(GIT_VERSION));
    }

    mPi->stopAnimation();
    delete mPi;
    mPi = NULL;
}


void Settings::onUpdatesDialogResult(int result)
{
    if (result == QDialog::Accepted) {
        LOG (LOG_SETTINGS, "%s - installing new app version", CLASS_INFO);
        consolePrintMessage("installing new app version", 0);

        if (checkInternetConnection()) {
            QFile file(QString(TMP_PATH) + QString(APP_REPO));
            QUrl url(APP_REPOSITORY);

            mPi = new QProgressIndicator(settings->updatesIndicator);
            mPi->startAnimation();
            mPi->show();

            mCheckConnection->stop();

            if (settings->checkUpdatesBtn->isEnabled()) {
                settings->checkUpdatesBtn->setDisabled(true);
                setWidgetStyleSheet(settings->checkUpdatesBtn, "notActive", true);
            }

            downloadFile(url, file);
        } else {
            checkInternetConnection();
            return;
        }

    } else {
        LOG (LOG_SETTINGS, "%s - installing new app version aborted", CLASS_INFO);
        consolePrintMessage("installing new app version aborted", 1);

        mUpdateStatus->setText("Process aborted");
        return;
    }
}


void Settings::downloadFile(QUrl &url, QFile &file)
{
    LOG (LOG_SETTINGS, "%s - downloading file %s", CLASS_INFO, url.toString().toStdString().c_str());

    QNetworkAccessManager name;

    QNetworkRequest req(url);

    if (!file.open(QIODevice::WriteOnly)) {
        LOG (LOG_SETTINGS, "%s - unable to save the file %s", CLASS_INFO, file.fileName());
        consolePrintMessage(QString("unable to save the file %1").arg(file.fileName()), 2);
        delete &file;
        return;
    }

    QEventLoop loop;

    QNetworkReply *reply = name.get(req);

    connect(reply, &QNetworkReply::sslErrors,
                [=] (QList<QSslError> errors) { this->sslErrors(errors); });

    connect (reply, &QNetworkReply::finished,
                &loop, &QEventLoop::quit);

    connect (reply, &QNetworkReply::readyRead,
                [&file, reply] {
                    LOG (LOG_SETTINGS, "%s - READ SMTH", CLASS_INFO);
                    if (&file) {
                        file.write(reply->readAll());
                    }
                });

    connect (reply, &QNetworkReply::downloadProgress,
                [this](qint64 read, qint64 total) {
                    this->onDownloadProgressUpdate(read, total);
                });

    connect (reply, &QNetworkReply::finished,
                 [this, &file, reply] {

                    LOG (LOG_SETTINGS, "%s - download complete", CLASS_INFO);
                    this->consolePrintMessage("Download complete", 0);

                    mCheckConnection->start();
                    mUpdateStatus->setText("Download complete");
                    mPi->stopAnimation();
                    delete mPi;
                    mPi = NULL;

                    if (reply->error()) {
                        this->consolePrintMessage(reply->errorString(), 2);
                    }

                    file.flush();
                    file.close();

                    reply->deleteLater();
    });

    loop.exec();
}


void Settings::onDownloadProgressUpdate(qint64 read, qint64 total)
{
    int progress;

    progress = read/MB;

    mUpdateStatus->setText(QString("%1 kB downloaded...").arg(progress));
}


void Settings::sslErrors(const QList<QSslError> &sslErrors)
{
    for (const QSslError &error : sslErrors)
       consolePrintMessage(QString("SSL error: %1").arg(error.errorString()), 2);
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


template <typename T>
void Settings::setWidgetStyleSheet(T &widget, const char* property, bool set)
{
    widget->setProperty(property, set);
    widget->style()->unpolish(widget);
    widget->style()->polish(widget);
    widget->update();
}


void Settings::saveConfigFile(void)
{
    LOG (LOG_SETTINGS, "%s - saving config file", CLASS_INFO);

    QFile file(FILE_NAME);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream out(&file);

        out << "# File generated automatically by VOCC. Do not make changes.\n";
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


void Settings::setUpdatesStatusLabel(void)
{
    if (mUpdateStatus == NULL) {
        mUpdateStatus = new QLabel();
        mUpdateStatus->setMinimumWidth(170);
        mUpdateStatus->setAlignment(Qt::AlignCenter);
        settings->statusLayer->addWidget(mUpdateStatus);
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

/* ------------------------------------------ */

Dialog::Dialog(QWidget *parent) : QDialog (parent)
{
    if (parent != NULL)
       resize(parent->width()/3, parent->height()/3);
    setFocusPolicy(Qt::NoFocus);

    QDialogButtonBox *bb = new QDialogButtonBox(
                QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mLabel = new QLabel;
    mLabel->setAlignment(Qt::AlignCenter);
    mLabel->setStyleSheet("QLabel { font: 13pt \"Halvetica\"; }");
    mainLayout->addWidget(mLabel);

    QPushButton *okBtn = bb->button(QDialogButtonBox::Ok);
    okBtn->setAutoDefault(true);
    okBtn->setDefault(true);
    setButtonStyleSheet(*okBtn);

    QPushButton *cnclBtn = bb->button(QDialogButtonBox::Cancel);
    cnclBtn->setAutoDefault(false);
    cnclBtn->setDefault(false);
    setButtonStyleSheet(*cnclBtn);

    mainLayout->addWidget(bb);

    this->setLayout(mainLayout);

    connect (bb, &QDialogButtonBox::accepted,
                this, &QDialog::accept);

    connect (bb, &QDialogButtonBox::rejected,
                this, &QDialog::reject);


}


void Dialog::setButtonStyleSheet(QPushButton &pb)
{
    pb.setStyleSheet("QPushButton { \
                     border: 2px solid #00ffc1; \
                     border-radius: 4px; } \
                      QPushButton:pressed { \
                     border: 4px solid #00ffc1; \
                     border-radius: 4px; }");
    pb.setFixedSize(this->width()/3, this->height()/4.5);
}
