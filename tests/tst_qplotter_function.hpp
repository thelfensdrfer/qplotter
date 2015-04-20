#ifndef TST_QPLOTTER_FUNCTION_HPP
#define TST_QPLOTTER_FUNCTION_HPP

#include <QtCore/QObject>

class QPlotterFunctionTest : public QObject
{
    Q_OBJECT

public:
    QPlotterFunctionTest();

private Q_SLOTS:
    void testSimpleFunction();
    void testSinus();
    void testConstants();
    void testSum();
    void testSquareRoot();
};

#endif // TST_QPLOTTER_FUNCTION_HPP

