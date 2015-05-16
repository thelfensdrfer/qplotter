#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include "plotter.hpp"

#include <QtCore/QObject>

#include <QtWidgets/QWidget>

#include <QtGui/QPaintEvent>

class PlotWidget: public QWidget
{
    Q_OBJECT
public:
    explicit PlotWidget(QWidget *parent = 0);
    ~PlotWidget();

    /**
     * Fügt dem Plotter eine neue Funktion hinzu.
     *
     * @param f
     */
    void addFunction(QString f, bool deleteOld);

    /**
     * Wird von Qt aufgerufen wenn das Widget gezeichnet werden soll.
     *
     * @param event
     */
    void paintEvent(QPaintEvent *event);

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

private:
    /**
     * Der Funktionsplotter.
     */
    Plotter *_plotter;

    /**
     * Ob Antialiasing aktiviert ist.
     */
    bool _isAntialiased;
};

#endif // PLOTWIDGET_H
