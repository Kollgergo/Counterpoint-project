QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app

SOURCES += main.cpp \
    score.cpp \
    note.cpp \
    staff.cpp \
    cpsystem.cpp \
    keysignature.cpp \
    scoreviewmodel.cpp \
    mainwindow.cpp \
    vnote.cpp \
    vstaff.cpp \
    vstaffline.cpp \
    scoreview.cpp \
    newstaffdialog.cpp

HEADERS += \
    score.h \
    note.h \
    staff.h \
    cpsystem.h \
    keysignature.h \
    scoreviewmodel.h \
    mainwindow.h \
    vnote.h \
    vstaff.h \
    vstaffline.h \
    scoreview.h \
    newstaffdialog.h

FORMS    += mainwindow.ui \
    newstaffdialog.ui

RESOURCES += \
    GUI.qrc

