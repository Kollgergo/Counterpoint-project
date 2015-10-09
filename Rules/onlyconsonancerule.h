#ifndef ONLYCONSONANCERULE_H
#define ONLYCONSONANCERULE_H

#include "tester.h"

class OnlyConsonanceRule : public Tester
{
public:
    OnlyConsonanceRule();

    QList<Error *> test(vector<Staff> staffs);
};

#endif // ONLYCONSONANCERULE_H
