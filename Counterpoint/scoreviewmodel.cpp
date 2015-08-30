#include "scoreviewmodel.h"

ScoreViewModel::ScoreViewModel()
{
    score = new Score();
}

ScoreViewModel::~ScoreViewModel()
{
    delete score;
}

unsigned int ScoreViewModel::getNumOfStaffs() const
{
    return score->getNumOfStaffs();
}

void ScoreViewModel::addStaff(Clef::clefNames clef, int keysig, unsigned int where)
{
    if(where == 0){
        clefs.push_back(Clef(clef));
        keysignatures.push_back(KeySignature(keysig));
    }else{
        clefs.insert(clefs.begin()+(where-1), Clef(clef));
        keysignatures.insert(keysignatures.begin()+(where-1), KeySignature(keysig));
    }
    score->addStaff(where);
}

void ScoreViewModel::deleteStaff(unsigned int which)
{
    score->deleteStaff(which);
}

void ScoreViewModel::addNote(unsigned int staffnum , int pitch, int duration, unsigned int where)
{
    score->getStaffByNum(staffnum).addNote(pitch, duration, where);
}

bool ScoreViewModel::deleteNote(unsigned int staffnum, unsigned int which)
{
    return score->getStaffByNum(staffnum).deleteNote(which);
}

Note &ScoreViewModel::getNoteByNum(unsigned int staffnum ,unsigned int which)
{
    return score->getStaffByNum(staffnum).getNoteByNum(which);
}

unsigned int ScoreViewModel::getNumOfNotes(unsigned int staffnum) const
{
    return score->getNumOfNotes(staffnum);
}

void ScoreViewModel::transpose(int interval)
{
    for(unsigned int i=0; i<score->getNumOfStaffs(); i++){
        score->getStaffByNum(i+1).transpose(interval);
    }
}

