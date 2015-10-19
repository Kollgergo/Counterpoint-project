#ifndef FIRSTRULE_H
#define FIRSTRULE_H

#include <QtCore>
#include "tester.h"

class FirstRule : public Tester
{
public:
    FirstRule();

    // Tester interface
public:
    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);
};

#endif // FIRSTRULE_H
