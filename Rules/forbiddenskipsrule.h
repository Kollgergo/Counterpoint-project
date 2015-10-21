#ifndef FORBIDDENSKIPSRULE_H
#define FORBIDDENSKIPSRULE_H

#include "tester.h"

class ForbiddenSkipsRule : public Tester
{
public:
    ForbiddenSkipsRule();

    // Tester interface
public:
    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);
};

#endif // FORBIDDENSKIPSRULE_H
