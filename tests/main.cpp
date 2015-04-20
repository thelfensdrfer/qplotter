#include "tst_qplotter_function.hpp"
#include "tst_qplotter_plotter.hpp"

#include <QtCore/QCoreApplication>

#include <QtTest/QTest>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    app.setAttribute(Qt::AA_Use96Dpi, true);

    QPlotterFunctionTest ft;
    QPlotterPlotterTest pt;

    return
        QTest::qExec(&ft, argc, argv) &&
        QTest::qExec(&pt, argc, argv);
}
