#ifndef SCORE_H
#define SCORE_H
#include <vector>
#include "staff.h"


class Score
{
private:
    QVector<Staff> staffs;

public:
    Score();
    Score(const QVector<Staff> &staffs);

    unsigned int getNumOfStaffs() const;
    unsigned int getNumOfNotes(unsigned int staffnum);
    void addStaff(unsigned int where = 0);
    bool deleteStaff(unsigned int which);
    Staff &getStaffByNum(unsigned int which);

    QVector<Staff> getStaffs() const;
};

#endif // SCORE_H
