#ifndef VSTAFFLINE_H
#define VSTAFFLINE_H

#include <QtGui>
#include <QtWidgets>

class VStaffLine : public QGraphicsObject
{
public:
    VStaffLine(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // VSTAFFLINE_H
