#include "settings.h"
#include "ui_settings.h"
#include "../logger.h"

#define CLASS_INFO      "settings"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    settings(new Ui::Settings)
{
    LOG (LOG_SETTINGS, "%s - in contructor", CLASS_INFO);

    settings->setupUi(this);
}

Settings::~Settings()
{
    delete settings;
}
