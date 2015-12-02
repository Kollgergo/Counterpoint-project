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
    CPmode = false;

    ui->actionTest->setEnabled(false);
    ui->actionPlayMIDI->setEnabled(false);
    ui->actionStopPlayBack->setEnabled(false);

    instrument = 0;
    midivelocity = 64;
    tempo = 400;

    vals = QMidiOut::devices();
    qDebug() << vals.firstKey();
    midi = new QMidiOut;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete midi;
}

void MainWindow::updateSceneRect()
{
    int maxstaffwidth = 0;

    foreach (VStaff *vstaff, vstaffs) {
        if(vstaff->getVStaffWidth() > maxstaffwidth){
            maxstaffwidth = vstaff->getVStaffWidth();
        }
    }

    scene->setSceneRect(QRectF(0,-100,maxstaffwidth,vstaffs.size()*200));
}

void MainWindow::setSvm(ScoreViewModel *value)
{
    svm = value;
}

void MainWindow::showScore(bool isCF)
{
    vstaffs.clear();
    //svm->deleteStaff(0);
    scene->clear();

    //    svm->updateAccentByKeySig();
    qDebug() << scene->sceneRect();

    for(unsigned int i=1; i<=svm->getNumOfStaffs(); i++){
        if(i == 1){
            this->showNextVStaff(new VStaff(CPmode, isCF,svm->getClefByNum(i), svm->getKeySignatureByNum(i).getKeysig(), 0));
        }else{
            this->showNextVStaff(new VStaff(CPmode, false,svm->getClefByNum(i), svm->getKeySignatureByNum(i).getKeysig(), 0));
        }

        connect(ui->scoreView, SIGNAL(ctrlWheelChanging(int)), vstaffs.last(), SLOT(setVNoteDistance(int)));
        connect(ui->scoreView, SIGNAL(ctrlWheelChanging()), this, SLOT(updateSceneRect()));

        for(unsigned int j=1; j<=svm->getNumOfNotes(i); j++){

            if(i == 1){
                vstaffs.last()->showNextVNote(new VNote(isCF,false, svm->getPosition(i,j), svm->getType(i,j), svm->getAccent(i,j), vstaffs.last()));
            }else{
                vstaffs.last()->showNextVNote(new VNote(false,false, svm->getPosition(i,j), svm->getType(i,j), svm->getAccent(i,j), vstaffs.last()));
            }

            //qDebug() << vstaffs.last();

            connect(vstaffs.last()->getVnotes().last(), SIGNAL(vNoteSelecting(VNote*)), this, SLOT(vNoteSelected(VNote*)));
            connect(vstaffs.last()->getVnotes().last(), SIGNAL(vNotePosChanging(VNote*)), this, SLOT(vNotePosChanged(VNote*)));
        }
        vstaffs.at(i-1)->updateAccentByKeySig();
    }

    updateSceneRect();

    qDebug() << scene->sceneRect();

}

void MainWindow::showNextVStaff(VStaff *vstaff)
{
    vstaffs.push_back(vstaff);
    connect(vstaff, SIGNAL(vstaffSelect(VStaff*)), this, SLOT(vstaffSelected(VStaff*)));

    vstaffs.last()->setY((vstaffs.size()-1)*200);

    scene->addItem(vstaffs.last());
}

void MainWindow::updateNoteData(VNote *vnote) //updates note properties in svm
{
    for(int i=0; i<vstaffs.size(); i++){
        if(vstaffs.at(i)->getVnotes().contains(vnote)){
            //qDebug() << "changing note:" << i+1 << vstaffs.at(i)->getVnotes().indexOf(note)+1;

            vstaffs.at(i)->updateAccentByKeySig();
            if(svm->getAccent(i+1, vstaffs.at(i)->getVnotes().indexOf(vnote)+1) != vnote->getAccent()){
                svm->updateAccent(i+1, vstaffs.at(i)->getVnotes().indexOf(vnote)+1, vnote->getAccent());
                svm->updatePosition(i+1, vstaffs.at(i)->getVnotes().indexOf(vnote)+1, vnote->getStaffpos());
            }

            if(svm->getPosition(i+1, vstaffs.at(i)->getVnotes().indexOf(vnote)+1) != vnote->getStaffpos()){
                svm->updatePosition(i+1, vstaffs.at(i)->getVnotes().indexOf(vnote)+1, vnote->getStaffpos());
                //vstaffs.at(i)->updateAccentByKeySig();
            }

            if(svm->getType(i+1, vstaffs.at(i)->getVnotes().indexOf(vnote)+1) != vnote->getNotetype()){
                svm->updateType(i+1, vstaffs.at(i)->getVnotes().indexOf(vnote)+1, vnote->getNotetype());
            }

            //vstaffs.at(i)->updateAccentByKeySig();
        }
    }
}

void MainWindow::addVStaff(VStaff *vstaff)
{
    vstaffs.push_back(vstaff);
    connect(vstaffs.last(), SIGNAL(vstaffSelect(VStaff*)), this, SLOT(vstaffSelected(VStaff*)));
    connect(vstaffs.last(), SIGNAL(vNoteAccentChanged(VNote*)), this, SLOT(vNoteUpdate(VNote*)));

    svm->addStaff(vstaff->getClef(), vstaff->getKeysignature().getKeysig(), 0);

    vstaffs.last()->setY((vstaffs.size()-1)*200);

    scene->addItem(vstaffs.last());
    connect(ui->scoreView, SIGNAL(ctrlWheelChanging(int)), vstaffs.last(), SLOT(setVNoteDistance(int)));
    connect(ui->scoreView, SIGNAL(ctrlWheelChanging()), this, SLOT(updateSceneRect()));

    updateSceneRect();

}

