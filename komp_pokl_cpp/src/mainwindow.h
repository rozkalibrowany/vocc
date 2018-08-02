#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QProcess>
#include <QObject>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void centerOnScreen(void);

    bool connected;

    Ui::MainWindow *ui;
    QDesktopWidget resolution;
    QProcess *process;
private slots:
    static void readLine();
};

#endif // MAINWINDOW_H
