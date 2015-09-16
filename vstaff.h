#ifndef VSTAFF_H
#define VSTAFF_H

#include <QtGui>
#include <QtWidgets>
#include "vstaffline.h"
#include "vnote.h"
#include "scoreviewmodel.h"

class VNote;

class VStaff : public QGraphicsObject
{
    Q_OBJECT

public:
    VStaff(ScoreViewModel::clefNames clef = ScoreViewModel::treble, QGraphicsObject *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QList<VStaffLine *> getVstafflines() const;

    QList<VNote *> getVnotes() const;
    void showNextVNote(VNote *vnote);

    void setNewVNote(ScoreViewModel::noteTypes notetype);
    void addNewVNote();

    void deleteSelectedVNote();

    VNote *getNewvnote() const;
    void setNewvnote(VNote *value);

    ScoreViewModel::clefNames getClef() const;

signals:
    void vstaffSelect(VStaff *vstaff);
    void newVNoteAdd(VNote *vnote);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    ScoreViewModel::clefNames clef;
    QList <VStaffLine *> vstafflines;
    QList<VNote *> vnotes;
    VNote *newvnote;

};

#endif // VSTAFF_H
