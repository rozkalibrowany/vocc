#ifndef LEDINDICATOR_H
#define LEDINDICATOR_H
#include <QAbstractButton>
#include <QColor>
#include <QWidget>
#include <QFrame>

class LedIndicator : public QAbstractButton
{

public:
    explicit LedIndicator(QWidget *parent);
    ~LedIndicator();

private:
    QColor offColor1, offColor2;
    QColor onColor1, onColor2;
    float scaledSize;

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);
};

#endif // LEDINDICATOR_H
