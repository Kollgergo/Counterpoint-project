#include "forbiddenskipsrule.h"

ForbiddenSkipsRule::ForbiddenSkipsRule()
{

}

QList<Error *> ForbiddenSkipsRule::test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap)
{
    int interval = 0;
    QList<Error *> errors;

    for(int i=1; i<staffs.size(); i++){
        for(unsigned int j=0; j<staffs[0].getNumOfNotes(); j++){

            if(j+1 <staffs[i].getNumOfNotes()){
                interval = qAbs(staffs[i].getNoteByNum(j+1) - staffs[i].getNoteByNum(j+2));

                QPair<int, int> currentloc(i,j);

                switch (interval) {
                case 0:

                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:

                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    errors.push_back(new Error(currentloc, "Tiltott lépés B4,T5"));
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    errors.push_back(new Error(currentloc, "Tiltott lépés N6"));
                    break;
                case 10:
                    errors.push_back(new Error(currentloc, "Tiltott lépés K7"));
                    break;
                case 11:
                    errors.push_back(new Error(currentloc, "Tiltott lépés N7"));
                    break;
                case 12:

                    break;
                default:
                    break;
                }
            }
        }
    }
    return errors;
}

int ForbiddenSkipsRule::getTestType() const
{
    return 2;
}
