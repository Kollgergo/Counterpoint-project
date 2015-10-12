#include "onlyconsonancerule.h"

OnlyConsonanceRule::OnlyConsonanceRule()
{

}

QList<Error *> OnlyConsonanceRule::test(QVector<Staff> staffs)
{
    int interval = 0;
    QList<Error *> errors;

    for(unsigned int i=1; i<staffs.size(); i++){
        for(unsigned int j=0; j<staffs[0].getNumOfNotes(); j++){

            interval = qAbs(staffs[0].getNoteByNum(j+1) - staffs[i].getNoteByNum(j+1));

            QPair<int, int> currentloc(i,j);

            while(interval > 12){
                interval-=12;
            }

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
