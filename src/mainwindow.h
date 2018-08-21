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
    void centerOnScreen(void);
    void initializeFunctionButtons(void);
    void menuButtonChanged(QFrame *frame);
    void setNewPage(int index);
    void buttonStyleUpdate(QFrame *frame, bool isChanged);

    QMap<QString, int> map;
    QFrame *lastButtonObject;
    Ui::MainWindow *ui;
    Ui::FrameObjects frObj;
    QDesktopWidget resolution;
    Connections *connection;
    RpmWidget *rpm;


};

#endif // MAINWINDOW_H
