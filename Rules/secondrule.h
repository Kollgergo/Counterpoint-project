#ifndef SECONDRULE_H
#define SECONDRULE_H

#include <QtCore>
#include "tester.h"

class SecondRule : public Tester
{
public:
    SecondRule();

    // Tester interface
public:
    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);
};

#endif // SECONDRULE_H
