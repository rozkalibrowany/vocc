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
    explicit ControllerWidget(QWidget *parent = 0);

    QMap<int, QString> controllerErrors;

private:
    Ui::ControllerWidget *con;
    void initControllerErrors(void);
};

#endif // CONTROLLERWIDGET_H
