#ifndef TIMESIGNATURE_H
#define TIMESIGNATURE_H


class TimeSignature
{
private:
    unsigned int top;
    unsigned int bottom;

public:
    TimeSignature(unsigned int t = 4, unsigned int b = 4);
    ~TimeSignature();
    unsigned int getTop() const;
    unsigned int getBottom() const;
};

#endif // TIMESIGNATURE_H
