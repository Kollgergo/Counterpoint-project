#include "maxintervalrule.h"

MaxIntervalRule::MaxIntervalRule()
{

}

QList<Error *> MaxIntervalRule::test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap)
{
    int interval = 0;
    QList<Error *> errors;

    for(int i=1; i<staffs.size(); i++){
        for(unsigned int j=0; j<staffs[0].getNumOfNotes(); j++){
            interval = this->getInterval(i,j,staffs,accentsMap);

            QPair<int, int> currentloc(i,j);

            if(interval > 12){
                errors.push_back(new Error(currentloc,"Túl nagy hangköz! Maximum T8 megengedett."));
            }
        }
    }
    return errors;
}

int MaxIntervalRule::getTestType() const
{
    return 4;
}
