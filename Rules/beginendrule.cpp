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
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen! Ez egy: K2"));
                    break;
                case 2:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen! Ez egy: N2"));
                    break;
                case 3:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen! Ez egy: K3"));
                    break;
                case 4:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen! Ez egy: N3"));
                    break;
                case 5:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen! Ez egy: T4"));

                    break;
                case 6:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen! Ez egy: B4,SZ5"));

                    break;
                case 7:

                    break;
                case 8:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen! Ez egy: K6"));

                    break;
                case 9:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen! Ez egy: N6"));

                    break;
                case 10:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen Ez egy: K7!"));

                    break;
                case 11:
                    errors.push_back(new Error(currentloc,"Az első és utolsó hangköz tökéletes konszonancia kell, hogy legyen! Ez egy: N7"));

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
