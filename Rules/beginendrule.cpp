#include "beginendrule.h"

BeginEndRule::BeginEndRule()
{

}

QList<Error *> BeginEndRule::test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap)
{
    int interval = 0;
    QList<Error *> errors;

    for(int i=1; i<staffs.size(); i++){
        for(unsigned int j=0; j<staffs[0].getNumOfNotes(); j++){

            if(j == 0 || j == staffs[0].getNumOfNotes()-1){
                interval = getInterval(i,j,staffs,accentsMap);

                QPair<int, int> currentloc(i,j);

                switch (interval) {
                case 0:

                    break;
                case 1:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen!"));
                    break;
                case 2:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen!"));
                    break;
                case 3:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen!"));
                    break;
                case 4:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen!"));
                    break;
                case 5:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen!"));

                    break;
                case 6:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen!"));

                    break;
                case 7:

                    break;
                case 8:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen!"));

                    break;
                case 9:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen!"));

                    break;
                case 10:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen!"));

                    break;
                case 11:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen!"));

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
