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

void MainWindow::setSvm(ScoreViewModel *value)
{
    svm = value;
}

void MainWindow::showScore()
{
    vstaffs.clear();
    //svm->deleteStaff(0);
    scene->clear();

    for(unsigned int i=1; i<=svm->getNumOfStaffs(); i++){
        this->showNextVStaff(new VStaff(svm->getClefByNum(i), svm->getKeySignatureByNum(i).getKeysig(), 0));

        for(unsigned int j=1; j<=svm->getNumOfNotes(i); j++){

            vstaffs.last()->showNextVNote(new VNote(false, svm->getPosition(i,j), svm->getType(i,j), svm->getAccent(i,j), vstaffs.last()));

            //qDebug() << vstaffs.last();

            connect(vstaffs.last()->getVnotes().last(), SIGNAL(vNoteSelecting(VNote*)), this, SLOT(vNoteSelected(VNote*)));
            connect(vstaffs.last()->getVnotes().last(), SIGNAL(vNotePosChanging(VNote*)), this, SLOT(vNotePosChanged(VNote*)));
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

void MainWindow::updateNoteData(VNote *vnote) //updates note properties in svm
{
    for(int i=0; i<vstaffs.size(); i++){
        if(vstaffs.at(i)->getVnotes().contains(vnote)){
            //qDebug() << "changing note:" << i+1 << vstaffs.at(i)->getVnotes().indexOf(note)+1;
            svm->updateAccent(i+1, vstaffs.at(i)->getVnotes().indexOf(vnote)+1, vnote->getAccent());
            svm->updatePosition(i+1, vstaffs.at(i)->getVnotes().indexOf(vnote)+1, vnote->getScorepos());

            if(svm->getType(i+1, vstaffs.at(i)->getVnotes().indexOf(vnote)+1) != vnote->getScorepos()){
                svm->updateType(i+1, vstaffs.at(i)->getVnotes().indexOf(vnote)+1, vnote->getNotetype());
            }
        }
    }
}

void MainWindow::addVStaff(VStaff *vstaff)
{
    vstaffs.push_back(vstaff);
    connect(vstaffs.last(), SIGNAL(vstaffSelect(VStaff*)), this, SLOT(vstaffSelected(VStaff*)));

    svm->addStaff(vstaff->getClef(), vstaff->getKeysignature().getKeysig(), 0);

    vstaffs.last()->setY((vstaffs.size()-1)*200);

    scene->addItem(vstaffs.last());
}

void MainWindow::vNotePosChanged(VNote *note)
{
    //qDebug() << "notepos changed";

    updateNoteData(note);

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
                    selectedvstaff->setNewvnote(NULL);
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
            svm->addNote(i+1, 0, 2, ScoreViewModel::none, 0);
            updateNoteData(vnote);
            disconnect(vstaffs.at(i), SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
            connect(vstaffs.at(i)->getVnotes().last(), SIGNAL(vNoteSelecting(VNote*)), this, SLOT(vNoteSelected(VNote*)));
            connect(vstaffs.at(i)->getVnotes().last(), SIGNAL(vNotePosChanging(VNote*)), this, SLOT(vNotePosChanged(VNote*)));

            vstaffs.at(i)->setNewVNote(vstaffs.at(i)->getVnotes().last()->getNotetype(), vstaffs.at(i)->getVnotes().last()->getAccent());
            connect(vstaffs.at(i), SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
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

    if(event->key() == Qt::Key_Delete){
        for(int i=0; i<vstaffs.size(); i++){
            if(vstaffs.at(i) == selectedvstaff){
                for(int j=0; j<vstaffs.at(i)->getVnotes().size(); j++){
                    if(vstaffs.at(i)->getVnotes().at(j)->isSelected()){
                        svm->changeToRest(i+1, j+1);
                        vstaffs.at(i)->deleteSelectedVNote();
                    }
                }
                vstaffs.at(i)->updateVStaff();
                vstaffs.at(i)->updateStaffWidth();
            }
        }
        //selectedvstaff->deleteSelectedVNote();
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionLilyPond_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Exportálás LilyPond fájlba", "./export", "*.ly");
    if(!filename.isEmpty()){
        svm->makeLilyPond(filename);
    }
}

void MainWindow::on_actionOpen_LilyPond_file_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "LilyPond fájl megnyitása", "./export", "*.ly");
    if(!filename.isEmpty()){
        svm->readLilyPond(filename);
        showScore();
    }
}

void MainWindow::on_actionAddNote_triggered(bool checked)
{
    if(checked){ //check
        if(!vstaffs.isEmpty()){
            foreach (VStaff *vstaff, vstaffs) {
                if(vstaff == selectedvstaff){
                    ui->actionAddNote->setChecked(true);
                    ui->actionAddRest->setChecked(false);
                    ui->actionHalf->setChecked(true);
                    ui->actionWhole->setChecked(false);
                    ui->actionQuarter->setChecked(false);
                    ui->actionEighth->setChecked(false);
                    if(vstaff->getNewvnote() != NULL){
                        delete(vstaff->getNewvnote());
                        //vstaff->setNewvnote(NULL);
                        //vstaff->getNewvnote() = NULL;
                    }
                    if(vstaff->getVnotes().isEmpty()){
                        vstaff->setNewVNote(ScoreViewModel::half, ScoreViewModel::none);
                    }else if(vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::whole || vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::half ||
                             vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::quarter || vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::eight){
                        vstaff->setNewVNote(vstaff->getVnotes().last()->getNotetype(), ScoreViewModel::none);
                    }else{
                        switch (vstaff->getVnotes().last()->getNotetype()) {
                        case ScoreViewModel::whole_rest:
                            vstaff->setNewVNote(ScoreViewModel::whole, ScoreViewModel::none);
                            break;
                        case ScoreViewModel::half_rest:
                            vstaff->setNewVNote(ScoreViewModel::half, ScoreViewModel::none);
                            break;
                        case ScoreViewModel::quarter_rest:
                            vstaff->setNewVNote(ScoreViewModel::quarter, ScoreViewModel::none);
                            break;
                        case ScoreViewModel::eight_rest:
                            vstaff->setNewVNote(ScoreViewModel::eight, ScoreViewModel::none);
                            break;
                        default:
                            vstaff->setNewVNote(ScoreViewModel::half, ScoreViewModel::none);
                            break;
                        }
                    }

                    connect(vstaff, SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
                    break;
                }else{
                    ui->actionAddNote->setChecked(false);
                }
            }
            scene->update();
        }else{
            ui->actionAddNote->setChecked(false);
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
            }
        }

        delete(selectedvstaff->getNewvnote());
        selectedvstaff->setNewvnote(NULL);

        scene->update();
    }
}

void MainWindow::on_actionAddRest_triggered(bool checked)
{
    if(checked){
        if(!vstaffs.isEmpty()){
            foreach (VStaff *vstaff, vstaffs) {
                if(vstaff == selectedvstaff){
                    ui->actionAddRest->setChecked(true);
                    ui->actionAddNote->setChecked(false);
                    ui->actionHalf->setChecked(true);
                    ui->actionWhole->setChecked(false);
                    ui->actionQuarter->setChecked(false);
                    ui->actionEighth->setChecked(false);
                    if(vstaff->getNewvnote() != NULL){
                        delete(vstaff->getNewvnote());
                        //vstaff->getNewvnote() = NULL;
                    }
                    if(vstaff->getVnotes().isEmpty()){
                        vstaff->setNewVNote(ScoreViewModel::half_rest, ScoreViewModel::none);
                    }else if(vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::whole_rest || vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::half_rest ||
                             vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::quarter_rest || vstaff->getVnotes().last()->getNotetype() == ScoreViewModel::eight_rest){
                        vstaff->setNewVNote(vstaff->getVnotes().last()->getNotetype(), ScoreViewModel::none);
                    }else{
                        switch (vstaff->getVnotes().last()->getNotetype()) {
                        case ScoreViewModel::whole:
                            vstaff->setNewVNote(ScoreViewModel::whole_rest, ScoreViewModel::none);
                            break;
                        case ScoreViewModel::half:
                            vstaff->setNewVNote(ScoreViewModel::half_rest, ScoreViewModel::none);
                            break;
                        case ScoreViewModel::quarter:
                            vstaff->setNewVNote(ScoreViewModel::quarter_rest, ScoreViewModel::none);
                            break;
                        case ScoreViewModel::eight:
                            vstaff->setNewVNote(ScoreViewModel::eight_rest, ScoreViewModel::none);
                            break;
                        default:
                            vstaff->setNewVNote(ScoreViewModel::half_rest, ScoreViewModel::none);
                            break;
                        }
                    }
                    connect(vstaff, SIGNAL(newVNoteAdd(VNote*)), this, SLOT(newVNoteAdded(VNote*)));
                    break;
                }else{
                    ui->actionAddRest->setChecked(false);
                }
            }
            scene->update();
        }else{
            ui->actionAddRest->setChecked(false);
        }


    }else{
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
            }
        }

        delete(selectedvstaff->getNewvnote());
        selectedvstaff->setNewvnote(NULL);

        scene->update();
    }
}

void MainWindow::on_actionWhole_triggered(bool checked)
{
    if(checked){
        if(!vstaffs.isEmpty()){
            if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){
                ui->actionHalf->setChecked(false);
                ui->actionQuarter->setChecked(false);
                ui->actionEighth->setChecked(false);

                selectedvstaff->getNewvnote()->setNotetype(ScoreViewModel::whole);
                scene->update();
            }else{

                ui->actionEighth->setChecked(false);
                ui->actionHalf->setChecked(false);
                ui->actionQuarter->setChecked(false);

                for(int i=0; i<vstaffs.size(); i++){
                    if(vstaffs.at(i)->isSelected()){
                        for(int j=0; j<selectedvstaff->getVnotes().size(); j++){
                            if(selectedvstaff->getVnotes().at(j)->isSelected()){
                                //svm->updateType(vstaffs.indexOf(selectedvstaff)+1, j+1, ScoreViewModel::whole);
                                selectedvstaff->getVnotes().at(j)->setNotetype(ScoreViewModel::whole);
                                updateNoteData(selectedvstaff->getVnotes().at(j));

                                selectedvstaff->updateVStaff();
                                selectedvstaff->getVnotes().at(j)->setSelected(true);
                                scene->update();
                                break;
                            }
                        }
                    }else{
                        ui->actionWhole->setChecked(false);
                    }
                }

                //ui->actionWhole->setChecked(false);
            }
        }else{
           ui->actionWhole->setChecked(false);
        }

    }
}

void MainWindow::on_actionHalf_triggered(bool checked)
{
    if(checked){
        if(!vstaffs.isEmpty()){
            if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){
                ui->actionWhole->setChecked(false);
                ui->actionQuarter->setChecked(false);
                ui->actionEighth->setChecked(false);

                selectedvstaff->getNewvnote()->setNotetype(ScoreViewModel::half);
                scene->update();
            }else{

                ui->actionWhole->setChecked(false);
                ui->actionQuarter->setChecked(false);
                ui->actionEighth->setChecked(false);

                for(int i=0; i<vstaffs.size(); i++){
                    if(vstaffs.at(i)->isSelected()){
                        for(int j=0; j<selectedvstaff->getVnotes().size(); j++){
                            if(selectedvstaff->getVnotes().at(j)->isSelected()){
                                svm->updateType(vstaffs.indexOf(selectedvstaff)+1, j+1, ScoreViewModel::half);
                                selectedvstaff->getVnotes().at(j)->setNotetype(ScoreViewModel::half);

                                selectedvstaff->updateVStaff();
                                selectedvstaff->getVnotes().at(j)->setSelected(true);
                                scene->update();
                                break;

                            }
                        }
                    }else{
                        ui->actionHalf->setChecked(false);
                    }
                }
                //ui->actionWhole->setChecked(false);
            }
        }else{
            ui->actionHalf->setChecked(false);
        }

    }
}

