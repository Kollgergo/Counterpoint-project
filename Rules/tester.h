#ifndef TESTER_H
#define TESTER_H
#include <QtCore>
#include "Datamodel/staff.h"
#include "Rules/error.h"

class Tester
{
public:
    Tester();

    virtual QList<Error *> test(QList<Staff> staffs) = 0;

};

#endif // TESTER_H
