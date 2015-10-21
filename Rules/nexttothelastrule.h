#ifndef NEXTTOTHELASTRULE_H
#define NEXTTOTHELASTRULE_H

#include "tester.h"

class NextToTheLastRule : public Tester
{
public:
    NextToTheLastRule();

    // Tester interface
public:
    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);
};

#endif // NEXTTOTHELASTRULE_H
