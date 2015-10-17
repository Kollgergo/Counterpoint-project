#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <QtCore>
#include "staff.h"
#include "accent.h"
#include "QMidiOut.h"
#include "QMidiFile.h"

class PlayBack : public QThread
{
    Q_OBJECT

public:
    PlayBack(); // parent!!!

    void run();

    void startPlayBack(Staff staff, QVector<Accent *> accents);
};

#endif // PLAYBACK_H