void MainWindow::on_actionQuarter_triggered(bool checked)
{
    if(checked){
        if(!vstaffs.isEmpty()){
            if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){
                ui->actionWhole->setChecked(false);
                ui->actionHalf->setChecked(false);
                ui->actionEighth->setChecked(false);

                selectedvstaff->getNewvnote()->setNotetype(ScoreViewModel::quarter);
                scene->update();
            }else{

                ui->actionWhole->setChecked(false);
                ui->actionHalf->setChecked(false);
                ui->actionEighth->setChecked(false);

                for(int i=0; i<vstaffs.size(); i++){
                    if(vstaffs.at(i)->isSelected()){
                        for(int j=0; j<selectedvstaff->getVnotes().size(); j++){
                            if(selectedvstaff->getVnotes().at(j)->isSelected()){
                                svm->updateType(vstaffs.indexOf(selectedvstaff)+1, j+1, ScoreViewModel::quarter);
                                selectedvstaff->getVnotes().at(j)->setNotetype(ScoreViewModel::quarter);

                                selectedvstaff->updateVStaff();
                                selectedvstaff->getVnotes().at(j)->setSelected(true);
                                scene->update();
                                break;

                            }
                        }
                    }else{
                        ui->actionQuarter->setChecked(false);
                    }
                }
                //ui->actionWhole->setChecked(false);
            }
        }else{
            ui->actionQuarter->setChecked(false);
        }

    }
}

