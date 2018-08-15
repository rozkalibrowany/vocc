#include "rpmwidget.h"
#include "ui_rpmwidget.h"

RpmWidget::RpmWidget(QWidget *parent)
    : QWidget(parent),
      rpm(new Ui::RpmWidget)
{
    rpm->setupUi(this);
}

RpmWidget::~RpmWidget()
{
    delete rpm;
}
