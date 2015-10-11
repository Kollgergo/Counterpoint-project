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
    ErrorMarker(QString errormes, QGraphicsObject *parent);
    ~ErrorMarker();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QString getErrormessage() const;

    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

private:
    QString errormessage;
    QGraphicsTextItem *errortext;
};

#endif // ERRORMARKER_H
