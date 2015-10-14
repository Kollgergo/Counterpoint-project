#include "accent.h"

Accent::Accent(accents accent)
{
    this->accent = accent;
}

Accent::accents Accent::getAccent() const
{
    return accent;
}

void Accent::setAccent(const accents &value)
{
    accent = value;
}


