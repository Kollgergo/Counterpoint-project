#ifndef MODERULE_H
#define MODERULE_H

#include "tester.h"

class ModeRule : public Tester
{
public:
    ModeRule();

    // Tester interface
public:
    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);
    int getTestType() const;
};

#endif // MODERULE_H
