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
    explicit Plotter(QObject *parent = 0);
    ~Plotter();

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
     * Skaliert die x und y-Werte auf die skalierte Einheit.
     *
     * @param x
     * @param y
     * @return
     */
    QPointF scaleF(double x, double y) const;

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
    void drawText(int x, int y, QString text, QPainter *painter);

    double _xMin;
    double _xMax;
    double _yMin;
    double _yMax;
};

#endif // PLOTTER_H
