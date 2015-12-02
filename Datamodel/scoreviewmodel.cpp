#include "scoreviewmodel.h"

ScoreViewModel::ScoreViewModel()
{
    score = new Score();
    accentsMap.clear();
    accentsMap[0];

    ruleList.push_back(new OnlyConsonanceRule());
    ruleList.push_back(new MainRules());
    ruleList.push_back(new BeginEndRule());
    ruleList.push_back(new NextToTheLastRule());
    ruleList.push_back(new ModeRule);
    ruleList.push_back(new MaxIntervalRule());
    ruleList.push_back(new ForbiddenSkipsRule());
}

ScoreViewModel::~ScoreViewModel()
{
    delete score;
    foreach (QVector<Accent *> staff, accentsMap) {
        foreach (Accent *acc, staff) {
            delete(acc);
        }
    }
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
//    if(!accentsMap.empty()){
//        accentsMap[0];
//    }
}

void ScoreViewModel::deleteStaff(unsigned int which)
{
    if(which == 0){
        score->deleteStaff(which);
        clefs.clear();
        keysignatures.clear();
        accentsMap.clear();
    }else{
        score->deleteStaff(which);
        clefs.erase(clefs.begin()+(which-1));
        keysignatures.erase(keysignatures.begin()+(which-1));
        accentsMap.erase(accentsMap.begin()+which-1);
    }
}

Staff &ScoreViewModel::getStaffByNum(unsigned int which)
{
    return score->getStaffByNum(which);
}

ScoreViewModel::clefNames ScoreViewModel::getClefByNum(int which)
{
    return clefs.at(which-1);
}

KeySignature ScoreViewModel::getKeySignatureByNum(int which)
{
    return keysignatures.at(which-1);
}

void ScoreViewModel::addNote(unsigned int staffnum , int pitch, int duration, Accent::accents accent, unsigned int where)
{
    score->getStaffByNum(staffnum).addNote(pitch, duration, where);
    accentsMap[staffnum-1].push_back(new Accent(accent));

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

        switch (keysignatures.at(i).getKeysig()) {
        case 1:
            lilystaff.append("\t\\key g \\major\n");
            break;
        case 2:
            lilystaff.append("\t\\key d \\major\n");
            break;
        case 3:
            lilystaff.append("\t\\key a \\major\n");
            break;
        case 4:
            lilystaff.append("\t\\key e \\major\n");
            break;
        case 5:
            lilystaff.append("\t\\key b \\major\n");
            break;
        case 6:
            lilystaff.append("\t\\key fis \\major\n");
            break;
        case 7:
            lilystaff.append("\t\\key cis \\major\n");
            break;
        case -1:
            lilystaff.append("\t\\key f \\major\n");
            break;
        case -2:
            lilystaff.append("\t\\key bes \\major\n");
            break;
        case -3:
            lilystaff.append("\t\\key ees \\major\n");
            break;
        case -4:
            lilystaff.append("\t\\key aes \\major\n");
            break;
        case -5:
            lilystaff.append("\t\\key des \\major\n");
            break;
        case -6:
            lilystaff.append("\t\\key ges \\major\n");
            break;
        case -7:
            lilystaff.append("\t\\key ces \\major\n");
            break;
        default:
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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("cis");
                    }else{
                       lilynote.append("des");
                    }

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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("dis");
                    }else{
                       lilynote.append("ees");
                    }
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -8:
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("eis");
                    }else{
                       lilynote.append("e");
                    }
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -7:
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::flat){
                        lilynote.append("fes");
                    }else{
                       lilynote.append("f");
                    }
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -6:
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("fis");
                    }else{
                       lilynote.append("ges");
                    }
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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("gis");
                    }else{
                       lilynote.append("aes");
                    }
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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("ais");
                    }else{
                       lilynote.append("bes");
                    }
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;
                case -1:
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("bis");
                    }else{
                       lilynote.append("b");
                    }
                    if(octave_counter>0){
                        for(unsigned int k=0; k<octave_counter; k++){
                            lilynote.append(",");
                        }
                    }
                    lilynote.append(durationstring);
                    break;

                case 0:
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::flat){
                        lilynote.append("ces");
                    }else{
                       lilynote.append("c");
                    }
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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("cis");
                    }else{
                       lilynote.append("des");
                    }
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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("dis");
                    }else{
                       lilynote.append("ees");
                    }
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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("eis");
                    }else{
                       lilynote.append("e");
                    }
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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::flat){
                        lilynote.append("fes");
                    }else{
                       lilynote.append("f");
                    }
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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("fis");
                    }else{
                       lilynote.append("ges");
                    }
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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("gis");
                    }else{
                       lilynote.append("aes");
                    }
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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("ais");
                    }else{
                       lilynote.append("bes");
                    }
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
                    if(accentsMap[i].at(j)->getAccent() == Accent::Accent::sharp){
                        lilynote.append("bis");
                    }else{
                       lilynote.append("b");
                    }
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

