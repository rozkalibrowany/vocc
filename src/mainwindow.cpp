#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logger.h"
#include <QObject>
#include <string>
#include <QSequentialIterable>
#include <QDateTime>

#define CLASS_INFO          "main window"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    LOG (LOG_MAINWINDOW, "%s - in constructor", CLASS_INFO);

    ui->setupUi(this);
    this->setWindowTitle("ADek UI v0.1");
    this->centerOnScreen();
    lastButtonObject = NULL;
    lapTimerStarted = false;

    /* create connection */
    if (connection != NULL)
        delete connection;
    connection = new Connections();

    /* create Rpm Widget */
    rpm = new RpmWidget(ui->rpm_widget);

    /* set buttons map */
    map["vfMain"] = 0;
    map["vfAlerts"] = 1;
    map["vfStats"] = 2;
    map["vfSettings"] = 3;

    /* initialize functions buttons */
    initializeFunctionButtons();

    /* set system datetime */
    setSystemDate();
    initializeTimerForDateTime();

    /* initialize lap timer */
    initializeLapTimer();

    /* set start page */
    menuButtonChanged(ui->vfMain);

}


MainWindow::~MainWindow()
{
    LOG (LOG_MAINWINDOW, "%s - destructor", CLASS_INFO);

    delete ui;
}


void MainWindow::centerOnScreen(void)
{
   LOG (LOG_MAINWINDOW, "%s - centering on screen", CLASS_INFO);

   this->move((resolution.width()/2) - (this->frameSize().width()/2),
           ((resolution.height()/2) - (this->frameSize().height()/2)));
}


void MainWindow::initializeFunctionButtons(void)
{
    LOG (LOG_MAINWINDOW, "%s - initializing function buttons", CLASS_INFO);

    connect (ui->driveButton, &QPushButton::clicked,
                [this] { menuButtonChanged(ui->vfMain); });
    connect (ui->alertsButton, &QPushButton::clicked,
                [this] { menuButtonChanged(ui->vfAlerts); });
    connect (ui->statsButton, &QPushButton::clicked,
                [this] { menuButtonChanged(ui->vfStats); });
    connect (ui->settingsButton, &QPushButton::clicked,
                [this] { menuButtonChanged(ui->vfSettings); });
}


void MainWindow::initializeLapTimer(void)
{
    LOG (LOG_MAINWINDOW, "%s - initializing lap timer", CLASS_INFO);

    lapTimer = new QTimer(this);
    sleepTimer = new QTimer(this);

    ui->timerButton->setText("Start Timer");

    sleepTimer->setInterval(2500);
    sleepTimer->setSingleShot(true);

    m = ms = s = 0;

    connect (ui->timerButton, &QPushButton::clicked, this, &MainWindow::startLapTimer);
    connect (lapTimer, &QTimer::timeout, this, &MainWindow::updateLapTimer);
    connect (sleepTimer, &QTimer::timeout, this, &MainWindow::resetLapTimer);
}


void MainWindow::initializeTimerForDateTime(void)
{
    LOG (LOG_MAINWINDOW, "%s - current date and time %s, %s", CLASS_INFO, \
         date.toStdString().c_str(), time.toStdString().c_str());

    QTimer *timer = new QTimer(this);
    connect (timer, &QTimer::timeout, this, &MainWindow::setSystemDate);
    timer->start(1000);
}

void MainWindow::menuButtonChanged(QFrame *frame)
{
    LOG (LOG_MAINWINDOW, "%s - initializing function button: %s", CLASS_INFO, \
         frame->objectName().toStdString().c_str());

    if (lastButtonObject == NULL) {
        lastButtonObject = frame;
        setNewPage(map[frame->objectName()]);
        buttonStyleUpdate(frame, true);
        LOG (LOG_MAINWINDOW, "%s - newPage: %d", CLASS_INFO, map[frame->objectName()]);
    } else if (lastButtonObject != frame) {
        setNewPage(map[frame->objectName()]);
        buttonStyleUpdate(frame, true);
        buttonStyleUpdate(lastButtonObject, false);
        lastButtonObject = frame;
    }
}


void MainWindow::buttonStyleUpdate(QFrame *frame, bool isChanged)
{

    LOG (LOG_MAINWINDOW, "%s - %s - %s", CLASS_INFO, Q_FUNC_INFO, \
         frame->objectName().toStdString().c_str());

    QPushButton *iconObject;
    QLabel *textObject;

    frObj.frame = frame;
    iconObject = frame->findChild<QPushButton *>();
    frObj.button = iconObject;
    textObject = frame->findChild<QLabel *>();
    frObj.label = textObject;

    frame->setProperty("chosen", isChanged);
    frame->style()->unpolish(frame);
    frame->style()->polish(frame);
    frame->update();
    iconObject->setProperty("chosen", isChanged);
    iconObject->style()->unpolish(iconObject);
    iconObject->style()->polish(iconObject);
    iconObject->update();
    textObject->setProperty("chosen", isChanged);
    textObject->style()->unpolish(textObject);
    textObject->style()->polish(textObject);
    textObject->update();

}


void MainWindow::buttonStyleUpdate(QPushButton *button, bool isChanged)
{
    LOG (LOG_MAINWINDOW, "%s - %s - %s", CLASS_INFO, Q_FUNC_INFO, \
         button->objectName().toStdString().c_str());

    button->setProperty("clicked", isChanged);
    button->style()->unpolish(button);
    button->style()->polish(button);
    button->update();
}

void MainWindow::setNewPage(int index)
{
    LOG (LOG_MAINWINDOW, "%s - changing page to %d", CLASS_INFO, index);

    ui->stackedWidget->setCurrentIndex(index);
}


void MainWindow::setSystemDate(void)
{
    date = QDate::currentDate().toString("dd-MM-yyyy");
    if (date != NULL)
        ui->dateLabel->setText(date);

    time = QTime::currentTime().toString("hh:mm");
    if (time != NULL)
        ui->timeLabel->setText(time);

}


void MainWindow::setLapTimerTime(void)
{
    lapTime = QString("%1:%2:%3").arg(QString::number(m), QString::number(s), QString::number(ms));
    ui->lcdNumber->setDigitCount(lapTime.length());
    ui->lcdNumber->display(lapTime);
}


void MainWindow::startLapTimer(void)
{
    LOG (LOG_MAINWINDOW, "%s - lap timer started", CLASS_INFO);

    if (!lapTimerStarted) {
        lapTimerStarted = true;
        buttonStyleUpdate(ui->timerButton, true);
        ui->timerButton->setText("Stop Timer");
        lapTimer->start(10);
    } else {
        buttonStyleUpdate(ui->timerButton, false);
        ui->timerButton->setText("Start Timer");
        sleepTimer->start();
        lapTimer->stop();
        lapTimerStarted = false;
    }
}


void MainWindow::updateLapTimer(void)
{
    if (ms < 100)
        ms += 1;
    else {
        if (s < 59) {
            ms = 0;
            s += 1;
        } else if (s == 59 && m < 59) {
            m += 1;
            ms = 0;
            s = 0;
        } else
            lapTimer->stop();
    }

    setLapTimerTime();
}


void MainWindow::resetLapTimer(void)
{
    LOG (LOG_MAINWINDOW, "%s - resetting lap timer", CLASS_INFO);

    s = m = ms = 0;
    setLapTimerTime();
}
