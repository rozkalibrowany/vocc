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
#include <QPushButton>
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

private slots:
    void chartButtonChanged(QPushButton &button);
    void switchUpperChartData(QPushButton &button);
    void switchBottomChartData(QPushButton &button);

private:
    bool mEnableChartData;
    Chart *chartUpper, *chartBottom;
    QChartView *viewUpper, *viewBottom;
    Ui::Statistics *ui;
    Connections *con;
    QPushButton *lastUpperButtonObject, *lastBottomButtonObject;

    void initializeButtonSignals(void);
    void styleUpdate(QPushButton *button, bool isChanged);
};

#endif // STATISTICS_H