void MainWindow::on_actionEighth_triggered(bool checked)
{   
    if(checked){
        if(!vstaffs.isEmpty()){
            if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){
                ui->actionWhole->setChecked(false);
                ui->actionHalf->setChecked(false);
                ui->actionQuarter->setChecked(false);

                selectedvstaff->getNewvnote()->setNotetype(ScoreViewModel::eight);
                scene->update();
            }else{

                ui->actionWhole->setChecked(false);
                ui->actionHalf->setChecked(false);
                ui->actionQuarter->setChecked(false);

                for(int i=0; i<vstaffs.size(); i++){
                    if(vstaffs.at(i)->isSelected()){
                        for(int j=0; j<selectedvstaff->getVnotes().size(); j++){
                            if(selectedvstaff->getVnotes().at(j)->isSelected()){
                                svm->updateType(vstaffs.indexOf(selectedvstaff)+1, j+1, ScoreViewModel::eight);
                                selectedvstaff->getVnotes().at(j)->setNotetype(ScoreViewModel::eight);

                                selectedvstaff->updateVStaff();
                                selectedvstaff->getVnotes().at(j)->setSelected(true);
                                scene->update();
                                break;
                            }
                        }
                    }else{
                        ui->actionEighth->setChecked(false);
                    }
                }
                //ui->actionWhole->setChecked(false);
            }
        }else{
            ui->actionEighth->setChecked(false);
        }

    }
}

