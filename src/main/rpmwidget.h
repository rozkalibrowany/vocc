/**
 * \class RpmWidget
 *
 * \brief
 *
 * This class construct UI widget needed for MainWindow UI
 *
 * \author Karol Siegieda
 *
 * \version 1.0
 *
 * \date 2018/09/05 14:16:20
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
    /**
     * @brief RpmWidget - creates a RpmWidget
     * @param parent - parent widget
     */
    explicit RpmWidget(QWidget *parent = 0);
    ~RpmWidget();

public slots:
    /**
     * @brief updateWidget - This method is used to update value of rpm widget
     * @param value - method argument passing current rpm value data
     */
    void updateWidget(int value);

private:
    /**
     * @brief initWidget - This method is used to initialize scene
     */
    void initWidget(void);
    /**
     * @brief drawLine - This method is used to draw the indicator
     * @param value - method argument passing current rpm value data
     */
    void drawLine(int value);

    int currentNoOfDots; /// - keeps information of number of dots needed to paint
    QList<QLabel *> dots; /// - keeps QLabel pointers to dots
    QGraphicsScene *scene; /// - is a pointer to object of QGraphicScene class
    QString mainColor; /// - keeps information about main theme color
    Ui::RpmWidget *rpm; /// - pointer to UI of RpmWidget

};
#endif // RPMWIDGET_H
