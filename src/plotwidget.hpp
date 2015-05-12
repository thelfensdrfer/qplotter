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
