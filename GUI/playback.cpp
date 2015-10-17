#include "playback.h"

PlayBack::PlayBack()
{

}

void PlayBack::run()
{

}

void PlayBack::startPlayBack(Staff staff, QVector<Accent *> accents)
{
    QMap<QString, QString> vals = QMidiOut::devices();
    qDebug() << vals.firstKey();
    QMidiOut midi;
    midi.connect(vals.firstKey());
    midi.setInstrument(/* voice */ 0, /* instrument */ 0);

    for(int i=0; i<staff.getNumOfNotes(); i++){
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
        default:

            break;
        }
        midi.noteOn(/* note */ note.getPitch()+60, /* voice */ 0 /* , velocity */);
//        midi.noteOn(/* note */ svm->getNoteByNum(2,i+1).getPitch()+60, /* voice */ 1 /* , velocity */);
        switch (note.getDuration()) {
        case 1:
            QThread::msleep(3200);
            break;
        case 2:
            QThread::msleep(1600);
            break;
        case 4:
            QThread::msleep(800);
            break;
        case 8:
            QThread::msleep(400);
            break;
        default:
            break;
        }
        midi.noteOff(/* note */ note.getPitch()+60, /* voice */ 0 /* , velocity */);
//        midi.noteOff(/* note */ svm->getNoteByNum(2,i+1).getPitch()+60, /* voice */ 1 /* , velocity */);
    }

    midi.disconnect();

}

