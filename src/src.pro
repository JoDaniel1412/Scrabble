include(../defaults.pri)

CONFIG -= qt
CONFIG += console
CONFIG -= app_bundle

TARGET = myapp
TEMPLATE = lib

HEADERS += \
    list/List.h \
    list/Node.h \
    list/List_impl.h \
    list/Node_impl.h \
    game/board.h \
    game/tile.h

SOURCES += \
        main.cpp \
    game/board.cpp \
    game/tile.cpp
