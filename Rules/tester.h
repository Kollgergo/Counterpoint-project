#ifndef TESTER_H
#define TESTER_H
#include <QtCore>
#include "Datamodel/staff.h"
#include "error.h"

class ScoreViewModel;

class Tester
{
public:
    Tester();

    virtual QList<Error *> test(QVector<Staff> staffs/*, QMap<int, vector<ScoreViewModel::accents> > accentsMap*/) = 0;

};

#endif // TESTER_H
