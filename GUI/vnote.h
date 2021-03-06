#ifndef VNOTE_H
#define VNOTE_H

#include <QtGui>
#include <QtWidgets>
#include <QGraphicsItem>
#include <QtDebug>
#include <fstream>
#include "vstaff.h"
#include "Datamodel/scoreviewmodel.h"

class VNote : public QGraphicsObject
{
    Q_OBJECT

public:
    VNote(bool isCF = false, bool newnote = false, unsigned int spos = 0, ScoreViewModel::noteTypes ntype = ScoreViewModel::half,
          Accent::accents acc = Accent::none, QGraphicsObject *parent = 0);
    ~VNote();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getStaffpos() const;
    void setScorepos(int value);

    ScoreViewModel::noteTypes getNotetype() const;
    void setNotetype(const ScoreViewModel::noteTypes &value);

    Accent::accents getAccent() const;
    void setAccent(const Accent::accents &value, bool iskeysig);

    bool getIskeysig() const;
    void setIskeysig(bool value);

    void changeToRest();
    void changeToNote();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:
    void vNoteSelecting(VNote *note);
    void vNotePosChanging(VNote *note);

public slots:
    void hoverEntered(VStaffLine *staffline);

private:
    QPixmap pixmap;
    ScoreViewModel::noteTypes notetype;
    Accent::accents accent;
    VNote *shadow;
    unsigned int staffpos;
    bool iskeysig;
    bool newnote;
};

#endif // VNOTE_H
