#include "function.hpp"
#include "mathjs.hpp"

#include <float.h>

#include <QtCore/QDebug>

Function::Function(QString f, double min, double max, QObject *parent):
    QObject(parent),
    _f(f),
    _xMin(min),
    _xMax(max)
{
    qDebug() << "Creating new Function" << this->_f;

    // Vertausche Min/Max-Werte falls Benutzer sie falsch herum eingeben hat
    if (this->_xMin > this->_xMax) {
        this->_xMin = max;
        this->_xMax = min;
    }

    this->_yMin = DBL_MAX;
    this->_yMax = -DBL_MAX;

    this->_color = QColor(200, 20, 20);

    this->calculate();
}

Function::~Function()
{
    qDebug() << "Destroying Function" << this->_f;
}

void Function::draw(QPainter *painter)
{
    qDebug() << "Draw Function" << this->_f;

    if (this->_points.count() == 0)
        return;

    QPainterPath f;

    for (int i = 0; i < this->_points.count(); i++) {
        Point point = this->_points.at(i);

        if (i == 0) {
            // Pfad startet
            f.moveTo(this->scaleF(point.x(), point.y()));
            continue;
        }

        f.lineTo(this->scaleF(point.x(), point.y()));
    }

    QBrush functionBrush;
    functionBrush.setColor(this->_color);

    painter->setBrush(functionBrush);
    painter->drawPath(f);
}

QList<Point> Function::points()
{
    return this->_points;
}

double Function::xMin() const
{
    return this->_xMin;
}

double Function::xMax() const
{
    return this->_xMax;
}

double Function::yMin() const
{
    return this->_yMin;
}

double Function::yMax() const
{
    return this->_yMax;
}

QScriptEngine *Function::createEngine()
{
    QScriptEngine *engine = new QScriptEngine;

    // Funktionen aus math.h in die QScript Umgebung einfügen
    engine->globalObject().setProperty("sin", engine->newFunction(MathJs::sin, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("cos", engine->newFunction(MathJs::cos, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("tan", engine->newFunction(MathJs::tan, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("asin", engine->newFunction(MathJs::asin, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("acos", engine->newFunction(MathJs::acos, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("atan", engine->newFunction(MathJs::atan, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("atan2", engine->newFunction(MathJs::atan2, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("sinh", engine->newFunction(MathJs::sinh, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("cosh", engine->newFunction(MathJs::cosh, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("tanh", engine->newFunction(MathJs::tanh, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("exp", engine->newFunction(MathJs::sin, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("log", engine->newFunction(MathJs::log, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("log10", engine->newFunction(MathJs::log10, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("pow", engine->newFunction(MathJs::pow, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("sqrt", engine->newFunction(MathJs::sqrt, 1), QScriptValue::ReadOnly);
    engine->globalObject().setProperty("fabs", engine->newFunction(MathJs::fabs, 1), QScriptValue::ReadOnly);

    // Konstanten in die QScript Umgebung einfügen
    engine->globalObject().setProperty("PI", MathJs::PI);
    engine->globalObject().setProperty("E", MathJs::E);

    return engine;
}

void Function::calculate()
{
    qDebug() << "Calculating";

    // Punkte löschen falls schon vorhanden
    this->_points.clear();

    // Anzahl an y-Werten zwischen x-Werten berechnen
    double steps;

    if (this->_xMax - this->_xMin != 0)
        steps = ((this->_xMax - this->_xMin) / Function::RESOLUTION);
    else
        steps = 1;

    // Skript-Engine erstellen
    QScriptEngine *engine = this->createEngine();

    // Funktionswerte durchlaufen
    for (double x = this->_xMin; x <= this->_xMax; x += steps) {
        // Aktuellen x-Wert der x-Variable zuweisen
        engine->globalObject().setProperty("x", x);

        // Ergebnis der Funktion abrufen
        QScriptValue y = engine->evaluate(this->_f);

        if (y.isNumber()) {
            double yValue = (double) y.toNumber();
            this->_points.append(Point(x, yValue, ""));

            if (yValue < this->_yMin)
                this->_yMin = yValue;

            if (yValue > this->_yMax)
                this->_yMax = yValue;
        } else {
            qWarning() << "Could not calculate f(" << x << ") for" << this->_f << ": " << y.toString();
        }
    }

    delete engine;
}

void Function::setScaleY(int scaleY)
{
    this->_scaleY = scaleY;
}

void Function::setScaleX(int scaleX)
{
    this->_scaleX = scaleX;
}

QPointF Function::scaleF(double x, double y) const
{
    return QPointF(this->_scaleX * x, this->_scaleY * y);
}
