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
    VNote(unsigned int spos = 0, ScoreViewModel::noteTypes ntype = ScoreViewModel::half, QGraphicsObject *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getScorepos() const;
    void setScorepos(int value);

    ScoreViewModel::noteTypes getNotetype() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:
    void notePosChanging(unsigned int spos);

private:
    QPixmap pixmap;
    VNote *shadow;
    unsigned int scorepos;
    ScoreViewModel::accents accent;
    ScoreViewModel::noteTypes notetype;
};

#endif // VNOTE_H
