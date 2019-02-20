#-------------------------------------------------
#
# Project created by QtCreator 2018-07-23T22:43:59
#
#-------------------------------------------------

QMAKE_CXXFLAGS_RELEASE += -O2


QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += GIT_VERSION="\\\"$(shell git -C \""$$_PRO_FILE_PWD_"\" describe --tags --abbrev=0)\\\""

TARGET = vocc
TEMPLATE = app

#QMAKE_LFLAGS += -static
#unix:!macx: LIBS += -L$$PWD/../libs/ -lQt5Charts

#INCLUDEPATH += $$PWD/../libs/include
#DEPENDPATH += $$PWD/../libs/include

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
    ../src/settings/parser.c \
    ../src/settings/progressIndicator.cpp \
    ../src/stats/chart.cpp


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
    ../src/settings/parser.h \
    ../src/settings/progressIndicator.h \
    ../src/stats/chart.h


FORMS += \
    ../ui/mainwindow.ui \
    ../ui/rpmwidget.ui \
    ../ui/controllerwidget.ui \
    ../ui/batterywidget.ui \
    ../ui/settings.ui \
    ../ui/statistics.ui

RESOURCES += \
    ../img/img.qrc

SUBDIRS += \
    ../src/qt/chartviewer.pro


unix:!macx: LIBS += -L$$PWD/../libs/ -lQt5Charts

INCLUDEPATH += $$PWD/../libs/include/QtCharts
DEPENDPATH += $$PWD/../libs/include/QtCharts

unix:!macx: PRE_TARGETDEPS += $$PWD/../libs/libQt5Charts.a
