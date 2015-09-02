#include "timesignature.h"


unsigned int TimeSignature::getTop() const
{
    return top;
}

unsigned int TimeSignature::getBottom() const
{
    return bottom;
}

TimeSignature::TimeSignature(unsigned int t, unsigned int b)
{
    top = t;
    bottom = b;
}

TimeSignature::~TimeSignature()
{
    
}

