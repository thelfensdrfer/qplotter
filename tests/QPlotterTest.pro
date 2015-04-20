QT += core gui script testlib


TARGET = tst_qplotter
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle


HEADERS += \
    ../src/mathhs.hpp \
    ../src/plotter.hpp \
    ../src/function.hpp \
    ../src/point.hpp \
    tst_qplotter_function.hpp \
    tst_qplotter_plotter.hpp

SOURCES += \
    main.cpp \
    ../src/mathjs.cpp \
    ../src/plotter.cpp \
    ../src/function.cpp \
    ../src/point.cpp \
    tst_qplotter_plotter.cpp \
    tst_qplotter_function.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
