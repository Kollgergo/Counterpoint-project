#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <vector>
#include "note.h"


using namespace std;


class Staff
{
private:
    vector<Note> notes;

public:
    Staff();
    Staff(const vector<Note> &notes);
    Staff(const Staff &obj);

    void addNote(int pitch, int duration, unsigned int where = 0);
    bool deleteNote(unsigned int which);
    Note& getNoteByNum(unsigned int which);
    unsigned int getNumOfNotes() const;

    void transpose(int interval);
};

#endif // STAFF_H
