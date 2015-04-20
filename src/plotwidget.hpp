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

    void addFunction(QString f);

    void paintEvent(QPaintEvent *event);

private:
    Plotter *_plotter;
};

#endif // PLOTWIDGET_H
