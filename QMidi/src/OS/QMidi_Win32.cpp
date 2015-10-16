/*
 * Copyright 2012-2015 Augustin Cavalier <waddlesplash>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#include "QMidiOut.h"

#include "QMidiFile.h"

#include <QStringList>

#include <windows.h>
#include <mmsystem.h>
#include <QDebug>
struct NativeMidiInstances {
	HMIDIOUT midiOutPtr;
};

// TODO: error reporting

QMap<QString, QString> QMidiOut::devices()
{
	QMap<QString, QString> ret;

    int numDevs = midiOutGetNumDevs();
	if (numDevs == 0) {
		return ret;
	}

	for (int i = 0; i < numDevs; i++) {
		MIDIOUTCAPS* devCaps = new MIDIOUTCAPS;
		midiOutGetDevCaps(i, devCaps, sizeof(*devCaps));
		ret.insert(QString::number(i), QString::fromWCharArray(devCaps->szPname));
		delete devCaps;
	}

	return ret;
}

bool QMidiOut::connect(QString outDeviceId)
{
	if (fConnected)
		disconnect();
	fMidiPtrs = new NativeMidiInstances;

    unsigned int err;
    HMIDIOUT out;
    qint32 msg = 4209808;

    err = midiOutOpen(&fMidiPtrs->midiOutPtr, outDeviceId.toInt(), 0, 0, CALLBACK_NULL);

    if (err != MMSYSERR_NOERROR)
           qDebug() << "error opening MIDI Mapper: %d\n" + err;
        else
            qDebug() << "successfully opened MIDI Mapper\n";

//    midiOutShortMsg(fMidiPtrs->midiOutPtr, (DWORD)msg);
//    Sleep(1000);
//    midiOutShortMsg(fMidiPtrs->midiOutPtr, 0x00003C90);

	fDeviceId = outDeviceId;
	fConnected = true;
	return true;
}

void QMidiOut::disconnect()
{
	if (!fConnected) {
		return;
	}

	midiOutClose(fMidiPtrs->midiOutPtr);

	delete fMidiPtrs;
	fMidiPtrs = NULL;
	fConnected = false;
    qDebug() << "DC";
}

void QMidiOut::sendMsg(qint32 msg)
{
	if (!fConnected) {
		return;
	}

	midiOutShortMsg(fMidiPtrs->midiOutPtr, (DWORD)msg);

}
