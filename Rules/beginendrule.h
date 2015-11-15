#ifndef BEGINENDRULE_H
#define BEGINENDRULE_H

#include "tester.h"

class BeginEndRule : public Tester
{
public:
    BeginEndRule();

    // Tester interface
public:
    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);

    int getTestType() const;
};

#endif // BEGINENDRULE_H
