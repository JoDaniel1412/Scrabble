include(../defaults.pri)

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
    game/tile.h \
    game/dock.h \
    game/game.h \
    dict/wordsdict.h \
    json/stringtojson.h

SOURCES += \
        main.cpp \
    game/board.cpp \
    game/tile.cpp \
    game/dock.cpp \
    game/game.cpp \
    dict/wordsdict.cpp \
    json/stringtojson.cpp
