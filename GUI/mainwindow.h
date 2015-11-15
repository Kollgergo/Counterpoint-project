#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QDebug>
#include "vstaff.h"
#include "scoreviewmodel.h"
#include "newstaffdialog.h"
#include "newcpdialog.h"
#include "midisettingsdialog.h"
#include "scoresettingsdialog.h"
#include "playback.h"


class QMidiOut;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //void updateSceneRect();

    void setSvm(ScoreViewModel *value);
    void showScore(bool isCF = false);
    void showNextVStaff(VStaff * vstaff);
    void updateNoteData(VNote *vnote);

    void addVStaff(VStaff *vstaff);
    void addVNote(VStaff *vstaff, unsigned int staffpos, ScoreViewModel::noteTypes notetype, Accent::accents accent, unsigned int where);

    void initToolBars(bool isCP);

    QList<VStaff *> getVstaffs() const;

    VStaff* getSelectedVStaff() const;

protected:
    void keyPressEvent(QKeyEvent * event);

private slots:

    void on_actionExit_triggered();

    void on_actionAddNote_triggered(bool checked);

    void on_actionAddRest_triggered(bool checked);

    void on_actionWhole_triggered(bool checked);

    void on_actionHalf_triggered(bool checked);

    void on_actionQuarter_triggered(bool checked);

    void on_actionEighth_triggered(bool checked);

    void on_actionAddSharp_triggered(bool checked);

    void on_actionAddFlat_triggered(bool checked);

    void on_actionNewScore_triggered();

    void on_actionNewCounterpoint_triggered();

    void on_actionChangeNoteRest_triggered();

    void on_actionOpenLilypond_triggered();

    void on_actionSaveLilypond_triggered();

    void on_actionTest_triggered();

    void on_actionNewStaff_triggered();

    void on_actionPlayMIDI_triggered();

    void on_actionStopPlayBack_triggered();

    void on_actionCutHalf_triggered();

    void on_actionMidiSettings_triggered();

    void on_actionScoreSettings_triggered();

public slots:
    void vNoteSelected(VNote *note);
    void vNotePosChanged(VNote *note);
    void vstaffSelected(VStaff *vstaff);
    void newVNoteAdded(VNote *vnote);
    void playBackEnded();
    void vNoteUpdate(VNote *vnote);
    void updateSceneRect();

private:
    Ui::MainWindow *ui;
    ScoreViewModel *svm;
    QGraphicsScene *scene;
    QList<VStaff*> vstaffs;
    VStaff *selectedvstaff;
    bool CPmode;

    QList<PlayBack *> voices;
    QMidiOut *midi;
    unsigned int instrument;
    unsigned int midivelocity;
    unsigned int tempo;
    unsigned int playbackcounter;

    QList<int> rulelist;

};

#endif // MAINWINDOW_H
