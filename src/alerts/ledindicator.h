/**
 * \class LedIndicator
 *
 * \brief
 *
 * This class is used to draw led indicator
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
#ifndef LEDINDICATOR_H
#define LEDINDICATOR_H
#include <QAbstractButton>
#include <QColor>
#include <QWidget>
#include <QFrame>

class LedIndicator : public QAbstractButton
{

public:
    /**
     * @brief LedIndicator - costructs LedIndicator object (alert led)
     * @param parent - QWidget parent
     */
    explicit LedIndicator(QWidget *parent);
    ~LedIndicator();

private:
    QColor offColor1, offColor2;
    QColor onColor1, onColor2;
    float scaledSize;

protected:
    /**
     * @brief resizeEvent - reimplemented method called when widget has new geometry
     */
    void resizeEvent(QResizeEvent *);
    /**
     * @brief paintEvent - reimplemented method called when request to repaint a widget occured
     */
    void paintEvent(QPaintEvent *);
};

#endif // LEDINDICATOR_H
