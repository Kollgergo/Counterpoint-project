#include "onlyconsonancerule.h"

OnlyConsonanceRule::OnlyConsonanceRule()
{

}

QList<Error *> OnlyConsonanceRule::test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap)
{
    int interval = 0;
    QList<Error *> errors;

    for(int i=1; i<staffs.size(); i++){
        for(unsigned int j=0; j<staffs[0].getNumOfNotes(); j++){

            interval = this->getInterval(i,j,staffs,accentsMap);

            QPair<int, int> currentloc(i,j);

            switch (interval) {
            case 0:

                break;
            case 1:
                errors.push_back(new Error(currentloc, "Ez nem konszonáns hangköz: K2"));
                break;
            case 2:
                errors.push_back(new Error(currentloc, "Ez nem konszonáns hangköz: N2"));
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                errors.push_back(new Error(currentloc, "Ez nem konszonáns hangköz: T4"));
                break;
            case 6:
                errors.push_back(new Error(currentloc, "Ez nem konszonáns hangköz: B4,SZ5"));
                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:
                errors.push_back(new Error(currentloc, "Ez nem konszonáns hangköz: K7"));
                break;
            case 11:
                errors.push_back(new Error(currentloc, "Ez nem konszonáns hangköz: N7"));
                break;
            case 12:

                break;
            default:
                break;
            }
        }
    }
    return errors;
}

int OnlyConsonanceRule::getTestType() const
{
    return 7;
}
