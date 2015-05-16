#include "messagehandler.hpp"
#include "plotterwindow.hpp"

#include <QtWidgets/QApplication>

#include <QtCore/QFile>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    qInstallMessageHandler(messageOutput);
    QApplication app(argc, argv);

    // Anwendungsoptionen
    qApp->setApplicationName("QPlotter");
    qApp->setOrganizationName("VisualAppeal");
    qApp->setOrganizationDomain("visualappeal.de");
    qApp->setApplicationVersion("0.1.0");

    // Lese CSS Datei aus Resource
    QFile cssFile(":/style/general.css");
    if (!cssFile.open(QFile::ReadOnly | QFile::Text)) {
        qCritical("Could not load css file from resources!");
        return 1;
    }

    QString css = QString(cssFile.readAll());

    PlotterWindow w;
    w.show();
    w.setStyleSheet(css);

    return app.exec();
}
