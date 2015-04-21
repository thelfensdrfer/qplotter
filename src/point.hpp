#ifndef POINT_H
#define POINT_H

#include <QtCore/QMetaType>
#include <QtCore/QString>

class Point
{
public:
    /**
     * Erstellt einen neuen Punkt mit x/y-Koordinaten und einer optionalen Beschreibung.
     *
     * @param x
     * @param y
     * @param description
     */
    Point(double x, double y, QString description = ""):
        _x(x),
        _y(y),
        _description(description) {}

    /**
     * Gibt den x-Wert zurück.
     *
     * @return
     */
    double x() const;

    /**
     * Gibt den y-Wert zurück.
     *
     * @return
     */
    double y() const;

    /**
     * Gibt die Beschreibung des Punktes zurück.
     *
     * @return
     */
    QString description() const;

private:
    /**
     * x-Koordinate
     */
    double _x;

    /**
     * y-Koordinate
     */
    double _y;

    /**
     * Beschreibung
     */
    QString _description;
};

#endif // POINT_H
