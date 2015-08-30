#include "vstaff.h"

VStaff::VStaff(QGraphicsItem *parent) : QGraphicsObject(parent)
{
    //setFlag(ItemHasNoContents);

    clefpixmap = QPixmap("./res/half_note.png");

    for(int i=0; i<13; i++) vstafflines.push_back(new VStaffLine(this));

    vstafflines.at(0)->setPos(0, 60);
    vstafflines.at(0)->setOpacity(0.1);
    vstafflines.at(1)->setPos(0, 50);
    vstafflines.at(1)->setOpacity(0);
    vstafflines.at(2)->setPos(0, 40);
    vstafflines.at(3)->setPos(0, 30);
    vstafflines.at(3)->setOpacity(0);
    vstafflines.at(4)->setPos(0, 20);
    vstafflines.at(5)->setPos(0, 10);
    vstafflines.at(5)->setOpacity(0);
    vstafflines.at(6)->setPos(0, 0);
    vstafflines.at(7)->setPos(0, -10);
    vstafflines.at(7)->setOpacity(0);
    vstafflines.at(8)->setPos(0, -20);
    vstafflines.at(9)->setPos(0, -30);
    vstafflines.at(9)->setOpacity(0);
    vstafflines.at(10)->setPos(0, -40);
    vstafflines.at(11)->setPos(0, -50);
    vstafflines.at(11)->setOpacity(0);
    vstafflines.at(12)->setPos(0, -60);
    vstafflines.at(12)->setOpacity(0.1);

}


QRectF VStaff::boundingRect() const
{
    return QRectF();
}

void VStaff::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    clefpixmap.load("./res/treble_clef.png");

    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPixmap(5,vstafflines.at(12)->y()-15,54,150,clefpixmap);
    /*QPen pen(Qt::red)
    painter->setPen(pen);
    painter->drawRect(boundingRect());*/

}
QList<VStaffLine *> VStaff::getVstafflines() const
{
    return vstafflines;
}

QList<VNote *> VStaff::getVnotes() const
{
    return vnotes;
}

void VStaff::showNextVNote(VNote *vnote)
{
    //qDebug() << vnotes.last()->x();
    int lastX;
    ScoreViewModel::noteTypes lastNoteType;
    if(!vnotes.isEmpty()){
        lastX = vnotes.last()->x();
        lastNoteType = vnotes.last()->getNotetype();
    }else{
        lastX = 0;
        lastNoteType = vnote->getNotetype();
    }

    vnotes.push_back(vnote);

    switch (lastNoteType) {
    case ScoreViewModel::whole:
        if(vnotes.size() > 1){
            vnotes.last()->setX(lastX+400);
        }else{
            vnotes.last()->setX(100);
        }
        break;
    case ScoreViewModel::half:
        if(vnotes.size() > 1){
            vnotes.last()->setX(lastX+200);
        }else{
            vnotes.last()->setX(100);
        }
        break;
    case ScoreViewModel::quarter:
        if(vnotes.size() > 1){
            vnotes.last()->setX(lastX+100);
        }else{
            vnotes.last()->setX(100);
        }
        break;
    case ScoreViewModel::eight:
        if(vnotes.size() > 1){
            vnotes.last()->setX(lastX+50);
        }else{
            vnotes.last()->setX(100);
        }
        break;
    case ScoreViewModel::whole_rest:
        if(vnotes.size() > 1){
            vnotes.last()->setX(lastX+400);
        }else{
            vnotes.last()->setX(100);
        }
        break;
    case ScoreViewModel::half_rest:
        if(vnotes.size() > 1){
            vnotes.last()->setX(lastX+200);
        }else{
            vnotes.last()->setX(100);
        }
        break;
    case ScoreViewModel::quarter_rest:
        if(vnotes.size() > 1){
            vnotes.last()->setX(lastX+100);
        }else{
            vnotes.last()->setX(100);
        }
        break;
    case ScoreViewModel::eight_rest:
       if(vnotes.size() > 1){
            vnotes.last()->setX(lastX+50);
        }else{
            vnotes.last()->setX(100);
        }
        break;
    default:
        break;
    }
    //qDebug() << vnotes.last()->x();

    //vnotes.last()->setX(50*vnotes.size());
}


