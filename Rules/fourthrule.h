#ifndef FOURTHRULE_H
#define FOURTHRULE_H

#include <QtCore>
#include "tester.h"

class FourthRule : public Tester
{
public:
    FourthRule();

    // Tester interface
public:
    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);
};

#endif // FOURTHRULE_H
