#include "plotwidget.hpp"

#include <QtCore/QDebug>

#include <QtGui/QPainter>

PlotWidget::PlotWidget(QWidget *parent): QWidget(parent)
{
    qDebug() << "Creating new PlotWidget";

    this->_plotter = new Plotter;
}

PlotWidget::~PlotWidget()
{
    delete this->_plotter;

    qDebug() << "Destroying PlotWidget";
}

void PlotWidget::addFunction(QString f)
{
    // TODO: Prüfen ob mehrere Funktionen geplottet werden sollen => sonst erst löschen
    if (this->_plotter != NULL)
        delete this->_plotter;

    this->_plotter = new Plotter;

    // Funktion zu Plotter hinzufügen
    this->_plotter->addFunction(f);

    // Plot neu zeichnen
    this->update();
}

void PlotWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter p(this);
    this->_plotter->draw(this, &p);
}
