#include "vstaffline.h"

VStaffLine::VStaffLine(bool iswhite, QGraphicsObject *parent) : QGraphicsObject(parent)
{
    this->iswhite = iswhite;
    setAcceptHoverEvents(false);
    setFlag(ItemStacksBehindParent, true);
}

QRectF VStaffLine::boundingRect() const
{
    QRectF rect(0,0,1500,1);


    return rect;
}

void VStaffLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF rect = boundingRect();

    QPen pen(Qt::black);

    if(iswhite == true) pen.setColor(Qt::white);


    painter->setPen(pen);
    painter->drawRect(rect);
}

void VStaffLine::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug() << "hover enter";
    emit hoverEntering(this);
    //this->scene()->update();

    //QGraphicsItem::hoverEnterEvent(event);
}

/*void VStaffLine::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //qDebug() << "hover leave";

    this->parentItem()->scene()->update();

    QGraphicsItem::hoverLeaveEvent(event);

}*/
