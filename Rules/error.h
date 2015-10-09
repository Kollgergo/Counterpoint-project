#ifndef ERROR_H
#define ERROR_H

#include <QtCore>

class Error
{
public:
    Error(QPair <int,int> loc, QString message);

    QPair<int, int> getLocation() const;

    QString getErrormessage() const;

private:
    QPair <int,int> location;
    QString errormessage;

};

#endif // ERROR_H
