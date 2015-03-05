TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    timepoint.cpp \
    subtitleduration.cpp \
    subtitle.cpp \
    subtitles.cpp

HEADERS += \
    timepoint.h \
    subtitleduration.h \
    subtitle.h \
    subtitles.h

CONFIG += C++11
