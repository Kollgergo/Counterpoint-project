#ifndef KEYSIGNATURE_H
#define KEYSIGNATURE_H


class KeySignature
{
private:
    int keysig;

public:
    KeySignature(int key = 0);

    int getKeysig() const;
    void setKeySig(int key = 0);
};

#endif // KEYSIGNATURE_H
