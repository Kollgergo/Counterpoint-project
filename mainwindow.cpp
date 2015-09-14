#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->scoreView->setScene(scene);
    ui->scoreView->setMouseTracking(true);

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
    foreach (VStaff *vstaff, vstaffs) {
        if(vstaff == selectedvstaff){
            vstaff->setNewVNote(ScoreViewModel::half);
            connect(vstaff, SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
        }
    }

    //selectedvstaff->addVNote(new VNote(false,0,ScoreViewModel::half,ScoreViewModel::none,selectedvstaff));
}

void MainWindow::setSvm(ScoreViewModel *value)
{
    svm = value;
}

void MainWindow::showScore()
{
    scene->clear();
    vstaffs.clear();
    for(unsigned int i=1; i<=svm->getNumOfStaffs(); i++){
        this->showNextVStaff(new VStaff(svm->getClefByNum(i-1), 0));

        for(unsigned int j=1; j<=svm->getNumOfNotes(i); j++){

            vstaffs.last()->showNextVNote(new VNote(false, svm->getPosition(i,j), svm->getType(i,j), svm->getAccent(i,j), vstaffs.last()));

            //qDebug() << vstaffs.last();

            connect(vstaffs.last()->getVnotes().last(), SIGNAL(notePosChanging(VNote*)), this, SLOT(notePosChanged(VNote*)));
        }
    }

}

void MainWindow::showNextVStaff(VStaff *vstaff)
{
    /*int idx = 0;
    if(!vstaffs.isEmpty()){
        idx = vstaffs.size();
    }*/

    vstaffs.push_back(vstaff);
    connect(vstaff, SIGNAL(vstaffSelect(VStaff*)), this, SLOT(vstaffSelected(VStaff*)));

    vstaffs.last()->setY((vstaffs.size()-1)*200);

    /*foreach (VStaffLine *line, vstaffs.last()->getVstafflines()) {
        int prevY = line->y();
        line->setY(prevY+(idx*200));
    }*/

    scene->addItem(vstaffs.last());
}

void MainWindow::updateNoteData(VNote *note) //updates note properties in svm
{
    for(int i=0; i<vstaffs.size(); i++){
        if(vstaffs.at(i)->getVnotes().contains(note)){
            //qDebug() << "changing note:" << i+1 << vstaffs.at(i)->getVnotes().indexOf(note)+1;
            svm->updatePosition(i+1, vstaffs.at(i)->getVnotes().indexOf(note)+1, note->getScorepos());
        }
    }
}

void MainWindow::addVStaff(VStaff *vstaff)
{
    vstaffs.push_back(vstaff);
    connect(vstaffs.last(), SIGNAL(vstaffSelect(VStaff*)), this, SLOT(vstaffSelected(VStaff*)));

    svm->addStaff(vstaff->getClef(), 0, 0);

    vstaffs.last()->setY((vstaffs.size()-1)*200);

    scene->addItem(vstaffs.last());
}

void MainWindow::notePosChanged(VNote *note)
{
    //qDebug() << "notepos changed";

    updateNoteData(note);

}

void MainWindow::vstaffSelected(VStaff *vstaff)
{
    selectedvstaff = vstaff;
    //qDebug() << selectedvstaff;
}

void MainWindow::newVNoteAdded(VNote *vnote)
{
    for(int i=0; i<vstaffs.size(); i++){
        if(vstaffs.at(i) == vnote->parentItem()){
            svm->addNote(i+1, 0, 2, 0);
            svm->updatePosition(i+1, svm->getNumOfNotes(i+1), vnote->getScorepos());
            disconnect(vstaffs.at(i), SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
            connect(vstaffs.at(i)->getVnotes().last(), SIGNAL(notePosChanging(VNote*)), this, SLOT(notePosChanged(VNote*)));
        }
    }


    scene->update();
}

QList<VStaff *> MainWindow::getVstaffs() const
{
    return vstaffs;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter){

        showScore();
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionLilyPond_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Export to Lilypond", "./export", "*.ly");
    svm->makeLilyPond(filename);
}

void MainWindow::on_actionOpen_LilyPond_file_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open LilyPond file", "./export", "*.ly");
    svm->readLilyPond(filename);
    showScore();
}

void MainWindow::on_addStaffButton_clicked()
{
    QStringList clefs;
    clefs << tr("Violin kulcs") << tr("Alt kulcs") << tr("Tenor kulcs") << tr("Basszus kulcs");

    bool ok;

    QString clef = QInputDialog::getItem(this, tr("Válasszon kulcsot"), tr("Kulcsok:"), clefs, 0, false, &ok);

    if(clef == "Violin kulcs"){
        addVStaff(new VStaff(ScoreViewModel::treble,0));
    }else if(clef == "Alt kulcs"){
        addVStaff(new VStaff(ScoreViewModel::alto,0));
    }else if(clef == "Tenor kulcs"){
        addVStaff(new VStaff(ScoreViewModel::tenor,0));
    }else if(clef == "Basszus kulcs"){
        addVStaff(new VStaff(ScoreViewModel::bass,0));
    }


}
