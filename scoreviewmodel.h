#ifndef SCOREVIEWMODEL_H
#define SCOREVIEWMODEL_H
#include <QRegularExpression>
#include <QFile>
#include <vector>
#include <iostream>
#include <string>
#include <QDebug>
#include <stdlib.h>
#include <map>
#include <sstream>
#include <fstream>
#include "score.h"
#include "keysignature.h"

class ScoreViewModel
{

public:
    enum clefNames{treble, alto, tenor, bass};
    enum accents{flat, none, sharp, natural};
    enum noteTypes{whole_rest, half_rest, quarter_rest, eight_rest,
                   whole, half, quarter, eight};

private:
    Score *score;
    vector<clefNames> clefs;
    vector<KeySignature> keysignatures;
    map<int,vector<accents> > accentsMap;

public:
    ScoreViewModel();
    ~ScoreViewModel();

    unsigned int getNumOfStaffs() const;
    void addStaff(clefNames clef = treble, int keysig = 0, unsigned int where = 0);
    void deleteStaff(unsigned int which);
    clefNames getClefByNum(int which);

    void addNote(unsigned int staffnum, int pitch, int duration, unsigned int where = 0);
    bool deleteNote(unsigned int staffnum, unsigned int which);
    Note& getNoteByNum(unsigned int staffnum, unsigned int which);
    unsigned int getNumOfNotes(unsigned int staffnum) const;
    void transpose(int interval);

    int getPosition(unsigned int staffnumber, unsigned int notenumber);
    accents getAccent(unsigned int staffnumber, unsigned int notenumber);
    noteTypes getType(unsigned int staffnumber, unsigned int notenumber);

    void updatePosition(unsigned int staffnumber, unsigned int notenumber, int newscorepos);
    void updateAccent(unsigned int staffnumber, unsigned int notenumber, accents newaccent);
    void updateType(unsigned int staffnumber, unsigned int notenumber, noteTypes newnotetype);

    void changeToRest(unsigned int staffnumber, unsigned int notenumber);


    void makeLilyPond(QString destination);
    void readLilyPond(QString file);

};

#endif // SCOREVIEWMODEL_H
