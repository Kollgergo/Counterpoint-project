#include "onlyconsonancerule.h"

OnlyConsonanceRule::OnlyConsonanceRule()
{

}

QList<Error *> OnlyConsonanceRule::test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap)
{
    int interval = 0;
    QList<Error *> errors;

    Note firstnote;
    Note secondnote;

    for(unsigned int i=1; i<staffs.size(); i++){
        for(unsigned int j=0; j<staffs[0].getNumOfNotes(); j++){
            firstnote = staffs[0].getNoteByNum(j+1);
            secondnote = staffs[i].getNoteByNum(j+1);

            switch (staffs[0].getNoteByNum(j+1).getPitch()) {
            case -24:
                if(accentsMap[0].at(j)->getAccent() == Accent::flat){
                    firstnote--;
                }
                break;
            case -20:
                if(accentsMap[0].at(j)->getAccent() == Accent::sharp){
                    firstnote++;
                }
                break;
            case -19:
                if(accentsMap[0].at(j)->getAccent() == Accent::flat){
                    firstnote--;
                }
                break;
            case -13:
                if(accentsMap[0].at(j)->getAccent() == Accent::sharp){
                    firstnote++;
                }
                break;
            case -12:
                if(accentsMap[0].at(j)->getAccent() == Accent::flat){
                    firstnote--;
                }
                break;
            case -8:
                if(accentsMap[0].at(j)->getAccent() == Accent::sharp){
                    firstnote++;
                }
                break;
            case -7:
                if(accentsMap[0].at(j)->getAccent() == Accent::flat){
                    firstnote--;
                }
                break;
            case -1:
                if(accentsMap[0].at(j)->getAccent() == Accent::sharp){
                    firstnote++;
                }
                break;
            case 0:
                if(accentsMap[0].at(j)->getAccent() == Accent::flat){
                    firstnote--;
                }
                break;
            case 4:
                if(accentsMap[0].at(j)->getAccent() == Accent::sharp){
                    firstnote++;
                }
                break;
            case 5:
                if(accentsMap[0].at(j)->getAccent() == Accent::flat){
                    firstnote--;
                }
                break;
            case 11:
                if(accentsMap[0].at(j)->getAccent() == Accent::sharp){
                    firstnote++;
                }
                break;
            case 12:
                if(accentsMap[0].at(j)->getAccent() == Accent::flat){
                    firstnote--;
                }
                break;
            case 16:
                if(accentsMap[0].at(j)->getAccent() == Accent::sharp){
                    firstnote++;
                }
                break;
            case 17:
                if(accentsMap[0].at(j)->getAccent() == Accent::flat){
                    firstnote--;
                }
                break;
            default:

                break;
            }

            switch (staffs[i].getNoteByNum(j+1).getPitch()) {
            case -24:
                if(accentsMap[i].at(j)->getAccent() == Accent::flat){
                    secondnote--;
                }
                break;
            case -20:
                if(accentsMap[i].at(j)->getAccent() == Accent::sharp){
                    secondnote++;
                }
                break;
            case -19:
                if(accentsMap[i].at(j)->getAccent() == Accent::flat){
                    secondnote--;
                }
                break;
            case -13:
                if(accentsMap[i].at(j)->getAccent() == Accent::sharp){
                    secondnote++;
                }
                break;
            case -12:
                if(accentsMap[i].at(j)->getAccent() == Accent::flat){
                    secondnote--;
                }
                break;
            case -8:
                if(accentsMap[i].at(j)->getAccent() == Accent::sharp){
                    secondnote++;
                }
                break;
            case -7:
                if(accentsMap[i].at(j)->getAccent() == Accent::flat){
                    secondnote--;
                }
                break;
            case -1:
                if(accentsMap[i].at(j)->getAccent() == Accent::sharp){
                    secondnote++;
                }
                break;
            case 0:
                if(accentsMap[i].at(j)->getAccent() == Accent::flat){
                    secondnote--;
                }
                break;
            case 4:
                if(accentsMap[i].at(j)->getAccent() == Accent::sharp){
                    secondnote++;
                }
                break;
            case 5:
                if(accentsMap[i].at(j)->getAccent() == Accent::flat){
                    secondnote--;
                }
                break;
            case 11:
                if(accentsMap[i].at(j)->getAccent() == Accent::sharp){
                    secondnote++;
                }
                break;
            case 12:
                if(accentsMap[i].at(j)->getAccent() == Accent::flat){
                    secondnote--;
                }
                break;
            case 16:
                if(accentsMap[i].at(j)->getAccent() == Accent::sharp){
                    secondnote++;
                }
                break;
            case 17:
                if(accentsMap[i].at(j)->getAccent() == Accent::flat){
                    secondnote--;
                }
                break;
            default:

                break;
            }

            interval = qAbs(firstnote - secondnote);

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
