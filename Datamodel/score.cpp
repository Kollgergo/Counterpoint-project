#include "score.h"


unsigned int Score::getNumOfStaffs() const
{
    return staffs.size();
}

unsigned int Score::getNumOfNotes(unsigned int staffnum)
{
    return getStaffByNum(staffnum).getNumOfNotes();
}

void Score::addStaff(unsigned int where)
{
    if(where == 0){
        staffs.push_back(Staff());
    }else{
        staffs.insert(staffs.begin()+(where-1), Staff());
    }
}

bool Score::deleteStaff(unsigned int which)
{
    if(which <= staffs.size() && which != 0){
        staffs.erase(staffs.begin()+(which-1));
        return true;
    }else if(which == 0){
        staffs.clear();
        return true;
    }else{
        return false;
    }
}

Staff& Score::getStaffByNum(unsigned int which)
{
    return staffs.at(which-1);
}

Score::Score()
{

}

Score::Score(const vector<Staff> &staffs)
{
    this->staffs = staffs;
}

