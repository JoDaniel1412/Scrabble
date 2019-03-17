GOOGLETEST_DIR = $$_PRO_FILE_PWD_/../lib/googletest

include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

INCLUDEPATH += ../src

HEADERS += \
    tst_list.h \
    tst_node.h

SOURCES += \
        main.cpp
