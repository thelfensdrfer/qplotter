#ifndef TST_QPLOTTER_PLOTTER_HPP
#define TST_QPLOTTER_PLOTTER_HPP

#include <QtCore/QObject>

class QPlotterPlotterTest : public QObject
{
    Q_OBJECT

public:
    QPlotterPlotterTest();

private Q_SLOTS:
    void testScaling();
};

#endif // TST_QPLOTTER_PLOTTER_HPP

