#ifndef VNOTE_H
#define VNOTE_H

#include <QtGui>
#include <QtWidgets>
#include <QGraphicsItem>
#include <QtDebug>
#include <fstream>
#include "vstaff.h"
#include "scoreviewmodel.h"

class VNote : public QGraphicsObject
{
    Q_OBJECT

public:
    VNote(bool newnote = false, unsigned int spos = 0, ScoreViewModel::noteTypes ntype = ScoreViewModel::half,
          ScoreViewModel::accents acc = ScoreViewModel::none, QGraphicsObject *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getScorepos() const;
    void setScorepos(int value);

    void changeToRest();

    ScoreViewModel::noteTypes getNotetype() const;
    void setNotetype(const ScoreViewModel::noteTypes &value);

    ScoreViewModel::accents getAccent() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:
    void notePosChanging(VNote *note);

public slots:
    void hoverEntered(VStaffLine *staffline);

private:
    QPixmap pixmap;
    VNote *shadow;
    unsigned int scorepos;
    ScoreViewModel::accents accent;
    ScoreViewModel::noteTypes notetype;
    bool newnote;
};

#endif // VNOTE_H
