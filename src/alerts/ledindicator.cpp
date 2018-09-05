#include <QColor>
#include <QtGlobal>
#include <QPen>
#include <QPainter>
#include <QRadialGradient>
#include <QPointF>
#include <QBrush>
#include "ledindicator.h"
#include "../common/logger.h"

#define CLASS_INFO          "led"

LedIndicator::LedIndicator(QWidget *parent)
    : QAbstractButton(parent)
{

    LOG (LOG_LEDINDICATOR, "%s - in contructor", CLASS_INFO);

    scaledSize = 600;
    this->setMinimumSize(22, 22);
    this->setCheckable(true);
    this->setStyleSheet("border: 1px solid red");

    /* defining green color of led */
    onColor1 = QColor(153, 255, 153);
    onColor2 = QColor(153, 255, 153);

    /* defining red color of led */
    offColor1 = QColor(255, 77, 77);
    offColor2 = QColor(255, 49, 49);
}

LedIndicator::~LedIndicator()
{

}

void LedIndicator::resizeEvent(QResizeEvent *)
{
    LOG (LOG_LEDINDICATOR, "%s - %s", CLASS_INFO, Q_FUNC_INFO);

    this->update();
}


void LedIndicator::paintEvent(QPaintEvent *)
{
    LOG (LOG_LEDINDICATOR, "%s - %s", CLASS_INFO, Q_FUNC_INFO);

    int realSize;

    realSize = qMin(this->width(), this->height());

    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(1);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(this->width()/2 , this->height()/2);
    painter.scale(realSize / scaledSize, realSize / scaledSize);

    QRadialGradient gradient(QPointF(-450, -450), 1500, QPointF(-450, -450));
//    gradient.setColorAt(0, QColor(245, 245, 245));
//    gradient.setColorAt(1, QColor(120, 120, 120));

//    painter.setPen(pen);
//    painter.setBrush(QBrush(gradient));
//    painter.drawEllipse(QPointF(0, 0), 310, 310);

    painter.setPen(pen);
    if (this->isChecked()) {
        LOG (LOG_LEDINDICATOR, "%s - %s - gradient on", CLASS_INFO, Q_FUNC_INFO);
        gradient.setColorAt(0, this->onColor1);
        gradient.setColorAt(1, this->onColor2);
    } else {
        LOG (LOG_LEDINDICATOR, "%s - %s - gradient off", CLASS_INFO, Q_FUNC_INFO);
        gradient.setColorAt(0, this->offColor1);
        gradient.setColorAt(1, this->offColor2);
    }

    painter.setBrush(QBrush(gradient));
    painter.drawEllipse(QPointF(0, 0), 250, 250);
}
