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
    ~VStaff();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QList<VStaffLine *> getVstafflines() const;
    int getVStaffWidth();
    void updateVStaffWidth();
    void updateVStaff();

    QList<VNote *> getVnotes() const;
    int getVNoteDistance() const;
    VNote *getSelectedvnote() const;
    void addVNote(unsigned int staffpos, ScoreViewModel::noteTypes notetype, Accent::accents accent, unsigned int where);
    void showNextVNote(VNote *vnote);
    int getDurationSum();

    void updateAccentByKeySig();

    VNote *getNewvnote() const;
    void setNewVNoteByData(ScoreViewModel::noteTypes notetype, Accent::accents accent);
    void setNewvnote(VNote *value);
    void finalizeNewVNote();

    ScoreViewModel::clefNames getClef() const;
    KeySignature getKeysignature() const;

    void setNewError(int location, QString errormessage);
    void deleteErrorMarkers();

signals:
    void vstaffSelect(VStaff *vstaff);
    void newVNoteAdd(VNote *vnote);
    void vNoteAccentChanged(VNote *vnote);

public slots:
    void setVNoteDistance(int dist);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    ScoreViewModel::clefNames clef;
    KeySignature keysignature;
    QList <VStaffLine *> vstafflines;
    QGraphicsPixmapItem *barline;
    QList<VNote *> vnotes;
    int vnotedistance;
    VNote *newvnote;
    bool CPmode;
    QList<ErrorMarker *> errormarkers;
};

#endif // VSTAFF_H
