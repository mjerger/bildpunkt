QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bildpunkt

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++17

INCLUDEPATH += /usr/include/opencv

LIBS += `pkg-config --libs opencv`

SOURCES += \
        src/main.cpp \
    src/view.cpp \
    src/timeline.cpp \
    src/engine.cpp \
    src/about.cpp \
    src/video.cpp \
    src/settingswindow.cpp \
    src/mainwindow.cpp \
    src/app.cpp \
    src/config.cpp \
    src/base.cpp

HEADERS += \
    src/view.h \
    src/timeline.h \
    src/engine.h \
    src/about.h \
    src/video.h \
    src/settingswindow.h \
    src/mainwindow.h \
    src/app.h \
    src/base.h \
    src/config.h \
    src/log.h

RESOURCES = data/resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    bildpunkt.conf