void MainWindow::on_action_newStaff_triggered()
{
    /*QStringList clefs;
    clefs << tr("Violin kulcs") << tr("Alt kulcs") << tr("Tenor kulcs") << tr("Basszus kulcs");

    bool ok;

    QString clef = QInputDialog::getItem(this, tr("Válasszon kulcsot"), tr("Kulcsok:"), clefs, 0, false, &ok);

    if(ok){
        if(clef == "Violin kulcs"){
            addVStaff(new VStaff(ScoreViewModel::treble,1,0));
        }else if(clef == "Alt kulcs"){
            addVStaff(new VStaff(ScoreViewModel::alto,-4,0));
        }else if(clef == "Tenor kulcs"){
            addVStaff(new VStaff(ScoreViewModel::tenor,-5,0));
        }else if(clef == "Basszus kulcs"){
            addVStaff(new VStaff(ScoreViewModel::bass,0,0));
        }
    }*/

//    bool ok = false;
//    ScoreViewModel::clefNames tempclef;
//    int tempkey;

    NewStaffDialog *staffdialog = new NewStaffDialog(this);
    if(staffdialog->exec() == QDialog::Accepted){
        addVStaff(new VStaff(staffdialog->getSelectedclef(), staffdialog->getSelectedkeysignature(), 0));
    }
    /*staffdialog->show();
    staffdialog->
    if(ok){
        addVStaff(new VStaff(staffdialog->getSelectedclef(), staffdialog->getSelectedkeysignature(), 0));
    }*/
}



