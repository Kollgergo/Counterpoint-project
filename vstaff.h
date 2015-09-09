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

    VNote *getNewvnote() const;
    void setNewvnote(VNote *value);

public slots:
    void hoverEntered(VStaffLine *staffline);

private:
    ScoreViewModel::clefNames clef;
    QList <VStaffLine *> vstafflines;
    QList<VNote *> vnotes;
    VNote *newvnote;

};

#endif // VSTAFF_H