void MainWindow::addVNote(VStaff *vstaff, unsigned int staffpos, ScoreViewModel::noteTypes notetype, Accent::accents accent, unsigned int where)
{
    vstaff->addVNote(staffpos, notetype, accent, where);
    connect(vstaff->getVnotes().at(where-1), SIGNAL(vNoteSelecting(VNote*)), this, SLOT(vNoteSelected(VNote*)));
    connect(vstaff->getVnotes().at(where-1), SIGNAL(vNotePosChanging(VNote*)), this, SLOT(vNotePosChanged(VNote*)));

    updateSceneRect();

}

void MainWindow::initToolBars(bool isCP)
{
    if(isCP){
        ui->mainToolBar->setEnabled(true);
        ui->actionNewScore->setEnabled(true);
        ui->actionOpenLilypond->setEnabled(true);
        ui->actionSaveLilypond->setEnabled(true);
        ui->actionNewCounterpoint->setEnabled(true);

        ui->actionStopPlayBack->setEnabled(false);
        ui->actionPlayMIDI->setEnabled(true);

        ui->actionAddNote->setChecked(false);
        ui->actionAddRest->setChecked(false);

        ui->actionNewStaff->setEnabled(false);

        ui->actionWhole->setChecked(false);
        ui->actionHalf->setChecked(false);
        ui->actionQuarter->setEnabled(false);
        ui->actionEighth->setEnabled(false);

        ui->actionAddNote->setEnabled(true);
        ui->actionAddRest->setEnabled(true);

        ui->actionWhole->setEnabled(true);
        ui->actionHalf->setEnabled(true);

        ui->actionAddSharp->setChecked(false);
        ui->actionAddFlat->setChecked(false);

    }else{
        ui->mainToolBar->setEnabled(true);
        ui->actionNewScore->setEnabled(true);
        ui->actionOpenLilypond->setEnabled(true);
        ui->actionSaveLilypond->setEnabled(true);
        ui->actionNewCounterpoint->setEnabled(true);

        ui->actionTest->setEnabled(false);
        ui->actionPlayMIDI->setEnabled(false);
        ui->actionStopPlayBack->setEnabled(false);

        ui->actionAddNote->setChecked(false);
        ui->actionAddRest->setChecked(false);

        ui->actionWhole->setChecked(false);
        ui->actionHalf->setChecked(false);
        ui->actionQuarter->setChecked(false);
        ui->actionEighth->setChecked(false);

        ui->actionAddNote->setEnabled(true);
        ui->actionAddRest->setEnabled(true);

        ui->actionWhole->setEnabled(true);
        ui->actionHalf->setEnabled(true);
        ui->actionQuarter->setEnabled(true);
        ui->actionEighth->setEnabled(true);

        ui->actionAddSharp->setChecked(false);
        ui->actionAddFlat->setChecked(false);
    }
}

void MainWindow::vNotePosChanged(VNote *note)
{
    //qDebug() << "notepos changed";

    updateNoteData(note);
    vNoteSelected(note);

}

void MainWindow::vstaffSelected(VStaff *vstaff)
{
    if(selectedvstaff != vstaff){
        foreach (VStaff *vstaff, vstaffs) {
            if(vstaff == selectedvstaff){

                if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){
                    disconnect(vstaff, SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
                    foreach (VStaffLine *staffline, vstaff->getVstafflines()) {
                        staffline->setAcceptHoverEvents(false);
                        disconnect(staffline,SIGNAL(hoverEntering(VStaffLine*)),vstaff->getNewvnote(),SLOT(hoverEntered(VStaffLine*)));
                    }

                    delete(selectedvstaff->getNewvnote());
                    //selectedvstaff->setNewvnote(NULL);
                    vstaff->updateVStaff();
                }

                ui->actionAddNote->setChecked(false);
                ui->actionAddRest->setChecked(false);

                break;
            }
        }
    }

    selectedvstaff = vstaff;
    //scene->update();
    //qDebug() << selectedvstaff;
}

