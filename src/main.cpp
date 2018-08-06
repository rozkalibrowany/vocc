#include "mainwindow.h"
#include <QApplication>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int c;
    while ((c = getopt(argc, argv, "lh")) != -1) {
        switch (c) {
        case 'h':
            qDebug() << "Usage: \n" << "h - help \n" \
                     << "l - debug level \n";
            break;
        case 'l':
            qDebug() << "Debug level";
            break;
        }
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
