#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QObject>
#include <QDebug>
#include <QFrame>
#include <QList>
#include <QPushButton>
#include "connections.h"
#include "rpmwidget.h"
#include <QMetaType>
#include <QString>
#include <QTimer>

namespace Ui {
    class MainWindow;

    struct FrameObjects
    {
        QFrame *frame;
        QPushButton *button;
        QLabel *label;
    };
}

Q_DECLARE_METATYPE(Ui::FrameObjects)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void buttonStyleUpdate(QFrame *frame, bool isChanged);
    void buttonStyleUpdate(QPushButton *button, bool isChanged);
    void centerOnScreen(void);
    void initializeFunctionButtons(void);
    void initializeLapTimer(void);
    void initializeTimerForDateTime(void);
    void menuButtonChanged(QFrame *frame);
    void setNewPage(int index);
    void setLapTimerTime(void);

    bool lapTimerStarted;
    int s, m, ms;
    QMap<QString, int> map;
    QFrame *lastButtonObject;
    QString date, time, lapTime;
    QTimer *lapTimer, *sleepTimer;
    Ui::MainWindow *ui;
    Ui::FrameObjects frObj;
    QDesktopWidget resolution;
    Connections *connection;
    RpmWidget *rpm;

private slots:
    void setSystemDate(void);
    void startLapTimer(void);
    void updateLapTimer(void);
    void resetLapTimer(void);

};

#endif // MAINWINDOW_H
