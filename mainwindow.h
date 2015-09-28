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


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setSvm(ScoreViewModel *value);
    void showScore();
    void showNextVStaff(VStaff * vstaff);
    void updateNoteData(VNote *vnote);
    void addVStaff(VStaff *vstaff);

    QList<VStaff *> getVstaffs() const;

protected:
    void keyPressEvent(QKeyEvent * event);

private slots:

    void on_actionExit_triggered();

    void on_actionLilyPond_triggered();

    void on_actionOpen_LilyPond_file_triggered();

    void on_actionAddNote_triggered(bool checked);

    void on_actionAddRest_triggered(bool checked);

    void on_actionWhole_triggered(bool checked);

    void on_actionHalf_triggered(bool checked);

    void on_actionQuarter_triggered(bool checked);

    void on_actionEighth_triggered(bool checked);

    void on_action_newStaff_triggered();

    void on_actionAddSharp_triggered(bool checked);

    void on_actionAddFlat_triggered(bool checked);

    void on_actionOpenLilypondToolBar_triggered();

public slots:
    void vNoteSelected(VNote *note);
    void vNotePosChanged(VNote *note);
    void vstaffSelected(VStaff *vstaff);
    void newVNoteAdded(VNote *vnote);

private:
    Ui::MainWindow *ui;
    ScoreViewModel *svm;
    QGraphicsScene *scene;
    QList<VStaff*> vstaffs;
    VStaff *selectedvstaff;

};

#endif // MAINWINDOW_H
