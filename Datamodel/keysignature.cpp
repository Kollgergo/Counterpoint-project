#include "keysignature.h"

KeySignature::KeySignature(int key)
{
    if(key >= -7 && key <= 7){
        keysig = key;
    }else{
        keysig = 0;
    }
}

int KeySignature::getKeysig() const
{
    return keysig;
}

void KeySignature::setKeySig(int key)
{
    if(key >= -7 && key <= 7){
        keysig = key;
    }else{
        keysig = 0;
    }
}

