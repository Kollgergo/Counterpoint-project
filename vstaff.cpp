#include "vstaff.h"

VStaff::VStaff(ScoreViewModel::clefNames clef, QGraphicsObject *parent) : QGraphicsObject(parent)
{
    setFlag(ItemIsSelectable);

    this->clef = clef;
    newvnote = NULL;

    //for(int i=0; i<13; i++) vstafflines.push_back(new VStaffLine(true, this));

    vstafflines.push_back(new VStaffLine(true, this));
    vstafflines.push_back(new VStaffLine(true, this));
    vstafflines.push_back(new VStaffLine(false, this));
    vstafflines.push_back(new VStaffLine(true, this));
    vstafflines.push_back(new VStaffLine(false, this));
    vstafflines.push_back(new VStaffLine(true, this));
    vstafflines.push_back(new VStaffLine(false, this));
    vstafflines.push_back(new VStaffLine(true, this));
    vstafflines.push_back(new VStaffLine(false, this));
    vstafflines.push_back(new VStaffLine(true, this));
    vstafflines.push_back(new VStaffLine(false, this));
    vstafflines.push_back(new VStaffLine(true, this));
    vstafflines.push_back(new VStaffLine(true, this));

//    vstafflines.at(0)->setPos(0, 60);
//    vstafflines.at(0)->setOpacity(0.1);
//    vstafflines.at(1)->setPos(0, 50);
//    vstafflines.at(1)->setOpacity(0);
//    vstafflines.at(2)->setPos(0, 40);
//    vstafflines.at(3)->setPos(0, 30);
//    vstafflines.at(3)->setOpacity(0);
//    vstafflines.at(4)->setPos(0, 20);
//    vstafflines.at(5)->setPos(0, 10);
//    vstafflines.at(5)->setOpacity(0);
//    vstafflines.at(6)->setPos(0, 0);
//    vstafflines.at(7)->setPos(0, -10);
//    vstafflines.at(7)->setOpacity(0);
//    vstafflines.at(8)->setPos(0, -20);
//    vstafflines.at(9)->setPos(0, -30);
//    vstafflines.at(9)->setOpacity(0);
//    vstafflines.at(10)->setPos(0, -40);
//    vstafflines.at(11)->setPos(0, -50);
//    vstafflines.at(11)->setOpacity(0);
//    vstafflines.at(12)->setPos(0, -60);
//    vstafflines.at(12)->setOpacity(0.1);

    //qDebug() << parent->y();
    //qDebug() << parentItem()->y();

    vstafflines.at(0)->setPos(0, this->y()+60);
    //vstafflines.at(0)->setOpacity(0.1);
    vstafflines.at(1)->setPos(0, this->y()+50);

    //vstafflines.at(1)->setOpacity(0.1);
    //vstafflines.at(1)->setVisible(true);
    //vstafflines.at(1)->setAcceptHoverEvents(true);
    vstafflines.at(2)->setPos(0, this->y()+40);
    vstafflines.at(3)->setPos(0, this->y()+30);
    //vstafflines.at(3)->setVisible(true);
    //vstafflines.at(3)->setOpacity(0);
    vstafflines.at(4)->setPos(0, this->y()+20);
    vstafflines.at(5)->setPos(0, this->y()+10);
    //vstafflines.at(5)->setVisible(true);
    //vstafflines.at(5)->setOpacity(0);
    vstafflines.at(6)->setPos(0, this->y());
    vstafflines.at(7)->setPos(0, this->y()-10);
    //vstafflines.at(7)->setVisible(true);
    //vstafflines.at(7)->setOpacity(0);
    vstafflines.at(8)->setPos(0, this->y()-20);
    vstafflines.at(9)->setPos(0, this->y()-30);
    //vstafflines.at(9)->setVisible(true);
    //vstafflines.at(9)->setOpacity(0);
    vstafflines.at(10)->setPos(0, this->y()-40);
    vstafflines.at(11)->setPos(0, this->y()-50);
    //vstafflines.at(11)->setVisible(true);
   // vstafflines.at(11)->setOpacity(0);
    vstafflines.at(12)->setPos(0, this->y()-60);
    //vstafflines.at(12)->setOpacity(0.1);



}


QRectF VStaff::boundingRect() const
{
    return QRectF(0,-60, 60, 120);
}

void VStaff::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    //qDebug() << this->y();



    if(this->isSelected()){
        QPen pen(Qt::green);
        pen.setWidth(2);

        painter->setPen(pen);
        painter->drawRect(boundingRect());
        emit vstaffSelect(this);
        //qDebug() << this;

    }


    QPixmap clefpixmap;

    //qDebug() << vstafflines.at(12)->y();

    switch (clef) {
    case ScoreViewModel::treble:
        clefpixmap = QPixmap("./res/treble_clef.png");
        painter->drawPixmap(5,vstafflines.at(12)->y()-15,54,150,clefpixmap);
        break;
    case ScoreViewModel::alto:
        clefpixmap = QPixmap("./res/c_clef.png");
        painter->drawPixmap(5,vstafflines.at(10)->y(),54,80,clefpixmap);
        break;
    case ScoreViewModel::tenor:
        clefpixmap = QPixmap("./res/c_clef.png");
        painter->drawPixmap(5,vstafflines.at(12)->y(),54,80,clefpixmap);
        break;
    case ScoreViewModel::bass:
        clefpixmap = QPixmap("./res/bass_clef.png");
        painter->drawPixmap(5,vstafflines.at(10)->y(),63,70,clefpixmap);
        break;
    default:
        clefpixmap = QPixmap("./res/treble_clef.png");
        painter->drawPixmap(5,vstafflines.at(12)->y()-15,54,150,clefpixmap);
        break;
    }

    QPixmap barline = QPixmap("./res/double_barline");


    painter->drawPixmap(vstafflines.at(0)->boundingRect().right()-22, vstafflines.at(10)->y()+1, 23, 80, barline);