void MainWindow::newVNoteAdded(VNote *vnote)
{
    for(int i=0; i<vstaffs.size(); i++){
        if(vstaffs.at(i) == vnote->parentItem()){
            svm->addNote(i+1, 0, 2, Accent::none, 0);
            updateNoteData(vnote);
            disconnect(vstaffs.at(i), SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
            connect(vstaffs.at(i)->getVnotes().last(), SIGNAL(vNoteSelecting(VNote*)), this, SLOT(vNoteSelected(VNote*)));
            connect(vstaffs.at(i)->getVnotes().last(), SIGNAL(vNotePosChanging(VNote*)), this, SLOT(vNotePosChanged(VNote*)));

            if(CPmode){
                if(vstaffs.at(0)->getDurationSum() > vstaffs.at(1)->getDurationSum()){
                    ui->actionAddNote->setEnabled(true);
                    ui->actionAddRest->setEnabled(true);

                    vstaffs.at(i)->setNewVNoteByData(vstaffs.at(i)->getVnotes().last()->getNotetype(), Accent::none/*vstaffs.at(i)->getVnotes().last()->getAccent()*/);
                    connect(vstaffs.at(i), SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
                    vstaffs.at(i)->updateVStaffWidth();
                    vstaffs.at(i)->setSelected(true);

                }else{
                    ui->actionAddNote->setChecked(false);
                    ui->actionAddRest->setChecked(false);
                    ui->actionWhole->setChecked(false);
                    ui->actionHalf->setChecked(false);
                    ui->actionAddNote->setEnabled(false);
                    ui->actionAddRest->setEnabled(false);
                    ui->actionWhole->setEnabled(false);
                    ui->actionHalf->setEnabled(false);
                    ui->actionTest->setEnabled(true);

                    vstaffs.at(i)->updateVStaffWidth();
                }

            }else{
                vstaffs.at(i)->setNewVNoteByData(vstaffs.at(i)->getVnotes().last()->getNotetype(), Accent::none/*vstaffs.at(i)->getVnotes().last()->getAccent()*/);
                connect(vstaffs.at(i), SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
                vstaffs.at(i)->updateVStaffWidth();
                vstaffs.at(i)->setSelected(true);
            }
        }
        //vstaffs.at(i)->updateAccentByKeySig();
    }

    scene->update();
    updateSceneRect();

}

void MainWindow::playBackEnded()
{
    playbackcounter++;

    if(playbackcounter == svm->getNumOfStaffs()){
        ui->actionStopPlayBack->setEnabled(false);
        if(CPmode){
            ui->actionPlayMIDI->setEnabled(true);
            ui->actionNewScore->setEnabled(true);
            ui->actionOpenLilypond->setEnabled(true);
            ui->actionSaveLilypond->setEnabled(true);
            ui->actionNewCounterpoint->setEnabled(true);
            //ui->actionTest->setEnabled(true);
            ui->mainToolBar->setEnabled(true);
            ui->actionNewStaff->setEnabled(false);
            ui->actionQuarter->setEnabled(false);
            ui->actionEighth->setEnabled(false);
            if(vstaffs.at(0)->getDurationSum() == vstaffs.at(1)->getDurationSum()){
                ui->actionTest->setEnabled(true);
            }
        }else{
            ui->actionPlayMIDI->setEnabled(true);
            ui->actionNewScore->setEnabled(true);
            ui->actionOpenLilypond->setEnabled(true);
            ui->actionSaveLilypond->setEnabled(true);
            ui->actionNewCounterpoint->setEnabled(true);
            ui->mainToolBar->setEnabled(true);
        }

        midi->disconnect();
    }
}

void MainWindow::vNoteUpdate(VNote *vnote)
{
    updateNoteData(vnote);
}

QList<VStaff *> MainWindow::getVstaffs() const
{
    return vstaffs;
}

VStaff *MainWindow::getSelectedVStaff() const
{
    foreach (VStaff* vstaff, vstaffs) {
        if(vstaff->isSelected()){
            return vstaff;
        }
    }
    return NULL;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Delete:
        for(int i=0; i<vstaffs.size(); i++){
            if(vstaffs.at(i) == getSelectedVStaff()){
                for(int j=0; j<vstaffs.at(i)->getVnotes().size(); j++){
                    if(vstaffs.at(i)->getVnotes().at(j)->isSelected()){
                        if(svm->getNoteByNum(i+1, j+1).getPitch() == Note::rest){
                            svm->deleteNote(i+1,j+1);
                            //vstaffs.at(i)->getVnotes().removeAt(j);
                            showScore();
                            if(CPmode){
                                ui->actionAddNote->setEnabled(true);
                                ui->actionAddRest->setEnabled(true);
                                ui->actionWhole->setEnabled(true);
                                ui->actionHalf->setEnabled(true);
                                ui->actionTest->setEnabled(false);
                            }
                            break;
                        }else{
                            svm->changeToRest(i+1, j+1);
                            vstaffs.at(i)->getVnotes().at(j)->changeToRest();
                            vstaffs.at(i)->updateVStaff();
                            vstaffs.at(i)->updateVStaffWidth();
                            break;
                        }
                    }
                }
            }
        }
        break;
    case Qt::Key_Escape:
        if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){
            foreach (VStaff *vstaff, vstaffs) {
                if(vstaff == selectedvstaff){
                    disconnect(vstaff, SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
                    foreach (VStaffLine *staffline, vstaff->getVstafflines()) {
                        staffline->setAcceptHoverEvents(false);
                        disconnect(staffline,SIGNAL(hoverEntering(VStaffLine*)),vstaff->getNewvnote(),SLOT(hoverEntered(VStaffLine*)));
                    }

                    vstaff->updateVStaff();
                    vstaff->updateVStaffWidth();

                    delete(selectedvstaff->getNewvnote());
                    selectedvstaff->setNewvnote(NULL);
                }
            }
        }
        ui->actionHalf->setChecked(false);
        ui->actionWhole->setChecked(false);
        ui->actionQuarter->setChecked(false);
        ui->actionEighth->setChecked(false);
        ui->actionAddSharp->setChecked(false);
        ui->actionAddFlat->setChecked(false);
        ui->actionAddNote->setChecked(false);
        ui->actionAddRest->setChecked(false);

        foreach (QGraphicsItem *item, scene->selectedItems()) {
            item->setSelected(false);
        }
        scene->update();
        break;
    default:
        break;
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::addVNoteButtonClicked(bool isrest, bool checked){
    if(checked){ //check
        if(!vstaffs.isEmpty()){
            foreach (VStaff *vstaff, vstaffs) {
                if(vstaff->isSelected()){
                    vstaff->updateVStaffWidth();
                    if(isrest){
                        ui->actionAddNote->setChecked(false);
                        ui->actionAddRest->setChecked(true);
                    }else{
                        ui->actionAddNote->setChecked(true);
                        ui->actionAddRest->setChecked(false);
                    }

                    ui->actionHalf->setChecked(false);
                    ui->actionWhole->setChecked(false);
                    ui->actionQuarter->setChecked(false);
                    ui->actionEighth->setChecked(false);
                    ui->actionAddSharp->setChecked(false);
                    ui->actionAddFlat->setChecked(false);
                    ui->actionPlayMIDI->setEnabled(true);

                    if(isrest){
                        if(vstaff->getVnotes().isEmpty()){
                            vstaff->setNewVNoteByData(ScoreViewModel::half_rest, Accent::none);
                            ui->actionHalf->setChecked(true);
                        }else if(vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::whole_rest || vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::half_rest ||
                                 vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::quarter_rest || vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::eighth_rest){
                            vstaff->setNewVNoteByData(vstaff->getVnotes().last()->getNotetype(), Accent::none);
                            switch (vstaff->getVnotes().last()->getNotetype()) {
                            case ScoreViewModel::whole:
                                ui->actionWhole->setChecked(true);
                                break;
                            case ScoreViewModel::half:
                                ui->actionHalf->setChecked(true);
                                break;
                            case ScoreViewModel::quarter:
                                ui->actionQuarter->setChecked(true);
                                break;
                            case ScoreViewModel::eighth:
                                ui->actionEighth->setChecked(true);
                                break;
                            default:
                                break;
                            }
                        }else{
                            switch (vstaff->getVnotes().last()->getNotetype()) {
                            case ScoreViewModel::whole:
                                vstaff->setNewVNoteByData(ScoreViewModel::whole_rest, Accent::none);
                                ui->actionWhole->setChecked(true);
                                break;
                            case ScoreViewModel::half:
                                vstaff->setNewVNoteByData(ScoreViewModel::half_rest, Accent::none);
                                ui->actionHalf->setChecked(true);
                                break;
                            case ScoreViewModel::quarter:
                                vstaff->setNewVNoteByData(ScoreViewModel::quarter_rest, Accent::none);
                                ui->actionQuarter->setChecked(true);
                                break;
                            case ScoreViewModel::eighth:
                                vstaff->setNewVNoteByData(ScoreViewModel::eighth_rest, Accent::none);
                                ui->actionEighth->setChecked(true);
                                break;
                            default:
                                vstaff->setNewVNoteByData(ScoreViewModel::half_rest, Accent::none);
                                break;
                            }
                        }
                    }else{
                        if(vstaff->getVnotes().isEmpty()){
                            vstaff->setNewVNoteByData(ScoreViewModel::half, Accent::none);

                            ui->actionHalf->setChecked(true);
                        }else if(vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::whole || vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::half ||
                                 vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::quarter || vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::eighth){
                            vstaff->setNewVNoteByData(vstaff->getVnotes().last()->getNotetype(), Accent::none);
                            switch (vstaff->getVnotes().last()->getNotetype()) {
                            case ScoreViewModel::whole:
                                ui->actionWhole->setChecked(true);
                                break;
                            case ScoreViewModel::half:
                                ui->actionHalf->setChecked(true);
                                break;
                            case ScoreViewModel::quarter:
                                ui->actionQuarter->setChecked(true);
                                break;
                            case ScoreViewModel::eighth:
                                ui->actionEighth->setChecked(true);
                                break;
                            default:
                                break;
                            }

                        }else{
                            switch (vstaff->getVnotes().last()->getNotetype()) {
                            case ScoreViewModel::whole_rest:
                                vstaff->setNewVNoteByData(ScoreViewModel::whole, Accent::none);
                                ui->actionWhole->setChecked(true);
                                break;
                            case ScoreViewModel::half_rest:
                                vstaff->setNewVNoteByData(ScoreViewModel::half, Accent::none);
                                ui->actionHalf->setChecked(true);
                                break;
                            case ScoreViewModel::quarter_rest:
                                vstaff->setNewVNoteByData(ScoreViewModel::quarter, Accent::none);
                                ui->actionQuarter->setChecked(true);
                                break;
                            case ScoreViewModel::eighth_rest:
                                vstaff->setNewVNoteByData(ScoreViewModel::eighth, Accent::none);
                                ui->actionEighth->setChecked(true);
                                break;
                            default:
                                vstaff->setNewVNoteByData(ScoreViewModel::half, Accent::none);
                                break;
                            }
                        }
                    }

                    connect(vstaff, SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
                    vstaff->updateVStaffWidth();
                    break;
                }else{
                    if(isrest){
                        ui->actionAddRest->setChecked(false);
                    }else{
                        ui->actionAddNote->setChecked(false);
                    }

                }
            }
            scene->update();

        }else{
            if(isrest){
                ui->actionAddRest->setChecked(false);
            }else{
                ui->actionAddNote->setChecked(false);
            }
        }

    }else{ //uncheck
        ui->actionHalf->setChecked(false);
        ui->actionWhole->setChecked(false);
        ui->actionQuarter->setChecked(false);
        ui->actionEighth->setChecked(false);
        ui->actionAddSharp->setChecked(false);
        ui->actionAddFlat->setChecked(false);

        foreach (VStaff *vstaff, vstaffs) {
            if(vstaff == selectedvstaff){
                disconnect(vstaff, SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
                foreach (VStaffLine *staffline, vstaff->getVstafflines()) {
                    staffline->setAcceptHoverEvents(false);
                    disconnect(staffline,SIGNAL(hoverEntering(VStaffLine*)),vstaff->getNewvnote(),SLOT(hoverEntered(VStaffLine*)));
                }

                vstaff->updateVStaff();
                vstaff->updateVStaffWidth();

                delete(selectedvstaff->getNewvnote());
                selectedvstaff->setNewvnote(NULL);
            }
        }

        scene->update();
    }
}

void MainWindow::on_actionAddNote_triggered(bool checked)
{
    addVNoteButtonClicked(false, checked);
}

void MainWindow::on_actionAddRest_triggered(bool checked)
{
    addVNoteButtonClicked(true, checked);
}

void MainWindow::durationButtonClicked(ScoreViewModel::noteTypes ntype, bool checked)
{
    if(checked){
        if(!vstaffs.isEmpty()){
            if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){
                ui->actionWhole->setChecked(false);
                ui->actionHalf->setChecked(false);
                ui->actionQuarter->setChecked(false);
                ui->actionEighth->setChecked(false);

                switch (ntype) {
                case ScoreViewModel::whole:
                    ui->actionWhole->setChecked(true);
                    getSelectedVStaff()->getNewvnote()->setNotetype(ScoreViewModel::whole);
                    break;
                case ScoreViewModel::half:
                    ui->actionHalf->setChecked(true);
                    getSelectedVStaff()->getNewvnote()->setNotetype(ScoreViewModel::half);
                    break;
                case ScoreViewModel::quarter:
                    ui->actionQuarter->setChecked(true);
                    getSelectedVStaff()->getNewvnote()->setNotetype(ScoreViewModel::quarter);
                    break;
                case ScoreViewModel::eighth:
                    ui->actionEighth->setChecked(true);
                    getSelectedVStaff()->getNewvnote()->setNotetype(ScoreViewModel::eighth);
                    break;
                default:
                    break;
                }


                scene->update();
            }else{
                ui->actionWhole->setChecked(false);
                ui->actionHalf->setChecked(false);
                ui->actionQuarter->setChecked(false);
                ui->actionEighth->setChecked(false);

                for(int i=0; i<vstaffs.size(); i++){
                    if(vstaffs.at(i)->isSelected()){
                        for(int j=0; j<getSelectedVStaff()->getVnotes().size(); j++){
                            if(getSelectedVStaff()->getVnotes().at(j)->isSelected()){
                                //svm->updateType(vstaffs.indexOf(selectedvstaff)+1, j+1, ScoreViewModel::whole);

                                switch (ntype) {
                                case ScoreViewModel::whole:
                                    ui->actionWhole->setChecked(true);
                                    getSelectedVStaff()->getVnotes().at(j)->setNotetype(ScoreViewModel::whole);
                                    break;
                                case ScoreViewModel::half:
                                    ui->actionHalf->setChecked(true);
                                    getSelectedVStaff()->getVnotes().at(j)->setNotetype(ScoreViewModel::half);
                                    break;
                                case ScoreViewModel::quarter:
                                    ui->actionQuarter->setChecked(true);
                                    getSelectedVStaff()->getVnotes().at(j)->setNotetype(ScoreViewModel::quarter);
                                    break;
                                case ScoreViewModel::eighth:
                                    ui->actionEighth->setChecked(true);
                                    getSelectedVStaff()->getVnotes().at(j)->setNotetype(ScoreViewModel::eighth);
                                    break;
                                default:
                                    break;
                                }
                                updateNoteData(getSelectedVStaff()->getVnotes().at(j));

                                getSelectedVStaff()->updateVStaff();
                                getSelectedVStaff()->getVnotes().at(j)->setSelected(true);
                                scene->update();

                                break;
                            }
                        }
                    }
                }

                //ui->actionWhole->setChecked(false);
            }
        }else{
            switch (ntype) {
            case ScoreViewModel::whole:
                ui->actionWhole->setChecked(false);
                break;
            case ScoreViewModel::half:
                ui->actionHalf->setChecked(false);

                break;
            case ScoreViewModel::quarter:
                ui->actionQuarter->setChecked(false);

                break;
            case ScoreViewModel::eighth:
                ui->actionEighth->setChecked(false);

                break;
            default:
                break;
            }

        }
    }
}

void MainWindow::on_actionWhole_triggered(bool checked)
{
    durationButtonClicked(ScoreViewModel::whole, checked);
}

void MainWindow::on_actionHalf_triggered(bool checked)
{
    durationButtonClicked(ScoreViewModel::half, checked);
}

void MainWindow::on_actionQuarter_triggered(bool checked)
{
    durationButtonClicked(ScoreViewModel::quarter, checked);
}

void MainWindow::on_actionEighth_triggered(bool checked)
{
    durationButtonClicked(ScoreViewModel::eighth, checked);
}

void MainWindow::addAccentButtonClicked(bool isflat, bool checked)
{
    if(checked){
        if(!vstaffs.isEmpty()){
            if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){
                if(isflat){
                    ui->actionAddSharp->setChecked(false);
                }else{
                    ui->actionAddFlat->setChecked(false);
                }

                if(getSelectedVStaff()->getNewvnote()->getNotetype() == ScoreViewModel::whole || getSelectedVStaff()->getNewvnote()->getNotetype() == ScoreViewModel::half ||
                        getSelectedVStaff()->getNewvnote()->getNotetype() == ScoreViewModel::quarter || getSelectedVStaff()->getNewvnote()->getNotetype() == ScoreViewModel::eighth){
                    if(isflat){
                        getSelectedVStaff()->getNewvnote()->setAccent(Accent::flat, false);
                    }else{
                        getSelectedVStaff()->getNewvnote()->setAccent(Accent::sharp, false);
                    }

                }else{
                    if(isflat){
                        ui->actionAddFlat->setChecked(false);
                    }else{
                        ui->actionAddSharp->setChecked(false);
                    }
                }
                scene->update();

            }else{
                ui->actionAddSharp->setChecked(false);
                ui->actionAddFlat->setChecked(false);

                for(int i=0; i<vstaffs.size(); i++){
                    if(vstaffs.at(i)->isSelected()){
                        for(int j=0; j<getSelectedVStaff()->getVnotes().size(); j++){
                            if(getSelectedVStaff()->getVnotes().at(j)->isSelected()){
                                if(getSelectedVStaff()->getVnotes().at(j)->getNotetype() == ScoreViewModel::whole || getSelectedVStaff()->getVnotes().at(j)->getNotetype() == ScoreViewModel::half ||
                                        getSelectedVStaff()->getVnotes().at(j)->getNotetype() == ScoreViewModel::quarter || getSelectedVStaff()->getVnotes().at(j)->getNotetype() == ScoreViewModel::eighth){
                                    //svm->updateType(vstaffs.indexOf(selectedvstaff)+1, j+1, ScoreViewModel::eight);
                                    if(isflat){
                                        getSelectedVStaff()->getVnotes().at(j)->setAccent(Accent::flat, false);
                                        ui->actionAddFlat->setChecked(true);
                                    }else{
                                        getSelectedVStaff()->getVnotes().at(j)->setAccent(Accent::sharp, false);
                                        ui->actionAddSharp->setChecked(true);
                                    }

                                    updateNoteData(getSelectedVStaff()->getVnotes().at(j));
                                    scene->update();
                                    //showScore();
                                    getSelectedVStaff()->getVnotes().at(j)->setSelected(true);

                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }else{
            if(isflat){
                ui->actionAddFlat->setChecked(false);
            }else{
                ui->actionAddSharp->setChecked(false);
            }
        }

    }else{

        if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){

            if(isflat){
                ui->actionAddSharp->setChecked(false);
                getSelectedVStaff()->getNewvnote()->setAccent(Accent::none, false);
            }else{
                ui->actionAddFlat->setChecked(false);
                getSelectedVStaff()->getNewvnote()->setAccent(Accent::none, false);
            }
            scene->update();

        }else{

            if(isflat){
                ui->actionAddSharp->setChecked(false);
            }else{
                ui->actionAddFlat->setChecked(false);
            }

            if(getSelectedVStaff()->getSelectedvnote()->getNotetype() == ScoreViewModel::whole || getSelectedVStaff()->getSelectedvnote()->getNotetype() == ScoreViewModel::half ||
                    getSelectedVStaff()->getSelectedvnote()->getNotetype() == ScoreViewModel::quarter || getSelectedVStaff()->getSelectedvnote()->getNotetype() == ScoreViewModel::eighth){
                if(getSelectedVStaff()->getSelectedvnote()->getIskeysig()){
                    getSelectedVStaff()->getSelectedvnote()->setAccent(Accent::natural, true);
                }else{
                    getSelectedVStaff()->getSelectedvnote()->setAccent(Accent::none, false);
                }
                updateNoteData(getSelectedVStaff()->getSelectedvnote());
                scene->update();
            }
        }
    }
}

void MainWindow::on_actionAddSharp_triggered(bool checked)
{
    addAccentButtonClicked(false, checked);
}

void MainWindow::on_actionAddFlat_triggered(bool checked)
{
    addAccentButtonClicked(true, checked);
}

void MainWindow::vNoteSelected(VNote *note)
{
    ui->actionHalf->setChecked(false);
    ui->actionWhole->setChecked(false);
    ui->actionQuarter->setChecked(false);
    ui->actionEighth->setChecked(false);
    ui->actionAddSharp->setChecked(false);
    ui->actionAddFlat->setChecked(false);

    switch (note->getNotetype()) {
    case ScoreViewModel::whole:
        ui->actionWhole->setChecked(true);
        break;
    case ScoreViewModel::half:
        ui->actionHalf->setChecked(true);
        break;
    case ScoreViewModel::quarter:
        ui->actionQuarter->setChecked(true);
        break;
    case ScoreViewModel::eighth:
        ui->actionEighth->setChecked(true);
        break;
    case ScoreViewModel::whole_rest:
        ui->actionWhole->setChecked(true);
        break;
    case ScoreViewModel::half_rest:
        ui->actionHalf->setChecked(true);
        break;
    case ScoreViewModel::quarter_rest:
        ui->actionQuarter->setChecked(true);
        break;
    case ScoreViewModel::eighth_rest:
        ui->actionEighth->setChecked(true);
        break;
    default:
        ui->actionHalf->setChecked(true);
        break;
    }

    switch (note->getAccent()) {
    case Accent::sharp:
        ui->actionAddSharp->setChecked(true);
        break;
    case Accent::flat:
        ui->actionAddFlat->setChecked(true);
        break;
    default:

        break;
    }

    if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){
        foreach (VStaff *vstaff, vstaffs) {
            if(vstaff == selectedvstaff){
                disconnect(vstaff, SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
                foreach (VStaffLine *staffline, vstaff->getVstafflines()) {
                    staffline->setAcceptHoverEvents(false);
                    disconnect(staffline,SIGNAL(hoverEntering(VStaffLine*)),vstaff->getNewvnote(),SLOT(hoverEntered(VStaffLine*)));
                }

                delete(selectedvstaff->getNewvnote());
                //selectedvstaff->setNewvnote(NULL);
                vstaff->updateVStaff();
            }
        }
    }
    ui->actionAddNote->setChecked(false);
    ui->actionAddRest->setChecked(false);

}

void MainWindow::on_actionNewScore_triggered()
{
    QMessageBox msgbox(this);
    msgbox.setWindowTitle("Új kotta megnyitása");
    msgbox.setText("Új kotta megnyitása.");
    msgbox.setInformativeText("Minden, el nem mentett változás elvész. Folytatja?");
    msgbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgbox.setDefaultButton(QMessageBox::Cancel);
    msgbox.setButtonText(QMessageBox::Ok, "Igen");
    msgbox.setButtonText(QMessageBox::Cancel, "Mégse");
    int ret = msgbox.exec();

    switch (ret) {
    case QMessageBox::Ok:
        svm->deleteStaff(0);
        vstaffs.clear();
        scene->clear();
        ui->actionNewStaff->setDisabled(false);
        initToolBars(false);
        CPmode = false;
        tempo = 400;
        break;
    case QMessageBox::Cancel:

        break;
    default:
        break;
    }
}

void MainWindow::on_actionNewCounterpoint_triggered()
{
    CPmode = true;

    tempo = 200;

    QMessageBox msgbox(this);
    msgbox.setWindowTitle("Új Ellenpont feladat");
    msgbox.setText("Új Ellenpont feladat megnyitása");
    msgbox.setInformativeText("Minden, el nem mentett változás elvész. Folytatja?");
    msgbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgbox.setDefaultButton(QMessageBox::Cancel);
    msgbox.setButtonText(QMessageBox::Ok, "Igen");
    msgbox.setButtonText(QMessageBox::Cancel, "Mégse");
    int ret = msgbox.exec();

    if(ret == QMessageBox::Ok){
        svm->deleteStaff(0);
        vstaffs.clear();
        scene->clear();

        NewCPDialog *cpdialog = new NewCPDialog(this);
        if(cpdialog->exec() == QDialog::Accepted){
            svm->readLilyPond(cpdialog->getFileName(), true);
            svm->addStaff(cpdialog->getClef(), svm->getClefByNum(1), 0);
            showScore(true);
            initToolBars(true);

            vstaffs.last()->setSelected(true);

        }
    }
}

void MainWindow::on_actionChangeNoteRest_triggered()
{
    for(int i=0; i<vstaffs.size(); i++){
        if(vstaffs.at(i)->isSelected()){
            for(int j=0; j<vstaffs.at(i)->getVnotes().size(); j++){
                if(vstaffs.at(i)->getVnotes().at(j)->isSelected()){
                    if(svm->getNoteByNum(i+1, j+1).getPitch() == Note::rest){ //change to note
                        vstaffs.at(i)->getVnotes().at(j)->changeToNote();
                        updateNoteData(vstaffs.at(i)->getVnotes().at(j));
                        vstaffs.at(i)->updateVStaff();
                        vstaffs.at(i)->updateVStaffWidth();
                        break;

                    }else{ //change to rest
                        svm->changeToRest(i+1, j+1);
                        vstaffs.at(i)->getVnotes().at(j)->changeToRest();
                        vstaffs.at(i)->updateVStaff();
                        vstaffs.at(i)->updateVStaffWidth();
                        break;
                    }
                }
            }
        }
    }
}

void MainWindow::on_actionOpenLilypond_triggered()
{
    CPmode = false;
    tempo = 400;

    initToolBars(false);
    ui->actionPlayMIDI->setEnabled(true);

    QString filename = QFileDialog::getOpenFileName(this, "LilyPond file megnyitása", "./export", "*.ly");
    if(!filename.isEmpty()){
        svm->readLilyPond(filename, false);
        showScore(false);
    }
}

void MainWindow::on_actionSaveLilypond_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Exportálás LilyPond fájlba", "./export", "*.ly");
    if(!filename.isEmpty()){
        svm->makeLilyPond(filename);
    }
}

void MainWindow::on_actionTest_triggered()
{
    QList<Error *> errors = svm->testScore();

    if(errors.isEmpty()){
        foreach (VStaff *vstaff, vstaffs) {
            vstaff->deleteErrorMarkers();
        }

        QMessageBox okBox(this);
        okBox.setWindowTitle("Az feladat ellenőrizve");
        okBox.setText("Az ellenpont hibátlan!");
        okBox.exec();

    }else{

        foreach (VStaff *vstaff, vstaffs) {
            vstaff->deleteErrorMarkers();
        }

        foreach (Error *error, errors) {
            //errormarkers.push_back(new ErrorMarker(error->getErrormessage(), this));
            vstaffs[error->getLocation().first]->setNewError(error->getLocation().second,error->getErrormessage());
        }
    }


}

void MainWindow::on_actionNewStaff_triggered()
{
    NewStaffDialog *staffdialog = new NewStaffDialog(this);
    if(staffdialog->exec() == QDialog::Accepted){
        addVStaff(new VStaff(false, false, staffdialog->getSelectedclef(), staffdialog->getSelectedkeysignature(), 0));
        foreach (VStaff *vstaff, vstaffs) {
            vstaff->setSelected(false);
        }
        vstaffs.last()->setSelected(true);
        ui->actionPlayMIDI->setEnabled(true);
    }
}

void MainWindow::on_actionPlayMIDI_triggered()
{
    if(svm->getNumOfStaffs() > 0){
        ui->actionPlayMIDI->setEnabled(false);
        ui->actionStopPlayBack->setEnabled(true);
        ui->actionNewScore->setEnabled(false);
        ui->actionOpenLilypond->setEnabled(false);
        ui->actionSaveLilypond->setEnabled(false);
        ui->actionNewCounterpoint->setEnabled(false);
        ui->actionTest->setEnabled(false);
        ui->mainToolBar->setEnabled(false);
        playbackcounter = 0;


        midi->connect(vals.firstKey());

        voices.clear();

        for(unsigned int i=0; i<svm->getNumOfStaffs(); i++){
            midi->setInstrument(/* voice */ i, /* instrument */ instrument);
            QThread* thread = new QThread;
            voices.push_back(new PlayBack(midi, i, midivelocity, tempo,svm->getStaffByNum(i+1), svm->getStaffAccentByNum(i+1)));
            voices.last()->moveToThread(thread);
            connect(thread, SIGNAL(started()), voices.last(), SLOT(process()));
            connect(voices.last(), SIGNAL(finished()), thread, SLOT(quit()));
            connect(voices.last(), SIGNAL(finished()), voices.last(), SLOT(deleteLater()));
            connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
            connect(voices.last(), SIGNAL(finished()), this, SLOT(playBackEnded()));
            thread->start();
        }

    }
}

void MainWindow::on_actionStopPlayBack_triggered()
{
    ui->actionStopPlayBack->setEnabled(false);
    //midi->stopAll();
    foreach (PlayBack *playback, voices) {
        playback->finished();
    }

    if(CPmode){
        ui->actionPlayMIDI->setEnabled(true);
        ui->actionNewScore->setEnabled(true);
        ui->actionOpenLilypond->setEnabled(true);
        ui->actionSaveLilypond->setEnabled(true);
        ui->actionNewCounterpoint->setEnabled(true);
        //ui->actionTest->setEnabled(true);
        ui->mainToolBar->setEnabled(true);
        ui->actionNewStaff->setEnabled(false);
        ui->actionQuarter->setEnabled(false);
        ui->actionEighth->setEnabled(false);
        if(vstaffs.at(0)->getDurationSum() == vstaffs.at(1)->getDurationSum()){
            ui->actionTest->setEnabled(true);
        }
    }else{
        ui->actionPlayMIDI->setEnabled(true);
        ui->actionNewScore->setEnabled(true);
        ui->actionOpenLilypond->setEnabled(true);
        ui->actionSaveLilypond->setEnabled(true);
        ui->actionNewCounterpoint->setEnabled(true);
        ui->mainToolBar->setEnabled(true);
    }

}

void MainWindow::on_actionCutHalf_triggered()
{
    if(getSelectedVStaff() != NULL){
        VStaff *tempvstaff = getSelectedVStaff();
        VNote *tempvnote = getSelectedVStaff()->getSelectedvnote();

        if(tempvnote != NULL){
            switch (tempvnote->getNotetype()) {
            case ScoreViewModel::whole:
                tempvnote->setNotetype(ScoreViewModel::half);
                updateNoteData(tempvnote);
                addVNote(tempvstaff, tempvnote->getStaffpos(),ScoreViewModel::half, tempvnote->getAccent(), tempvstaff->getVnotes().indexOf(tempvnote)+1);
                svm->addNote(vstaffs.indexOf(tempvstaff)+1,0,0,Accent::none,tempvstaff->getVnotes().indexOf(tempvnote)+1);
                updateNoteData(tempvnote);
                break;
            case ScoreViewModel::half:
                tempvnote->setNotetype(ScoreViewModel::quarter);
                updateNoteData(tempvnote);
                addVNote(tempvstaff, tempvnote->getStaffpos(),ScoreViewModel::quarter, tempvnote->getAccent(), tempvstaff->getVnotes().indexOf(tempvnote)+1);
                svm->addNote(vstaffs.indexOf(tempvstaff)+1,0,0,Accent::none,tempvstaff->getVnotes().indexOf(tempvnote)+1);
                updateNoteData(tempvnote);
                break;
            case ScoreViewModel::quarter:
                tempvnote->setNotetype(ScoreViewModel::eighth);
                updateNoteData(tempvnote);
                addVNote(tempvstaff, tempvnote->getStaffpos(),ScoreViewModel::eighth, tempvnote->getAccent(), tempvstaff->getVnotes().indexOf(tempvnote)+1);
                svm->addNote(vstaffs.indexOf(tempvstaff)+1,0,0,Accent::none,tempvstaff->getVnotes().indexOf(tempvnote)+1);
                updateNoteData(tempvnote);
                break;
            case ScoreViewModel::eighth:
                addVNote(tempvstaff, tempvnote->getStaffpos(),ScoreViewModel::eighth, tempvnote->getAccent(), tempvstaff->getVnotes().indexOf(tempvnote)+1);
                svm->addNote(vstaffs.indexOf(tempvstaff)+1,0,0,Accent::none,tempvstaff->getVnotes().indexOf(tempvnote)+1);
                updateNoteData(tempvnote);
                break;
            case ScoreViewModel::whole_rest:
                tempvnote->setNotetype(ScoreViewModel::half);
                updateNoteData(tempvnote);
                addVNote(tempvstaff, tempvnote->getStaffpos(),ScoreViewModel::half_rest, tempvnote->getAccent(), tempvstaff->getVnotes().indexOf(tempvnote)+1);
                svm->addNote(vstaffs.indexOf(tempvstaff)+1,Note::rest,0,Accent::none,tempvstaff->getVnotes().indexOf(tempvnote)+1);
                updateNoteData(tempvnote);
                break;
            case ScoreViewModel::half_rest:
                tempvnote->setNotetype(ScoreViewModel::quarter);
                updateNoteData(tempvnote);
                addVNote(tempvstaff, tempvnote->getStaffpos(),ScoreViewModel::quarter_rest, tempvnote->getAccent(), tempvstaff->getVnotes().indexOf(tempvnote)+1);
                svm->addNote(vstaffs.indexOf(tempvstaff)+1,Note::rest,0,Accent::none,tempvstaff->getVnotes().indexOf(tempvnote)+1);
                updateNoteData(tempvnote);
                break;
            case ScoreViewModel::quarter_rest:
                tempvnote->setNotetype(ScoreViewModel::eighth);
                updateNoteData(tempvnote);
                addVNote(tempvstaff, tempvnote->getStaffpos(),ScoreViewModel::eighth_rest, tempvnote->getAccent(), tempvstaff->getVnotes().indexOf(tempvnote)+1);
                svm->addNote(vstaffs.indexOf(tempvstaff)+1,Note::rest,0,Accent::none,tempvstaff->getVnotes().indexOf(tempvnote)+1);
                updateNoteData(tempvnote);
                break;
            case ScoreViewModel::eighth_rest:
                addVNote(tempvstaff, tempvnote->getStaffpos(),ScoreViewModel::eighth_rest, tempvnote->getAccent(), tempvstaff->getVnotes().indexOf(tempvnote)+1);
                svm->addNote(vstaffs.indexOf(tempvstaff)+1,Note::rest,0,Accent::none,tempvstaff->getVnotes().indexOf(tempvnote)+1);
                updateNoteData(tempvnote);
                break;
            default:
                break;
            }
        }
    }
}

void MainWindow::on_actionMidiSettings_triggered()
{
    //qDebug() << midivelocity;
    MidiSettingsDialog *dialog = new MidiSettingsDialog(instrument, midivelocity, tempo/8, this);

    if(dialog->exec() == QDialog::Accepted){
        instrument = dialog->getInstrument();
        midivelocity = dialog->getVolume()-1;
        tempo = dialog->getTempo()*8;
    }
}

void MainWindow::on_actionScoreSettings_triggered()
{
    int notedist = 50;
    if(!vstaffs.isEmpty()){
        notedist = vstaffs.first()->getVNoteDistance();
    }

    ScoreSettingsDialog *dialog = new ScoreSettingsDialog(svm->getRuleList(), notedist, this);

    if(dialog->exec() == QDialog::Accepted){
        svm->setRules(dialog->getRuleList());
        foreach (VStaff *vstaff, vstaffs) {
            vstaff->setVNoteDistance(dialog->getVnoteDistance());
        }
    }
}
