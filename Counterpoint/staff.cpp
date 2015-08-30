#include "staff.h"


void Staff::addNote(int pitch, int duration, unsigned int where)
{
    if(where == 0){
        notes.push_back(Note(pitch, duration));
    }else{
        notes.insert(notes.begin()+(where-1), Note(pitch, duration));
    }
}

bool Staff::deleteNote(unsigned int which)
{
    if(which <= notes.size()){
        notes.erase(notes.begin()+(which-1));
        return true;
    }else{
        return false;
    }
}

Note &Staff::getNoteByNum(unsigned int which)
{
    return notes.at(which-1);
}

unsigned int Staff::getNumOfNotes() const
{
    return notes.size();
}

void Staff::transpose(int interval)
{
    for(unsigned int i=0; i<notes.size(); i++){
        notes.at(i).setPitch(notes.at(i).getPitch()+interval);
    }
}

Staff::Staff()
{

}

Staff::Staff(const vector<Note> &notes)
{
    this->notes = notes;
}

Staff::Staff(const Staff &obj)
{
    notes = obj.notes;
}


