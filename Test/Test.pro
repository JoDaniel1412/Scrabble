include(../defaults.pri)

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    main.cpp \
    game/tst_boardtest.cpp \
    game/tst_tiletest.cpp \
    game/tst_docktest.cpp \


LIBS += -L../src -lmyapp
