#ifndef PLOTTER_H
#define PLOTTER_H

#include "function.hpp"

#include <QtCore/QObject>
#include <QtCore/QString>

#include <QtWidgets/QWidget>

#include <QtGui/QPainter>

class Plotter: public QObject
{
    Q_OBJECT
public:
    /**
     * Erstellt einen neuen Plotter
     *
     * @param parent
     */
    explicit Plotter(QObject *parent = 0);
    ~Plotter();

    /**
     * Standard für den kleinsten darzustellenden x-Wert.
     */
    static const int DEFAULT_X_MIN = -10;

    /**
     * Standard für den größten darzustellenden x-Wert.
     */
    static const int DEFAULT_X_MAX = 10;

    /**
     * Standard für den kleinsten darzustellenden y-Wert.
     */
    static const int DEFAULT_Y_MIN = -10;

    /**
     * Standard für den größten darzustellenden y-Wert.
     */
    static const int DEFAULT_Y_MAX = 10;

    /**
     * Anzahl an dargestellten Zahlen pro Achse (Zoom?)
     */
    static const int STEPS = 20;

    /**
     * Füge Funktion zu dem Plot hinzu.
     *
     * @param f
     */
    void addFunction(QString f);

    /**
     * Zeichne Hintergrund und Funktionen mittels QPainter.
     */
    void draw(QWidget *widget, QPainter *painter);

    /**
     * Berechnet wie viele Pixel einer Einheit entsprechen.
     *
     * @param painter
     */
    void calculateScaling(QWidget *widget, QPainter *painter);

    /**
     * Skaliert die x und y-Werte auf die skalierte Einheit.
     *
     * @param x
     * @param y
     * @return
     */
    QPoint scale(double x, double y) const;

    /**
     * Setze x-Min Wert.
     *
     * @param value
     */
    void setXMin(const double value);

    /**
     * Setze x-Max Wert.
     *
     * @param value
     */
    void setXMax(const double value);

    /**
     * Setze y-Min Wert.
     *
     * @param value
     */
    void setYMin(const double value);

    /**
     * Setze y-Max Wert.
     *
     * @param value
     */
    void setYMax(const double value);

protected:
    /**
     * Draw the widget background.
     *
     * @param widget
     * @param painter
     */
    void drawBackground(QWidget *widget, QPainter *painter);

    /**
     * Draw the x axis.
     *
     * @param widget
     * @param painter
     * @param center
     * @param pen
     */
    void drawXAxis(QPainter *painter, QBrush *axesBrush, QBrush *labelBrush);

    /**
     * Draw the y axis.
     *
     * @param widget
     * @param painter
     * @param center
     * @param pen
     */
    void drawYAxis(QPainter *painter, QBrush *axesBrush, QBrush *labelBrush);

    /**
     * Schriftart der Label.
     */
    QFont _font;

private:
    /**
     * Liste aller Funktionen die dargestellt werden sollen.
     */
    QList<Function*> _functions;

    /**
     * x-Achsen Skala.
     *
     * Ein Wert von 20 bedeutet z.B. das alle 20 Pixel eine Einheit dargestellt wird.
     */
    double _scaleX;

    /**
     * y-Achsen Skala.
     *
     * Ein Wert von 20 bedeutet z.B. das alle 20 Pixel eine Einheit dargestellt wird.
     */
    double _scaleY;

    /**
     * Zeichnet einen Text.
     *
     * @param x
     * @param y
     * @param text
     * @param painter
     */
    void drawText(QPoint p, QString text, QPainter *painter);

    /**
     * Kleinster darzustellender x-Wert.
     */
    double _xMin;

    /**
     * Größter darzustellender x-Wert.
     */
    double _xMax;

    /**
     * Kleinster darzustellender y-Wert.
     */
    double _yMin;

    /**
     * Größter darzustellender y-Wert.
     */
    double _yMax;

signals:
    /**
     * Wird ausgelöst wenn sich die Achseneinteilung geändert hat.
     *
     * @param xMin
     * @param xMax
     */
    void boundsChanged(double xMin, double xMax);

private slots:
    /**
     * Berechnet die Funktionswerte für den Wertebereich neu.
     *
     * @param xMin
     * @param xMax
     */
    void onBoundsChanged(double xMin, double xMax);
};

#endif // PLOTTER_H