void MainWindow::on_actionAddSharp_triggered(bool checked)
{
    if(checked){
        if(!vstaffs.isEmpty()){
            if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){
                ui->actionAddFlat->setChecked(false);

                if(selectedvstaff->getNewvnote()->getNotetype() == ScoreViewModel::whole || selectedvstaff->getNewvnote()->getNotetype() == ScoreViewModel::half ||
                        selectedvstaff->getNewvnote()->getNotetype() == ScoreViewModel::quarter || selectedvstaff->getNewvnote()->getNotetype() == ScoreViewModel::eight){
                    selectedvstaff->getNewvnote()->setAccent(ScoreViewModel::sharp);

                }else{
                   ui->actionAddSharp->setChecked(false);
                }
                scene->update();

            }else{

                for(int i=0; i<vstaffs.size(); i++){
                    if(vstaffs.at(i)->isSelected()){
                        for(int j=0; j<selectedvstaff->getVnotes().size(); j++){
                            if(selectedvstaff->getVnotes().at(j)->isSelected()){
                                if(selectedvstaff->getVnotes().at(j)->getNotetype() == ScoreViewModel::whole || selectedvstaff->getVnotes().at(j)->getNotetype() == ScoreViewModel::half ||
                                        selectedvstaff->getVnotes().at(j)->getNotetype() == ScoreViewModel::quarter || selectedvstaff->getVnotes().at(j)->getNotetype() == ScoreViewModel::eight){
                                    //svm->updateType(vstaffs.indexOf(selectedvstaff)+1, j+1, ScoreViewModel::eight);
                                    selectedvstaff->getVnotes().at(j)->setAccent(ScoreViewModel::sharp);
                                    ui->actionAddFlat->setChecked(false);
                                    updateNoteData(selectedvstaff->getVnotes().at(j));
                                    scene->update();
                                    //showScore();
                                    selectedvstaff->getVnotes().at(j)->setSelected(true);
                                    break;
                                }
                            }
                        }
                    }else{
                        ui->actionAddSharp->setChecked(false);
                    }
                }

                //ui->actionWhole->setChecked(false);
            }
        }else{
           ui->actionAddSharp->setChecked(false);
        }

    }else{
        ui->actionAddFlat->setChecked(false);

        if(selectedvstaff->getSelectedvnote()->getNotetype() == ScoreViewModel::whole || selectedvstaff->getSelectedvnote()->getNotetype() == ScoreViewModel::half ||
                selectedvstaff->getSelectedvnote()->getNotetype() == ScoreViewModel::quarter || selectedvstaff->getSelectedvnote()->getNotetype() == ScoreViewModel::eight){
            selectedvstaff->getSelectedvnote()->setAccent(ScoreViewModel::none);
            updateNoteData(selectedvstaff->getSelectedvnote());
        }
        scene->update();
    }
}

