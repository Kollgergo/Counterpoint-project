#include "clef.h"

void Clef::setClef(clefNames cl)
{
    clef = cl;
    if(clef == treble){
        offset = -6;
    }else if(clef == alto){
        offset = 0;
    }else if(clef == tenor){
        offset = 2;
    }else if(clef == bass){
        offset = 6;
    }

}

Clef::clefNames Clef::getClef() const
{
    return clef;
}

int Clef::getOffset() const
{
    return offset;
}

Clef::Clef(clefNames cl)
{
    clef = cl;
    if(clef == treble){
        offset = -6;
    }else if(clef == alto){
        offset = 0;
    }else if(clef == tenor){
        offset = 2;
    }else if(clef == bass){
        offset = 6;
    }
}



