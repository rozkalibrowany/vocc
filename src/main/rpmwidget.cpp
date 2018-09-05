#include "rpmwidget.h"
#include "ui_rpmwidget.h"
#include "../common/logger.h"
#include "../common/parameters.h"
#include <QDebug>
#include <QtMath>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>


#define CLASS_INFO  "rpm"


RpmWidget::RpmWidget(QWidget *parent)
    : QWidget(parent),
      rpm(new Ui::RpmWidget)
{
    LOG (LOG_RPM, "%s - in contructor", CLASS_INFO);

    rpm->setupUi(this);
    this->initWidget();
}


RpmWidget::~RpmWidget()
{
    LOG (LOG_RPM, "%s - destructor", CLASS_INFO);

    delete rpm;
}


void RpmWidget::initWidget()
{
    LOG (LOG_RPM, "%s - initializing rpm widget", CLASS_INFO);

    dots = rpm->dots_widget->findChildren<QLabel *>();
    for (int i = 0; i < dots.size(); ++i) {
        if (dots.at(i) != NULL)
            dots.at(i)->setVisible(false);
    }

    currentNoOfDots = 0;
    scene = new QGraphicsScene(this);
    rpm->graphicsView->setScene(scene);
    rpm->graphicsView->setSceneRect(0, 0, rpm->graphicsView->frameSize().width(), \
                                    rpm->graphicsView->frameSize().height());
    rpm->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    rpm->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->updateWidget(0);
}

void RpmWidget::drawLine(int value)
{
    LOG (LOG_RPM, "%s - drawing line, value %d", CLASS_INFO, value);

    float x1, x2, y1, y2, lineLength, angle, angleOffset;

    QGraphicsEllipseItem *pintopItem, *dotItem;
    QGraphicsLineItem *lineItem;
    scene->clear();

    /* define colors of line and pintop */
    mainColor = "#22e2a2";
    QColor color(0,0,0);

    /* define shape and thickness of pen */
    color.setNamedColor(mainColor);
    QBrush brush(color);
    QPen pen(brush, 5, Qt::SolidLine, Qt::RoundCap);
    QPen penPintop(brush, 10, Qt::SolidLine, Qt::RoundCap);

    /* determine of point1 coordinates */
    x1 = rpm->graphicsView->width()/2;
    y1 = rpm->graphicsView->height()/2;

    /* determine line length and angle */
    lineLength = (rpm->graphicsView->width()/2) - 10.0;
    angle = (qDegreesToRadians(ANGLE_RANGE) * value)/MAX_RPM_VALUE;
    angleOffset = (360 - ANGLE_RANGE)/2;

    /* determine of point2 coordinates */
    x2 = lineLength * qSin(angle + qDegreesToRadians(angleOffset));
    y2 = (-1) * lineLength * qCos(angle + qDegreesToRadians(angleOffset));

    LOG (LOG_RPM, "%s - x1: %.2f\t y1: %.2f\t x2: %.2f\t y2: %.2f\t lineLength: %.2f\t" \
                  "angle: %.2f\t angleOffset: %.2f", CLASS_INFO, x1, y1, x2, y2, lineLength, angle, angleOffset);

    /* draw pintop */
    QRectF pintop(x1 - 2, y1 - 4, 10, 10);
    pintopItem = new QGraphicsEllipseItem(pintop);
    scene->addItem(pintopItem);
    pintopItem->setPen(penPintop);

    /* draw line */
    QLineF line(x1, y1, x1 - x2, y1 - y2 + 10);
    lineItem = new QGraphicsLineItem(line);
    scene->addItem(lineItem);
    lineItem->setPen(pen);

}

void RpmWidget::updateWidget(int value)
{
    LOG (LOG_RPM, "%s - updating rpm widget by value %d", CLASS_INFO, value);

    int speed, nOfDots;

    /* update LCD display */
    speed = int(value * 0.02827); // gokart speed
    rpm->rpmNumber->display(speed);

    /* update line */
    drawLine(value);

    /* update leds */
    nOfDots = int(value/(MAX_RPM_VALUE / dots.length()));

    LOG (LOG_RPM, "%s - speed: %d km/h\t dots: %d", CLASS_INFO, speed, nOfDots);

    if (nOfDots != currentNoOfDots) {
        for (int i = 0; i < nOfDots; ++i) {
            if (dots.at(i) != NULL && !dots.at(i)->isVisible())
                dots.at(i)->setVisible(true);
        }
        for (int i = nOfDots; i < dots.length(); ++i) {
            if (dots.at(i) != NULL && dots.at(i)->isVisible())
                dots.at(i)->setVisible(false);
        }
    }
    currentNoOfDots = nOfDots;
}
