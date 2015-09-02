#ifndef CLEF_H
#define CLEF_H

class Clef
{
public:


private:
    clefNames clef;
    int offset; // position of the C' note, distance from the 3rd line

public:
    Clef(clefNames cl = treble);

    void setClef(clefNames cl);
    clefNames getClef() const;
    int getOffset() const;
};



#endif // CLEF_H
