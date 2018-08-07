/********************************************************************************
** Form generated from reading UI file 'rpmwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RPMWIDGET_H
#define UI_RPMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rpm_widget
{
public:
    QLabel *rpmCaption;
    QGraphicsView *graphicsView;
    QLCDNumber *rpmNumber;
    QLabel *black_circle;
    QWidget *dots_widget;
    QLabel *circle1;
    QLabel *circle2;
    QLabel *circle3;
    QLabel *circle4;
    QLabel *circle5;
    QLabel *circle6;
    QLabel *circle7;
    QLabel *circle8;
    QLabel *circle9;
    QLabel *circle10;
    QLabel *circle11;
    QLabel *circle12;
    QLabel *circle13;
    QLabel *circle14;
    QLabel *circle15;
    QLabel *circle16;
    QLabel *circle17;
    QLabel *circle18;
    QLabel *circle19;
    QLabel *circle20;
    QLabel *circle21;
    QLabel *circle22;
    QLabel *circle23;
    QLabel *pintop;
    QWidget *dark_dots_widget;
    QLabel *circle1_3;
    QLabel *circle2_3;
    QLabel *circle3_3;
    QLabel *circle4_3;
    QLabel *circle5_3;
    QLabel *circle6_3;
    QLabel *circle7_3;
    QLabel *circle8_3;
    QLabel *circle9_3;
    QLabel *circle10_3;
    QLabel *circle11_3;
    QLabel *circle12_3;
    QLabel *circle13_3;
    QLabel *circle14_3;
    QLabel *circle15_3;
    QLabel *circle16_3;
    QLabel *circle17_3;
    QLabel *circle18_3;
    QLabel *circle19_3;
    QLabel *circle20_3;
    QLabel *circle21_3;
    QLabel *circle22_3;
    QLabel *circle23_3;
    QLabel *rpmCaption_2;
    QLabel *rpmCaption_3;
    QLabel *rpmCaption_4;
    QLabel *rpmCaption_5;
    QLabel *rpmCaption_6;
    QLabel *rpmCaption_7;
    QLabel *rpmCaption_8;

    void setupUi(QWidget *rpm_widget)
    {
        if (rpm_widget->objectName().isEmpty())
            rpm_widget->setObjectName(QStringLiteral("rpm_widget"));
        rpm_widget->resize(301, 272);
        rpm_widget->setStyleSheet(QStringLiteral("background: none;"));
        rpmCaption = new QLabel(rpm_widget);
        rpmCaption->setObjectName(QStringLiteral("rpmCaption"));
        rpmCaption->setGeometry(QRect(120, 240, 51, 21));
        QFont font;
        font.setFamily(QStringLiteral("Gill Sans MT"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(9);
        rpmCaption->setFont(font);
        rpmCaption->setStyleSheet(QLatin1String("color: white; \n"
"background:none;\n"
"font: 75 italic 14pt \"Gill Sans MT\" ;\n"
"color: #6affcd;"));
        rpmCaption->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        graphicsView = new QGraphicsView(rpm_widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 301, 270));
        graphicsView->setStyleSheet(QStringLiteral("background: transparent; "));
        rpmNumber = new QLCDNumber(rpm_widget);
        rpmNumber->setObjectName(QStringLiteral("rpmNumber"));
        rpmNumber->setGeometry(QRect(74, 173, 151, 61));
        rpmNumber->setStyleSheet(QLatin1String("color: #6affcd;\n"
"background-color: rgba(255, 255, 255, 20)"));
        rpmNumber->setFrameShape(QFrame::NoFrame);
        rpmNumber->setDigitCount(5);
        black_circle = new QLabel(rpm_widget);
        black_circle->setObjectName(QStringLiteral("black_circle"));
        black_circle->setGeometry(QRect(0, 0, 301, 301));
        black_circle->setLayoutDirection(Qt::RightToLeft);
        black_circle->setStyleSheet(QStringLiteral("background-color: none;"));
        black_circle->setFrameShape(QFrame::Box);
        black_circle->setFrameShadow(QFrame::Sunken);
        black_circle->setPixmap(QPixmap(QString::fromUtf8("img/blackcircle.png")));
        black_circle->setScaledContents(true);
        dots_widget = new QWidget(rpm_widget);
        dots_widget->setObjectName(QStringLiteral("dots_widget"));
        dots_widget->setEnabled(true);
        dots_widget->setGeometry(QRect(0, 0, 301, 301));
        circle1 = new QLabel(dots_widget);
        circle1->setObjectName(QStringLiteral("circle1"));
        circle1->setGeometry(QRect(14, 195, 31, 31));
        circle1->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle1.png")));
        circle1->setScaledContents(true);
        circle2 = new QLabel(dots_widget);
        circle2->setObjectName(QStringLiteral("circle2"));
        circle2->setGeometry(QRect(7, 172, 31, 31));
        circle2->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle2.png")));
        circle2->setScaledContents(true);
        circle3 = new QLabel(dots_widget);
        circle3->setObjectName(QStringLiteral("circle3"));
        circle3->setGeometry(QRect(1, 148, 31, 31));
        circle3->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle3.png")));
        circle3->setScaledContents(true);
        circle4 = new QLabel(dots_widget);
        circle4->setObjectName(QStringLiteral("circle4"));
        circle4->setGeometry(QRect(2, 124, 31, 31));
        circle4->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle4.png")));
        circle4->setScaledContents(true);
        circle5 = new QLabel(dots_widget);
        circle5->setObjectName(QStringLiteral("circle5"));
        circle5->setGeometry(QRect(8, 99, 31, 31));
        circle5->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle5.png")));
        circle5->setScaledContents(true);
        circle6 = new QLabel(dots_widget);
        circle6->setObjectName(QStringLiteral("circle6"));
        circle6->setGeometry(QRect(18, 75, 31, 31));
        circle6->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle6.png")));
        circle6->setScaledContents(true);
        circle7 = new QLabel(dots_widget);
        circle7->setObjectName(QStringLiteral("circle7"));
        circle7->setGeometry(QRect(31, 54, 31, 31));
        circle7->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle7.png")));
        circle7->setScaledContents(true);
        circle8 = new QLabel(dots_widget);
        circle8->setObjectName(QStringLiteral("circle8"));
        circle8->setGeometry(QRect(48, 36, 31, 31));
        circle8->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle8.png")));
        circle8->setScaledContents(true);
        circle9 = new QLabel(dots_widget);
        circle9->setObjectName(QStringLiteral("circle9"));
        circle9->setGeometry(QRect(68, 21, 31, 31));
        circle9->setStyleSheet(QStringLiteral(""));
        circle9->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle9.png")));
        circle9->setScaledContents(true);
        circle10 = new QLabel(dots_widget);
        circle10->setObjectName(QStringLiteral("circle10"));
        circle10->setGeometry(QRect(89, 11, 31, 31));
        circle10->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle10.png")));
        circle10->setScaledContents(true);
        circle11 = new QLabel(dots_widget);
        circle11->setObjectName(QStringLiteral("circle11"));
        circle11->setEnabled(true);
        circle11->setGeometry(QRect(112, 4, 31, 31));
        circle11->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle11.png")));
        circle11->setScaledContents(true);
        circle12 = new QLabel(dots_widget);
        circle12->setObjectName(QStringLiteral("circle12"));
        circle12->setGeometry(QRect(136, 1, 31, 31));
        circle12->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle12.png")));
        circle12->setScaledContents(true);
        circle13 = new QLabel(dots_widget);
        circle13->setObjectName(QStringLiteral("circle13"));
        circle13->setGeometry(QRect(159, 5, 31, 31));
        circle13->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle13.png")));
        circle13->setScaledContents(true);
        circle14 = new QLabel(dots_widget);
        circle14->setObjectName(QStringLiteral("circle14"));
        circle14->setGeometry(QRect(182, 11, 31, 31));
        circle14->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle14.png")));
        circle14->setScaledContents(true);
        circle15 = new QLabel(dots_widget);
        circle15->setObjectName(QStringLiteral("circle15"));
        circle15->setGeometry(QRect(205, 21, 31, 31));
        circle15->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle15.png")));
        circle15->setScaledContents(true);
        circle16 = new QLabel(dots_widget);
        circle16->setObjectName(QStringLiteral("circle16"));
        circle16->setGeometry(QRect(224, 37, 31, 31));
        circle16->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle16.png")));
        circle16->setScaledContents(true);
        circle17 = new QLabel(dots_widget);
        circle17->setObjectName(QStringLiteral("circle17"));
        circle17->setGeometry(QRect(241, 55, 31, 31));
        circle17->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle17.png")));
        circle17->setScaledContents(true);
        circle18 = new QLabel(dots_widget);
        circle18->setObjectName(QStringLiteral("circle18"));
        circle18->setGeometry(QRect(253, 75, 31, 31));
        circle18->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle18.png")));
        circle18->setScaledContents(true);
        circle19 = new QLabel(dots_widget);
        circle19->setObjectName(QStringLiteral("circle19"));
        circle19->setGeometry(QRect(263, 98, 31, 31));
        circle19->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle19.png")));
        circle19->setScaledContents(true);
        circle20 = new QLabel(dots_widget);
        circle20->setObjectName(QStringLiteral("circle20"));
        circle20->setGeometry(QRect(269, 121, 31, 31));
        circle20->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle20.png")));
        circle20->setScaledContents(true);
        circle21 = new QLabel(dots_widget);
        circle21->setObjectName(QStringLiteral("circle21"));
        circle21->setGeometry(QRect(270, 145, 31, 31));
        circle21->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle21.png")));
        circle21->setScaledContents(true);
        circle22 = new QLabel(dots_widget);
        circle22->setObjectName(QStringLiteral("circle22"));
        circle22->setGeometry(QRect(266, 169, 31, 31));
        circle22->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle22.png")));
        circle22->setScaledContents(true);
        circle23 = new QLabel(dots_widget);
        circle23->setObjectName(QStringLiteral("circle23"));
        circle23->setGeometry(QRect(257, 191, 31, 31));
        circle23->setPixmap(QPixmap(QString::fromUtf8("img/colorized_circles/circle23.png")));
        circle23->setScaledContents(true);
        pintop = new QLabel(rpm_widget);
        pintop->setObjectName(QStringLiteral("pintop"));
        pintop->setGeometry(QRect(130, 130, 41, 41));
        pintop->setStyleSheet(QStringLiteral("background: none;"));
        pintop->setFrameShape(QFrame::NoFrame);
        pintop->setPixmap(QPixmap(QString::fromUtf8("img/pintop.png")));
        pintop->setScaledContents(true);
        dark_dots_widget = new QWidget(rpm_widget);
        dark_dots_widget->setObjectName(QStringLiteral("dark_dots_widget"));
        dark_dots_widget->setEnabled(true);
        dark_dots_widget->setGeometry(QRect(0, 0, 301, 301));
        circle1_3 = new QLabel(dark_dots_widget);
        circle1_3->setObjectName(QStringLiteral("circle1_3"));
        circle1_3->setGeometry(QRect(14, 195, 31, 31));
        circle1_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle1.png")));
        circle1_3->setScaledContents(true);
        circle2_3 = new QLabel(dark_dots_widget);
        circle2_3->setObjectName(QStringLiteral("circle2_3"));
        circle2_3->setGeometry(QRect(7, 172, 31, 31));
        circle2_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle2.png")));
        circle2_3->setScaledContents(true);
        circle3_3 = new QLabel(dark_dots_widget);
        circle3_3->setObjectName(QStringLiteral("circle3_3"));
        circle3_3->setGeometry(QRect(1, 148, 31, 31));
        circle3_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle3.png")));
        circle3_3->setScaledContents(true);
        circle4_3 = new QLabel(dark_dots_widget);
        circle4_3->setObjectName(QStringLiteral("circle4_3"));
        circle4_3->setGeometry(QRect(2, 124, 31, 31));
        circle4_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle4.png")));
        circle4_3->setScaledContents(true);
        circle5_3 = new QLabel(dark_dots_widget);
        circle5_3->setObjectName(QStringLiteral("circle5_3"));
        circle5_3->setGeometry(QRect(8, 99, 31, 31));
        circle5_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle5.png")));
        circle5_3->setScaledContents(true);
        circle6_3 = new QLabel(dark_dots_widget);
        circle6_3->setObjectName(QStringLiteral("circle6_3"));
        circle6_3->setGeometry(QRect(18, 75, 31, 31));
        circle6_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle6.png")));
        circle6_3->setScaledContents(true);
        circle7_3 = new QLabel(dark_dots_widget);
        circle7_3->setObjectName(QStringLiteral("circle7_3"));
        circle7_3->setGeometry(QRect(31, 54, 31, 31));
        circle7_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle7.png")));
        circle7_3->setScaledContents(true);
        circle8_3 = new QLabel(dark_dots_widget);
        circle8_3->setObjectName(QStringLiteral("circle8_3"));
        circle8_3->setGeometry(QRect(48, 36, 31, 31));
        circle8_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle8.png")));
        circle8_3->setScaledContents(true);
        circle9_3 = new QLabel(dark_dots_widget);
        circle9_3->setObjectName(QStringLiteral("circle9_3"));
        circle9_3->setGeometry(QRect(68, 21, 31, 31));
        circle9_3->setStyleSheet(QStringLiteral(""));
        circle9_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle9.png")));
        circle9_3->setScaledContents(true);
        circle10_3 = new QLabel(dark_dots_widget);
        circle10_3->setObjectName(QStringLiteral("circle10_3"));
        circle10_3->setGeometry(QRect(89, 11, 31, 31));
        circle10_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle10.png")));
        circle10_3->setScaledContents(true);
        circle11_3 = new QLabel(dark_dots_widget);
        circle11_3->setObjectName(QStringLiteral("circle11_3"));
        circle11_3->setEnabled(true);
        circle11_3->setGeometry(QRect(112, 4, 31, 31));
        circle11_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle11.png")));
        circle11_3->setScaledContents(true);
        circle12_3 = new QLabel(dark_dots_widget);
        circle12_3->setObjectName(QStringLiteral("circle12_3"));
        circle12_3->setGeometry(QRect(136, 1, 31, 31));
        circle12_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle12.png")));
        circle12_3->setScaledContents(true);
        circle13_3 = new QLabel(dark_dots_widget);
        circle13_3->setObjectName(QStringLiteral("circle13_3"));
        circle13_3->setGeometry(QRect(159, 5, 31, 31));
        circle13_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle13.png")));
        circle13_3->setScaledContents(true);
        circle14_3 = new QLabel(dark_dots_widget);
        circle14_3->setObjectName(QStringLiteral("circle14_3"));
        circle14_3->setGeometry(QRect(182, 11, 31, 31));
        circle14_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle14.png")));
        circle14_3->setScaledContents(true);
        circle15_3 = new QLabel(dark_dots_widget);
        circle15_3->setObjectName(QStringLiteral("circle15_3"));
        circle15_3->setGeometry(QRect(205, 21, 31, 31));
        circle15_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle15.png")));
        circle15_3->setScaledContents(true);
        circle16_3 = new QLabel(dark_dots_widget);
        circle16_3->setObjectName(QStringLiteral("circle16_3"));
        circle16_3->setGeometry(QRect(224, 37, 31, 31));
        circle16_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle16.png")));
        circle16_3->setScaledContents(true);
        circle17_3 = new QLabel(dark_dots_widget);
        circle17_3->setObjectName(QStringLiteral("circle17_3"));
        circle17_3->setGeometry(QRect(241, 55, 31, 31));
        circle17_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle17.png")));
        circle17_3->setScaledContents(true);
        circle18_3 = new QLabel(dark_dots_widget);
        circle18_3->setObjectName(QStringLiteral("circle18_3"));
        circle18_3->setGeometry(QRect(253, 75, 31, 31));
        circle18_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle18.png")));
        circle18_3->setScaledContents(true);
        circle19_3 = new QLabel(dark_dots_widget);
        circle19_3->setObjectName(QStringLiteral("circle19_3"));
        circle19_3->setGeometry(QRect(263, 98, 31, 31));
        circle19_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle19.png")));
        circle19_3->setScaledContents(true);
        circle20_3 = new QLabel(dark_dots_widget);
        circle20_3->setObjectName(QStringLiteral("circle20_3"));
        circle20_3->setGeometry(QRect(269, 121, 31, 31));
        circle20_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle20.png")));
        circle20_3->setScaledContents(true);
        circle21_3 = new QLabel(dark_dots_widget);
        circle21_3->setObjectName(QStringLiteral("circle21_3"));
        circle21_3->setGeometry(QRect(270, 145, 31, 31));
        circle21_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle21.png")));
        circle21_3->setScaledContents(true);
        circle22_3 = new QLabel(dark_dots_widget);
        circle22_3->setObjectName(QStringLiteral("circle22_3"));
        circle22_3->setGeometry(QRect(266, 169, 31, 31));
        circle22_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle22.png")));
        circle22_3->setScaledContents(true);
        circle23_3 = new QLabel(dark_dots_widget);
        circle23_3->setObjectName(QStringLiteral("circle23_3"));
        circle23_3->setGeometry(QRect(257, 191, 31, 31));
        circle23_3->setPixmap(QPixmap(QString::fromUtf8("img/dark_colorized_circles/circle23.png")));
        circle23_3->setScaledContents(true);
        rpmCaption_2 = new QLabel(rpm_widget);
        rpmCaption_2->setObjectName(QStringLiteral("rpmCaption_2"));
        rpmCaption_2->setGeometry(QRect(30, 130, 20, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Gill Sans MT"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(9);
        rpmCaption_2->setFont(font1);
        rpmCaption_2->setStyleSheet(QLatin1String("color: white; \n"
"background:none;\n"
"font: 75 italic 12pt \"Gill Sans MT\" ;\n"
"color: #6affcd;"));
        rpmCaption_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rpmCaption_3 = new QLabel(rpm_widget);
        rpmCaption_3->setObjectName(QStringLiteral("rpmCaption_3"));
        rpmCaption_3->setGeometry(QRect(70, 60, 20, 20));
        rpmCaption_3->setFont(font1);
        rpmCaption_3->setStyleSheet(QLatin1String("color: white; \n"
"background:none;\n"
"font: 75 italic 12pt \"Gill Sans MT\" ;\n"
"color: #6affcd;"));
        rpmCaption_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rpmCaption_4 = new QLabel(rpm_widget);
        rpmCaption_4->setObjectName(QStringLiteral("rpmCaption_4"));
        rpmCaption_4->setGeometry(QRect(140, 40, 16, 16));
        rpmCaption_4->setFont(font1);
        rpmCaption_4->setStyleSheet(QLatin1String("color: white; \n"
"background:none;\n"
"font: 75 italic 12pt \"Gill Sans MT\" ;\n"
"color: #6affcd;"));
        rpmCaption_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rpmCaption_5 = new QLabel(rpm_widget);
        rpmCaption_5->setObjectName(QStringLiteral("rpmCaption_5"));
        rpmCaption_5->setGeometry(QRect(200, 60, 20, 20));
        rpmCaption_5->setFont(font1);
        rpmCaption_5->setStyleSheet(QLatin1String("color: white; \n"
"background:none;\n"
"font: 75 italic 12pt \"Gill Sans MT\" ;\n"
"color: #6affcd;"));
        rpmCaption_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rpmCaption_6 = new QLabel(rpm_widget);
        rpmCaption_6->setObjectName(QStringLiteral("rpmCaption_6"));
        rpmCaption_6->setGeometry(QRect(240, 130, 20, 21));
        rpmCaption_6->setFont(font1);
        rpmCaption_6->setStyleSheet(QLatin1String("color: white; \n"
"background:none;\n"
"font: 75 italic 12pt \"Gill Sans MT\" ;\n"
"color: #6affcd;"));
        rpmCaption_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rpmCaption_7 = new QLabel(rpm_widget);
        rpmCaption_7->setObjectName(QStringLiteral("rpmCaption_7"));
        rpmCaption_7->setGeometry(QRect(230, 200, 20, 21));
        rpmCaption_7->setFont(font1);
        rpmCaption_7->setStyleSheet(QLatin1String("color: white; \n"
"background:none;\n"
"font: 75 italic 12pt \"Gill Sans MT\" ;\n"
"color: #6affcd;"));
        rpmCaption_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rpmCaption_8 = new QLabel(rpm_widget);
        rpmCaption_8->setObjectName(QStringLiteral("rpmCaption_8"));
        rpmCaption_8->setGeometry(QRect(110, 100, 91, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        rpmCaption_8->setFont(font2);
        rpmCaption_8->setStyleSheet(QLatin1String("color: white; \n"
"font: 14pt \"Ubuntu Mono\";\n"
"background:none;\n"
"font: 63 italic 14pt \"Ubuntu\";\n"
"color: #6affcd;\n"
"font: italic 14pt \"Ubuntu\";"));
        rpmCaption_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        black_circle->raise();
        dark_dots_widget->raise();
        dots_widget->raise();
        graphicsView->raise();
        pintop->raise();
        rpmCaption->raise();
        rpmNumber->raise();
        rpmCaption_2->raise();
        rpmCaption_3->raise();
        rpmCaption_4->raise();
        rpmCaption_5->raise();
        rpmCaption_6->raise();
        rpmCaption_7->raise();
        rpmCaption_8->raise();

        retranslateUi(rpm_widget);

        QMetaObject::connectSlotsByName(rpm_widget);
    } // setupUi

    void retranslateUi(QWidget *rpm_widget)
    {
        rpm_widget->setWindowTitle(QApplication::translate("rpm_widget", "Form", 0));
        rpmCaption->setText(QApplication::translate("rpm_widget", "km/h", 0));
        black_circle->setText(QString());
        circle1->setText(QString());
        circle2->setText(QString());
        circle3->setText(QString());
        circle4->setText(QString());
        circle5->setText(QString());
        circle6->setText(QString());
        circle7->setText(QString());
        circle8->setText(QString());
        circle9->setText(QString());
        circle10->setText(QString());
        circle11->setText(QString());
        circle12->setText(QString());
        circle13->setText(QString());
        circle14->setText(QString());
        circle15->setText(QString());
        circle16->setText(QString());
        circle17->setText(QString());
        circle18->setText(QString());
        circle19->setText(QString());
        circle20->setText(QString());
        circle21->setText(QString());
        circle22->setText(QString());
        circle23->setText(QString());
        pintop->setText(QString());
        circle1_3->setText(QString());
        circle2_3->setText(QString());
        circle3_3->setText(QString());
        circle4_3->setText(QString());
        circle5_3->setText(QString());
        circle6_3->setText(QString());
        circle7_3->setText(QString());
        circle8_3->setText(QString());
        circle9_3->setText(QString());
        circle10_3->setText(QString());
        circle11_3->setText(QString());
        circle12_3->setText(QString());
        circle13_3->setText(QString());
        circle14_3->setText(QString());
        circle15_3->setText(QString());
        circle16_3->setText(QString());
        circle17_3->setText(QString());
        circle18_3->setText(QString());
        circle19_3->setText(QString());
        circle20_3->setText(QString());
        circle21_3->setText(QString());
        circle22_3->setText(QString());
        circle23_3->setText(QString());
        rpmCaption_2->setText(QApplication::translate("rpm_widget", "1", 0));
        rpmCaption_3->setText(QApplication::translate("rpm_widget", "2", 0));
        rpmCaption_4->setText(QApplication::translate("rpm_widget", "3", 0));
        rpmCaption_5->setText(QApplication::translate("rpm_widget", "4", 0));
        rpmCaption_6->setText(QApplication::translate("rpm_widget", "5", 0));
        rpmCaption_7->setText(QApplication::translate("rpm_widget", "6", 0));
        rpmCaption_8->setText(QApplication::translate("rpm_widget", "rpm * 1000", 0));
    } // retranslateUi

};

namespace Ui {
    class rpm_widget: public Ui_rpm_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RPMWIDGET_H
