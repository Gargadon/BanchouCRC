#-------------------------------------------------
#
# Project created by QtCreator 2019-04-08T15:38:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BanchouCRC
TEMPLATE = app
VERSION = 2.0.0

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11 \
static

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    crc32.cpp \
    about.cpp

HEADERS += \
        mainwindow.h \
    crc32.h \
    about.h

FORMS += \
        mainwindow.ui \
    about.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /usr/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = BanchouCRC.ico

RESOURCES += \
    resources.qrc

icono.path = /usr/share/icons/hicolor/256x256/apps
icono.files = BanchouCRC.png
INSTALLS += icono

escritorio.path = /usr/share/applications
escritorio.files = BanchouCRC.desktop
INSTALLS += escritorio
