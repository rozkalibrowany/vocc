/**
 * \class ControllerWidget
 *
 * \brief
 *
 * This class is used to display controller alerts (as QWidget)
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
#ifndef CONTROLLERWIDGET_H
#define CONTROLLERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QMap>

namespace Ui {
class ControllerWidget;
}

class ControllerWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief ControllerWidget - construct ControllerWidget object
     * @param parent - is a parent QWidget
     */
    explicit ControllerWidget(QWidget *parent = 0);

    QMap<int, QString> controllerErrors; /// - container that keeps error description

private:
    /**
     * @brief initControllerErrors - method that mapping controller errors
     */
    void initControllerErrors(void);
    Ui::ControllerWidget *con; /// pointer to UI object

};

#endif // CONTROLLERWIDGET_H
