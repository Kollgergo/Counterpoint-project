#include "error.h"

Error::Error(QPair<int, int> loc, QString message)
{
    location = loc;
    errormessage = message;
}

