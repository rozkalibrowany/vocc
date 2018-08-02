#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ADek UI v0.1");
    this->centerOnScreen();

    connected = false;
    process = new QProcess();
    connect(process, &QProcess::readyReadStandardOutput,
                     readLine);
    // RPM WIDGET HERE

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::centerOnScreen(void)
{

   this->move((resolution.width()/2) - (this->frameSize().width()/2),
           ((resolution.height()/2) - (this->frameSize().height()/2)));
}

void MainWindow::readLine()
{

}
