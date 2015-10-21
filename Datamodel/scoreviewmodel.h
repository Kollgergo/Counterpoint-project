#ifndef SCOREVIEWMODEL_H
#define SCOREVIEWMODEL_H
#include <QtCore>
#include <QRegularExpression>
#include <QFile>
#include <QDebug>
#include "score.h"
#include "keysignature.h"
#include "accent.h"
#include "onlyconsonancerule.h"
#include "mainrules.h"
#include "beginendrule.h"
#include "nexttothelastrule.h"
#include "moderule.h"
#include "maxintervalrule.h"
#include "forbiddenskipsrule.h"

class ScoreViewModel
{

public:
    enum clefNames{treble, alto, tenor, bass};
    enum noteTypes{whole_rest, half_rest, quarter_rest, eight_rest,
                   whole, half, quarter, eight};

public:
    ScoreViewModel();
    ~ScoreViewModel();

    unsigned int getNumOfStaffs() const;
    void addStaff(clefNames clef = treble, int keysig = 0, unsigned int where = 0);
    void deleteStaff(unsigned int which);
    Staff &getStaffByNum(unsigned int which);
    clefNames getClefByNum(int which);
    KeySignature getKeySignatureByNum(int which);

    void addNote(unsigned int staffnum, int pitch, int duration, Accent::accents accent, unsigned int where = 0);
    bool deleteNote(unsigned int staffnum, unsigned int which);
    Note& getNoteByNum(unsigned int staffnum, unsigned int which);
    unsigned int getNumOfNotes(unsigned int staffnum) const;
    void transpose(int interval);

    int getPosition(unsigned int staffnumber, unsigned int notenumber);
    Accent::accents getAccent(unsigned int staffnumber, unsigned int notenumber);
    noteTypes getType(unsigned int staffnumber, unsigned int notenumber);

    QVector<Accent *> getStaffAccentByNum(unsigned int which);

    void updatePosition(unsigned int staffnumber, unsigned int notenumber, int newscorepos);
    void updateAccent(unsigned int staffnumber, unsigned int notenumber, Accent::accents newaccent);
    void updateType(unsigned int staffnumber, unsigned int notenumber, noteTypes newnotetype);

    void changeToRest(unsigned int staffnumber, unsigned int notenumber);

    void makeLilyPond(QString destination);
    void readLilyPond(QString file, bool isCF);

    QList<Error *> testScore();

    Score *getScore() const;

private:
    Score *score;
    QVector<clefNames> clefs;
    QVector<KeySignature> keysignatures;
    QMap<int,QVector<Accent *> > accentsMap;

    QList<Tester *> ruleList;
    //OnlyConsonanceRule *consonancerule;

};

#endif // SCOREVIEWMODEL_H
