#include "errormarker.h"

ErrorMarker::ErrorMarker(QGraphicsObject *parent) : QGraphicsObject(parent)
{

}

QRectF ErrorMarker::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void ErrorMarker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap errorpixmap("./res/errormarker.png");
}

