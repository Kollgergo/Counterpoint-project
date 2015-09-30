#ifndef VSTAFFLINE_H
#define VSTAFFLINE_H

#include <QtGui>
#include <QtWidgets>

class VStaffLine : public QGraphicsObject
{
    Q_OBJECT

public:
    VStaffLine(bool iswhite = true, int initstaffwidth = 173, QGraphicsObject *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void addStaffwidth(int value);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    //void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void hoverEntering(VStaffLine *staffline);

private:
    bool iswhite;
    int initstaffwidth;
    int staffwidth;

};

#endif // VSTAFFLINE_H
