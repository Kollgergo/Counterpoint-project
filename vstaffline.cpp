#include "vstaffline.h"

VStaffLine::VStaffLine(QGraphicsObject *parent) : QGraphicsObject(parent)
{
    setAcceptHoverEvents(true);
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

void VStaffLine::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug() << "hover enter";
    emit hoverEntering(this);
    this->parentItem()->scene()->update();

    QGraphicsItem::hoverEnterEvent(event);
}

void VStaffLine::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug() << "hover leave";

    this->parentItem()->scene()->update();

    QGraphicsItem::hoverLeaveEvent(event);

}
