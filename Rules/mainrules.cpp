#include "mainrules.h"

MainRules::MainRules()
{

}

QList<Error *> MainRules::test(QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap)
{
    int interval = 0;
    QList<Error *> errors;

    for(int i=1; i<staffs.size(); i++){
        for(unsigned int j=0; j<staffs[0].getNumOfNotes(); j++){

            if(j+1 < staffs[0].getNumOfNotes()){
                interval = getInterval(i,j,staffs,accentsMap);
                int nextinterval = getInterval(i,j+1,staffs,accentsMap);

                QPair<int, int> currentloc(i,j);

                switch (interval) {
                case 0:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(interval > nextinterval || interval < nextinterval){

                        }else{
                           errors.push_back(new Error(currentloc,"Első szabály nem teljesül!"));
                        }

                    }
                    break;
                case 1:

                    break;
                case 2:

                    break;
                case 3:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(interval > nextinterval || interval < nextinterval){

                        }else{
                           errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül!"));
                        }

                    }
                    break;
                case 4:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(interval > nextinterval || interval < nextinterval){

                        }else{
                           errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül!"));
                        }

                    }
                    break;
                case 5:

                    break;
                case 6:

                    break;
                case 7:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(interval > nextinterval || interval < nextinterval){

                        }
                        errors.push_back(new Error(currentloc,"Első szabály nem teljesül!"));
                    }
                    break;
                case 8:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(interval > nextinterval || interval < nextinterval){

                        }else{
                           errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül!"));
                        }

                    }
                    break;
                case 9:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(interval > nextinterval || interval < nextinterval){

                        }else{
                           errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül!"));
                        }

                    }
                    break;
                case 10:

                    break;
                case 11:

                    break;
                case 12:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(interval > nextinterval || interval < nextinterval){

                        }
                        errors.push_back(new Error(currentloc,"Első szabály nem teljesül!"));
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
