#-------------------------------------------------
#
# Project created by QtCreator 2018-07-23T22:43:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = komp_pokl_cpp
TEMPLATE = app

CONFIG += c++11

SOURCES += \
    ../src/main.cpp \
    ../src/mainwindow.cpp \
    ../src/connections.cpp \
    ../src/rpmwidget.cpp

HEADERS  += \
    ../src/mainwindow.h \
    ../src/connections.h \
    ../src/logger.h \
    ../src/rpmwidget.h

FORMS += \
    ../ui/mainwindow.ui \
    ../ui/rpmwidget.ui

RESOURCES += \
    ../img/img.qrc
