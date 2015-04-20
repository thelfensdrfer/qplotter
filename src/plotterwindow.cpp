#include "plotterwindow.hpp"
#include "ui_plotterwindow.h"

#include <QtCore/QDebug>

PlotterWindow::PlotterWindow(QWidget *parent):
    QMainWindow(parent),
    _ui(new Ui::PlotterWindow)
{
    qDebug() << "Creating PlotterWindow";

    this->_ui->setupUi(this);

    connect(this->_ui->plotButton, &QPushButton::pressed, this, &PlotterWindow::onPlotFunction);
    connect(this->_ui->functionInput, &QLineEdit::returnPressed, this, &PlotterWindow::onPlotFunction);

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
    this->_ui->plotCanvas->addFunction(f);

    this->_ui->historyList->insertItem(0, f);
}

void PlotterWindow::onHistoryRestore(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    QString f = this->_ui->historyList->item(index.row())->text();
    this->_ui->functionInput->setText(f);
}
