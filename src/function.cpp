#include "function.hpp"
#include "mathjs.hpp"

#include <float.h>

#include <QtCore/QDebug>

uint Function::FUNCTION_COUNTER = 0;

Function::Function(QString f, double min, double max, double steps, QObject *parent):
    QObject(parent),
    _f(f),
    _xMin(min),
    _xMax(max),
    _steps(steps)
{
    qDebug() << "Creating new Function" << this->_f;

    // Vertausche Min/Max-Werte falls Benutzer sie falsch herum eingeben hat
    if (this->_xMin > this->_xMax) {
        this->_xMin = max;
        this->_xMax = min;
    }

    this->_yMin = DBL_MAX;
    this->_yMax = -DBL_MAX;

    // Zufällige Farbe für Graphen bestimmen
    QList<QColor> colors;
    colors.append(QColor(200, 20, 20)); // Rot
    colors.append(QColor(20, 20, 200)); // Blau
    colors.append(QColor(20, 200, 20)); // Grün
    colors.append(QColor(200, 200, 20)); // Gelb

    this->_color = colors.at(Function::FUNCTION_COUNTER % colors.size());
    Function::FUNCTION_COUNTER++;

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

        // Zeichne von der letzten zu der aktuellen Position
        f.lineTo(this->scaleF(point.x(), point.y()));
    }

    // Setze Zeicheneigenschaften des Pfads
    QBrush functionBrush;
    functionBrush.setStyle(Qt::NoBrush);

    painter->setBrush(functionBrush);
    painter->setPen(this->_color);

    // Zeichne Pfad
    painter->drawPath(f);
}

QList<Point> Function::points() const
{
    return this->_points;
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

    // Skript-Engine erstellen
    QScriptEngine *engine = this->createEngine();

    qDebug() << "Calculate values for" << this->_f << "from" << this->_xMin << "to" << this->_xMax << "with step width of" << this->_steps;

    // Funktionswerte durchlaufen
    for (double x = this->_xMin; x <= this->_xMax; x += this->_steps) {
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

void Function::setScale(int scaleX, int scaleY)
{
    this->_scaleX = scaleX;
    this->_scaleY = scaleY;
}

void Function::setBounds(double xMin, double xMax)
{
    this->_xMin = xMin;
    this->_xMax = xMax;
}

void Function::setSteps(double steps)
{
    qDebug() << "Function: Steps: " << steps;
    this->_steps = steps;
}

QPointF Function::scaleF(double x, double y) const
{
    return QPointF(this->_scaleX * x, this->_scaleY * y);
}
