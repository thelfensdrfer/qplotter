#ifndef PLOTTERWINDOW_H
#define PLOTTERWINDOW_H

#include <QtWidgets/QMainWindow>

namespace Ui {
    class PlotterWindow;
}

class PlotterWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit PlotterWindow(QWidget *parent = 0);
    ~PlotterWindow();

private:
    Ui::PlotterWindow *_ui;

private slots:
    /**
     * Funktion im Textfeld soll geplotted werden.
     */
    void onPlotFunction();

    /**
     * Eine Funktion soll aus der Historie geladen werden.
     */
    void onHistoryRestore(const QModelIndex &index);

    /**
     * x-Min Wert wurde geändert.
     */
    void onXMinChange(const double value);

    /**
     * x-Max Wert wurde geändert.
     */
    void onXMaxChange(const double value);

    /**
     * y-Min Wert wurde geändert.
     */
    void onYMinChange(const double value);

    /**
     * y-Max Wert wurde geändert.
     */
    void onYMaxChange(const double value);
};

#endif // PLOTTERWINDOW_H
