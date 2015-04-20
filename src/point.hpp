#ifndef POINT_H
#define POINT_H

#include <QtCore/QMetaType>
#include <QtCore/QString>

class Point
{
public:
    Point(double x, double y, QString description = ""):
        _x(x),
        _y(y),
        _description(description) {}

    double x() const;

    double y() const;

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
