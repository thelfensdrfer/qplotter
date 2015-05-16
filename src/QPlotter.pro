QT += core gui widgets script


TARGET = QPlotter
TEMPLATE = app
CONFIG += c++11
QMAKE_MAC_SDK = macosx10.10


SOURCES += \
    main.cpp \
    plotterwindow.cpp \
    plotter.cpp \
    mathjs.cpp \
    function.cpp \
    plotwidget.cpp \
    point.cpp \
    messagehandler.cpp

HEADERS += \
    plotter.hpp \
    plotterwindow.hpp \
    mathjs.hpp \
    function.hpp \
    point.hpp \
    plotwidget.hpp \
    messagehandler.hpp

FORMS += \
    plotterwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    ../.gitignore \
    ../LICENSE \
    ../README.md \
    style/general.css
