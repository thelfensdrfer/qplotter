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
    QList<Point> points() const;

    /**
     * Gibt den minimalen x-Wert zurück.
     *
     * @return
     */
    double xMin() const;

    /**
     * Gibt den maximalen x-Wert zurück.
     *
     * @return
     */
    double xMax() const;

    /**
     * Gibt den minimalen y-Wert zurück.
     *
     * @return
     */
    double yMin() const;

    /**
     * Gibt den maximalen y-Wert zurück.
     *
     * @return
     */
    double yMax() const;

    /**
     * Berechne Punkte die später dargestellt werden sollen.
     */
    void calculate();

    /**
     * Setzt die x-Achsen Skalierung.
     *
     * @param scaleX
     */
    void setScaleX(int scaleX);

    /**
     * Setzt die y-Achsen Skalierung.
     *
     * @param scaleY
     */
    void setScaleY(int scaleY);

protected:
    /**
     * Erstellt die QScriptEngine mit mathematischen Funktionen und Konstanten.
     *
     * @return
     */
    QScriptEngine *createEngine();

    /**
     * Skaliert die Koordinaten x und y auf die entsprechenden Pixel.
     * @param x
     * @param y
     * @return
     */
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

    /**
     * x-Skalierung der Einheiten.
     */
    int _scaleX;

    /**
     * y-Skalierung der Einheiten.
     */
    int _scaleY;
};

#endif // FUNCTION_H
