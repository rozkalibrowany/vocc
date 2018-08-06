/********************************************************************************
** Form generated from reading UI file 'newGui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGUI_H
#define UI_NEWGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *menuButtonsGroup;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hlMain;
    QFrame *vfMain;
    QVBoxLayout *vlMain;
    QVBoxLayout *vlMain_5;
    QHBoxLayout *hlMainIcon;
    QPushButton *driveButton;
    QHBoxLayout *hlMainText;
    QLabel *driveLabel;
    QHBoxLayout *hlAlerts;
    QFrame *vfAlerts;
    QVBoxLayout *vlMain_2;
    QVBoxLayout *vlAlerts;
    QHBoxLayout *hlAlertsIcon;
    QPushButton *alertsButton;
    QHBoxLayout *hlAlertsText;
    QLabel *alertsLabel;
    QHBoxLayout *hlStats;
    QFrame *vfStats;
    QVBoxLayout *vlMain_3;
    QVBoxLayout *vlStats;
    QHBoxLayout *hlStatsIcon;
    QPushButton *statsButton;
    QHBoxLayout *hlStatsText;
    QLabel *statsLabel;
    QHBoxLayout *hlSettings;
    QFrame *vfSettings;
    QVBoxLayout *vlMain_4;
    QVBoxLayout *vlSettings;
    QHBoxLayout *hlSettingsIcon;
    QPushButton *settingsButton;
    QHBoxLayout *hlSettingsText;
    QLabel *settingsLabel;
    QFrame *gridFrame;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *drive;
    QFrame *line;
    QFrame *line_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *dvl1;
    QHBoxLayout *dhl13;
    QFrame *throttle;
    QLabel *label_4;
    QLCDNumber *throttleLcd;
    QLabel *label_5;
    QHBoxLayout *dhl12;
    QFrame *contrTemp;
    QLabel *label_6;
    QLCDNumber *contrTempLcd;
    QLabel *label_7;
    QHBoxLayout *dhl11;
    QFrame *motorTemp;
    QLabel *label_9;
    QLCDNumber *motorTempLcd;
    QLabel *label_8;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *dvl2;
    QHBoxLayout *dhl23;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *timeLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *dateLabel;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *timerButton;
    QVBoxLayout *verticalLayout_3;
    QLCDNumber *lcdNumber;
    QHBoxLayout *dhl22;
    QWidget *rpm_widget;
    QFrame *horizontalFrame_4;
    QHBoxLayout *dhl21;
    QVBoxLayout *dvl22;
    QPushButton *canButton;
    QVBoxLayout *dvl21;
    QLabel *alertStatus;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *dvl3;
    QHBoxLayout *dhl33;
    QFrame *avrPower;
    QLabel *label_11;
    QLCDNumber *avrPowerLcd;
    QLabel *label_10;
    QHBoxLayout *dhl32;
    QFrame *batteryCurrent;
    QLabel *label_13;
    QLCDNumber *batteryCurrentLcd;
    QLabel *label_12;
    QHBoxLayout *dhl31;
    QFrame *batteryVoltage;
    QLabel *label_15;
    QLCDNumber *batteryVoltageLcd;
    QLabel *label_14;
    QWidget *alerts;
    QFrame *frame;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QHBoxLayout *horizontalLayout_7;
    QFrame *frame_2;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_11;
    QFrame *led_err0;
    QFrame *led_err1;
    QFrame *led_err2;
    QFrame *led_err4;
    QFrame *led_err5;
    QFrame *led_err6;
    QFrame *led_err7;
    QFrame *led_err9;
    QFrame *led_err10;
    QFrame *led_err11;
    QFrame *led_err14;
    QFrame *led_err15;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_err0;
    QLabel *label_err1;
    QLabel *label_err2;
    QLabel *label_err4;
    QLabel *label_err5;
    QLabel *label_err6;
    QLabel *label_err7;
    QLabel *label_err9;
    QLabel *label_err10;
    QLabel *label_err11;
    QLabel *label_err14;
    QLabel *label_err15;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QWidget *stats;
    QWidget *settings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMaximumSize(QSize(800, 480));
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(24,24,24); "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        menuButtonsGroup = new QGroupBox(centralwidget);
        menuButtonsGroup->setObjectName(QStringLiteral("menuButtonsGroup"));
        menuButtonsGroup->setGeometry(QRect(0, 0, 81, 480));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menuButtonsGroup->sizePolicy().hasHeightForWidth());
        menuButtonsGroup->setSizePolicy(sizePolicy);
        menuButtonsGroup->setMinimumSize(QSize(70, 0));
        menuButtonsGroup->setMaximumSize(QSize(16777215, 480));
        menuButtonsGroup->setStyleSheet(QLatin1String("/*background-image: url(\":general/general/gradient3.png\"); */\n"