void ScoreViewModel::makeLilyPond()
{
    string lilyscore, lilystaff;

    for(unsigned int i=0; i<score->getNumOfStaffs(); i++){
        lilystaff.clear();
        lilystaff.append("\\new Staff{\n\t\\override Staff.TimeSignature #'stencil = ##f\n\t\\set Score.timing = ##f\n\t{\n");
        string lilynote;
        lilynote.clear();
        for(unsigned int j=0; j<score->getNumOfNotes(i+1); j++){
            lilystaff.append("\t");
            lilynote.clear();
            bool isrest =false;
            bool isLowerC = false;
            int note=score->getStaffByNum(i+1).getNoteByNum(j+1).getPitch();
            unsigned int octave_counter = 0;
            std::string durationstring;

            if(note>0){ //positive
                if(note>11){ //greater than octave
                    while(note>11){
                        note -= 12;
                        octave_counter++;
                    }
                }
            }else{ //negative
                if(note == Note::rest){
                    isrest = true;
                }else{ //not rest
                    if(note<-11){ //greater than octave
                        while(note<-11){
                            note += 12;
                            octave_counter++;
                        }
                        if(note == 0){
                            isLowerC = true;
                        }
                    }
                }
            }

            std::stringstream ss;
            ss << score->getStaffByNum(i+1).getNoteByNum(j+1).getDuration();
            ss >> durationstring;

            if(isrest){
                lilynote.append(" r");
                lilynote.append(durationstring);
            }else{
                switch (note) {
                case -11:
                    lilynote.append(" cis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -10:
                    lilynote.append(" d");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -9:
                    lilynote.append(" dis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -8:
                    lilynote.append(" e");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -7:
                    lilynote.append(" f");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -6:
                    lilynote.append(" fis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -5:
                    lilynote.append(" g");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -4:
                    lilynote.append(" gis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -3:
                    lilynote.append(" a");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -2:
                    lilynote.append(" ais");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -1:
                    lilynote.append(" b");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;

                case 0:
                    lilynote.append(" c");
                    if(isLowerC){
                        if(octave_counter>0){
                            for(unsigned int k=1; k<octave_counter; k++){
                                lilynote.append(",");
                            }
                        }
                        lilynote.append(durationstring);
                    }else{
                        if(octave_counter>0){
                            for(unsigned int k=0; k<=octave_counter; k++){
                                lilynote.append("'");
                            }
                        }else{
                            lilynote.append("'");
                        }
                        lilynote.append(durationstring);
                    }
                    break;
                case 1:
                    lilynote.append(" cis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<=octave_counter; k++){
                            lilynote.append("'");
                        }
                    }else{
                        lilynote.append("'");
                    }
                    lilynote.append(durationstring);
                    break;
                case 2:
                    lilynote.append(" d");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<=octave_counter; k++){
                            lilynote.append("'");
                        }
                    }else{
                        lilynote.append("'");
                    }
                    lilynote.append(durationstring);
                    break;
                case 3:
                    lilynote.append(" dis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<=octave_counter; k++){
                            lilynote.append("'");
                        }
                    }else{
                        lilynote.append("'");
                    }
                    lilynote.append(durationstring);
                    break;
                case 4:
                    lilynote.append(" e");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<=octave_counter; k++){
                            lilynote.append("'");
                        }
                    }else{
                        lilynote.append("'");
                    }
                    lilynote.append(durationstring);
                    break;
                case 5:
                    lilynote.append(" f");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<=octave_counter; k++){
                            lilynote.append("'");
                        }
                    }else{
                        lilynote.append("'");
                    }
                    lilynote.append(durationstring);
                    break;
                case 6:
                    lilynote.append(" fis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<=octave_counter; k++){
                            lilynote.append("'");
                        }
                    }else{
                        lilynote.append("'");
                    }
                    lilynote.append(durationstring);
                    break;
                case 7:
                    lilynote.append(" g");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<=octave_counter; k++){
                            lilynote.append("'");
                        }
                    }else{
                        lilynote.append("'");
                    }
                    lilynote.append(durationstring);
                    break;
                case 8:
                    lilynote.append(" gis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<=octave_counter; k++){
                            lilynote.append("'");
                        }
                    }else{
                        lilynote.append("'");
                    }
                    lilynote.append(durationstring);
                    break;
                case 9:
                    lilynote.append(" a");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<=octave_counter; k++){
                            lilynote.append("'");
                        }
                    }else{
                        lilynote.append("'");
                    }
                    lilynote.append(durationstring);
                    break;
                case 10:
                    lilynote.append(" ais");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<=octave_counter; k++){
                            lilynote.append("'");
                        }
                    }else{
                        lilynote.append("'");
                    }
                    lilynote.append(durationstring);
                    break;
                case 11:
                    lilynote.append(" b");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<=octave_counter; k++){
                            lilynote.append("'");
                        }
                    }else{
                        lilynote.append("'");
                    }
                    lilynote.append(durationstring);
                    break;
                default:
                    break;
                }
            }
            lilystaff.append(lilynote);
        }
        lilystaff.append("\n\\bar \"|.\"\n");
        lilystaff.append("\t}\n}");
        lilyscore.append(lilystaff);
    }

    lilyscore.append(">>");

    lilyscore.insert(0,"\\version \"2.16.0\"\n\\header{}\n\\new StaffGroup << \n");


    ofstream lilyfile;
    lilyfile.open("./export/lilypond.ly");
    lilyfile << lilyscore;
    lilyfile.close();


}

