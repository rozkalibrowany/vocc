#ifndef LOGGER
#define LOGGER

#include <stdarg.h>

#define LOG_MAIN                0x0001
#define LOG_GUI                 0x0002
#define LOG_CONNECTIONS         0x0004
#define LOG_RPM                 0x0008
#define LOG_MAINWINDOW          0x0010
#define LOG_ALERTS              0x0020
#define LOG_LEDINDICATOR        0x0040
#define LOG_SETTINGS            0x0080

#define LOG_ERROR               0x8000

extern int gLogMask;

#define STR(s) (s).toStdString ().c_str ()
#define LOG(l, arg...) logger (l, false, arg)
#define LOGRAW(l, arg...) logger (l, true, arg)

void logger (int level, bool raw, const char *fmt, ...);
void logger (const char *fmt, ...);

#endif // LOGGER

