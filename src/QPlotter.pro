QT += core gui widgets script


TARGET = QPlotter
TEMPLATE = app
CONFIG += c++11


SOURCES += \
    main.cpp \
    plotterwindow.cpp \
    plotter.cpp \
    mathjs.cpp \
    function.cpp \
    plotwidget.cpp \
    point.cpp

HEADERS += \
    plotter.hpp \
    plotterwindow.hpp \
    mathjs.hpp \
    function.hpp \
    point.hpp \
    plotwidget.hpp

FORMS += \
    plotterwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    ../.gitignore \
    ../LICENSE \
    ../README.md \
    style/general.css
