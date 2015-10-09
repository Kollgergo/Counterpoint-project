#ifndef ERRORMARKER_H
#define ERRORMARKER_H

#include <QtGui>
#include <QtWidgets>
#include <QGraphicsItem>
#include <QtDebug>

class ErrorMarker : public QGraphicsObject
{
    Q_OBJECT

public:
    ErrorMarker(QGraphicsObject *parent);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ERRORMARKER_H
