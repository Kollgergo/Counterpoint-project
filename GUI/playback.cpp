#include "playback.h"

PlayBack::PlayBack(QMidiOut *midi, int voice, unsigned int velocity, int tempo, Staff staff, QVector<Accent *> accents)
{
    this->midi = midi;
    this->voice = voice;
    this->velocity = velocity;
    this->tempo = tempo;
    this->staff = staff;
    this->accents = accents;
}

PlayBack::~PlayBack()
{

}

void PlayBack::process()
{
    for(unsigned int i=0; i<staff.getNumOfNotes(); i++){

        Note note = staff.getNoteByNum(i+1);

        switch (staff.getNoteByNum(i+1).getPitch()) {
        case -24:
            if(accents.at(i)->getAccent() == Accent::flat){
                note--;
            }
            break;
        case -20:
            if(accents.at(i)->getAccent() == Accent::sharp){
                note++;
            }
            break;
        case -19:
            if(accents.at(i)->getAccent() == Accent::flat){
                note--;
            }
            break;
        case -13:
            if(accents.at(i)->getAccent() == Accent::sharp){
                note++;
            }
            break;
        case -12:
            if(accents.at(i)->getAccent() == Accent::flat){
                note--;
            }
            break;
        case -8:
            if(accents.at(i)->getAccent() == Accent::sharp){
                note++;
            }
            break;
        case -7:
            if(accents.at(i)->getAccent() == Accent::flat){
                note--;
            }
            break;
        case -1:
            if(accents.at(i)->getAccent() == Accent::sharp){
                note++;
            }
            break;
        case 0:
            if(accents.at(i)->getAccent() == Accent::flat){
                note--;
            }
            break;
        case 4:
            if(accents.at(i)->getAccent() == Accent::sharp){
                note++;
            }
            break;
        case 5:
            if(accents.at(i)->getAccent() == Accent::flat){
                note--;
            }
            break;
        case 11:
            if(accents.at(i)->getAccent() == Accent::sharp){
                note++;
            }
            break;
        case 12:
            if(accents.at(i)->getAccent() == Accent::flat){
                note--;
            }
            break;
        case 16:
            if(accents.at(i)->getAccent() == Accent::sharp){
                note++;
            }
            break;
        case 17:
            if(accents.at(i)->getAccent() == Accent::flat){
                note--;
            }
            break;
        case 23:
            if(accents.at(i)->getAccent() == Accent::sharp){
                note++;
            }
            break;
        case 24:
            if(accents.at(i)->getAccent() == Accent::flat){
                note--;
            }
            break;
        default:

            break;
        }

        if(!midi->isConnected()){
            emit finished();
            return;
        }
        midi->noteOn(/* note */ note.getPitch()+60, /* voice */ voice , velocity /*velocity */);
        //        midi.noteOn(/* note */ svm->getNoteByNum(2,i+1).getPitch()+60, /* voice */ 1 /* , velocity */);
        switch (note.getDuration()) {
        case 1:
            QThread::msleep(tempo*8);
            break;
        case 2:
            QThread::msleep(tempo*4);
            break;
        case 4:
            QThread::msleep(tempo*2);
            break;
        case 8:
            QThread::msleep(tempo);
            break;
        default:
            break;
        }
        if(!midi->isConnected()){
            emit finished();
            return;
        }
        midi->noteOff(/* note */ note.getPitch()+60, /* voice */ voice);
        //        midi.noteOff(/* note */ svm->getNoteByNum(2,i+1).getPitch()+60, /* voice */ 1 /* , velocity */);
    }
    emit finished();
    //this->exit();

}