void ScoreViewModel::readLilyPond(QString file, bool isCF)
{
    int staffnum = 0;
    Accent::accents accent;
    //accentsMap.clear();
    //accentsMap[0];
    accent = Accent::none;

    deleteStaff(0);

    QFile inlilyfile(file);
    inlilyfile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString line;
    QRegularExpression clefregexp("\\b(treble|alto|tenor|bass)");
    QRegularExpression keyregexp("\key (g|d|a|e|b|fis|cis|f|bes|ees|aes|des|ges)");
    QRegularExpression noteregexp("\\b[r,c,d,e,f,g,a,b](is|es)*('+|,+)*\\d");
    QRegularExpressionMatch match;

    //keyregexp.setPattern("key");
//    match = keyregexp.match("\\t\\key a \\major\\n");
//    qDebug() << keyregexp.isValid();
//    qDebug() << keyregexp.errorString();



    while(!inlilyfile.atEnd()){
        line = inlilyfile.readLine();

        if(isCF == true){
            if(staffnum == 1 && line == "\\new Staff{\n"){
                return;
            }
        }

        if(line == "\\new Staff{\n"){ //new Staff
            addStaff(treble, 0, 0);
            staffnum++;
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
                match = keyregexp.match(line);
                if(match.hasMatch()){
                    //qDebug() << match.captured(1);
                    //qDebug() << match.captured(2);
                    if(match.captured(1) == "g"){
                        keysignatures.back() = 1;
                    }else if(match.captured(1) == "d"){
                        keysignatures.back() = 2;
                    }else if(match.captured(1) == "a"){
                        keysignatures.back() = 3;
                    }else if(match.captured(1) == "e"){
                        keysignatures.back() = 4;
                    }else if(match.captured(1) == "b"){
                        keysignatures.back() = 5;
                    }else if(match.captured(1) == "fis"){
                        keysignatures.back() = 6;
                    }else if(match.captured(1) == "cis"){
                        keysignatures.back() = 7;
                    }else if(match.captured(1) == "f"){
                        keysignatures.back() = -1;
                    }else if(match.captured(1) == "bes"){
                        keysignatures.back() = -2;
                    }else if(match.captured(1) == "ees"){
                        keysignatures.back() = -3;
                    }else if(match.captured(1) == "aes"){
                        keysignatures.back() = -4;
                    }else if(match.captured(1) == "des"){
                        keysignatures.back() = -5;
                    }else if(match.captured(1) == "ges"){
                        keysignatures.back() = -6;
                    }else if(match.captured(1) == "ces"){
                        keysignatures.back() = -7;
                    }
                }else{
                    match = noteregexp.match(line);
                    if(match.hasMatch()){
                        QString notestring = line;
                        int pitch = 0;
                        int duration = 0;
                        int octave_counter = 0;
                        for(int i=0; i<notestring.size(); i++){

                            if(notestring.at(i)=='r'){
                                pitch = Note::rest;

                            }else if(notestring.at(i)=='c'){
                                pitch = 0;

                            }else if(notestring.at(i)=='d'){
                                pitch = 2;

                            }else if(notestring.at(i)=='e' && notestring.at(i+1) != 's'){
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
                                    if(notestring.at(i-1) != 'e' && notestring.at(i-1) != 'b'){
                                        pitch++;
                                    }

                                    accent = Accent::Accent::sharp;
                                }else if(notestring.at(i) == 'e'){
                                    if(notestring.at(i-1) != 'c' && notestring.at(i-1) != 'f'){
                                        pitch--;
                                    }

                                    accent = Accent::Accent::flat;
                                }
                            }else if(notestring.at(i)=='\''){
                                octave_counter++;
                            }else if(notestring.at(i)==','){
                                octave_counter--;
                            }else if(notestring.at(i)=='1'){
                                duration = 1;

                                if(pitch != Note::rest){
                                    if(clefs.back() == bass){
                                        pitch -= 12;
                                    }else{
                                        octave_counter--;
                                    }

                                    pitch += octave_counter * 12;
                                }
                                octave_counter = 0;

                                addNote(getNumOfStaffs(),pitch,duration,accent,0);
                                //accentsMap[staffnum].push_back(accent);
                                accent = Accent::none;
                            }else if(notestring.at(i)=='2'){
                                duration = 2;

                                if(pitch != Note::rest){
                                    if(clefs.back() == bass){
                                        pitch -= 12;
                                    }else{
                                        octave_counter--;
                                    }

                                    pitch += octave_counter * 12;
                                }
                                octave_counter = 0;

                                addNote(getNumOfStaffs(),pitch,duration,accent,0);
                                //accentsMap[staffnum].push_back(accent);
                                accent = Accent::none;
                            }else if(notestring.at(i)=='4'){
                                duration = 4;

                                if(pitch != Note::rest){
                                    if(clefs.back() == bass){
                                        pitch -= 12;
                                    }else{
                                        octave_counter--;
                                    }

                                    pitch += octave_counter * 12;
                                }

                                octave_counter = 0;

                                addNote(getNumOfStaffs(),pitch,duration,accent,0);
                                //accentsMap[staffnum].push_back(accent);
                                accent = Accent::none;
                            }else if(notestring.at(i)=='8'){
                                duration = 8;

                                if(pitch != Note::rest){
                                    if(clefs.back() == bass){
                                        pitch -= 12;
                                    }else{
                                        octave_counter--;
                                    }

                                    pitch += octave_counter * 12;
                                }
                                octave_counter = 0;

                                addNote(getNumOfStaffs(),pitch,duration,accent,0);
                                //accentsMap[staffnum].push_back(accent);
                                accent = Accent::none;
                            }
                        }

                    }
                }

            }
        }
    }

    inlilyfile.close();

}

