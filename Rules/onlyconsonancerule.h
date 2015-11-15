#ifndef ONLYCONSONANCERULE_H
#define ONLYCONSONANCERULE_H

#include "tester.h"

class ScoreViewModel;

class OnlyConsonanceRule : public Tester
{
public:
    OnlyConsonanceRule();

    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);
    int getTestType() const;
};

#endif // ONLYCONSONANCERULE_H
