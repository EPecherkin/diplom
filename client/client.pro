QT       += core
QT       -= gui

TARGET   = client
TEMPLATE = app

CONFIG   += console
CONFIG   -= app_bundle


SOURCES  += main.cpp \
    key_logger_windows.cpp

HEADERS  += \
    key_logger.h

win32:DEFINES  += WIN32
unix:DEFINES   += UNIX
