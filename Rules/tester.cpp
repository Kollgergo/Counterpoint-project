#include "tester.h"

Tester::Tester()
{

}

Tester::~Tester()
{

}

unsigned int Tester::getInterval(unsigned int staffnum, unsigned int notenum, QVector<Staff> staffs, QMap<int, QVector<Accent *> > accentsMap)
{
    int interval = 0;

    Note firstnote = staffs[0].getNoteByNum(notenum+1);
    Note secondnote = staffs[staffnum].getNoteByNum(notenum+1);

    switch (staffs[0].getNoteByNum(notenum+1).getPitch()) {
    case -24:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::flat){
            firstnote--;
        }
        break;
    case -20:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::sharp){
            firstnote++;
        }
        break;
    case -19:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::flat){
            firstnote--;
        }
        break;
    case -13:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::sharp){
            firstnote++;
        }
        break;
    case -12:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::flat){
            firstnote--;
        }
        break;
    case -8:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::sharp){
            firstnote++;
        }
        break;
    case -7:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::flat){
            firstnote--;
        }
        break;
    case -1:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::sharp){
            firstnote++;
        }
        break;
    case 0:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::flat){
            firstnote--;
        }
        break;
    case 4:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::sharp){
            firstnote++;
        }
        break;
    case 5:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::flat){
            firstnote--;
        }
        break;
    case 11:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::sharp){
            firstnote++;
        }
        break;
    case 12:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::flat){
            firstnote--;
        }
        break;
    case 16:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::sharp){
            firstnote++;
        }
        break;
    case 17:
        if(accentsMap[0].at(notenum)->getAccent() == Accent::flat){
            firstnote--;
        }
        break;
    default:

        break;
    }

    switch (staffs[staffnum].getNoteByNum(notenum+1).getPitch()) {
    case -24:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::flat){
            secondnote--;
        }
        break;
    case -20:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::sharp){
            secondnote++;
        }
        break;
    case -19:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::flat){
            secondnote--;
        }
        break;
    case -13:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::sharp){
            secondnote++;
        }
        break;
    case -12:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::flat){
            secondnote--;
        }
        break;
    case -8:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::sharp){
            secondnote++;
        }
        break;
    case -7:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::flat){
            secondnote--;
        }
        break;
    case -1:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::sharp){
            secondnote++;
        }
        break;
    case 0:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::flat){
            secondnote--;
        }
        break;
    case 4:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::sharp){
            secondnote++;
        }
        break;
    case 5:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::flat){
            secondnote--;
        }
        break;
    case 11:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::sharp){
            secondnote++;
        }
        break;
    case 12:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::flat){
            secondnote--;
        }
        break;
    case 16:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::sharp){
            secondnote++;
        }
        break;
    case 17:
        if(accentsMap[staffnum].at(notenum)->getAccent() == Accent::flat){
            secondnote--;
        }
        break;
    default:

        break;
    }

    interval = qAbs(firstnote - secondnote);

    while(interval > 12){
        interval-=12;
    }

    return interval;
}
