#ifndef TESTFORM_H
#define TESTFORM_H

#include <QWidget>

namespace Ui {
class testform;
}

class testform : public QWidget
{
    Q_OBJECT

public:
    explicit testform(QWidget *parent);
    ~testform();

private:
    Ui::testform *uii;
};

#endif // TESTFORM_H