QList<Error *> ScoreViewModel::testScore()
{

    QList<Error *> errorlist;

    foreach (Tester *rule, ruleList) {
        errorlist.append(rule->test(score->getStaffs(), accentsMap));
    }

    return errorlist;
}
Score *ScoreViewModel::getScore() const
{
    return score;
}

void ScoreViewModel::setRules(QList<int> rulelist)
{
    ruleList.clear();

    foreach (int rule, rulelist) {
        switch (rule) {
        case 1:
            ruleList.push_back(new BeginEndRule());
            break;
        case 2:
            ruleList.push_back(new ForbiddenSkipsRule());
            break;
        case 3:
            ruleList.push_back(new MainRules());
            break;
        case 4:
            ruleList.push_back(new MaxIntervalRule());
            break;
        case 5:
            ruleList.push_back(new ModeRule);
            break;
        case 6:
            ruleList.push_back(new NextToTheLastRule());
            break;
        case 7:
            ruleList.push_back(new OnlyConsonanceRule());
            break;
        default:
            break;
        }
    }
}

QList<Tester *> ScoreViewModel::getRuleList() const
{
    return ruleList;
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
        pos = 9;
        break;
    case -11:
        if(accentsMap[staffnumber-1].at(notenumber-1)->getAccent() == Accent::Accent::sharp){
            pos = 2;
        }else{
            pos = 3;
        }
        break;
    case -10:
        pos = 3;
        break;
    case -9:
        if(accentsMap[staffnumber-1].at(notenumber-1)->getAccent() == Accent::Accent::sharp){
            pos = 3;
        }else{
            pos = 4;
        }
        break;
    case -8:
        pos = 4;
        break;
    case -7:
        pos = 5;
        break;
    case -6:
        if(accentsMap[staffnumber-1].at(notenumber-1)->getAccent() == Accent::Accent::sharp){
            pos = 5;
        }else{
            pos = 6;
        }
        break;
    case -5:
        pos = 6;
        break;
    case -4:
        if(accentsMap[staffnumber-1].at(notenumber-1)->getAccent() == Accent::Accent::sharp){
            pos = 6;
        }else{
            pos = 7;
        }
        break;
    case -3:
        pos = 7;
        break;
    case -2:
        if(accentsMap[staffnumber-1].at(notenumber-1)->getAccent() == Accent::Accent::sharp){
            pos = 7;
        }else{
            pos = 8;
        }
        break;
    case -1:
        pos = 8;
        break;

    case 0:
        pos = 9;
        break;

    case 1:
        if(accentsMap[staffnumber-1].at(notenumber-1)->getAccent() == Accent::Accent::sharp){
            pos = 9;
        }else{
            pos = 10;
        }
        break;
    case 2:
        pos = 10;
        break;
    case 3:
        if(accentsMap[staffnumber-1].at(notenumber-1)->getAccent() == Accent::Accent::sharp){
            pos = 10;
        }else{
            pos = 11;
        }
        break;
    case 4:
        pos = 11;
        break;
    case 5:
        pos = 12;
        break;
    case 6:
        if(accentsMap[staffnumber-1].at(notenumber-1)->getAccent() == Accent::Accent::sharp){
            pos = 12;
        }else{
            pos = 13;
        }
        break;
    case 7:
        pos = 13;
        break;
    case 8:
        if(accentsMap[staffnumber-1].at(notenumber-1)->getAccent() == Accent::Accent::sharp){
            pos = 13;
        }else{
            pos = 14;
        }
        break;
    case 9:
        pos = 14;
        break;
    case 10:
        if(accentsMap[staffnumber-1].at(notenumber-1)->getAccent() == Accent::Accent::sharp){
            pos = 14;
        }else{
            pos = 15;
        }
        break;
    case 11:
        pos = 15;
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

Accent::accents ScoreViewModel::getAccent(unsigned int staffnumber, unsigned int notenumber)
{
    return accentsMap[staffnumber-1].at(notenumber-1)->getAccent();
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
            type = eighth_rest;
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
            type = eighth;
            break;
        default:
            break;
        }

    }

    return type;
}

