#ifndef ONLYCONSONANCERULE_H
#define ONLYCONSONANCERULE_H

#include "tester.h"
//#include "Datamodel/scoreviewmodel.h"

class ScoreViewModel;

class OnlyConsonanceRule : public Tester
{
public:
    OnlyConsonanceRule();

    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);
};

#endif // ONLYCONSONANCERULE_H
