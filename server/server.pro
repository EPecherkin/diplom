QT       += core network
QT       -= gui

TARGET   = server
TEMPLATE = app

CONFIG   += console
CONFIG   -= app_bundle


SOURCES  += main.cpp \
    service.cpp

HEADERS += \
    service.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../qjsonrpc/release/ -lqjsonrpc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../qjsonrpc/debug/ -lqjsonrpc
else:unix: LIBS += -L$$OUT_PWD/../qjsonrpc/ -lqjsonrpc

INCLUDEPATH += $$PWD/../qjsonrpc
DEPENDPATH += $$PWD/../qjsonrpc
