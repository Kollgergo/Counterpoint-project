#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <QtCore>
#include "staff.h"
#include "accent.h"
#include "QMidiOut.h"
#include "QMidiFile.h"

class PlayBack : public QObject
{
    Q_OBJECT

public:
    PlayBack(QMidiOut *midi, int voice, unsigned int velocity, int tempo, Staff staff, QVector<Accent *> accents);

    ~PlayBack();

public slots:
    void process();

signals:
    void finished();

private:
    QMidiOut *midi;
    int voice;

    Staff staff;
    QVector<Accent *> accents;

    unsigned int velocity;
    int tempo;
};

#endif // PLAYBACK_H
