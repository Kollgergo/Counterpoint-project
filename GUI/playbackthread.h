#ifndef PLAYBACKTHREAD_H
#define PLAYBACKTHREAD_H

#include <QtCore>
#include "staff.h"

class PlayBackThread : public QThread
{
    Q_OBJECT

public:
    PlayBackThread(QList<Staff> staffs, QObject *parent = 0);

    //void run() Q_DECL_OVERRIDE;


};

#endif // PLAYBACKTHREAD_H