int ScoreViewModel::getPosition(unsigned int staffnumber, unsigned int notenumber)
{
    int pos;
    int note = score->getStaffByNum(staffnumber).getNoteByNum(notenumber).getPitch();
    int octave_counter = 0;

    if(note>0){ //higher than C'
        if(note>11){ //greater than octave
            while(note>11){
                note -= 12;
                octave_counter++;
            }
        }
    }else{ //lower than C'
        if(note != Note::rest){
            if(note<-11){ //greater than octave
                while(note<-11){
                    note += 12;
                    octave_counter--;
                }
            }
        }
    }

    switch (note) { //calculate position
    case -32767:
        pos = 7;
        break;
    case -11:
        pos = 0;
        break;
    case -10:
        pos = 1;
        break;
    case -9:
        pos = 1;
        break;
    case -8:
        pos = 2;
        break;
    case -7:
        pos = 3;
        break;
    case -6:
        pos = 3;
        break;
    case -5:
        pos = 4;
        break;
    case -4:
        pos = 4;
        break;
    case -3:
        pos = 5;
        break;
    case -2:
        pos = 5;
        break;
    case -1:
        pos = 6;
        break;

    case 0:
        pos = 7;
        break;

    case 1:
        pos = 7;
        break;
    case 2:
        pos = 8;
        break;
    case 3:
        pos = 8;
        break;
    case 4:
        pos = 9;
        break;
    case 5:
        pos = 9;
        break;
    case 6:
        pos = 10;
        break;
    case 7:
        pos = 11;
        break;
    case 8:
        pos = 11;
        break;
    case 9:
        pos = 12;
        break;
    case 10:
        pos = 12;
        break;
    case 11:
        pos = 13;
        break;
    default:
        break;
    }

    if(note != Note::rest){
        switch (clefs.at(staffnumber-1).getClef()) {
        case Clef::treble:
            pos -= 7;
            break;
        case Clef::tenor:
            pos -= 1;
            break;
        case Clef::alto:
            pos += 1;
            break;
        case Clef::bass:
            pos += 5;
            break;
        default:
            break;
        }
    }

    pos += octave_counter * 7;

    return pos;
}

ScoreViewModel::noteTypes ScoreViewModel::getType(unsigned int staffnumber, unsigned int notenumber)
{
    noteTypes type;
    int duration = score->getStaffByNum(staffnumber).getNoteByNum(notenumber).getDuration();

    if((score->getStaffByNum(staffnumber).getNoteByNum(notenumber).getPitch()) == Note::rest){
        switch (duration) {
        case 1:
            type = whole_rest;
            break;
        case 2:
            type = half_rest;
            break;
        case 4:
            type = quarter_rest;
            break;
        case 8:
            type = eight_rest;
            break;
        default:
            break;
        }
    }else{
        switch (duration) {
        case 1:
            type = whole;
            break;
        case 2:
            type = half;
            break;
        case 4:
            type = quarter;
            break;
        case 8:
            type = eight;
            break;
        default:
            break;
        }

    }

    return type;
}

void ScoreViewModel::updatePosition(unsigned int staffnumber, unsigned int notenumber, int newscorepos)
{
    int octave_counter = 0;
    int newdatapos;

    /*while(newscorepos > 7){
        newscorepos -= 7;
        octave_counter++;
    }*/

    switch (clefs.at(staffnumber-1).getClef()) {
    case Clef::treble:
        newscorepos += 7;
        break;
    case Clef::tenor:
        newscorepos += 1;
        break;
    case Clef::alto:
        newscorepos -= 1;
        break;
    case Clef::bass:
        newscorepos -= 5;
        break;
    default:
        break;
    }

    switch (newscorepos) {
    case 0:
        newdatapos = -11;
        break;
    case 1:
        newdatapos = -10;
        break;
    case 2:
        newdatapos = -8;
        break;
    case 3:
       newdatapos = -7;
        break;
    case 4:
        newdatapos = -5;
        break;
    case 5:
        newdatapos = -3;
        break;
    case 6:
        newdatapos = -1;
        break;
    case 7:
        newdatapos = 0;
        break;
    case 8:
        newdatapos = 2;
        break;
    case 9:
        newdatapos = 4;
        break;
    case 10:
        newdatapos = 6;
        break;
    case 11:
        newdatapos = 8;
        break;
    case 12:
        newdatapos = 10;
        break;
    case 13:
        newdatapos = 11;
        break;
    default:
        newdatapos = 0;
        break;
    }

    //getNoteByNum(staffnumber, notenumber).setPitch(newdatapos);
    score->getStaffByNum(staffnumber).getNoteByNum(notenumber).setPitch(newdatapos);
}

