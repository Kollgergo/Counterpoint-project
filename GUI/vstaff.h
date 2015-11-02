#ifndef VSTAFF_H
#define VSTAFF_H

#include <QtGui>
#include <QtWidgets>
#include "vstaffline.h"
#include "vnote.h"
#include "Datamodel/scoreviewmodel.h"
#include "errormarker.h"

class VNote;

class VStaff : public QGraphicsObject
{
    Q_OBJECT

public:
    VStaff(bool CPmode, bool isCF = false ,ScoreViewModel::clefNames clef = ScoreViewModel::treble, KeySignature keysig = 0,QGraphicsObject *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QList<VStaffLine *> getVstafflines() const;

    QList<VNote *> getVnotes() const;

    VNote *getNewvnote() const;
    void setNewvnote(VNote *value);
    void setNewVNoteByData(ScoreViewModel::noteTypes notetype, Accent::accents accent);
    void addVNote(unsigned int staffpos, ScoreViewModel::noteTypes notetype, Accent::accents accent, unsigned int where);

    ScoreViewModel::clefNames getClef() const;
    KeySignature getKeysignature() const;

    VNote *getSelectedvnote() const;
    void setSelectedvnote(VNote *value);

    void showNextVNote(VNote *vnote);

    void finalizeNewVNote();

    void updateStaffWidth();
    void updateVStaff();

    int getDurationSum();

    void setNewError(int location, QString errormessage);

    void deleteErrorMarkers();

signals:
    void vstaffSelect(VStaff *vstaff);
    void newVNoteAdd(VNote *vnote);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    ScoreViewModel::clefNames clef;
    KeySignature keysignature;
    QList <VStaffLine *> vstafflines;
    QList<VNote *> vnotes;
    VNote *newvnote;
    VNote *selectedvnote;
    bool CPmode;
    QList<ErrorMarker *> errormarkers;

};

#endif // VSTAFF_H
