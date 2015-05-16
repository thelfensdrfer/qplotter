#include "plotwidget.hpp"

#include <QtCore/QDebug>

#include <QtGui/QPainter>

PlotWidget::PlotWidget(QWidget *parent): QWidget(parent)
{
    qDebug() << "Creating new PlotWidget";

    this->_plotter = new Plotter;

    this->_isAntialiased = true;
}

PlotWidget::~PlotWidget()
{
    delete this->_plotter;

    qDebug() << "Destroying PlotWidget";
}

void PlotWidget::addFunction(QString f, bool deleteOld)
{
    // TODO: Prüfen ob mehrere Funktionen geplottet werden sollen => sonst erst löschen
    if (deleteOld) {
        delete this->_plotter;
        this->_plotter = NULL;
    }

    if (this->_plotter == NULL)
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
    p.setRenderHints(QPainter::Antialiasing, this->_isAntialiased);
    p.setRenderHint(QPainter::TextAntialiasing, this->_isAntialiased);

    this->_plotter->draw(this, &p);
}

void PlotWidget::setXMin(const double value)
{
    this->_plotter->setXMin(value);
}

void PlotWidget::setXMax(const double value)
{
    this->_plotter->setXMax(value);
}

void PlotWidget::setYMin(const double value)
{
    this->_plotter->setYMin(value);
}

void PlotWidget::setYMax(const double value)
{
    this->_plotter->setYMax(value);
}
