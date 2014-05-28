QT       += core network
QT       -= gui

TARGET   = client
TEMPLATE = app

CONFIG   += console
CONFIG   -= app_bundle

SOURCES  += *.cpp
HEADERS  += *.h

win32:DEFINES  += WIN32
unix:DEFINES   += UNIX

DEFINES = QJSONRPC_SHARED

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../qjsonrpc/release/ -lqjsonrpc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../qjsonrpc/debug/ -lqjsonrpc
else:unix: LIBS += -L$$OUT_PWD/../qjsonrpc/ -lqjsonrpc1

INCLUDEPATH += $$PWD/../qjsonrpc
DEPENDPATH += $$PWD/../qjsonrpc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../model/release/ -lmodel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../model/debug/ -lmodel
else:unix: LIBS += -L$$OUT_PWD/../model/ -lmodel

INCLUDEPATH += $$PWD/../model
DEPENDPATH += $$PWD/../model
