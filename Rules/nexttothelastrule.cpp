#include "nexttothelastrule.h"

NextToTheLastRule::NextToTheLastRule()
{

}

QList<Error *> NextToTheLastRule::test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap)
{
    int interval = 0;
    QList<Error *> errors;

    for(int i=1; i<staffs.size(); i++){
        for(unsigned int j=0; j<staffs[0].getNumOfNotes(); j++){

            if(j == staffs[0].getNumOfNotes()-2){
                interval = getInterval(i,j,staffs,accentsMap);

                QPair<int, int> currentloc(i,j);

                if(staffs[0].getNoteByNum(j+1).getPitch() > staffs[i].getNoteByNum(j+1).getPitch()){
                    switch (interval) {
                    case 0:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    case 1:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    case 2:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    case 3:
                        break;
                    case 4:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    case 5:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    case 6:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    case 7:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    case 8:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    case 9:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    case 10:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    case 11:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    case 12:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz K3 kell, hogy legyen!"));
                        break;
                    default:
                        break;
                    }
                }else{
                    switch (interval) {
                    case 0:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    case 1:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    case 2:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    case 3:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    case 4:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    case 5:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    case 6:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    case 7:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    case 8:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    case 9:

                        break;
                    case 10:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    case 11:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    case 12:
                        errors.push_back(new Error(currentloc,"Az utolsó előtti hangköz N6 kell, hogy legyen!"));
                        break;
                    default:
                        break;
                    }
                }
            }
        }
            }
    return errors;
}

int NextToTheLastRule::getTestType() const
{
    return 6;
}
