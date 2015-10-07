#ifndef DIRECTMOTIONRULE_H
#define DIRECTMOTIONRULE_H

#include "tester.h"

class DirectMotionRule : public Tester
{
public:
    DirectMotionRule();

    QList<Error> test(QList<Staff> staffs);
};

#endif // DIRECTMOTIONRULE_H
