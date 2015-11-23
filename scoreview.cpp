#include "scoreview.h"

ScoreView::ScoreView(QWidget *parent) : QGraphicsView(parent)
{
    setDragMode(ScrollHandDrag);
    setAlignment(Qt::AlignCenter);
}

void ScoreView::mouseReleaseEvent(QMouseEvent *event)
{
    this->scene()->update();
    QGraphicsView::mouseReleaseEvent(event);
}

void ScoreView::wheelEvent(QWheelEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier){
        if(event->delta() > 0){
            emit ctrlWheelChanging(+5);
            emit ctrlWheelChanging();
        }else{
            emit ctrlWheelChanging(-5);
            emit ctrlWheelChanging();
        }
    }else{
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        double scalefactor = 1.15;

        if(event->delta() > 0){
            scale(scalefactor, scalefactor);
        }else{
            scale(1/scalefactor, 1/scalefactor);
        }
    }
}

//void ScoreView::contextMenuEvent(QContextMenuEvent *event)
//{
//    QMenu menu(this);
//    QAction *actionNewScore = new QAction("Új kotta", this);

//    menu.addAction("Valami");

//    menu.exec(event->globalPos());
//}
