#ifndef FUNCTION_H
#define FUNCTION_H

#include "point.hpp"

#include <QtCore/QObject>
#include <QtCore/QString>

#include <QtScript/QScriptEngine>

#include <QtGui/QPainter>

class Function: public QObject
{
    Q_OBJECT
public:
    explicit Function(QString f, double min = -10, double max = 10, QObject *parent = 0);
    ~Function();

    /**
     * Wie viele Punkte ausgerechnet werden sollen.
     */
    static constexpr double RESOLUTION = 300;

    /**
     * Zeichne die Funktion mittels QPainter.
     *
     * @param painter
     */
    void draw(QPainter *painter);

    /**
     * Gibt die Liste mit allen ausgerechneten Punkten zurück.
     *
     * @return QList<Point>
     */
    QList<Point> points();

    double xMin() const;

    double xMax() const;

    double yMin() const;

    double yMax() const;

    /**
     * Berechne Punkte die später dargestellt werden sollen.
     */
    void calculate();

    void setScaleX(int scaleX);

    void setScaleY(int scaleY);

protected:
    QScriptEngine *createEngine();

    QPointF scaleF(double x, double y) const;

private:
    /**
     * Funktionsstring f(x)
     */
    QString _f;

    /**
     * Kleinster x-Wert der berechnet werden soll.
     */
    double _xMin;

    /**
     * Größter x-Wert der berechnet werden soll.
     */
    double _xMax;

    /**
     * Kleinster y-Wert der berechnet wurde.
     */
    double _yMin;

    /**
     * Größter y-Wert der berechnet wurde.
     */
    double _yMax;

    /**
     * Liste aller Punkte die gerendert werden sollen.
     */
    QList<Point> _points;

    /**
     * Farbe des Graphen.
     */
    QColor _color;

    int _scaleX;

    int _scaleY;
};

#endif // FUNCTION_H
