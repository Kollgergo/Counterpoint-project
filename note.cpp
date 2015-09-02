#include "note.h"

int Note::Cpitch = 0;
int Note::rest = -32767;

int Note::getPitch() const
{
    return pitch;
}

void Note::setPitch(int value)
{
    pitch = value;
}

int Note::getDuration() const
{
    return duration;
}

void Note::setDuration(unsigned value)
{
    if(value == 1 || (value % 2 == 0 && value != 0 && value <= 8)){
        duration = value;
    }else{
        duration = 4;
    }
}

bool Note::isRest() const
{
    if(pitch == rest){
        return true;
    }else{
        return false;
    }
}

void Note::operator++()
{
    this->pitch++;
}

void Note::operator--()
{
    this->pitch--;
}

bool Note::oneDurationUp()
{
    if(duration == 8){
        return false;
    }else{
        duration = duration * 2;
        return true;
    }
}

bool Note::oneDurationDown()
{
    if(duration == 1){
        return false;
    }else{
        duration = duration / 2;
        return true;
    }
}

int Note::operator -(const Note &other) const 
{
    return other.getPitch()-this->pitch;
}

bool Note::operator ==(const Note &other) const
{
    return operator -(other) == 0;
}

Note &Note::operator =(const Note &obj)
{
    if(this != &obj){
        pitch = obj.pitch;
        duration = obj.duration;
    }
    return *this;
}

Note::Note(int pi, int dur)
{
    pitch = pi;
    if(dur == 1 || (dur % 2 == 0 && dur != 0 && dur <= 8)){
        duration = dur;
    }else{
        duration = 4;
    }
}

Note::Note(const Note &obj)
{
    pitch = obj.pitch;
    duration = obj.duration;
}
