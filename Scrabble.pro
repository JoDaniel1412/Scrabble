TEMPLATE = subdirs

SUBDIRS += \
    App \
    Server \
    src \
    Test

App.depends = src
Test.depends = src

DISTFILES += \
    defaults.pri
