#include "moderule.h"

ModeRule::ModeRule()
{

}

QList<Error *> ModeRule::test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap)
{
    int interval = 0;
    QList<Error *> errors;

    for(int i=1; i<staffs.size(); i++){
        for(unsigned int j=0; j<staffs[0].getNumOfNotes(); j++){

            if(j == 0 || j == staffs[0].getNumOfNotes()-1){
                interval = this->getInterval(i,j,staffs,accentsMap);

                QPair<int, int> currentloc(i,j);

                switch (interval) {
                case 7:
                    if(j == 0){
                        if(staffs[0].getNoteByNum(j+1) > staffs[i].getNoteByNum(j+1)){
                            errors.push_back(new Error(currentloc,"Az első hangköz nem lehet T5, ha az ellenpont az alsó szólam."));
                        }

                    }else{
                        errors.push_back(new Error(currentloc,"Az utolsó hangköz nem lehet T5."));
                    }

                    break;
                default:
                    break;
                }
            }
        }
    }
    return errors;
}

int ModeRule::getTestType() const
{
    return 5;
}
