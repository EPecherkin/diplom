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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/qjsonrpc/r/ -lqjsonrpc1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/qjsonrpc/d/ -lqjsonrpc1
else:unix: LIBS += -L$$PWD/../lib/qjsonrpc/ -lqjsonrpc1

INCLUDEPATH += $$PWD/../lib/qjsonrpc
DEPENDPATH  += $$PWD/../lib/qjsonrpc
