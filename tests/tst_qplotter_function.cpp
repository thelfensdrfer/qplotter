#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "../src/function.hpp"
#include "tst_qplotter_function.hpp"

QPlotterFunctionTest::QPlotterFunctionTest()
{
}

void QPlotterFunctionTest::testSimpleFunction()
{
    double start = -10;
    double end = 10;
    Function f("x + 4", start, end, 0);

    f.calculate();
    QList<Point> points = f.points();
    QCOMPARE(points.count(), qRound(Function::RESOLUTION) + 1);

    QCOMPARE(points.first().x(), start);
    QCOMPARE(points.first().y(), start + 4);

    QCOMPARE(points.last().x(), end);
    QCOMPARE(points.last().y(), end + 4);
}

void QPlotterFunctionTest::testSinus()
{
    double start = -5;
    double end = 5;
    Function f("2*sin(x)", start, end, 0);

    f.calculate();
    QList<Point> points = f.points();
    QCOMPARE(points.count(), qRound(Function::RESOLUTION) + 1);

    QCOMPARE(points.first().x(), start);
    QCOMPARE(QString::number(points.first().y(), 'f', 2), QString("1.92"));

    QCOMPARE(points.last().x(), end);
    QCOMPARE(QString::number(points.last().y(), 'f', 2), QString("-1.92"));
}

void QPlotterFunctionTest::testConstants()
{
    Function f("pow(E, PI/2)", 0, 0, 0);

    f.calculate();
    QList<Point> points = f.points();
    QCOMPARE(points.count(), 1);

    QCOMPARE(points.first().x(), 0.0);
    QCOMPARE(QString::number(points.first().y(), 'f', 2), QString("4.81"));
}

void QPlotterFunctionTest::testSum()
{
    double start = -100;
    double end = -90;
    Function f("pow(E, PI/2) + tan(x)", start, end, 0);

    f.calculate();
    QList<Point> points = f.points();
    QCOMPARE(points.count(), qRound(Function::RESOLUTION) + 1);

    QCOMPARE(points.first().x(), start);
    QCOMPARE(QString::number(points.first().y(), 'f', 2), QString("5.40"));

    QCOMPARE(points.last().x(), end);
    QCOMPARE(QString::number(points.last().y(), 'f', 2), QString("6.81"));
}

void QPlotterFunctionTest::testSquareRoot()
{
    double start = -100;
    double end = -90;
    Function f("sqrt(pow(E, PI/2) + tan(x))", start, end, 0);

    f.calculate();
    QList<Point> points = f.points();
    QCOMPARE(points.count(), qRound(Function::RESOLUTION) + 1);

    QCOMPARE(points.first().x(), start);
    QCOMPARE(QString::number(points.first().y(), 'f', 2), QString("2.32"));

    QCOMPARE(points.last().x(), end);
    QCOMPARE(QString::number(points.last().y(), 'f', 2), QString("2.61"));
}
