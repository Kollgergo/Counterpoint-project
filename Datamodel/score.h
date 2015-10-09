#ifndef SCORE_H
#define SCORE_H
#include <vector>
#include "staff.h"


class Score
{
private:
    vector<Staff> staffs;

public:
    Score();
    Score(const vector<Staff> &staffs);

    unsigned int getNumOfStaffs() const;
    unsigned int getNumOfNotes(unsigned int staffnum);
    void addStaff(unsigned int where = 0);
    bool deleteStaff(unsigned int which);
    Staff &getStaffByNum(unsigned int which);

    vector<Staff> getStaffs() const;
};

#endif // SCORE_H
