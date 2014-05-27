#-------------------------------------------------
#
# Project created by QtCreator 2014-05-27T23:23:09
#
#-------------------------------------------------

QT       -= gui

TARGET = model
TEMPLATE = lib

DEFINES += MODEL_LIBRARY

SOURCES += \
    modelkeypress.cpp \
    modeluser.cpp

HEADERS += \
    model_export.h \
    modelkeypress.h \
    modeluser.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
