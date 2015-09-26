#include "keysignature.h"

KeySignature::KeySignature(int key)
{
    if(key > -6 && key < 6){
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
    if(key > -6 && key < 6){
        keysig = key;
    }else{
        keysig = 0;
    }
}

