#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T16:50:53
#
#-------------------------------------------------

QT       += core gui

TARGET = testecu
TEMPLATE = app

#<lhj add>
# Change the following version number
EMA_VERSION = 1.0.1
# End of Change the following version number

#DEFINES += QT_NO_DEBUG_OUTPUT
CONFIG += _arm_
#</lhj>


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

#   <lhj add>
linux-g++ {
    LINUX_LIB_DIR = /usr/local/lib
    LINUX_INCLUDE_DIR = ../include

    _arm_ {
        message(_arm_)
        INCLUDEPATH += $$LINUX_INCLUDE_DIR
        LIBS  += -L$$LINUX_LIB_DIR -lemaLib_arm_$$EMA_VERSION

        ematest.files = $${TARGET}
        ematest.path = /usr/local/bin
        ematest.extra = strip $${TARGET};
        INSTALLS += testecu
    }
}
#   </lhj>
