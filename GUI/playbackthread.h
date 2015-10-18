#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <QtCore>
#include "staff.h"
#include "accent.h"
#include "QMidiOut.h"
#include "QMidiFile.h"

class PlayBackThread : public QThread
{
    Q_OBJECT

public:
    PlayBackThread(QMidiOut *midi, int voice, Staff staff, QVector<Accent *> accents, QObject *parent);

    void run();

signals:
    void playBackEnding();

private:
    QMidiOut *midi;
    int voice;

    Staff staff;
    QVector<Accent *> accents;
};

#endif // PLAYBACK_H