"background-color: rgb(24,24,24);\n"
""));
        menuButtonsGroup->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(menuButtonsGroup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        hlMain = new QHBoxLayout();
        hlMain->setObjectName(QStringLiteral("hlMain"));
        vfMain = new QFrame(menuButtonsGroup);
        vfMain->setObjectName(QStringLiteral("vfMain"));
        vfMain->setMinimumSize(QSize(70, 0));
        vfMain->setStyleSheet(QLatin1String("QPushButton,QFrame {\n"
"border: 1.5 px solid \"#6affcd\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"}\n"
"\n"
"QFrame[chosen=\"true\"] {\n"
"border: none;\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"background: \"#365546\";\n"
"}\n"
"QPushButton[chosen=\"true\"]{\n"
"background: \"#365546\"; \n"
"}\n"
"\n"
"QLabel[chosen=\"true\"] {\n"
"background: \"#365546\"; \n"
"}"));
        vlMain = new QVBoxLayout(vfMain);
        vlMain->setObjectName(QStringLiteral("vlMain"));
        vlMain->setContentsMargins(0, 0, 0, 0);
        vlMain_5 = new QVBoxLayout();
        vlMain_5->setObjectName(QStringLiteral("vlMain_5"));
        hlMainIcon = new QHBoxLayout();
        hlMainIcon->setObjectName(QStringLiteral("hlMainIcon"));
        hlMainIcon->setContentsMargins(-1, 0, -1, -1);
        driveButton = new QPushButton(vfMain);
        driveButton->setObjectName(QStringLiteral("driveButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(driveButton->sizePolicy().hasHeightForWidth());
        driveButton->setSizePolicy(sizePolicy1);
        driveButton->setMinimumSize(QSize(0, 65));
        driveButton->setStyleSheet(QStringLiteral("border-image: url(\":44x44/44x44/navigation.png\");"));

        hlMainIcon->addWidget(driveButton);


        vlMain_5->addLayout(hlMainIcon);

        hlMainText = new QHBoxLayout();
        hlMainText->setObjectName(QStringLiteral("hlMainText"));
        driveLabel = new QLabel(vfMain);
        driveLabel->setObjectName(QStringLiteral("driveLabel"));
        sizePolicy1.setHeightForWidth(driveLabel->sizePolicy().hasHeightForWidth());
        driveLabel->setSizePolicy(sizePolicy1);
        driveLabel->setMaximumSize(QSize(16777215, 20));
        driveLabel->setStyleSheet(QLatin1String("border: 0 px; \n"
"font: 11 pt \"Purisa\" ;\n"
"color:  \"#6affcd\";"));
        driveLabel->setAlignment(Qt::AlignCenter);

        hlMainText->addWidget(driveLabel);


        vlMain_5->addLayout(hlMainText);


        vlMain->addLayout(vlMain_5);


        hlMain->addWidget(vfMain);


        verticalLayout->addLayout(hlMain);

        hlAlerts = new QHBoxLayout();
        hlAlerts->setObjectName(QStringLiteral("hlAlerts"));
        vfAlerts = new QFrame(menuButtonsGroup);
        vfAlerts->setObjectName(QStringLiteral("vfAlerts"));
        vfAlerts->setMinimumSize(QSize(70, 0));
        vfAlerts->setStyleSheet(QLatin1String("QPushButton,QFrame {\n"
"border: 1.5 px solid \"#6affcd\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"}\n"
"\n"
"QFrame[chosen=\"true\"] {\n"
"border: none;\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"background: \"#365546\";\n"
"}\n"
"QPushButton[chosen=\"true\"]{\n"
"background: \"#365546\"; \n"
"}\n"
"\n"
"QLabel[chosen=\"true\"] {\n"
"background: \"#365546\"; \n"
"}\n"
"\n"
"QFrame[alert=\"true\"] {\n"
"border: 3.5 px solid \"#ff4d4d\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"background: transparent;\n"
"}"));
        vlMain_2 = new QVBoxLayout(vfAlerts);
        vlMain_2->setObjectName(QStringLiteral("vlMain_2"));
        vlMain_2->setContentsMargins(0, 0, 0, 0);
        vlAlerts = new QVBoxLayout();
        vlAlerts->setObjectName(QStringLiteral("vlAlerts"));
        hlAlertsIcon = new QHBoxLayout();
        hlAlertsIcon->setObjectName(QStringLiteral("hlAlertsIcon"));
        hlAlertsIcon->setContentsMargins(-1, -1, -1, 5);
        alertsButton = new QPushButton(vfAlerts);
        alertsButton->setObjectName(QStringLiteral("alertsButton"));
        sizePolicy1.setHeightForWidth(alertsButton->sizePolicy().hasHeightForWidth());
        alertsButton->setSizePolicy(sizePolicy1);
        alertsButton->setMinimumSize(QSize(0, 65));
        alertsButton->setStyleSheet(QStringLiteral("border-image: url(\":44x44/44x44/message.png\");"));

        hlAlertsIcon->addWidget(alertsButton);


        vlAlerts->addLayout(hlAlertsIcon);

        hlAlertsText = new QHBoxLayout();
        hlAlertsText->setObjectName(QStringLiteral("hlAlertsText"));
        alertsLabel = new QLabel(vfAlerts);
        alertsLabel->setObjectName(QStringLiteral("alertsLabel"));
        alertsLabel->setMaximumSize(QSize(16777215, 20));
        alertsLabel->setStyleSheet(QLatin1String("border: 0 px; \n"
"font: 11 pt \"Purisa\" ;\n"
"color:  \"#6affcd\";"));
        alertsLabel->setAlignment(Qt::AlignCenter);

        hlAlertsText->addWidget(alertsLabel);


        vlAlerts->addLayout(hlAlertsText);


        vlMain_2->addLayout(vlAlerts);


        hlAlerts->addWidget(vfAlerts);


        verticalLayout->addLayout(hlAlerts);

        hlStats = new QHBoxLayout();
        hlStats->setObjectName(QStringLiteral("hlStats"));
        vfStats = new QFrame(menuButtonsGroup);
        vfStats->setObjectName(QStringLiteral("vfStats"));
        vfStats->setMinimumSize(QSize(70, 0));
        vfStats->setStyleSheet(QLatin1String("QPushButton,QFrame {\n"
"border: 1.5 px solid \"#6affcd\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"}\n"
"\n"
"QFrame[chosen=\"true\"] {\n"
"border: none;\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"background: \"#365546\";\n"
"}\n"
"QPushButton[chosen=\"true\"]{\n"
"background: \"#365546\"; \n"
"}\n"
"\n"
"QLabel[chosen=\"true\"] {\n"
"background: \"#365546\"; \n"
"}"));
        vlMain_3 = new QVBoxLayout(vfStats);
        vlMain_3->setObjectName(QStringLiteral("vlMain_3"));
        vlMain_3->setContentsMargins(0, 0, 0, 0);
        vlStats = new QVBoxLayout();
        vlStats->setObjectName(QStringLiteral("vlStats"));
        hlStatsIcon = new QHBoxLayout();
        hlStatsIcon->setObjectName(QStringLiteral("hlStatsIcon"));
        statsButton = new QPushButton(vfStats);
        statsButton->setObjectName(QStringLiteral("statsButton"));
        sizePolicy1.setHeightForWidth(statsButton->sizePolicy().hasHeightForWidth());
        statsButton->setSizePolicy(sizePolicy1);
        statsButton->setMinimumSize(QSize(0, 65));
        statsButton->setStyleSheet(QStringLiteral("border-image: url(\":44x44/44x44/statistics.png\");"));

        hlStatsIcon->addWidget(statsButton);


        vlStats->addLayout(hlStatsIcon);

        hlStatsText = new QHBoxLayout();
        hlStatsText->setObjectName(QStringLiteral("hlStatsText"));
        statsLabel = new QLabel(vfStats);
        statsLabel->setObjectName(QStringLiteral("statsLabel"));
        statsLabel->setMaximumSize(QSize(16777215, 20));
        statsLabel->setStyleSheet(QLatin1String("border: 0 px; \n"
"font: 11 pt \"Purisa\" ;\n"
"color:  \"#6affcd\";"));
        statsLabel->setAlignment(Qt::AlignCenter);

        hlStatsText->addWidget(statsLabel);


        vlStats->addLayout(hlStatsText);


        vlMain_3->addLayout(vlStats);


        hlStats->addWidget(vfStats);


        verticalLayout->addLayout(hlStats);

        hlSettings = new QHBoxLayout();
        hlSettings->setObjectName(QStringLiteral("hlSettings"));
        vfSettings = new QFrame(menuButtonsGroup);
        vfSettings->setObjectName(QStringLiteral("vfSettings"));
        vfSettings->setMinimumSize(QSize(70, 0));
        vfSettings->setStyleSheet(QLatin1String("QPushButton,QFrame {\n"
"border: 1.5 px solid \"#6affcd\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"}\n"
"\n"
"QFrame[chosen=\"true\"] {\n"
"border: none;\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"background: \"#365546\";\n"
"}\n"
"QPushButton[chosen=\"true\"]{\n"
"background: \"#365546\"; \n"
"}\n"
"\n"
"QLabel[chosen=\"true\"] {\n"
"background: \"#365546\"; \n"
"}"));
        vlMain_4 = new QVBoxLayout(vfSettings);
        vlMain_4->setObjectName(QStringLiteral("vlMain_4"));
        vlMain_4->setContentsMargins(0, 0, 0, 0);
        vlSettings = new QVBoxLayout();
        vlSettings->setObjectName(QStringLiteral("vlSettings"));
        hlSettingsIcon = new QHBoxLayout();
        hlSettingsIcon->setObjectName(QStringLiteral("hlSettingsIcon"));
        settingsButton = new QPushButton(vfSettings);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        sizePolicy1.setHeightForWidth(settingsButton->sizePolicy().hasHeightForWidth());
        settingsButton->setSizePolicy(sizePolicy1);
        settingsButton->setMinimumSize(QSize(0, 65));
        settingsButton->setStyleSheet(QStringLiteral("border-image: url(\":44x44/44x44/settings.png\");"));

        hlSettingsIcon->addWidget(settingsButton);


        vlSettings->addLayout(hlSettingsIcon);

        hlSettingsText = new QHBoxLayout();
        hlSettingsText->setObjectName(QStringLiteral("hlSettingsText"));
        settingsLabel = new QLabel(vfSettings);
        settingsLabel->setObjectName(QStringLiteral("settingsLabel"));
        settingsLabel->setMaximumSize(QSize(16777215, 20));
        settingsLabel->setStyleSheet(QLatin1String("border: 0 px; \n"
"font: 11 pt \"Purisa\" ;\n"
"color:  \"#6affcd\";"));
        settingsLabel->setAlignment(Qt::AlignCenter);

        hlSettingsText->addWidget(settingsLabel);


        vlSettings->addLayout(hlSettingsText);


        vlMain_4->addLayout(vlSettings);


        hlSettings->addWidget(vfSettings);


        verticalLayout->addLayout(hlSettings);

        gridFrame = new QFrame(centralwidget);
        gridFrame->setObjectName(QStringLiteral("gridFrame"));
        gridFrame->setGeometry(QRect(88, 0, 711, 480));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gridFrame->sizePolicy().hasHeightForWidth());
        gridFrame->setSizePolicy(sizePolicy2);
        gridFrame->setMaximumSize(QSize(720, 480));
        gridFrame->setStyleSheet(QLatin1String("background-color: rgb(24,24,24);\n"
""));
        gridLayout = new QGridLayout(gridFrame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(gridFrame);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        drive = new QWidget();
        drive->setObjectName(QStringLiteral("drive"));
        drive->setStyleSheet(QStringLiteral(""));
        line = new QFrame(drive);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(170, 20, 2, 430));
        line->setStyleSheet(QStringLiteral("background-color: \"#6affcd\""));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(drive);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(510, 20, 2, 430));
        line_2->setStyleSheet(QStringLiteral("background-color: \"#6affcd\""));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget = new QWidget(drive);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 161, 451));
        dvl1 = new QVBoxLayout(verticalLayoutWidget);
        dvl1->setObjectName(QStringLiteral("dvl1"));
        dvl1->setContentsMargins(0, 0, 0, 0);
        dhl13 = new QHBoxLayout();
        dhl13->setObjectName(QStringLiteral("dhl13"));
        throttle = new QFrame(verticalLayoutWidget);
        throttle->setObjectName(QStringLiteral("throttle"));
        throttle->setStyleSheet(QLatin1String("QFrame{\n"
"border: 1.5 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning=\"true\"] {\n"
"border: 4 px solid \"#ffff99\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning2=\"true\"] {\n"
"border: 4 px solid \"#ff4d4d\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
""));
        throttle->setFrameShape(QFrame::StyledPanel);
        throttle->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(throttle);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 151, 31));
        label_4->setStyleSheet(QLatin1String("border: none;\n"
"font: 14 pt \"Ubuntu\";\n"
"color:  \"#6affcd\";"));
        label_4->setAlignment(Qt::AlignCenter);
        throttleLcd = new QLCDNumber(throttle);
        throttleLcd->setObjectName(QStringLiteral("throttleLcd"));
        throttleLcd->setGeometry(QRect(0, 30, 121, 111));
        sizePolicy.setHeightForWidth(throttleLcd->sizePolicy().hasHeightForWidth());
        throttleLcd->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        throttleLcd->setFont(font);
        throttleLcd->setStyleSheet(QLatin1String("QLCDNumber{\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";\n"
"}\n"
"\n"
"QLCDNumber[warning=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ffff99\";\n"
"}\n"
"\n"
"QLCDNumber[warning2=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ff4d4d\";\n"
"}"));
        throttleLcd->setFrameShape(QFrame::StyledPanel);
        throttleLcd->setFrameShadow(QFrame::Sunken);
        throttleLcd->setLineWidth(5);
        throttleLcd->setSmallDecimalPoint(false);
        throttleLcd->setDigitCount(3);
        throttleLcd->setSegmentStyle(QLCDNumber::Flat);
        throttleLcd->setProperty("value", QVariant(0));
        throttleLcd->setProperty("intValue", QVariant(0));
        label_5 = new QLabel(throttle);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 40, 41, 101));
        label_5->setStyleSheet(QLatin1String("border: none;\n"
"font: 22 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";"));
        label_5->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        dhl13->addWidget(throttle);


        dvl1->addLayout(dhl13);

        dhl12 = new QHBoxLayout();
        dhl12->setObjectName(QStringLiteral("dhl12"));
        contrTemp = new QFrame(verticalLayoutWidget);
        contrTemp->setObjectName(QStringLiteral("contrTemp"));
        contrTemp->setStyleSheet(QLatin1String("QFrame{\n"
"border: 1.5 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning=\"true\"] {\n"
"border: 4 px solid \"#ffff99\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning2=\"true\"] {\n"
"border: 4 px solid \"#ff4d4d\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
""));
        contrTemp->setFrameShape(QFrame::StyledPanel);
        contrTemp->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(contrTemp);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 0, 151, 31));
        label_6->setStyleSheet(QLatin1String("border: none;\n"
"font: 12 pt \"Ubuntu\";\n"
"color:  \"#6affcd\";"));
        label_6->setAlignment(Qt::AlignCenter);
        contrTempLcd = new QLCDNumber(contrTemp);
        contrTempLcd->setObjectName(QStringLiteral("contrTempLcd"));
        contrTempLcd->setGeometry(QRect(0, 30, 121, 111));
        sizePolicy.setHeightForWidth(contrTempLcd->sizePolicy().hasHeightForWidth());
        contrTempLcd->setSizePolicy(sizePolicy);
        contrTempLcd->setFont(font);
        contrTempLcd->setStyleSheet(QLatin1String("QLCDNumber{\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";\n"
"}\n"
"\n"
"QLCDNumber[warning=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ffff99\";\n"
"}\n"
"\n"
"QLCDNumber[warning2=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ff4d4d\";\n"
"}"));
        contrTempLcd->setFrameShape(QFrame::StyledPanel);
        contrTempLcd->setFrameShadow(QFrame::Sunken);
        contrTempLcd->setLineWidth(5);
        contrTempLcd->setDigitCount(3);
        contrTempLcd->setSegmentStyle(QLCDNumber::Flat);
        label_7 = new QLabel(contrTemp);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(110, 50, 41, 91));
        label_7->setStyleSheet(QLatin1String("border: none;\n"
"font: 26 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";"));
        label_7->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        dhl12->addWidget(contrTemp);


        dvl1->addLayout(dhl12);

        dhl11 = new QHBoxLayout();
        dhl11->setObjectName(QStringLiteral("dhl11"));
        motorTemp = new QFrame(verticalLayoutWidget);
        motorTemp->setObjectName(QStringLiteral("motorTemp"));
        motorTemp->setStyleSheet(QLatin1String("QFrame{\n"
"border: 1.5 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning=\"true\"] {\n"
"border: 4 px solid \"#ffff99\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning2=\"true\"] {\n"
"border: 4 px solid \"#ff4d4d\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
""));
        motorTemp->setFrameShape(QFrame::StyledPanel);
        motorTemp->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(motorTemp);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 0, 151, 31));
        label_9->setStyleSheet(QLatin1String("border: none;\n"
"font: 12 pt \"Ubuntu\";\n"
"color:  \"#6affcd\";"));
        label_9->setAlignment(Qt::AlignCenter);
        motorTempLcd = new QLCDNumber(motorTemp);
        motorTempLcd->setObjectName(QStringLiteral("motorTempLcd"));
        motorTempLcd->setGeometry(QRect(0, 30, 121, 111));
        sizePolicy.setHeightForWidth(motorTempLcd->sizePolicy().hasHeightForWidth());
        motorTempLcd->setSizePolicy(sizePolicy);
        motorTempLcd->setFont(font);
        motorTempLcd->setStyleSheet(QLatin1String("QLCDNumber{\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";\n"
"}\n"
"\n"
"QLCDNumber[warning=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ffff99\";\n"
"}\n"
"\n"
"QLCDNumber[warning2=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ff4d4d\";\n"
"}"));
        motorTempLcd->setFrameShape(QFrame::StyledPanel);
        motorTempLcd->setFrameShadow(QFrame::Sunken);
        motorTempLcd->setLineWidth(5);
        motorTempLcd->setDigitCount(3);
        motorTempLcd->setSegmentStyle(QLCDNumber::Flat);
        label_8 = new QLabel(motorTemp);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(110, 50, 41, 91));
        label_8->setStyleSheet(QLatin1String("border: none;\n"
"font: 26 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";"));
        label_8->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        dhl11->addWidget(motorTemp);


        dvl1->addLayout(dhl11);

        verticalLayoutWidget_2 = new QWidget(drive);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(180, 0, 320, 461));
        dvl2 = new QVBoxLayout(verticalLayoutWidget_2);
        dvl2->setObjectName(QStringLiteral("dvl2"));
        dvl2->setContentsMargins(0, 0, 0, 0);
        dhl23 = new QHBoxLayout();
        dhl23->setObjectName(QStringLiteral("dhl23"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        timeLabel = new QLabel(verticalLayoutWidget_2);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setStyleSheet(QLatin1String("font: 26 pt \"Halvetica\" ;\n"
"color: \"#f2f2f2\";\n"
"background: transparent;"));
        timeLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        horizontalLayout->addWidget(timeLabel);


        verticalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        dateLabel = new QLabel(verticalLayoutWidget_2);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        dateLabel->setStyleSheet(QLatin1String("font: 75 italic 15 pt \"Halvetica\" ;\n"
"color: \"#a6a6a6\";\n"
"background: transparent;"));
        dateLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        horizontalLayout_4->addWidget(dateLabel);


        verticalLayout_6->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, -1, 9, -1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        timerButton = new QPushButton(verticalLayoutWidget_2);
        timerButton->setObjectName(QStringLiteral("timerButton"));
        timerButton->setMinimumSize(QSize(0, 40));
        timerButton->setMaximumSize(QSize(16777215, 45));
        timerButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border: 1.4 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"}\n"
"\n"
"QPushButton[clicked=\"true\"] {\n"
"border: 4 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"}"));

        verticalLayout_4->addWidget(timerButton);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lcdNumber = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(20);
        sizePolicy3.setVerticalStretch(40);
        sizePolicy3.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy3);
        lcdNumber->setMinimumSize(QSize(0, 40));
        lcdNumber->setMaximumSize(QSize(150, 45));
        lcdNumber->setSizeIncrement(QSize(7, 21));
        lcdNumber->setBaseSize(QSize(13, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        lcdNumber->setFont(font1);
        lcdNumber->setStyleSheet(QLatin1String("color: \"#f2f2f2\";\n"
"border: 1.4 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"background: transparent;\n"
"color:  \"#00ffc1\";"));
        lcdNumber->setFrameShape(QFrame::StyledPanel);
        lcdNumber->setLineWidth(4);
        lcdNumber->setMidLineWidth(20);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(0));
        lcdNumber->setProperty("intValue", QVariant(0));

        verticalLayout_3->addWidget(lcdNumber);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        dhl23->addLayout(verticalLayout_2);


        dvl2->addLayout(dhl23);

        dhl22 = new QHBoxLayout();
        dhl22->setObjectName(QStringLiteral("dhl22"));
        rpm_widget = new QWidget(verticalLayoutWidget_2);
        rpm_widget->setObjectName(QStringLiteral("rpm_widget"));
        sizePolicy1.setHeightForWidth(rpm_widget->sizePolicy().hasHeightForWidth());
        rpm_widget->setSizePolicy(sizePolicy1);
        rpm_widget->setMinimumSize(QSize(300, 270));
        rpm_widget->setMaximumSize(QSize(300, 270));
        rpm_widget->setStyleSheet(QLatin1String("border: 0;\n"
"background: transparent;\n"
"border-image: none;"));

        dhl22->addWidget(rpm_widget);


        dvl2->addLayout(dhl22);

        horizontalFrame_4 = new QFrame(verticalLayoutWidget_2);
        horizontalFrame_4->setObjectName(QStringLiteral("horizontalFrame_4"));
        horizontalFrame_4->setMaximumSize(QSize(16777215, 40));
        dhl21 = new QHBoxLayout(horizontalFrame_4);
        dhl21->setObjectName(QStringLiteral("dhl21"));
        dhl21->setSizeConstraint(QLayout::SetMinimumSize);
        dhl21->setContentsMargins(-1, 0, -1, 9);
        dvl22 = new QVBoxLayout();
        dvl22->setObjectName(QStringLiteral("dvl22"));
        dvl22->setSizeConstraint(QLayout::SetMaximumSize);
        canButton = new QPushButton(horizontalFrame_4);
        canButton->setObjectName(QStringLiteral("canButton"));
        canButton->setMinimumSize(QSize(145, 35));
        canButton->setStyleSheet(QLatin1String("QPushButton {\n"
"border: 1.5 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"}\n"
"\n"
"QPushButton[connected=\"true\"] {\n"
"border: 1.5 px solid \"#99ff99\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#99ff99\";\n"
"}"));

        dvl22->addWidget(canButton);


        dhl21->addLayout(dvl22);

        dvl21 = new QVBoxLayout();
        dvl21->setObjectName(QStringLiteral("dvl21"));
        alertStatus = new QLabel(horizontalFrame_4);
        alertStatus->setObjectName(QStringLiteral("alertStatus"));
        alertStatus->setMinimumSize(QSize(145, 35));
        alertStatus->setMaximumSize(QSize(145, 16777215));
        alertStatus->setStyleSheet(QLatin1String("QLabel {\n"
"border: 1.5 px solid \"#99ff99\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#99ff99\";\n"
"}\n"
"\n"
"QLabel[isAlert=\"true\"] {\n"
"border: 1.5 px solid \"#ff4d4d\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#ff4d4d\";\n"
"}"));
        alertStatus->setAlignment(Qt::AlignCenter);

        dvl21->addWidget(alertStatus);


        dhl21->addLayout(dvl21);


        dvl2->addWidget(horizontalFrame_4);

        verticalLayoutWidget_5 = new QWidget(drive);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(520, 0, 161, 451));
        dvl3 = new QVBoxLayout(verticalLayoutWidget_5);
        dvl3->setObjectName(QStringLiteral("dvl3"));
        dvl3->setContentsMargins(0, 0, 0, 0);
        dhl33 = new QHBoxLayout();
        dhl33->setObjectName(QStringLiteral("dhl33"));
        avrPower = new QFrame(verticalLayoutWidget_5);
        avrPower->setObjectName(QStringLiteral("avrPower"));
        avrPower->setMaximumSize(QSize(16777215, 160));
        avrPower->setStyleSheet(QLatin1String("QFrame{\n"
"border: 1.5 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning=\"true\"] {\n"
"border: 4 px solid \"#ffff99\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning2=\"true\"] {\n"
"border: 4 px solid \"#ff4d4d\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
""));
        avrPower->setFrameShape(QFrame::StyledPanel);
        avrPower->setFrameShadow(QFrame::Raised);
        label_11 = new QLabel(avrPower);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 0, 151, 31));
        label_11->setStyleSheet(QLatin1String("border: none;\n"
"font: 12 pt \"Ubuntu\";\n"
"color:  \"#6affcd\";"));
        label_11->setAlignment(Qt::AlignCenter);
        avrPowerLcd = new QLCDNumber(avrPower);
        avrPowerLcd->setObjectName(QStringLiteral("avrPowerLcd"));
        avrPowerLcd->setGeometry(QRect(0, 30, 121, 111));
        sizePolicy.setHeightForWidth(avrPowerLcd->sizePolicy().hasHeightForWidth());
        avrPowerLcd->setSizePolicy(sizePolicy);
        avrPowerLcd->setFont(font);
        avrPowerLcd->setStyleSheet(QLatin1String("QLCDNumber{\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";\n"
"}\n"
"\n"
"QLCDNumber[warning=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ffff99\";\n"
"}\n"
"\n"
"QLCDNumber[warning2=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ff4d4d\";\n"
"}"));
        avrPowerLcd->setFrameShape(QFrame::StyledPanel);
        avrPowerLcd->setFrameShadow(QFrame::Sunken);
        avrPowerLcd->setLineWidth(5);
        avrPowerLcd->setDigitCount(3);
        avrPowerLcd->setSegmentStyle(QLCDNumber::Flat);
        label_10 = new QLabel(avrPower);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(110, 50, 41, 91));
        label_10->setStyleSheet(QLatin1String("border: none;\n"
"font: 17 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        dhl33->addWidget(avrPower);


        dvl3->addLayout(dhl33);

        dhl32 = new QHBoxLayout();
        dhl32->setObjectName(QStringLiteral("dhl32"));
        batteryCurrent = new QFrame(verticalLayoutWidget_5);
        batteryCurrent->setObjectName(QStringLiteral("batteryCurrent"));
        batteryCurrent->setMaximumSize(QSize(16777215, 160));
        batteryCurrent->setStyleSheet(QLatin1String("QFrame{\n"
"border: 1.5 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning=\"true\"] {\n"
"border: 4 px solid \"#ffff99\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning2=\"true\"] {\n"
"border: 4 px solid \"#ff4d4d\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
""));
        batteryCurrent->setFrameShape(QFrame::StyledPanel);
        batteryCurrent->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(batteryCurrent);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(0, 0, 151, 31));
        label_13->setStyleSheet(QLatin1String("border: none;\n"
"font: 12 pt \"Ubuntu\";\n"
"color:  \"#6affcd\";"));
        label_13->setAlignment(Qt::AlignCenter);
        batteryCurrentLcd = new QLCDNumber(batteryCurrent);
        batteryCurrentLcd->setObjectName(QStringLiteral("batteryCurrentLcd"));
        batteryCurrentLcd->setGeometry(QRect(0, 30, 121, 111));
        sizePolicy.setHeightForWidth(batteryCurrentLcd->sizePolicy().hasHeightForWidth());
        batteryCurrentLcd->setSizePolicy(sizePolicy);
        batteryCurrentLcd->setFont(font);
        batteryCurrentLcd->setStyleSheet(QLatin1String("QLCDNumber{\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";\n"
"}\n"
"\n"
"QLCDNumber[warning=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ffff99\";\n"
"}\n"
"\n"
"QLCDNumber[warning2=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ff4d4d\";\n"
"}"));
        batteryCurrentLcd->setFrameShape(QFrame::StyledPanel);
        batteryCurrentLcd->setFrameShadow(QFrame::Sunken);
        batteryCurrentLcd->setLineWidth(5);
        batteryCurrentLcd->setDigitCount(3);
        batteryCurrentLcd->setSegmentStyle(QLCDNumber::Flat);
        label_12 = new QLabel(batteryCurrent);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(110, 50, 41, 91));
        label_12->setStyleSheet(QLatin1String("border: none;\n"
"font: 21 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";"));
        label_12->setAlignment(Qt::AlignCenter);

        dhl32->addWidget(batteryCurrent);


        dvl3->addLayout(dhl32);

        dhl31 = new QHBoxLayout();
        dhl31->setObjectName(QStringLiteral("dhl31"));
        batteryVoltage = new QFrame(verticalLayoutWidget_5);
        batteryVoltage->setObjectName(QStringLiteral("batteryVoltage"));
        batteryVoltage->setMaximumSize(QSize(16777215, 160));
        batteryVoltage->setStyleSheet(QLatin1String("QFrame{\n"
"border: 1.5 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning=\"true\"] {\n"
"border: 4 px solid \"#ffff99\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
"\n"
"QFrame[warning2=\"true\"] {\n"
"border: 4 px solid \"#ff4d4d\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 11 pt \"Halvetica\" ;\n"
"color: \"#00ffc1\";\n"
"background: transparent;\n"
"}\n"
""));
        batteryVoltage->setFrameShape(QFrame::StyledPanel);
        batteryVoltage->setFrameShadow(QFrame::Raised);
        label_15 = new QLabel(batteryVoltage);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(0, 0, 151, 31));
        label_15->setStyleSheet(QLatin1String("border: none;\n"
"font: 12 pt \"Ubuntu\";\n"
"color:  \"#6affcd\";"));
        label_15->setAlignment(Qt::AlignCenter);
        batteryVoltageLcd = new QLCDNumber(batteryVoltage);
        batteryVoltageLcd->setObjectName(QStringLiteral("batteryVoltageLcd"));
        batteryVoltageLcd->setGeometry(QRect(0, 30, 121, 111));
        sizePolicy.setHeightForWidth(batteryVoltageLcd->sizePolicy().hasHeightForWidth());
        batteryVoltageLcd->setSizePolicy(sizePolicy);
        batteryVoltageLcd->setFont(font);
        batteryVoltageLcd->setStyleSheet(QLatin1String("QLCDNumber{\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";\n"
"}\n"
"\n"
"QLCDNumber[warning=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ffff99\";\n"
"}\n"
"\n"
"QLCDNumber[warning2=\"true\"] {\n"
"border: none;\n"
"font: 16 pt \"Ubuntu\";\n"
"color:  \"#ff4d4d\";\n"
"}"));
        batteryVoltageLcd->setFrameShape(QFrame::StyledPanel);
        batteryVoltageLcd->setFrameShadow(QFrame::Sunken);
        batteryVoltageLcd->setLineWidth(5);
        batteryVoltageLcd->setDigitCount(3);
        batteryVoltageLcd->setSegmentStyle(QLCDNumber::Flat);
        label_14 = new QLabel(batteryVoltage);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(110, 50, 41, 91));
        label_14->setStyleSheet(QLatin1String("border: none;\n"
"font: 21 pt \"Ubuntu\";\n"
"color:  \"#00ffc1\";"));
        label_14->setAlignment(Qt::AlignCenter);

        dhl31->addWidget(batteryVoltage);


        dvl3->addLayout(dhl31);

        stackedWidget->addWidget(drive);
        line->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        verticalLayoutWidget_5->raise();
        line_2->raise();
        alerts = new QWidget();
        alerts->setObjectName(QStringLiteral("alerts"));
        frame = new QFrame(alerts);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 691, 461));
        frame->setStyleSheet(QLatin1String("QFrame{\n"
"border: 1 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_3 = new QWidget(frame);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 691, 479));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 25));
        label->setStyleSheet(QLatin1String("QLabel{\n"
"border: 2 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 12 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label);


        verticalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        frame_2 = new QFrame(verticalLayoutWidget_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy4);
        frame_2->setMinimumSize(QSize(0, 435));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_7 = new QWidget(frame_2);
        verticalLayoutWidget_7->setObjectName(QStringLiteral("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(10, 0, 71, 431));
        verticalLayout_11 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_11->setSpacing(4);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        led_err0 = new QFrame(verticalLayoutWidget_7);
        led_err0->setObjectName(QStringLiteral("led_err0"));
        led_err0->setMaximumSize(QSize(16777215, 30));
        led_err0->setStyleSheet(QStringLiteral(""));
        led_err0->setFrameShape(QFrame::NoFrame);
        led_err0->setFrameShadow(QFrame::Raised);

        verticalLayout_11->addWidget(led_err0);

        led_err1 = new QFrame(verticalLayoutWidget_7);
        led_err1->setObjectName(QStringLiteral("led_err1"));
        led_err1->setMaximumSize(QSize(16777215, 30));
        led_err1->setFrameShape(QFrame::NoFrame);
        led_err1->setFrameShadow(QFrame::Raised);
        led_err1->setLineWidth(0);

        verticalLayout_11->addWidget(led_err1);

        led_err2 = new QFrame(verticalLayoutWidget_7);
        led_err2->setObjectName(QStringLiteral("led_err2"));
        led_err2->setMaximumSize(QSize(16777215, 30));
        led_err2->setFrameShape(QFrame::NoFrame);
        led_err2->setFrameShadow(QFrame::Raised);

        verticalLayout_11->addWidget(led_err2);

        led_err4 = new QFrame(verticalLayoutWidget_7);
        led_err4->setObjectName(QStringLiteral("led_err4"));
        led_err4->setMaximumSize(QSize(16777215, 30));
        led_err4->setFrameShape(QFrame::NoFrame);
        led_err4->setFrameShadow(QFrame::Raised);

        verticalLayout_11->addWidget(led_err4);

        led_err5 = new QFrame(verticalLayoutWidget_7);
        led_err5->setObjectName(QStringLiteral("led_err5"));
        led_err5->setMaximumSize(QSize(16777215, 30));
        led_err5->setFrameShape(QFrame::NoFrame);
        led_err5->setFrameShadow(QFrame::Raised);

        verticalLayout_11->addWidget(led_err5);

        led_err6 = new QFrame(verticalLayoutWidget_7);
        led_err6->setObjectName(QStringLiteral("led_err6"));
        led_err6->setMaximumSize(QSize(16777215, 30));
        led_err6->setFrameShape(QFrame::NoFrame);
        led_err6->setFrameShadow(QFrame::Raised);

        verticalLayout_11->addWidget(led_err6);

        led_err7 = new QFrame(verticalLayoutWidget_7);
        led_err7->setObjectName(QStringLiteral("led_err7"));
        led_err7->setMaximumSize(QSize(16777215, 30));
        led_err7->setFrameShape(QFrame::NoFrame);
        led_err7->setFrameShadow(QFrame::Raised);

        verticalLayout_11->addWidget(led_err7);

        led_err9 = new QFrame(verticalLayoutWidget_7);
        led_err9->setObjectName(QStringLiteral("led_err9"));
        led_err9->setMaximumSize(QSize(16777215, 30));
        led_err9->setFrameShape(QFrame::NoFrame);
        led_err9->setFrameShadow(QFrame::Raised);

        verticalLayout_11->addWidget(led_err9);

        led_err10 = new QFrame(verticalLayoutWidget_7);
        led_err10->setObjectName(QStringLiteral("led_err10"));
        led_err10->setMaximumSize(QSize(16777215, 30));
        led_err10->setFrameShape(QFrame::NoFrame);
        led_err10->setFrameShadow(QFrame::Raised);

        verticalLayout_11->addWidget(led_err10);

        led_err11 = new QFrame(verticalLayoutWidget_7);
        led_err11->setObjectName(QStringLiteral("led_err11"));
        led_err11->setMaximumSize(QSize(16777215, 30));
        led_err11->setFrameShape(QFrame::NoFrame);
        led_err11->setFrameShadow(QFrame::Raised);

        verticalLayout_11->addWidget(led_err11);

        led_err14 = new QFrame(verticalLayoutWidget_7);
        led_err14->setObjectName(QStringLiteral("led_err14"));
        led_err14->setMaximumSize(QSize(16777215, 30));
        led_err14->setFrameShape(QFrame::NoFrame);
        led_err14->setFrameShadow(QFrame::Raised);

        verticalLayout_11->addWidget(led_err14);

        led_err15 = new QFrame(verticalLayoutWidget_7);
        led_err15->setObjectName(QStringLiteral("led_err15"));
        led_err15->setMaximumSize(QSize(16777215, 30));
        led_err15->setFrameShape(QFrame::NoFrame);
        led_err15->setFrameShadow(QFrame::Raised);

        verticalLayout_11->addWidget(led_err15);

        verticalLayoutWidget_8 = new QWidget(frame_2);
        verticalLayoutWidget_8->setObjectName(QStringLiteral("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(90, 0, 251, 431));
        verticalLayout_12 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_12->setSpacing(4);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_err0 = new QLabel(verticalLayoutWidget_8);
        label_err0->setObjectName(QStringLiteral("label_err0"));
        label_err0->setMaximumSize(QSize(16777215, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Halvetica"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_err0->setFont(font2);
        label_err0->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err0);

        label_err1 = new QLabel(verticalLayoutWidget_8);
        label_err1->setObjectName(QStringLiteral("label_err1"));
        label_err1->setMaximumSize(QSize(16777215, 30));
        label_err1->setFont(font2);
        label_err1->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err1);

        label_err2 = new QLabel(verticalLayoutWidget_8);
        label_err2->setObjectName(QStringLiteral("label_err2"));
        label_err2->setMaximumSize(QSize(16777215, 30));
        label_err2->setFont(font2);
        label_err2->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err2);

        label_err4 = new QLabel(verticalLayoutWidget_8);
        label_err4->setObjectName(QStringLiteral("label_err4"));
        label_err4->setMaximumSize(QSize(16777215, 30));
        label_err4->setFont(font2);
        label_err4->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err4);

        label_err5 = new QLabel(verticalLayoutWidget_8);
        label_err5->setObjectName(QStringLiteral("label_err5"));
        label_err5->setMaximumSize(QSize(16777215, 30));
        label_err5->setFont(font2);
        label_err5->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err5);

        label_err6 = new QLabel(verticalLayoutWidget_8);
        label_err6->setObjectName(QStringLiteral("label_err6"));
        label_err6->setMaximumSize(QSize(16777215, 30));
        label_err6->setFont(font2);
        label_err6->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err6);

        label_err7 = new QLabel(verticalLayoutWidget_8);
        label_err7->setObjectName(QStringLiteral("label_err7"));
        label_err7->setMaximumSize(QSize(16777215, 30));
        label_err7->setFont(font2);
        label_err7->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err7);

        label_err9 = new QLabel(verticalLayoutWidget_8);
        label_err9->setObjectName(QStringLiteral("label_err9"));
        label_err9->setMaximumSize(QSize(16777215, 30));
        label_err9->setFont(font2);
        label_err9->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err9);

        label_err10 = new QLabel(verticalLayoutWidget_8);
        label_err10->setObjectName(QStringLiteral("label_err10"));
        label_err10->setMaximumSize(QSize(16777215, 30));
        label_err10->setFont(font2);
        label_err10->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err10);

        label_err11 = new QLabel(verticalLayoutWidget_8);
        label_err11->setObjectName(QStringLiteral("label_err11"));
        label_err11->setMaximumSize(QSize(16777215, 30));
        label_err11->setFont(font2);
        label_err11->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err11);

        label_err14 = new QLabel(verticalLayoutWidget_8);
        label_err14->setObjectName(QStringLiteral("label_err14"));
        label_err14->setMaximumSize(QSize(16777215, 30));
        label_err14->setFont(font2);
        label_err14->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err14);

        label_err15 = new QLabel(verticalLayoutWidget_8);
        label_err15->setObjectName(QStringLiteral("label_err15"));
        label_err15->setMaximumSize(QSize(16777215, 30));
        label_err15->setFont(font2);
        label_err15->setStyleSheet(QLatin1String("QLabel{\n"
"font: 10 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));

        verticalLayout_12->addWidget(label_err15);


        horizontalLayout_7->addWidget(frame_2);


        verticalLayout_8->addLayout(horizontalLayout_7);


        horizontalLayout_5->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 25));
        label_3->setStyleSheet(QLatin1String("QLabel{\n"
"border: 2 px solid \"#00ffc1\";\n"
"border-radius: 4 px;\n"
"padding: 2 px;\n"
"font: 75 italic 12 pt \"Halvetica\" ;\n"
"color: \"#e6e6e6\";\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_3);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 435));

        horizontalLayout_9->addWidget(label_2);


        verticalLayout_7->addLayout(horizontalLayout_9);


        horizontalLayout_5->addLayout(verticalLayout_7);


        verticalLayout_5->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(alerts);
        stats = new QWidget();
        stats->setObjectName(QStringLiteral("stats"));
        stackedWidget->addWidget(stats);
        settings = new QWidget();
        settings->setObjectName(QStringLiteral("settings"));
        stackedWidget->addWidget(settings);

        gridLayout->addWidget(stackedWidget, 0, 0, 2, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        driveButton->setText(QString());
        driveLabel->setText(QApplication::translate("MainWindow", "Drive", 0));
        alertsButton->setText(QString());
        alertsLabel->setText(QApplication::translate("MainWindow", "Alerts", 0));
        statsButton->setText(QString());
        statsLabel->setText(QApplication::translate("MainWindow", "Stats", 0));
        settingsButton->setText(QString());
        settingsLabel->setText(QApplication::translate("MainWindow", "Setting", 0));
        label_4->setText(QApplication::translate("MainWindow", "Throttle", 0));
        label_5->setText(QApplication::translate("MainWindow", "%", 0));
        label_6->setText(QApplication::translate("MainWindow", "Controller Temp", 0));
        label_7->setText(QApplication::translate("MainWindow", "\"\302\260\"", 0));
        label_9->setText(QApplication::translate("MainWindow", "Motor Temp", 0));
        label_8->setText(QApplication::translate("MainWindow", "\"\302\260\"", 0));
        timeLabel->setText(QString());
        dateLabel->setText(QString());
        timerButton->setText(QString());
        canButton->setText(QString());
        alertStatus->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "Avr Power", 0));
        label_10->setText(QApplication::translate("MainWindow", "kW", 0));
        label_13->setText(QApplication::translate("MainWindow", "Battery Current", 0));
        label_12->setText(QApplication::translate("MainWindow", "A", 0));
        label_15->setText(QApplication::translate("MainWindow", "Battery Voltage", 0));
        label_14->setText(QApplication::translate("MainWindow", "V", 0));
        label->setText(QApplication::translate("MainWindow", "Controller Status", 0));
        label_err0->setText(QApplication::translate("MainWindow", "Identification error", 0));
        label_err1->setText(QApplication::translate("MainWindow", "Over voltage", 0));
        label_err2->setText(QApplication::translate("MainWindow", "Low voltage", 0));
        label_err4->setText(QApplication::translate("MainWindow", "motor provide speed feedback", 0));
        label_err5->setText(QApplication::translate("MainWindow", "Internal volts fault", 0));
        label_err6->setText(QApplication::translate("MainWindow", "Over temperature", 0));
        label_err7->setText(QApplication::translate("MainWindow", "Throttle error at power-up", 0));
        label_err9->setText(QApplication::translate("MainWindow", "internal reset", 0));
        label_err10->setText(QApplication::translate("MainWindow", "hall throttle open", 0));
        label_err11->setText(QApplication::translate("MainWindow", "angle sensor open", 0));
        label_err14->setText(QApplication::translate("MainWindow", "Motor over temperature", 0));
        label_err15->setText(QApplication::translate("MainWindow", "Hall Galvanometer sensor error", 0));
        label_3->setText(QApplication::translate("MainWindow", "Battery Status", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGUI_H
