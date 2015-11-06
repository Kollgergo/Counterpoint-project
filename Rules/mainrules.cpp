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
                        if(staffs[0].getNoteByNum(j+1) < staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) < staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Felfelé mozgó T1 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Felfelé mozgó T1 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Felfelé mozgó T1 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }else if(staffs[0].getNoteByNum(j+1) > staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) > staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Lefelé mozgó T1 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Lefelé mozgó T1 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Lefelé mozgó T1 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }
                    }
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(staffs[0].getNoteByNum(j+1) < staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) < staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó K3 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó K3 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó K3 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }else if(staffs[0].getNoteByNum(j+1) > staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) > staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó K3 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó K3 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó K3 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }
                    }
                    break;
                case 4:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(staffs[0].getNoteByNum(j+1) < staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) < staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó N3 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó N3 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó N3 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }else if(staffs[0].getNoteByNum(j+1) > staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) > staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó N3 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó N3 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó N3 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }
                    }
                    break;
                case 5:

                    break;
                case 6:

                    break;
                case 7:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(staffs[0].getNoteByNum(j+1) < staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) < staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Felfelé mozgó T5 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Felfelé mozgó T5 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Felfelé mozgó T5 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }else if(staffs[0].getNoteByNum(j+1) > staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) > staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Lefelé mozgó T5 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Lefelé mozgó T5 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Lefelé mozgó T5 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }
                    }
                    break;
                case 8:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(staffs[0].getNoteByNum(j+1) < staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) < staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó K6 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó K6 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó K6 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }else if(staffs[0].getNoteByNum(j+1) > staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) > staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó K6 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó K6 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó K6 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }
                    }
                    break;
                case 9:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(staffs[0].getNoteByNum(j+1) < staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) < staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó N6 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó N6 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Felfelé mozgó N6 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }else if(staffs[0].getNoteByNum(j+1) > staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) > staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó N6 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó N6 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Harmadik szabály nem teljesül! Lefelé mozgó N6 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }
                    }
                    break;
                case 10:
                    break;
                case 11:
                    break;
                case 12:
                    if(nextinterval == 12 || nextinterval == 7 || nextinterval == 0){
                        if(staffs[0].getNoteByNum(j+1) < staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) < staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Felfelé mozgó T8 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Felfelé mozgó T8 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Felfelé mozgó T8 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }else if(staffs[0].getNoteByNum(j+1) > staffs[0].getNoteByNum(j+2) && staffs[i].getNoteByNum(j+1) > staffs[i].getNoteByNum(j+2)){
                            switch (nextinterval) {
                            case 0:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Lefelé mozgó T8 után T1!"));
                                break;
                            case 7:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Lefelé mozgó T8 után T5!"));
                                break;
                            case 12:
                                errors.push_back(new Error(currentloc,"Első szabály nem teljesül! Lefelé mozgó T8 után T8!"));
                                break;
                            default:
                                break;
                            }
                        }
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
