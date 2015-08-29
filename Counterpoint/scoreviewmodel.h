#ifndef SCOREVIEWMODEL_H
#define SCOREVIEWMODEL_H
#include <vector>
#include <fstream>
#include "score.h"
#include "clef.h"
#include "keysignature.h"

class ScoreViewModel
{

public:
    enum accents{double_flat, flat, none, sharp, double_sharp};
    enum noteTypes{whole_rest, half_rest, quarter_rest, eight_rest,
                   whole, half, quarter, eight};

private:
    Score *score;
    vector<Clef> clefs;
    vector<KeySignature> keysignatures;

public:
    ScoreViewModel();
    ~ScoreViewModel();

    unsigned int getNumOfStaffs() const;
    void addStaff(Clef::clefNames clef = Clef::treble, int keysig = 0, unsigned int where = 0);
    void deleteStaff(unsigned int which);

    void addNote(unsigned int staffnum, int pitch, int duration, unsigned int where = 0);
    bool deleteNote(unsigned int staffnum, unsigned int which);
    const Note& getNoteByNum(unsigned int staffnum, unsigned int which);
    unsigned int getNumOfNotes(unsigned int staffnum) const;
    void transpose(int interval);

    int getPosition(unsigned int staffnumber, unsigned int notenumber);
    accents getAccent(unsigned int staffnumber, unsigned int notenumber);
    noteTypes getType(unsigned int staffnumber, unsigned int notenumber);

    void makeLilyPond();

};

#endif // SCOREVIEWMODEL_H
