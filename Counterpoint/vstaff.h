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
public:
    VStaff(ScoreViewModel::clefNames clef = ScoreViewModel::treble, QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QList<VStaffLine *> getVstafflines() const;

    QList<VNote *> getVnotes() const;
    void showNextVNote(VNote *vnote);

private:
    ScoreViewModel::clefNames clef;
    QList <VStaffLine *> vstafflines;
    QList<VNote *> vnotes;

};

#endif // VSTAFF_H
