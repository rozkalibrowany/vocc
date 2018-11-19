#include <QApplication>
#include <unistd.h>
#include <stdio.h>
#include <cstdarg>

#include "main/mainwindow.h"
#include "common/logger.h"
#include "main/rpmwidget.h"

#define     BUF_LEN         255
#define     EXIT_FAILURE    1
int gLogMask;

int main(int argc, char *argv[])
{
    int opt;

    while ((opt = getopt(argc, argv, "hl:")) != -1) {
        switch (opt) {
        case 'h':
            qDebug() << "Usage: \n\t" << "-h\t  - help \n\t" \
                     << "-l <arg> - debug level \n\t\t" << "LOG_MAIN \t\t 0x0001\n\t\t" \
                     << "LOG_GUI \t\t 0x0002\n\t\t" << "LOG_CONNECTIONS \t 0x0004\n\t\t" \
                     << "LOG_RPM \t\t 0x0008\n\t\t" << "LOG_MAINWINDOW \t 0x0010\n\t\t" \
                     << "LOG_ALERTS \t\t 0x0020\n\t\t" << "LOG_LEDINDICATOR \t 0x0040\n\t\t" \
                     << "LOG_SETTINGS \t\t 0x0080\n\t\t" << "LOG_CONNECTIONS_DATA \t 0x0100\n\t\t" \
                     << "LOG_MAINWINDOW_DATA \t 0x0200\n";
            exit(EXIT_FAILURE);
            break;
        case 'l':
            sscanf(optarg, "%x", &gLogMask);
            LOG (LOG_MAIN, "Logger mask - [0x%04x]\n", gLogMask);
            break;
        }
    }
#ifdef GIT_VERSION
    LOG (LOG_MAIN, "App version - %s", GIT_VERSION);
#endif
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

void logger (int level, bool raw, const char* fmt, ...)
{
    char date[BUF_LEN];
    char data[BUF_LEN];
    char buf[BUF_LEN];
    va_list args;

    if(level != LOG_ERROR && !(level & gLogMask))
        return;

    time_t now = time(NULL);
    ctime_r (&now, date);

    date[strlen(date)-1] = 0x0; //obcięcie \n na końcu
    va_start (args, fmt);
    vsnprintf (data, BUF_LEN, fmt, args);
    va_end (args);

    if(raw == true)
        snprintf (buf, BUF_LEN-1, "$s\n", data);
    else
        snprintf (buf, BUF_LEN-1, "[%s] [0x%04x] - %s\n", date, level, data);
    fprintf (stderr, "%s", buf);

}

void logger (const char *fmt, ...)
{
    va_list args;
    va_start (args, fmt);
    logger (0xFFFF, false, fmt, args);
    va_end (args);
}