QVector<Accent *> ScoreViewModel::getStaffAccentByNum(unsigned int which)
{
    return accentsMap[which-1];
}

void ScoreViewModel::updatePosition(unsigned int staffnumber, unsigned int notenumber, int newscorepos)
{
    int newdatapos = 0;

    switch (clefs.at(staffnumber-1)) {
    case ScoreViewModel::treble:
        switch (newscorepos) {
        case 0:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::Accent::sharp:
                newdatapos = -2;
                break;
            case Accent::flat:
                newdatapos = -4;
                break;
            default:
                newdatapos = -3;
                break;
            }
            break;
        case 1:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -1;
                break;
            case Accent::flat:
                newdatapos = -2;
                break;
            default:
                newdatapos = -1;
                break;
            }
            break;
        case 2:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 1;
                break;
            case Accent::flat:
                newdatapos = 0;
                break;
            default:
                newdatapos = 0;
                break;
            }

            break;
        case 3:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 3;
                break;
            case Accent::flat:
                newdatapos = 1;
                break;
            default:
                newdatapos = 2;
                break;
            }

            break;
        case 4:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 4;
                break;
            case Accent::flat:
                newdatapos = 3;
                break;
            default:
                newdatapos = 4;
                break;
            }

            break;
        case 5:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 6;
                break;
            case Accent::flat:
                newdatapos = 5;
                break;
            default:
                newdatapos = 5;
                break;
            }

            break;
        case 6:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 8;
                break;
            case Accent::flat:
                newdatapos = 6;
                break;
            default:
                newdatapos = 7;
                break;
            }

            break;
        case 7:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 10;
                break;
            case Accent::flat:
                newdatapos = 8;
                break;
            default:
                newdatapos = 9;
                break;
            }

            break;
        case 8:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 11;
                break;
            case Accent::flat:
                newdatapos = 10;
                break;
            default:
                newdatapos = 11;
                break;
            }

            break;
        case 9:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 13;
                break;
            case Accent::flat:
                newdatapos = 12;
                break;
            default:
                newdatapos = 12;
                break;
            }

            break;
        case 10:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 15;
                break;
            case Accent::flat:
                newdatapos = 13;
                break;
            default:
                newdatapos = 14;
                break;
            }

            break;
        case 11:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 16;
                break;
            case Accent::flat:
                newdatapos = 15;
                break;
            default:
                newdatapos = 16;
                break;
            }

            break;
        case 12:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 18;
                break;
            case Accent::flat:
                newdatapos = 17;
                break;
            default:
                newdatapos = 17;
                break;
            }

            break;
        case 13:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 20;
                break;
            case Accent::flat:
                newdatapos = 18;
                break;
            default:
                newdatapos = 19;
                break;
            }

            break;
        case 14:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 21;
                break;
            case Accent::flat:
                newdatapos = 20;
                break;
            default:
                newdatapos = 21;
                break;
            }

            break;
        case 15:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 23;
                break;
            case Accent::flat:
                newdatapos = 22;
                break;
            default:
                newdatapos = 23;
                break;
            }

            break;
        case 16:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 25;
                break;
            case Accent::flat:
                newdatapos = 24;
                break;
            default:
                newdatapos = 24;
                break;
            }

            break;
        default:
            newdatapos = 0;
            break;
        }
        break;

    case ScoreViewModel::alto:
        switch (newscorepos) {
        case 0:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -13;
                break;
            case Accent::flat:
                newdatapos = -14;
                break;
            default:
                newdatapos = -13;
                break;
            }
            break;
        case 1:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -11;
                break;
            case Accent::flat:
                newdatapos = -12;
                break;
            default:
                newdatapos = -12;
                break;
            }
            break;
        case 2:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -9;
                break;
            case Accent::flat:
                newdatapos = -11;
                break;
            default:
                newdatapos = -10;
                break;
            }

            break;
        case 3:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -8;
                break;
            case Accent::flat:
                newdatapos = -9;
                break;
            default:
                newdatapos = -8;
                break;
            }

            break;
        case 4:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -6;
                break;
            case Accent::flat:
                newdatapos = -7;
                break;
            default:
                newdatapos = -7;
                break;
            }

            break;
        case 5:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -4;
                break;
            case Accent::flat:
                newdatapos = -6;
                break;
            default:
                newdatapos = -5;
                break;
            }

            break;
        case 6:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -2;
                break;
            case Accent::flat:
                newdatapos = -4;
                break;
            default:
                newdatapos = -3;
                break;
            }

            break;
        case 7:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -1;
                break;
            case Accent::flat:
                newdatapos = -2;
                break;
            default:
                newdatapos = -1;
                break;
            }

            break;
        case 8:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 1;
                break;
            case Accent::flat:
                newdatapos = 0;
                break;
            default:
                newdatapos = 0;
                break;
            }

            break;
        case 9:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 3;
                break;
            case Accent::flat:
                newdatapos = 1;
                break;
            default:
                newdatapos = 2;
                break;
            }

            break;
        case 10:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 4;
                break;
            case Accent::flat:
                newdatapos = 3;
                break;
            default:
                newdatapos = 4;
                break;
            }

            break;
        case 11:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 6;
                break;
            case Accent::flat:
                newdatapos = 5;
                break;
            default:
                newdatapos = 5;
                break;
            }

            break;
        case 12:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 8;
                break;
            case Accent::flat:
                newdatapos = 6;
                break;
            default:
                newdatapos = 7;
                break;
            }

            break;
        case 13:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 10;
                break;
            case Accent::flat:
                newdatapos = 8;
                break;
            default:
                newdatapos = 9;
                break;
            }

            break;
        case 14:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 11;
                break;
            case Accent::flat:
                newdatapos = 10;
                break;
            default:
                newdatapos = 11;
                break;
            }

            break;
        case 15:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 13;
                break;
            case Accent::flat:
                newdatapos = 12;
                break;
            default:
                newdatapos = 12;
                break;
            }

            break;
        case 16:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 15;
                break;
            case Accent::flat:
                newdatapos = 13;
                break;
            default:
                newdatapos = 14;
                break;
            }

            break;
        default:
            newdatapos = 0;
            break;
        }
        break;

    case ScoreViewModel::tenor:
        switch (newscorepos) {
        case 0:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -16;
                break;
            case Accent::flat:
                newdatapos = -18;
                break;
            default:
                newdatapos = -17;
                break;
            }

            break;
        case 1:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -14;
                break;
            case Accent::flat:
                newdatapos = -16;
                break;
            default:
                newdatapos = -15;
                break;
            }

            break;
        case 2:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -13;
                break;
            case Accent::flat:
                newdatapos = -14;
                break;
            default:
                newdatapos = -13;
                break;
            }

            break;
        case 3:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -11;
                break;
            case Accent::flat:
                newdatapos = -12;
                break;
            default:
                newdatapos = -12;
                break;
            }

            break;
        case 4:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -9;
                break;
            case Accent::flat:
                newdatapos = -11;
                break;
            default:
                newdatapos = -10;
                break;
            }

            break;
        case 5:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -8;
                break;
            case Accent::flat:
                newdatapos = -9;
                break;
            default:
                newdatapos = -8;
                break;
            }

            break;
        case 6:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -6;
                break;
            case Accent::flat:
                newdatapos = -7;
                break;
            default:
                newdatapos = -7;
                break;
            }

            break;
        case 7:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -4;
                break;
            case Accent::flat:
                newdatapos = -6;
                break;
            default:
                newdatapos = -5;
                break;
            }

            break;
        case 8:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -2;
                break;
            case Accent::flat:
                newdatapos = -4;
                break;
            default:
                newdatapos = -3;
                break;
            }

            break;
        case 9:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -1;
                break;
            case Accent::flat:
                newdatapos = -2;
                break;
            default:
                newdatapos = -1;
                break;
            }

            break;
        case 10:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 1;
                break;
            case Accent::flat:
                newdatapos = 0;
                break;
            default:
                newdatapos = 0;
                break;
            }

            break;
        case 11:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 3;
                break;
            case Accent::flat:
                newdatapos = 1;
                break;
            default:
                newdatapos = 2;
                break;
            }

            break;
        case 12:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 4;
                break;
            case Accent::flat:
                newdatapos = 3;
                break;
            default:
                newdatapos = 4;
                break;
            }

            break;
        case 13:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 6;
                break;
            case Accent::flat:
                newdatapos = 5;
                break;
            default:
                newdatapos = 5;
                break;
            }

            break;
        case 14:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 8;
                break;
            case Accent::flat:
                newdatapos = 6;
                break;
            default:
                newdatapos = 7;
                break;
            }

            break;
        case 15:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 10;
                break;
            case Accent::flat:
                newdatapos = 8;
                break;
            default:
                newdatapos = 9;
                break;
            }

            break;
        case 16:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 11;
                break;
            case Accent::flat:
                newdatapos = 10;
                break;
            default:
                newdatapos = 11;
                break;
            }

            break;
        default:
            newdatapos = 0;
            break;
        }
        break;

    case ScoreViewModel::bass:
        switch (newscorepos) {
        case 0:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -23;
                break;
            case Accent::flat:
                newdatapos = -24;
                break;
            default:
                newdatapos = -24;
                break;
            }

            break;
        case 1:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -21;
                break;
            case Accent::flat:
                newdatapos = -23;
                break;
            default:
                newdatapos = -22;
                break;
            }

            break;
        case 2:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -20;
                break;
            case Accent::flat:
                newdatapos = -21;
                break;
            default:
                newdatapos = -20;
                break;
            }

            break;
        case 3:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -18;
                break;
            case Accent::flat:
                newdatapos = -19;
                break;
            default:
                newdatapos = -19;
                break;
            }

            break;
        case 4:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -16;
                break;
            case Accent::flat:
                newdatapos = -18;
                break;
            default:
                newdatapos = -17;
                break;
            }

            break;
        case 5:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -14;
                break;
            case Accent::flat:
                newdatapos = -16;
                break;
            default:
                newdatapos = -15;
                break;
            }

            break;
        case 6:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -13;
                break;
            case Accent::flat:
                newdatapos = -14;
                break;
            default:
                newdatapos = -13;
                break;
            }

            break;
        case 7:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -11;
                break;
            case Accent::flat:
                newdatapos = -12;
                break;
            default:
                newdatapos = -12;
                break;
            }

            break;
        case 8:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -9;
                break;
            case Accent::flat:
                newdatapos = -11;
                break;
            default:
                newdatapos = -10;
                break;
            }

            break;
        case 9:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -8;
                break;
            case Accent::flat:
                newdatapos = -9;
                break;
            default:
                newdatapos = -8;
                break;
            }

            break;
        case 10:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -6;
                break;
            case Accent::flat:
                newdatapos = -7;
                break;
            default:
                newdatapos = -7;
                break;
            }

            break;
        case 11:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -4;
                break;
            case Accent::flat:
                newdatapos = -6;
                break;
            default:
                newdatapos = -5;
                break;
            }

            break;
        case 12:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -2;
                break;
            case Accent::flat:
                newdatapos = -4;
                break;
            default:
                newdatapos = -3;
                break;
            }

            break;
        case 13:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = -1;
                break;
            case Accent::flat:
                newdatapos = -2;
                break;
            default:
                newdatapos = -1;
                break;
            }

            break;
        case 14:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 1;
                break;
            case Accent::flat:
                newdatapos = 0;
                break;
            default:
                newdatapos = 0;
                break;
            }

            break;
        case 15:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 3;
                break;
            case Accent::flat:
                newdatapos = 1;
                break;
            default:
                newdatapos = 2;
                break;
            }

            break;
        case 16:
            switch (accentsMap[staffnumber-1].at(notenumber-1)->getAccent()) {
            case Accent::sharp:
                newdatapos = 4;
                break;
            case Accent::flat:
                newdatapos = 3;
                break;
            default:
                newdatapos = 4;
                break;
            }

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

