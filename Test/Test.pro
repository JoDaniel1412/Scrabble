GOOGLETEST_DIR = $$_PRO_FILE_PWD_/../lib/googletest

include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

LIBS += -L../src -lsrc

HEADERS += \
    list/tst_list.h \
    list/tst_node.h \
    game/tst_tile.h \
    game/tst_board.h

SOURCES += \
        main.cpp

INCLUDEPATH += ../src/
DEPENDPATH += $${INCLUDEPATH}  # Force rebuild if the headers change
