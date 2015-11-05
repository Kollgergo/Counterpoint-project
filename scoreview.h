#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <QGraphicsView>
#include <QtWidgets>
#include <QWidget>

class ScoreView : public QGraphicsView
{
    Q_OBJECT

public:
    ScoreView(QWidget *parent = 0);

protected:
    void mouseReleaseEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);

signals:
    void ctrlWheelChanging(int value);

};

#endif // SCOREVIEW_H
