#ifndef NOTE_H
#define NOTE_H

class Note
{
public:
    static int Cpitch;
    static int rest;

private:
    int pitch;
    int duration;


public:
    Note(int pi = Cpitch, int dur = 4);
    Note(const Note &obj);

    int getPitch() const;
    void setPitch(int value);
    int getDuration() const;
    void setDuration(unsigned value);
    bool isRest() const;

    void operator ++(int);
    void operator --(int);
    bool oneDurationUp();
    bool oneDurationDown();
    int operator -(const Note& other) const;
    bool operator ==(const Note& other) const;
    Note& operator =(const Note& obj);    
    
};

#endif // NOTE_H
