#include "vstaffline.h"

VStaffLine::VStaffLine(QGraphicsItem *parent) : QGraphicsObject(parent)
{

}

QRectF VStaffLine::boundingRect() const
{
    return QRectF(0,0,1500,1);
}

void VStaffLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF rect = boundingRect();

    QBrush brush(Qt::black);

    painter->setBrush(brush);
    painter->drawRect(rect);
}
