#include "plotter.hpp"

#include <float.h>

#include <QtCore/QDebug>

Plotter::Plotter(QWidget *widget, QObject *parent): QObject(parent)
{
    qDebug() << "Creating new Plotter";

    this->setZoom(Plotter::DEFAULT_ZOOM);
    this->calculateSteps(widget);
}

Plotter::~Plotter()
{
    for (int i = 0; i < this->_functions.count(); i++) {
        delete this->_functions.at(i);
    }

    this->_functions.clear();

    qDebug() << "Destroying Plotter";
}

void Plotter::addFunction(QString f)
{
    qDebug() << "Add function" << f << "to plotter" << this->_steps;

    Function *func = new Function(f, this->_xMin, this->_xMax, this->_steps);
    this->_functions.append(func);
}

void Plotter::draw(QWidget *widget, QPainter *painter)
{
    qDebug() << "Draw plotter";

    // Setze Schrift
    this->_font = painter->font();
    this->_font.setPointSize(10);
    this->_font.setFamily("monospace");

    // Zeichne Hintergrund
    this->drawBackground(widget, painter);

    // Skalierung
    this->calculateScaling(widget, painter);

    // Schrittweite
    this->calculateSteps(widget);

    // Zeichne Achsen
    QBrush axesBrush;
    axesBrush.setColor(QColor(150, 150, 150));
    axesBrush.setStyle(Qt::SolidPattern);

    QBrush labelBrush;
    labelBrush.setColor(QColor(100, 100, 100));
    labelBrush.setStyle(Qt::SolidPattern);

    this->drawXAxis(painter, &axesBrush, &labelBrush);
    this->drawYAxis(painter, &axesBrush, &labelBrush);

    // Zeichne Funktionen
    for (int i = 0; i < this->_functions.count(); i++) {
        this->_functions.at(i)->setScale(this->_scaleX, this->_scaleY);
        this->_functions.at(i)->draw(painter);
    }

    qDebug() << "Drawing finished";
}

QPoint Plotter::scale(double x, double y) const
{
    return QPoint(qRound(this->_scaleX * x), qRound(this->_scaleY * y));
}

void Plotter::setZoom(const double value)
{
    if (value <= 0)
        return;

    this->_zoom = value;

    qDebug() << "Set zoom to" << this->_zoom;

    this->_xMin = this->_zoom / -2;
    this->_xMax = this->_zoom / 2;
    this->_yMin = this->_zoom / -2;
    this->_yMax = this->_zoom / 2;

    for (int i = 0; i < this->_functions.count(); i++) {
        this->_functions.at(i)->setBounds(this->_xMin, this->_xMax);
        this->_functions.at(i)->setSteps(this->_steps);
        this->_functions.at(i)->calculate();
    }
}

void Plotter::drawBackground(QWidget *widget, QPainter *painter)
{
    QBrush background;
    background.setStyle(Qt::SolidPattern);
    background.setColor(Qt::white);
    painter->fillRect(0, 0, widget->width(), widget->height(), background);
}

void Plotter::drawXAxis(QPainter *painter, QBrush *axesBrush, QBrush *labelBrush)
{
    // Zeichne x-Achse
    QPoint left = this->scale(this->_xMin, 0);
    QPoint right = this->scale(this->_xMax, 0);

    QLine xAxis;
    xAxis.setP1(left);
    xAxis.setP2(right);

    // Zeichne x-Achse
    painter->setBrush(*axesBrush);
    painter->drawLine(xAxis);

    double deltaIntercept = this->_zoom / (double) Plotter::STEPS;

    // Zeichne Achsen-Einteilung
    for (double x = this->_xMin; x <= this->_xMax; x += deltaIntercept) {
        // Zeichne x-Achsen Abschnitte
        QPoint interceptStart = this->scale(x, 0);
        interceptStart.setY(-5);
        QPoint interceptEnd = this->scale(x, 0);
        interceptEnd.setY(5);
        painter->setBrush(*axesBrush);
        painter->drawLine(interceptStart, interceptEnd);

        // Zeichne Beschriftung
        QPoint labelPos = this->scale(x, 0);
        labelPos.setY(-15);
        painter->setBrush(*labelBrush);
        this->drawText(labelPos, QString::number(x, 'f', 1), painter);
    }
}

void Plotter::drawYAxis(QPainter *painter, QBrush *axesBrush, QBrush *labelBrush)
{
    // Zeichne y-Achse
    QPoint top = this->scale(0, this->_yMin);
    QPoint bottom = this->scale(0, this->_yMax);

    QLine yAxis;
    yAxis.setP1(top);
    yAxis.setP2(bottom);

    // Zeichne y-Achse
    painter->setBrush(*axesBrush);
    painter->drawLine(yAxis);

    double deltaIntercept = this->_zoom / (double) Plotter::STEPS;

    // Zeichne Achsen-Einteilung
    for (double y = this->_yMin; y <= this->_yMax; y += deltaIntercept) {
        // Nullpunkt wurde schon für x-Achse gezeichnet
        if (y == 0)
            continue;

        // Zeichne y-Achsen Abschnitte
        QPoint interceptStart = this->scale(0, y);
        interceptStart.setX(-5);
        QPoint interceptEnd = this->scale(0, y);
        interceptEnd.setX(5);
        painter->setBrush(*axesBrush);
        painter->drawLine(interceptStart, interceptEnd);

        // Zeichne Beschriftung
        QPoint labelPos = this->scale(0, y);
        labelPos.setX(-30);
        painter->setBrush(*labelBrush);
        this->drawText(labelPos, QString::number(y, 'f', 1), painter);
    }
}

void Plotter::drawText(QPoint p, QString text, QPainter *painter)
{
    // Speichert die aktuelle Skalierung
    painter->save();

    // Skaliert den Text auf normale Größe mit invertierter y-Achse
    // ohne invertierte y-Achse würde die y-Koordinate nicht stimmen
    painter->scale(1, -1);

    // Zeichne Text vertikal gespiegelt (durch invertierte y-Achse)
    p.setY(p.y() * -1);
    painter->drawText(p, text);

    // Stellt ursprüngliche Skalierung wieder her
    painter->restore();
}

void Plotter::calculateScaling(QWidget *widget, QPainter *painter)
{
    // Berechne Skalierung je nachdem ob bereits Funktionen hinzugefügt wurden
    this->_scaleX = (widget->width() / 2) / (this->_zoom / 2);
    this->_scaleY = (widget->height() / 2) / (this->_zoom / 2);

    painter->translate(widget->width() / 2, widget->height() / 2);
    painter->scale(1, -1);
}

void Plotter::calculateSteps(QWidget *widget)
{
    this->_steps = 1.0 / (double) widget->width() * this->_zoom;
}
