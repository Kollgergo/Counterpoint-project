#include "scoreview.h"

ScoreView::ScoreView(QWidget *parent) : QGraphicsView(parent)
{

}

void ScoreView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scalefactor = 1.15;

    if(event->delta() > 0){
        scale(scalefactor, scalefactor);
    }else{
        scale(1/scalefactor, 1/scalefactor);
    }


}

void ScoreView::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    QAction *actionNewScore = new QAction("Új kotta", this);



    menu.addAction("Valami");

    menu.exec(event->globalPos());
}

