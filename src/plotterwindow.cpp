#include "plotterwindow.hpp"
#include "ui_plotterwindow.h"

#include <QtCore/QDebug>

PlotterWindow::PlotterWindow(QWidget *parent):
    QMainWindow(parent),
    _ui(new Ui::PlotterWindow)
{
    qDebug() << "Creating PlotterWindow";

    this->_ui->setupUi(this);

    // Einstellungen
    connect(this->_ui->plotButton, &QPushButton::pressed, this, &PlotterWindow::onPlotFunction);
    connect(this->_ui->functionInput, &QLineEdit::returnPressed, this, &PlotterWindow::onPlotFunction);
    connect(this->_ui->xMinBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &PlotterWindow::onXMinChange);
    connect(this->_ui->xMaxBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &PlotterWindow::onXMaxChange);
    connect(this->_ui->yMinBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &PlotterWindow::onYMinChange);
    connect(this->_ui->yMaxBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &PlotterWindow::onYMaxChange);

    // Historie
    connect(this->_ui->historyList, &QListWidget::doubleClicked, this, &PlotterWindow::onHistoryRestore);
}

PlotterWindow::~PlotterWindow()
{
    delete this->_ui;

    qDebug() << "Destroying PlotterWindow";
}

void PlotterWindow::onPlotFunction()
{
    QString f = this->_ui->functionInput->text();
    this->_ui->plotCanvas->addFunction(f, this->_ui->deleteOldFunctions->isChecked());

    // Funktion zur Historie hinzufügen
    this->_ui->historyList->insertItem(0, f);

    // Funktion zur Funktionsübersicht hinzufügen
    if (this->_ui->deleteOldFunctions->isChecked())
        this->_ui->functionOverview->clear();
}

void PlotterWindow::onHistoryRestore(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    QString f = this->_ui->historyList->item(index.row())->text();
    this->_ui->functionInput->setText(f);
}

void PlotterWindow::onXMinChange(const double value)
{
    this->_ui->plotCanvas->setXMin(value);
}

void PlotterWindow::onXMaxChange(const double value)
{
    this->_ui->plotCanvas->setXMin(value);
}

void PlotterWindow::onYMinChange(const double value)
{
    this->_ui->plotCanvas->setYMin(value);
}

void PlotterWindow::onYMaxChange(const double value)
{
    this->_ui->plotCanvas->setYMin(value);
}
