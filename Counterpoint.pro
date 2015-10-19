QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Counterpoint
TEMPLATE = app

CONFIG += c++11

INCLUDEPATH += Datamodel
INCLUDEPATH += GUI
INCLUDEPATH += Rules
INCLUDEPATH += QMidi/src

win32{
    LIBS += -lwinmm
}

unix{

}

SOURCES += main.cpp \
    Datamodel/score.cpp \
    Datamodel/note.cpp \
    Datamodel/staff.cpp \
    Datamodel/cpsystem.cpp \
    Datamodel/keysignature.cpp \
    Datamodel/scoreviewmodel.cpp \
    GUI/mainwindow.cpp \
    GUI/vnote.cpp \
    GUI/vstaff.cpp \
    GUI/vstaffline.cpp \
    scoreview.cpp \
    GUI/newstaffdialog.cpp \
    GUI/newcpdialog.cpp \
    Rules/tester.cpp \
    Rules/error.cpp \
    Rules/onlyconsonancerule.cpp \
    GUI/errormarker.cpp \
    Datamodel/accent.cpp \
    QMidi/src/OS/QMidi_Win32.cpp \
    QMidi/src/QMidiFile.cpp \
    QMidi/src/QMidiOut.cpp \
    GUI/playbackthread.cpp \
    Rules/firstrule.cpp \
    Rules/secondrule.cpp \
    Rules/thirdrule.cpp \
    Rules/fourthrule.cpp


HEADERS += \
    Datamodel/score.h \
    Datamodel/note.h \
    Datamodel/staff.h \
    Datamodel/cpsystem.h \
    Datamodel/keysignature.h \
    Datamodel/scoreviewmodel.h \
    GUI/mainwindow.h \
    GUI/vnote.h \
    GUI/vstaff.h \
    GUI/vstaffline.h \
    scoreview.h \
    GUI/newstaffdialog.h \
    GUI/newcpdialog.h \
    Rules/tester.h \
    Rules/error.h \
    Rules/onlyconsonancerule.h \
    GUI/errormarker.h \
    Datamodel/accent.h \
    QMidi/src/QMidiFile.h \
    QMidi/src/QMidiOut.h \
    GUI/playbackthread.h \
    Rules/firstrule.h \
    Rules/secondrule.h \
    Rules/thirdrule.h \
    Rules/fourthrule.h


FORMS    += GUI/mainwindow.ui \
    GUI/newstaffdialog.ui \
    GUI/newcpdialog.ui

RESOURCES += \
    GUI.qrc

