/**
 * \class RpmWidget
 *
 * \brief
 *
 * This class construct UI widget needed for MainWindow UI
 *
 *
 * \author $Author: bv $
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2018/09/05 14:16:20 $
 *
 * Contact: karolsiegied@gmail.com
 *
 */
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
    /// creates a RpmWidget
    explicit RpmWidget(QWidget *parent = 0);
    /// destructs a RpmWidget
    ~RpmWidget();

public slots:
    /// This method is used to update value of rpm widget
    void updateWidget(int value);

private:
    /// This method is used to initialize scene
    void initWidget(void);
    /// This method is used to draw the indicator
    void drawLine(int value);

    int currentNoOfDots; /// keeps information of number of dots needed to paint
    QList<QLabel *> dots; /// keeps QLabel pointers to dots
    QGraphicsScene *scene; /// is a pointer to object of QGraphicScene class
    QString mainColor; /// keeps information about main theme color
    Ui::RpmWidget *rpm; /// pointer to UI of RpmWidget
};

#endif // RPMWIDGET_H
