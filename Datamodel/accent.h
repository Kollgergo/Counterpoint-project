#ifndef ACCENT_H
#define ACCENT_H


class Accent
{
public:
    enum accents{flat, none, sharp, natural};

    Accent(accents accent);

    accents getAccent() const;
    void setAccent(const accents &value);

private:
    accents accent;
};

#endif // ACCENT_H
