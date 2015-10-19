#ifndef THIRDRULE_H
#define THIRDRULE_H

#include <QtCore>
#include "tester.h"

class ThirdRule : public Tester
{
public:
    ThirdRule();

    // Tester interface
public:
    QList<Error *> test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap);
};

#endif // THIRDRULE_H
