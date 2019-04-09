include(../defaults.pri)

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app


HEADERS += \
    game/tst_boardtest.h \
    game/tst_docktest.h \
    game/tst_gametest.h \
    game/tst_tiletest.h \
    dict/tst_wordsdicttest.h \
    json/tst_stringtojsontest.h

SOURCES +=  \
    main.cpp \
    game/tst_boardtest.cpp \
    game/tst_tiletest.cpp \
    game/tst_docktest.cpp \
    game/tst_gametest.cpp \
    dict/tst_wordsdicttest.cpp \
    json/tst_stringtojsontest.cpp


LIBS += -L../src -lmyapp
