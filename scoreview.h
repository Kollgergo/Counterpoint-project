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
    void wheelEvent(QWheelEvent *event);

signals:
    void ctrlWheelChanging(int value);
    void ctrlWheelChanging();

};

#endif // SCOREVIEW_H
