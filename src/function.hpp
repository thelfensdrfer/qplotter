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
    explicit Function(QString f, double min, double max, double steps, QObject *parent = 0);
    ~Function();

    static uint FUNCTION_COUNTER;

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
     * Berechne Punkte die später dargestellt werden sollen.
     */
    void calculate();

    /**
     * Setzt die Achsen Skalierung.
     *
     * @param scaleX
     */
    void setScale(int scaleX, int scaleY);

    /**
     * Ändert den Wertebereich der Funktion.
     *
     * @param xMin
     * @param xMax
     */
    void setBounds(double xMin, double xMax);

    /**
     * Setzt die Anzahl der Schritte pro Einheit.
     *
     * @param steps
     */
    void setSteps(double steps);

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

    /**
     * Wie viele Werte pro Einheit berechnet werden sollen.
     */
    double _steps;
};

#endif // FUNCTION_H