void MainWindow::on_actionAddFlat_triggered(bool checked)
{
    if(checked){
        if(!vstaffs.isEmpty()){
            if(ui->actionAddNote->isChecked() || ui->actionAddRest->isChecked()){
                ui->actionAddSharp->setChecked(false);

                if(selectedvstaff->getNewvnote()->getNotetype() == ScoreViewModel::whole || selectedvstaff->getNewvnote()->getNotetype() == ScoreViewModel::half ||
                        selectedvstaff->getNewvnote()->getNotetype() == ScoreViewModel::quarter || selectedvstaff->getNewvnote()->getNotetype() == ScoreViewModel::eight){
                    selectedvstaff->getNewvnote()->setAccent(ScoreViewModel::flat);

                }else{
                   ui->actionAddFlat->setChecked(false);
                }
                scene->update();

            }else{

                for(int i=0; i<vstaffs.size(); i++){
                    if(vstaffs.at(i)->isSelected()){
                        for(int j=0; j<selectedvstaff->getVnotes().size(); j++){
                            if(selectedvstaff->getVnotes().at(j)->isSelected()){
                                if(selectedvstaff->getVnotes().at(j)->getNotetype() == ScoreViewModel::whole || selectedvstaff->getVnotes().at(j)->getNotetype() == ScoreViewModel::half ||
                                        selectedvstaff->getVnotes().at(j)->getNotetype() == ScoreViewModel::quarter || selectedvstaff->getVnotes().at(j)->getNotetype() == ScoreViewModel::eight){
                                    //svm->updateType(vstaffs.indexOf(selectedvstaff)+1, j+1, ScoreViewModel::eight);
                                    ui->actionAddSharp->setChecked(false);
                                    selectedvstaff->getVnotes().at(j)->setAccent(ScoreViewModel::flat);

                                    updateNoteData(selectedvstaff->getVnotes().at(j));
                                    scene->update();
                                    //showScore();
                                    selectedvstaff->getVnotes().at(j)->setSelected(true);
                                    break;
                                }
                            }
                        }
                    }else{
                        ui->actionAddFlat->setChecked(false);
                     }
                }
                //ui->actionWhole->setChecked(false);
            }
        }else{
           ui->actionAddFlat->setChecked(false);
        }

    }else{
        ui->actionAddFlat->setChecked(false);

        if(selectedvstaff->getSelectedvnote()->getNotetype() == ScoreViewModel::whole || selectedvstaff->getSelectedvnote()->getNotetype() == ScoreViewModel::half ||
                selectedvstaff->getSelectedvnote()->getNotetype() == ScoreViewModel::quarter || selectedvstaff->getSelectedvnote()->getNotetype() == ScoreViewModel::eight){
            selectedvstaff->getSelectedvnote()->setAccent(ScoreViewModel::none);
            updateNoteData(selectedvstaff->getSelectedvnote());

        }
        scene->update();
    }
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
    case ScoreViewModel::eight:
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
    case ScoreViewModel::eight_rest:
        ui->actionEighth->setChecked(true);
        break;
    default:
        ui->actionHalf->setChecked(true);
        break;
    }

    switch (note->getAccent()) {
    case ScoreViewModel::sharp:
        ui->actionAddSharp->setChecked(true);
        break;
    case ScoreViewModel::flat:
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
                selectedvstaff->setNewvnote(NULL);
                vstaff->updateVStaff();
            }
        }
    }
    ui->actionAddNote->setChecked(false);
    ui->actionAddRest->setChecked(false);

}

void MainWindow::on_actionOpenLilypondToolBar_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "LilyPond file megnyitása", "./export", "*.ly");
    if(!filename.isEmpty()){
        svm->readLilyPond(filename);
        showScore();
    }
}

void MainWindow::on_actionSaveLilypondToolBar_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Exportálás LilyPond fájlba", "./export", "*.ly");
    if(!filename.isEmpty()){
        svm->makeLilyPond(filename);
    }
}

void MainWindow::on_actionNewScore_triggered()
{
    QMessageBox msgbox;
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
        break;
    case QMessageBox::Cancel:

        break;
    default:
        break;
    }
}

void MainWindow::on_actionScore_triggered()
{
    QMessageBox msgbox(this);
    msgbox.setWindowTitle("Új kotta");
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
        break;
    case QMessageBox::Cancel:

        break;
    default:
        break;
    }
}
