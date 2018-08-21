#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logger.h"
#include <QObject>
#include <string>
#include <QSequentialIterable>

#define CLASS_INFO          "main window"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    LOG (LOG_MAINWINDOW, "%s - in constructor", CLASS_INFO);

    ui->setupUi(this);
    this->setWindowTitle("ADek UI v0.1");
    this->centerOnScreen();
    lastButtonObject = NULL;

    // create connection
    if (connection != NULL)
        delete connection;
    connection = new Connections();

    // create Rpm Widget
    rpm = new RpmWidget(ui->rpm_widget);

    /* set buttons map */
    map["vfMain"] = 0;
    map["vfAlerts"] = 1;
    map["vfStats"] = 2;
    map["vfSettings"] = 3;

    /* initialize functions buttons */
    initializeFunctionButtons();
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


void MainWindow::setNewPage(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}


void MainWindow::buttonStyleUpdate(QFrame *frame, bool isChanged)
{

    LOG (LOG_MAINWINDOW, "%s - %s - obj name %s", CLASS_INFO, Q_FUNC_INFO, \
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
