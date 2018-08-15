#include "testform.h"
#include "ui_testform.h"

testform::testform(QWidget *parent) :
    QWidget(parent),
    uii(new Ui::testform)
{
    uii->setupUi(this);
}

testform::~testform()
{
    delete uii;
}
