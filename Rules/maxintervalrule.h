#ifndef MAXINTERVALRULE_H
#define MAXINTERVALRULE_H

#include "tester.h"

class MaxIntervalRule : public Tester
{
public:
    MaxIntervalRule();

    // Tester interface
public:
    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);
};

#endif // MAXINTERVALRULE_H
