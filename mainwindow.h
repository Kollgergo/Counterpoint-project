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
    void updateNoteData(VNote *note);
    void addVStaff(VStaff *vstaff);

    QList<VStaff *> getVstaffs() const;

protected:
    void keyPressEvent(QKeyEvent * event);

private slots:
    void on_addNoteButton_clicked();

    void on_actionExit_triggered();

    void on_actionLilyPond_triggered();

    void on_actionOpen_LilyPond_file_triggered();

    void on_addStaffButton_clicked();

    void on_actionAddNote_triggered();

    void on_actionAddRest_triggered();

    void on_actionHalf_triggered();

    void on_actionWhole_triggered();

    void on_actionQuarter_triggered();

    void on_actionEighth_triggered();

public slots:
    void notePosChanged(VNote *note);
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
