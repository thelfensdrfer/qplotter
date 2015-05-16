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
    connect(this->_ui->zoomBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &PlotterWindow::onZoomChange);

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
    if (this->_ui->deleteOldFunctions->isChecked()) {
        while (this->_ui->functionOverview->rowCount() > 0) {
            this->_ui->functionOverview->removeRow(0);
        }
    }

    int newIndex = this->_ui->functionOverview->rowCount();

    this->_ui->functionOverview->insertRow(newIndex);
    QTableWidgetItem *functionItem = new QTableWidgetItem(f);
    this->_ui->functionOverview->setItem(newIndex, 0, functionItem);
}

void PlotterWindow::onHistoryRestore(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    QString f = this->_ui->historyList->item(index.row())->text();
    this->_ui->functionInput->setText(f);
}

void PlotterWindow::onZoomChange(const double value)
{
    qDebug() << "Set zoom to" << value;

    this->_ui->plotCanvas->setZoom(value);
    this->repaint();
}
