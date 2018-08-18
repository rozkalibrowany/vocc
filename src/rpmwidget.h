#ifndef RPMWIDGET_H
#define RPMWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGraphicsScene>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QGraphicsEllipseItem>

namespace Ui {
class RpmWidget;
}

class RpmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RpmWidget(QWidget *parent = 0);
    ~RpmWidget();

private:
    void initWidget(void);
    void updateLine(int value);

    QList<QLabel *> dots;
    QGraphicsScene *scene;
    QString mainColor;
    QColor color;
    Ui::RpmWidget *rpm;
};

#endif // RPMWIDGET_H
