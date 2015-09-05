#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <QGraphicsView>
#include <QtWidgets>
#include <QWidget>

class ScoreView : public QGraphicsView
{
public:
    ScoreView(QWidget *parent = 0);

protected:
    virtual void wheelEvent(QWheelEvent *event);

};

#endif // SCOREVIEW_H
