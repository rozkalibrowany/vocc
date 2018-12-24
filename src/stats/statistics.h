/**
 * \class Statistics
 *
 * \brief
 *
 * This class construct Statistics widget to display data
 *
 *
 * \author $Author: bv $
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2018/09/05 14:16:20 $
 *
 * Contact: karolsiegied@gmail.com
 *
 */
#ifndef STATISTICS_H
#define STATISTICS_H

#include <QWidget>
#include "chart.h"
#include "../connections/connections.h"

namespace Ui {
class Statistics;
}

class Statistics : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Statistics - costructs Statistics widget
     * @param parent
     */
    explicit Statistics(QWidget *parent, Connections *connection);
    ~Statistics();

public slots:
    void enableChartData(void);
    void disableChartData(void);

private:
    Chart *chartUpper, *chartBottom;
    QChartView *viewUpper, *viewBottom;
    Ui::Statistics *ui;
    Connections *con;
};

#endif // STATISTICS_H
