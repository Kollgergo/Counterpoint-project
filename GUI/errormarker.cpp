#include "errormarker.h"

ErrorMarker::ErrorMarker(QString errormes, QGraphicsObject *parent) : QGraphicsObject(parent)
{
    errormessage = errormes;
    setAcceptHoverEvents(true);
}

ErrorMarker::~ErrorMarker()
{
    delete errortext;
}

QRectF ErrorMarker::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void ErrorMarker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPixmap errorpixmap("./res/errormarker.png");

    painter->drawPixmap(0, 0, 50, 50, errorpixmap);


}
QString ErrorMarker::getErrormessage() const
{
    return errormessage;
}

void ErrorMarker::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    errortext = new QGraphicsTextItem(errormessage, this);
    errortext->setDefaultTextColor(Qt::red);
    errortext->setFont(QFont("Times",15,-1, false));
    errortext->setY(50);

}

void ErrorMarker::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    errortext->hide();
}


