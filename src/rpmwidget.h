#ifndef RPMWIDGET_H
#define RPMWIDGET_H

#include <QObject>
#include <QWidget>

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
    Ui::RpmWidget *rpm;
};

#endif // RPMWIDGET_H
