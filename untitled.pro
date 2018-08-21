#-------------------------------------------------
#
# Project created by QtCreator 2018-07-31T15:13:36
#
#-------------------------------------------------

QT       += core gui widgets sql

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    member_preview.cpp \
    member_search.cpp \
    member_info_entry.cpp \
    date_input.cpp \
    next_steps_info_entry.cpp \
    date_labels.cpp \
    member_incentives.cpp \
    incentives_entry.cpp \
    incentives_labels.cpp \
    crud_input.cpp \
    member_selection.cpp

HEADERS += \
        mainwindow.h \
    member_preview.h \
    member_search.h \
    member_info_entry.h \
    date_input.h \
    next_steps_info_entry.h \
    date_labels.h \
    member_incentives.h \
    incentives_entry.h \
    incentives_labels.h \
    crud_input.h \
    member_selection.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
