QT       += core network sql
QT       -= gui

TARGET   = server
TEMPLATE = app

CONFIG   += console
CONFIG   -= app_bundle

SOURCES  += *.cpp
HEADERS  += *.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/qjsonrpc/ -lqjsonrpc1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/qjsonrpc/ -lqjsonrpc1d
else:unix: LIBS += -L$$PWD/../lib/qjsonrpc/ -lqjsonrpc1

INCLUDEPATH += $$PWD/../lib/qjsonrpc
DEPENDPATH  += $$PWD/../lib/qjsonrpc
