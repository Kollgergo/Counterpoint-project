#include "vstaffline.h"

VStaffLine::VStaffLine(bool iswhite, int initstaffwidth ,QGraphicsObject *parent) : QGraphicsObject(parent)
{
    this->iswhite = iswhite;
    setAcceptHoverEvents(false);
    setFlag(ItemStacksBehindParent, true);
    this->initstaffwidth = initstaffwidth;
    staffwidth = initstaffwidth;
}

QRectF VStaffLine::boundingRect() const
{
    QRectF rect(0,0,staffwidth,1);

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
    emit hoverEntering(this);
    this->scene()->update();

}
int VStaffLine::getStaffwidth() const
{
    return staffwidth;
}


void VStaffLine::addStaffwidth(int value)
{
    prepareGeometryChange();
    if(value == 0){
        staffwidth = initstaffwidth;
    }else{
        staffwidth += value;
    }

    this->scene()->update();
}