//    painter->drawPixmap(0, 0, 32, 113, barline);

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

    if(vnotes.isEmpty()){
        vnotes.last()->setX(100);

        switch (vnote->getNotetype()) {
        case ScoreViewModel::whole:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(400);
            }

            break;
        case ScoreViewModel::half:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        case ScoreViewModel::quarter:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(100);
            }

            break;
        case ScoreViewModel::eight:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(50);
            }

            break;
        case ScoreViewModel::whole_rest:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(400);
            }

            break;
        case ScoreViewModel::half_rest:
            vnotes.last()->setX(100);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        case ScoreViewModel::quarter_rest:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(100);
            }

            break;
        case ScoreViewModel::eight_rest:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(50);
            }

            break;
        default:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        }
    }else{
        switch (lastNoteType) {
        case ScoreViewModel::whole:
            vnotes.last()->setX(lastX+400);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(400);
            }
            break;
        case ScoreViewModel::half:
            vnotes.last()->setX(lastX+200);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        case ScoreViewModel::quarter:
            vnotes.last()->setX(lastX+100);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(100);
            }

            break;
        case ScoreViewModel::eight:
            vnotes.last()->setX(lastX+50);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(50);
            }

            break;
        case ScoreViewModel::whole_rest:
            vnotes.last()->setX(lastX+400);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(400);
            }

            break;
        case ScoreViewModel::half_rest:
            vnotes.last()->setX(lastX+200);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        case ScoreViewModel::quarter_rest:
            vnotes.last()->setX(lastX+100);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(100);
            }

            break;
        case ScoreViewModel::eight_rest:
            vnotes.last()->setX(lastX+50);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(50);
            }

            break;
        default:
            vnotes.last()->setX(lastX+200);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        }
    }


    //qDebug() << vnotes.last()->x();

    //vnotes.last()->setX(50*vnotes.size());
}

void VStaff::setNewVNote(ScoreViewModel::noteTypes notetype)
{
    newvnote = new VNote(true,7,notetype,ScoreViewModel::none,this);
    newvnote->setOpacity(0.5);

    if(vnotes.isEmpty()){
        newvnote->setX(100);
        switch (notetype) {
        case ScoreViewModel::whole:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(400);
            }

            break;
        case ScoreViewModel::half:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        case ScoreViewModel::quarter:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(100);
            }

            break;
        case ScoreViewModel::eight:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(50);
            }

            break;
        case ScoreViewModel::whole_rest:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(400);
            }

            break;
        case ScoreViewModel::half_rest:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        case ScoreViewModel::quarter_rest:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(100);
            }

            break;
        case ScoreViewModel::eight_rest:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(50);
            }

            break;
        default:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        }

    }else{
        switch (vnotes.last()->getNotetype()) {
        case ScoreViewModel::whole:
            newvnote->setX(vnotes.last()->x()+400);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(400);
            }

            break;
        case ScoreViewModel::half:
            newvnote->setX(vnotes.last()->x()+200);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        case ScoreViewModel::quarter:
            newvnote->setX(vnotes.last()->x()+100);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(100);
            }

            break;
        case ScoreViewModel::eight:
            newvnote->setX(vnotes.last()->x()+50);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(50);
            }

            break;
        case ScoreViewModel::whole_rest:
            newvnote->setX(vnotes.last()->x()+400);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(400);
            }

            break;
        case ScoreViewModel::half_rest:
            newvnote->setX(vnotes.last()->x()+200);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        case ScoreViewModel::quarter_rest:
            newvnote->setX(vnotes.last()->x()+100);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(100);
            }

            break;
        case ScoreViewModel::eight_rest:
            newvnote->setX(vnotes.last()->x()+50);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(50);
            }

            break;
        default:
            newvnote->setX(vnotes.last()->x()+200);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->setExtrawidth(200);
            }

            break;
        }
    }

    foreach (VStaffLine *staffline, vstafflines) {
        staffline->setAcceptHoverEvents(true);
        connect(staffline,SIGNAL(hoverEntering(VStaffLine*)),newvnote,SLOT(hoverEntered(VStaffLine*)));
    }
}

void VStaff::addNewVNote()
{
    newvnote->setOpacity(1);
    vnotes.push_back(new VNote(false, newvnote->getScorepos(), newvnote->getNotetype(), ScoreViewModel::none, this));

    vnotes.last()->setX(newvnote->x());


    foreach (VStaffLine *staffline, vstafflines) {
        staffline->setAcceptHoverEvents(false);
        disconnect(staffline,SIGNAL(hoverEntering(VStaffLine*)),newvnote,SLOT(hoverEntered(VStaffLine*)));
    }

    delete newvnote;
    newvnote = NULL;
    emit newVNoteAdd(vnotes.last());

}

void VStaff::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit vstaffSelect(this);
    //qDebug() << this;

    QGraphicsItem::mousePressEvent(event);
}
ScoreViewModel::clefNames VStaff::getClef() const
{
    return clef;
}


VNote *VStaff::getNewvnote() const
{
    return newvnote;
}

void VStaff::setNewvnote(VNote *value)
{
    newvnote = value;
}




