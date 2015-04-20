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
};

#endif // PLOTTERWINDOW_H
