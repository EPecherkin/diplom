QT       += core network
QT       -= gui

TARGET   = client
TEMPLATE = app

CONFIG   += console
CONFIG   -= app_bundle


SOURCES  += main.cpp \
    key_logger_windows.cpp \
    key_logger_unix.cpp \
    server.cpp

HEADERS  += \
    key_logger.h \
    server.h

win32:DEFINES  += WIN32
unix:DEFINES   += UNIX

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../qjsonrpc/release/ -lqjsonrpc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../qjsonrpc/debug/ -lqjsonrpc
else:unix: LIBS += -L$$OUT_PWD/../qjsonrpc/ -lqjsonrpc

INCLUDEPATH += $$PWD/../qjsonrpc
DEPENDPATH += $$PWD/../qjsonrpc
