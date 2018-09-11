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
    explicit Statistics(QWidget *parent = 0);
    ~Statistics();

public slots:
    /**
     * @brief setLapTime - this method sets lap time
     * @param lapTime
     */
    void setLapTime(QString lapTime);

private:
    Ui::Statistics *ui;
};

#endif // STATISTICS_H
