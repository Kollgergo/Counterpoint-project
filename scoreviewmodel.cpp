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

void ScoreViewModel::addStaff(ScoreViewModel::clefNames clef, int keysig, unsigned int where)
{
    if(where == 0){
        clefs.push_back(clef);
        keysignatures.push_back(KeySignature(keysig));
    }else{
        clefs.insert(clefs.begin()+(where-1), clef);
        keysignatures.insert(keysignatures.begin()+(where-1), KeySignature(keysig));
    }
    score->addStaff(where);
}

void ScoreViewModel::deleteStaff(unsigned int which)
{
    score->deleteStaff(which);
}

ScoreViewModel::clefNames ScoreViewModel::getClefByNum(int which)
{
    return clefs.at(which);
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

void ScoreViewModel::makeLilyPond(QString destination)
{
    QString lilyscore, lilystaff;

    for(unsigned int i=0; i<score->getNumOfStaffs(); i++){
        lilystaff.clear();
        lilystaff.append("\\new Staff{\n\t\\override Staff.TimeSignature #'stencil = ##f\n\t\\set Score.timing = ##f\n");
        switch (clefs.at(i)) {
        case treble:
            lilystaff.append("\t\\clef treble\n");
            break;
        case alto:
            lilystaff.append("\t\\clef alto\n");
            break;
        case tenor:
            lilystaff.append("\t\\clef tenor\n");
            break;
        case bass:
            lilystaff.append("\t\\clef bass\n");
            break;
        default:
            lilystaff.append("\t\\clef treble\n");
            break;
        }
        lilystaff.append("\t{\n");
        QString lilynote;
        lilynote.clear();
        for(unsigned int j=0; j<score->getNumOfNotes(i+1); j++){
            lilystaff.append("\t");
            lilynote.clear();
            bool isrest =false;
            bool isLowerC = false;
            int note=score->getStaffByNum(i+1).getNoteByNum(j+1).getPitch();
            unsigned int octave_counter = 0;
            QString durationstring;

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

            /*std::stringstream ss;
            ss << score->getStaffByNum(i+1).getNoteByNum(j+1).getDuration();
            ss >> durationstring;*/

            durationstring.setNum(score->getStaffByNum(i+1).getNoteByNum(j+1).getDuration());

            if(isrest){
                lilynote.append("r");
                lilynote.append(durationstring);
            }else{
                switch (note) {
                case -11:
                    lilynote.append("cis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -10:
                    lilynote.append("d");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -9:
                    lilynote.append("dis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -8:
                    lilynote.append("e");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -7:
                    lilynote.append("f");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -6:
                    lilynote.append("fis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -5:
                    lilynote.append("g");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -4:
                    lilynote.append("gis");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -3:
                    lilynote.append("a");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -2:
                    lilynote.append("ais");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -1:
                    lilynote.append("b");
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;

                case 0:
                    lilynote.append("c");
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
                    lilynote.append("cis");
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
                    lilynote.append("d");
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
                    lilynote.append("dis");
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
                    lilynote.append("e");
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
                    lilynote.append("f");
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
                    lilynote.append("fis");
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
                    lilynote.append("g");
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
                    lilynote.append("gis");
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
                    lilynote.append("a");
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
                    lilynote.append("ais");
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
                    lilynote.append("b");
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
        lilystaff.append("\n\t\\bar \"|.\"\n");
        lilystaff.append("\t}\n}\n");
        lilyscore.append(lilystaff);
    }

    lilyscore.append(">>");

    lilyscore.insert(0,"\\version \"2.16.0\"\n\\header{}\n\\new StaffGroup << \n");


    QFile lilyfile(destination);
    lilyfile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream outstream(&lilyfile);
    outstream << lilyscore;
    lilyfile.close();


}

void ScoreViewModel::readLilyPond(QString file)
{
    score->deleteStaff(0);

    QFile inlilyfile(file);
    inlilyfile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString line;

    QRegularExpression staffregexp("^\\new Staff{");
    QRegularExpression clefregexp("\\b(treble|alto|tenor|bass)");
    QRegularExpression noteregexp("\\b[c,d,e,f,g,a,b](is|es)*('+|,+)*\\d");
    QRegularExpressionMatch match;

    QString temp = staffregexp.errorString();
    bool valid = staffregexp.isValid();
    match = staffregexp.match("\\new Staff{\n");

    while(!inlilyfile.atEnd()){
        line = inlilyfile.readLine();

        if(line == "\\new Staff{\n"){ //new Staff
            addStaff(treble, 0, 0);
        }else{
            match = clefregexp.match(line);
            if(match.hasMatch()){
                if(match.captured(1) == "treble"){
                    clefs.back() = treble;
                }else if(match.captured(1) == "alto"){
                    clefs.back() = alto;
                }else if(match.captured(1) == "tenor"){
                    clefs.back() = tenor;
                }else if(match.captured(1) == "bass"){
                    clefs.back() = bass;
                }
            }else{
                match = noteregexp.match(line);
                if(match.hasMatch()){
                    QString notestring = line;
                    int pitch = 0;
                    int duration = 0;
                    int octave_counter = 0;
                    for(int i=0; i<notestring.size(); i++){

                        if(notestring.at(i)=='c'){
                            pitch = 0;
                        }else if(notestring.at(i)=='d'){
                            pitch = 2;
                        }else if(notestring.at(i)=='e'){
                            pitch = 4;
                        }else if(notestring.at(i)=='f'){
                            pitch = 5;
                        }else if(notestring.at(i)=='g'){
                            pitch = 7;
                        }else if(notestring.at(i)=='a'){
                            pitch = 9;
                        }else if(notestring.at(i)=='b'){
                            pitch = 11;
                        }else if(i+1 < notestring.size() && notestring.at(i+1)=='s'){
                            if(notestring.at(i) == 'i'){
                                pitch++;
                            }else if(notestring.at(i) == 'e'){
                                pitch--;
                            }
                        }else if(notestring.at(i)=='\''){
                            octave_counter++;
                        }else if(notestring.at(i)==','){
                            octave_counter--;
                        }else if(notestring.at(i)=='1'){
                            duration = 1;

                            if(clefs.back() == bass){
                                pitch -= 12;
                            }else{
                                octave_counter--;
                            }

                            pitch += octave_counter * 12;
                            octave_counter = 0;

                            addNote(getNumOfStaffs(),pitch,duration,0);
                        }else if(notestring.at(i)=='2'){
                            duration = 2;

                            if(clefs.back() == bass){
                                pitch -= 12;
                            }else{
                                octave_counter--;
                            }

                            pitch += octave_counter * 12;
                            octave_counter = 0;

                            addNote(getNumOfStaffs(),pitch,duration,0);
                        }else if(notestring.at(i)=='4'){
                            duration = 4;

                            if(clefs.back() == bass){
                                pitch -= 12;
                            }else{
                                octave_counter--;
                            }

                            pitch += octave_counter * 12;
                            octave_counter = 0;

                            addNote(getNumOfStaffs(),pitch,duration,0);
                        }else if(notestring.at(i)=='8'){
                            duration = 8;

                            if(clefs.back() == bass){
                                pitch -= 12;
                            }else{
                                octave_counter--;
                            }

                            pitch += octave_counter * 12;
                            octave_counter = 0;

                            addNote(getNumOfStaffs(),pitch,duration,0);
                        }
                    }
                }

            }
        }
    }

    inlilyfile.close();

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
        pos = 10;
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
        switch (clefs.at(staffnumber-1)) {
        case ScoreViewModel::treble:
            pos -= 7;
            break;
        case ScoreViewModel::alto:
            pos -= 1;
            break;
        case ScoreViewModel::tenor:
            pos += 1;
            break;
        case ScoreViewModel::bass:
            pos += 5;
            break;
        default:
            break;
        }
    }

    pos += octave_counter * 7;

    return pos;
}

ScoreViewModel::accents ScoreViewModel::getAccent(unsigned int staffnumber, unsigned int notenumber)
{
    switch (getNoteByNum(staffnumber, notenumber).getPitch()) { //calculate accent
    case -32767:
        return none;
        break;
    case -11:
        return sharp;
        break;
    case -9:
        return sharp;
        break;
    case -6:
        return sharp;
        break;
    case -4:
        return sharp;
        break;
    case -2:
        return sharp;
        break;
    case 1:
       return sharp;
        break;
    case 3:
        return sharp;
        break;
    case 6:
        return sharp;
        break;
    case 8:
        return sharp;
        break;
    case 10:
        return sharp;
        break;
    default:
        return none;
        break;
    }
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
    int newdatapos;

    switch (clefs.at(staffnumber-1)) {
    case ScoreViewModel::treble:
        switch (newscorepos) {
        case 0:
            newdatapos = 0;
            break;
        case 1:
            newdatapos = 2;
            break;
        case 2:
            newdatapos = 4;
            break;
        case 3:
           newdatapos = 5;
            break;
        case 4:
            newdatapos = 7;
            break;
        case 5:
            newdatapos = 9;
            break;
        case 6:
            newdatapos = 11;
            break;
        case 7:
            newdatapos = 12;
            break;
        case 8:
            newdatapos = 14;
            break;
        case 9:
            newdatapos = 16;
            break;
        case 10:
            newdatapos = 17;
            break;
        case 11:
            newdatapos = 19;
            break;
        case 12:
            newdatapos = 21;
            break;
        default:
            newdatapos = 0;
            break;
        }
        break;
    case ScoreViewModel::alto:
        switch (newscorepos) {
        case 0:
            newdatapos = -10;
            break;
        case 1:
            newdatapos = -8;
            break;
        case 2:
            newdatapos = -7;
            break;
        case 3:
           newdatapos = -5;
            break;
        case 4:
            newdatapos = -3;
            break;
        case 5:
            newdatapos = -1;
            break;
        case 6:
            newdatapos = 0;
            break;
        case 7:
            newdatapos = 2;
            break;
        case 8:
            newdatapos = 4;
            break;
        case 9:
            newdatapos = 5;
            break;
        case 10:
            newdatapos = 7;
            break;
        case 11:
            newdatapos = 9;
            break;
        case 12:
            newdatapos = 11;
            break;
        default:
            newdatapos = 0;
            break;
        }
        break;
    case ScoreViewModel::tenor:
        switch (newscorepos) {
        case 0:
            newdatapos = -13;
            break;
        case 1:
            newdatapos = -12;
            break;
        case 2:
            newdatapos = -10;
            break;
        case 3:
           newdatapos = -8;
            break;
        case 4:
            newdatapos = -7;
            break;
        case 5:
            newdatapos = -5;
            break;
        case 6:
            newdatapos = -3;
            break;
        case 7:
            newdatapos = -1;
            break;
        case 8:
            newdatapos = 0;
            break;
        case 9:
            newdatapos = 2;
            break;
        case 10:
            newdatapos = 4;
            break;
        case 11:
            newdatapos = 5;
            break;
        case 12:
            newdatapos = 7;
            break;
        default:
            newdatapos = 9;
            break;
        }
        break;
    case ScoreViewModel::bass:
        switch (newscorepos) {
        case 0:
            newdatapos = -20;
            break;
        case 1:
            newdatapos = -19;
            break;
        case 2:
            newdatapos = -17;
            break;
        case 3:
           newdatapos = -15;
            break;
        case 4:
            newdatapos = -13;
            break;
        case 5:
            newdatapos = -12;
            break;
        case 6:
            newdatapos = -10;
            break;
        case 7:
            newdatapos = -8;
            break;
        case 8:
            newdatapos = -7;
            break;
        case 9:
            newdatapos = -5;
            break;
        case 10:
            newdatapos = -3;
            break;
        case 11:
            newdatapos = -1;
            break;
        case 12:
            newdatapos = 0;
            break;
        default:
            newdatapos = 0;
            break;
        }
        break;
    default:
        break;
    }



    //getNoteByNum(staffnumber, notenumber).setPitch(newdatapos);
    score->getStaffByNum(staffnumber).getNoteByNum(notenumber).setPitch(newdatapos);
}

