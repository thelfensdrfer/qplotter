#include "plotter.hpp"

#include <float.h>

#include <QtCore/QDebug>

Plotter::Plotter(QObject *parent): QObject(parent)
{
    qDebug() << "Creating new Plotter";

    this->_xMin = Plotter::DEFAULT_X_MIN;
    this->_xMax = Plotter::DEFAULT_X_MAX;
    this->_yMin = Plotter::DEFAULT_Y_MIN;
    this->_yMax = Plotter::DEFAULT_Y_MAX;
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
    qDebug() << "Add function" << f << "to plotter";

    this->_functions.append(new Function(f));
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

void Plotter::drawBackground(QWidget *widget, QPainter *painter)
{
    qDebug() << "Draw background";

    QBrush background;
    background.setStyle(Qt::SolidPattern);
    background.setColor(Qt::white);
    painter->fillRect(0, 0, widget->width(), widget->height(), background);
}

void Plotter::drawXAxis(QPainter *painter, QBrush *axesBrush, QBrush *labelBrush)
{
    qDebug() << "Draw x Axis";

    // Zeichne x-Achse
    QPoint left = this->scale(this->_xMin, 0);
    QPoint right = this->scale(this->_xMax, 0);

    QLine xAxis;
    xAxis.setP1(left);
    xAxis.setP2(right);

    // Zeichne x-Achse
    painter->setBrush(*axesBrush);
    painter->drawLine(xAxis);

    // Zeichne Achsen-Einteilung
    for (int x = left.x(); x <= right.x(); x += this->_scaleX) {
        // Zeichne x-Achsen Abschnitte
        painter->setBrush(*axesBrush);
        painter->drawLine(x, -5, x, 5);
        painter->setBrush(*labelBrush);
        this->drawText(x, -15, QString::number(x / this->_scaleX), painter);
    }
}

void Plotter::drawYAxis(QPainter *painter, QBrush *axesBrush, QBrush *labelBrush)
{
    qDebug() << "Draw y Axis";

    // Zeichne y-Achse
    QPoint top = this->scale(0, this->_yMin);
    QPoint bottom = this->scale(0, this->_yMax);

    QLine yAxis;
    yAxis.setP1(top);
    yAxis.setP2(bottom);

    // Zeichne y-Achse
    painter->setBrush(*axesBrush);
    painter->drawLine(yAxis);

    // Zeichne Achsen-Einteilung
    for (int y = top.y(); y <= bottom.y(); y += this->_scaleY) {
        // Nullpunkt wurde schon für x-Achse gezeichnet
        if (y == 0)
            continue;

        // Zeichne y-Achsen Abschnitte
        painter->setBrush(*axesBrush);
        painter->drawLine(-5, y, 5, y);
        painter->setBrush(*labelBrush);
        this->drawText(15, y, QString::number(y / this->_scaleY), painter);
    }
}

void Plotter::drawText(int x, int y, QString text, QPainter *painter)
{
    // Speichert die aktuelle Skalierung
    painter->save();

    // Skaliert den Text auf normale Größe mit invertierter y-Achse
    // ohne invertierte y-Achse würde die y-Koordinate nicht stimmen
    painter->scale(1, -1);

    // Zeichne Text vertikal gespiegelt (durch invertierte y-Achse)
    painter->drawText(x, y * -1, text);

    // Stellt ursprüngliche Skalierung wieder her
    painter->restore();
}

void Plotter::calculateScaling(QWidget *widget, QPainter *painter)
{
    // Berechne Skalierung je nachdem ob bereits Funktionen hinzugefügt wurden
    if (this->_functions.count() > 0) {
        this->_scaleX = (widget->width() / 2) / ((this->_xMax - this->_xMin) / 2);
        this->_scaleY = (widget->height() / 2) / ((this->_yMax - this->_yMin) / 2);
    } else {
        this->_scaleX = (widget->width() / 2) / ((Plotter::DEFAULT_X_MAX - Plotter::DEFAULT_X_MIN) / 2);
        this->_scaleY = (widget->height() / 2) / ((Plotter::DEFAULT_Y_MAX - Plotter::DEFAULT_Y_MIN) / 2);
    }

    painter->translate(widget->width() / 2, widget->height() / 2);
    painter->scale(1, -1);
}
