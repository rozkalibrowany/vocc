#include "statistics.h"
#include "ui_statistics.h"
#include "../common/logger.h"
#include <QTableWidgetItem>

#define CLASS_INFO      "stats"


Statistics::Statistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statistics)
{
    LOG (LOG_STATS, "%s - in constructor", CLASS_INFO);

    ui->setupUi(this);
}

Statistics::~Statistics()
{
    LOG (LOG_STATS, "%s - in destructor", CLASS_INFO);

    delete ui;
}


void Statistics::setLapTime(QString lapTime)
{
    LOG (LOG_STATS, "%s - setting lap time - %s", CLASS_INFO,
            lapTime.toStdString().c_str());

    QTableWidgetItem *item = new QTableWidgetItem(lapTime);
    item->setTextAlignment(Qt::AlignCenter);
    ui->tabLapTimes->insertRow(ui->tabLapTimes->rowCount());
    ui->tabLapTimes->setItem(ui->tabLapTimes->rowCount()-1, 0, item);
}
