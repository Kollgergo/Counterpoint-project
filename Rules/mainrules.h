#ifndef FIRSTRULE_H
#define FIRSTRULE_H

#include "tester.h"

class MainRules : public Tester
{
public:
    MainRules();

    // Tester interface
public:
    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);
    int getTestType() const;
};

#endif // FIRSTRULE_H
