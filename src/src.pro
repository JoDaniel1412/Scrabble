TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


HEADERS += \
    game/board.h \
    game/tile.h

SOURCES += \
        main.cpp \
    game/board.cpp \
    game/tile.cpp

INCLUDEPATH += ../lib/dstructures/include
