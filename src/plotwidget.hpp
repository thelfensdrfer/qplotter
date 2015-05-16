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
     * Setze Zoom Wert.
     *
     * @param value
     */
    void setZoom(const double value);

private:
    /**
     * Der Funktionsplotter.
     */
    Plotter *_plotter;

    /**
     * Ob Antialiasing aktiviert ist.
     */
    bool _isAntialiased;

    /**
     * Zoom-Wert.
     */
    double _zoom;
};

#endif // PLOTWIDGET_H
