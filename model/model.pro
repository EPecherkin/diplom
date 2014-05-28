QT       -= gui

TARGET = model
TEMPLATE = lib

DEFINES += MODEL_LIBRARY

SOURCES += *.cpp
HEADERS += *.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
