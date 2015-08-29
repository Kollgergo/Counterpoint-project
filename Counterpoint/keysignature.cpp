#include "keysignature.h"


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

KeySignature::KeySignature(int key)
{
    if(key > -6 && key < 6){
        keysig = key;
    }else{
        keysig = 0;
    }
}