void ScoreViewModel::updateAccent(unsigned int staffnumber, unsigned int notenumber, Accent::accents newaccent)
{
    accentsMap[staffnumber-1][notenumber-1]->setAccent(newaccent);

}

void ScoreViewModel::updateType(unsigned int staffnumber, unsigned int notenumber, ScoreViewModel::noteTypes newnotetype)
{
    switch (newnotetype) {
    case whole:
        getNoteByNum(staffnumber, notenumber).setDuration(1);
        break;
    case half:
        getNoteByNum(staffnumber, notenumber).setDuration(2);
        break;
    case quarter:
        getNoteByNum(staffnumber, notenumber).setDuration(4);
        break;
    case eighth:
        getNoteByNum(staffnumber, notenumber).setDuration(8);
        break;
    case whole_rest:
        getNoteByNum(staffnumber, notenumber).setDuration(1);
        getNoteByNum(staffnumber, notenumber).setPitch(Note::rest);
        break;
    case half_rest:
        getNoteByNum(staffnumber, notenumber).setDuration(2);
        getNoteByNum(staffnumber, notenumber).setPitch(Note::rest);
        break;
    case quarter_rest:
        getNoteByNum(staffnumber, notenumber).setDuration(4);
        getNoteByNum(staffnumber, notenumber).setPitch(Note::rest);
        break;
    case eighth_rest:
        getNoteByNum(staffnumber, notenumber).setDuration(8);
        getNoteByNum(staffnumber, notenumber).setPitch(Note::rest);
        break;
    default:
        getNoteByNum(staffnumber, notenumber).setDuration(2);
        break;
    }
}

void ScoreViewModel::changeToRest(unsigned int staffnumber, unsigned int notenumber)
{
    getNoteByNum(staffnumber, notenumber).setPitch(Note::rest);
    accentsMap[staffnumber-1].at(notenumber-1)->setAccent(Accent::none);
}


