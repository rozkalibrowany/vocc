#-------------------------------------------------
#
# Project created by QtCreator 2018-07-23T22:43:59
#
#-------------------------------------------------
QMAKE_CXXFLAGS_RELEASE += -O2

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = komp_pokl_cpp
TEMPLATE = app

CONFIG += c++11

DESTDIR = ../bin

OBJECTS_DIR = obj/

MOC_DIR = moc/

SOURCES += \
    ../src/main.cpp \
    ../src/alerts/ledindicator.cpp \
    ../src/alerts/alerts.cpp \
    ../src/alerts/batterywidget.cpp \
    ../src/alerts/controllerwidget.cpp \
    ../src/settings/settings.cpp \
    ../src/connections/connections.cpp \
    ../src/main/mainwindow.cpp \
    ../src/main/rpmwidget.cpp \
    ../src/stats/statistics.cpp \
    ../src/settings/parser.c

HEADERS  += \
    ../src/alerts/ledindicator.h \
    ../src/alerts/alerts.h \
    ../src/alerts/batterywidget.h \
    ../src/alerts/controllerwidget.h \
    ../src/settings/settings.h \
    ../src/common/logger.h \
    ../src/common/parameters.h \
    ../src/connections/connections.h \
    ../src/main/mainwindow.h \
    ../src/main/rpmwidget.h \
    ../src/stats/statistics.h \
    ../src/settings/parser.h

FORMS += \
    ../ui/mainwindow.ui \
    ../ui/rpmwidget.ui \
    ../ui/controllerwidget.ui \
    ../ui/batterywidget.ui \
    ../ui/settings.ui \
    ../ui/statistics.ui

RESOURCES += \
    ../img/img.qrc
