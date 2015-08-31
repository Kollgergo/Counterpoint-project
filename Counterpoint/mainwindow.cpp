#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->scoreView->setScene(scene);

    //vstaff = new VStaff;
    //scene->addItem(vstaff);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::on_addNoteButton_clicked()
{

}

void MainWindow::on_exportButton_clicked()
{
    svm->makeLilyPond();
}
void MainWindow::setSvm(ScoreViewModel *value)
{
    svm = value;
}

void MainWindow::on_showButton_clicked()
{
    scene->clear();
    vstaffs.clear();
    showScore();
}

void MainWindow::showScore()
{
    for(unsigned int i=1; i<=svm->getNumOfStaffs(); i++){
        this->showNextVStaff(new VStaff(svm->getClefByNum(i-1), 0));

        for(unsigned int j=1; j<=svm->getNumOfNotes(i); j++){
            VNote *newnote = new VNote(svm->getPosition(i,j), svm->getType(i,j), svm->getAccent(i,j), vstaffs.last());

            vstaffs.last()->showNextVNote(newnote);

            connect(vstaffs.last()->getVnotes().last(), SIGNAL(notePosChanging(VNote*)), this, SLOT(notePosChanged(VNote*)));
        }
    }

}

void MainWindow::showNextVStaff(VStaff *vstaff)
{
    int idx = 0;
    if(!vstaffs.isEmpty()){
        idx = vstaffs.size();
    }

    vstaffs.push_back(vstaff);

    foreach (VStaffLine *line, vstaffs.last()->getVstafflines()) {
        int prevY = line->y();
        line->setY(prevY+(idx*200));
    }

    scene->addItem(vstaffs.last());
}

void MainWindow::updateNoteData(VNote *note)
{
    for(int i=0; i<vstaffs.size(); i++){
        if(vstaffs.at(i)->getVnotes().contains(note)){
            qDebug() << "changing note:" << i+1 << vstaffs.at(i)->getVnotes().indexOf(note)+1;
            svm->updatePosition(i+1, vstaffs.at(i)->getVnotes().indexOf(note)+1, note->getScorepos());
        }
    }
}

void MainWindow::notePosChanged(VNote *note)
{
    qDebug() << "notepos changed";

    updateNoteData(note);

}
QList<VStaff *> MainWindow::getVstaffs() const
{
    return vstaffs;
}


