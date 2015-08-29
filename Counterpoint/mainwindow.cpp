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

void MainWindow::showScore()
{
    for(unsigned int i=1; i<=svm->getNumOfStaffs(); i++){
        this->showNextVStaff(new VStaff);
        //newstaff->setY((i-1)*100);
//        foreach (VStaffLine line, newstaff->getVstafflines()) {
//            line.setY((i-1)*100);
//        }
//        for(int j=0; j<newstaff->getVstafflines().size(); j++){
//            newstaff->getVstafflines().at(j)->setY((i-1)*100);
//        }

        for(unsigned int j=1; j<=svm->getNumOfNotes(i); j++){
            VNote *newnote = new VNote(svm->getPosition(i,j), svm->getType(i,j), vstaffs.last());

            vstaffs.last()->showNextVNote(newnote);

            connect(vstaffs.last()->getVnotes().last(), SIGNAL(notePosChanging(unsigned int)), this, SLOT(notePosChanged(unsigned int)));
        }
    }

}

void MainWindow::showNextVStaff(VStaff *vstaff)
{
    vstaffs.push_back(vstaff);
    /*foreach (VStaffLine *line, vstaffs.last()->getVstafflines()) {
        line->setY(100*vstaffs.size());
    }*/
    scene->addItem(vstaffs.last());
}

void MainWindow::on_showButton_clicked()
{
    showScore();
}

void MainWindow::notePosChanged(unsigned int spos)
{
    qDebug() << "notepos changed";
    //(VNote *)sender()->setObjectName();
}
QList<VStaff *> MainWindow::getVstaffs() const
{
    return vstaffs;
}


