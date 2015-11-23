#ifndef TESTER_H
#define TESTER_H
#include <QtCore>
#include "Datamodel/staff.h"
#include "error.h"
#include "Datamodel/accent.h"

class ScoreViewModel;

class Tester
{
public:
    Tester();
    ~Tester();

    virtual QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap) = 0;
    virtual int getTestType() const = 0;

    unsigned int getInterval(unsigned int staffnum, unsigned int notenum, QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);

};

#endif // TESTER_H
