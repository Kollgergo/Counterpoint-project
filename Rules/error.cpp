#include "error.h"

Error::Error(QPair<int, int> loc, QString message)
{
    location = loc;
    errormessage = message;
}
QPair<int, int> Error::getLocation() const
{
    return location;
}
QString Error::getErrormessage() const
{
    return errormessage;
}



