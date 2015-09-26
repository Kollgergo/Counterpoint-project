#include "vstaff.h"

VStaff::VStaff(ScoreViewModel::clefNames clef, KeySignature keysig, QGraphicsObject *parent) : QGraphicsObject(parent)
{
    setFlag(ItemIsSelectable);

    this->clef = clef;
    this->keysignature = keysig;
    newvnote = NULL;

    //for(int i=0; i<13; i++) vstafflines.push_back(new VStaffLine(true, this));

    vstafflines.push_back(new VStaffLine(true, this));
    vstafflines.push_back(new VStaffLine(true, this));
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
    vstafflines.push_back(new VStaffLine(true, this));
    vstafflines.push_back(new VStaffLine(true, this));

    vstafflines.at(0)->setPos(0, this->y()+80);
    vstafflines.at(1)->setPos(0, this->y()+70);
    vstafflines.at(2)->setPos(0, this->y()+60);
    vstafflines.at(3)->setPos(0, this->y()+50);
    vstafflines.at(4)->setPos(0, this->y()+40);
    vstafflines.at(5)->setPos(0, this->y()+30);
    vstafflines.at(6)->setPos(0, this->y()+20);
    vstafflines.at(7)->setPos(0, this->y()+10);
    vstafflines.at(8)->setPos(0, this->y());
    vstafflines.at(9)->setPos(0, this->y()-10);
    vstafflines.at(10)->setPos(0, this->y()-20);
    vstafflines.at(11)->setPos(0, this->y()-30);
    vstafflines.at(12)->setPos(0, this->y()-40);
    vstafflines.at(13)->setPos(0, this->y()-50);
    vstafflines.at(14)->setPos(0, this->y()-60);
    vstafflines.at(15)->setPos(0, this->y()-70);
    vstafflines.at(16)->setPos(0, this->y()-80);

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
        painter->drawPixmap(5,vstafflines.at(14)->y()-15,54,150,clefpixmap);
        break;
    case ScoreViewModel::alto:
        clefpixmap = QPixmap("./res/c_clef.png");
        painter->drawPixmap(5,vstafflines.at(12)->y(),54,80,clefpixmap);
        break;
    case ScoreViewModel::tenor:
        clefpixmap = QPixmap("./res/c_clef.png");
        painter->drawPixmap(5,vstafflines.at(14)->y(),54,80,clefpixmap);
        break;
    case ScoreViewModel::bass:
        clefpixmap = QPixmap("./res/bass_clef.png");
        painter->drawPixmap(5,vstafflines.at(12)->y(),63,70,clefpixmap);
        break;
    default:
        clefpixmap = QPixmap("./res/treble_clef.png");
        painter->drawPixmap(5,vstafflines.at(14)->y()-15,54,150,clefpixmap);
        break;
    }

    /*QList <QPixmap> keylist;

    if(keysignature.getKeysig() == 0){

    }else if(keysignature.getKeysig() > 0){
        keylist.clear();
        for(int i=0; i<keysignature.getKeysig(); i++){
            keylist.push_back(QPixmap("./res/sharp.png"));
        }
    }else{
        int tempkeysig = qAbs(keysignature.getKeysig());
        keylist.clear();
        for(int i=0; i<tempkeysig; i++){
            keylist.push_back(QPixmap("./res/flat.png"));
        }

    }*/

    QPixmap keypixmap("./res/flat.png");

    switch (keysignature.getKeysig()) {
    case -7:

        break;
    case -6:

        break;
    case -5:

        break;
    case -4:

        break;
    case -3:

        break;
    case -2:

        break;
    case -1:
        painter->drawPixmap(-20, -15, 16, 35, keypixmap); //valamelyik staffline boundingrectjéhez képest kell elhelyezni
        break;
    case 0:

        break;
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    default:
        break;
    }

    QPixmap barline = QPixmap("./res/double_barline");

    painter->drawPixmap(vstafflines.at(2)->boundingRect().right()-22, vstafflines.at(12)->y()+1, 23, 80, barline);

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
    int lastX = 0;
    ScoreViewModel::noteTypes lastNoteType;

    if(vnotes.isEmpty()){
        vnote->setX(100);
        updateStaffWidth();

    }else{
        lastX = vnotes.last()->x();
        lastNoteType = vnotes.last()->getNotetype();

        switch (lastNoteType) {
        case ScoreViewModel::whole:
            vnote->setX(lastX+400);

            break;
        case ScoreViewModel::half:
            vnote->setX(lastX+200);

            break;
        case ScoreViewModel::quarter:
            vnote->setX(lastX+100);

            break;
        case ScoreViewModel::eight:
            vnote->setX(lastX+50);

            break;
        case ScoreViewModel::whole_rest:
            vnote->setX(lastX+400);

            break;
        case ScoreViewModel::half_rest:
            vnote->setX(lastX+200);

            break;
        case ScoreViewModel::quarter_rest:
            vnote->setX(lastX+100);

            break;
        case ScoreViewModel::eight_rest:
            vnote->setX(lastX+50);

            break;
        default:
            vnote->setX(lastX+200);

            break;
        }
    }

    vnotes.push_back(vnote);
    updateStaffWidth();
    //qDebug() << vnotes.last()->x();

    //vnotes.last()->setX(50*vnotes.size());
}

void VStaff::setNewVNote(ScoreViewModel::noteTypes notetype, ScoreViewModel::accents accent)
{
    newvnote = new VNote(true,9,notetype,accent,this);

    newvnote->setOpacity(0.5);

    if(vnotes.isEmpty()){
        newvnote->setX(100);

    }else{
        switch (vnotes.last()->getNotetype()) {
        case ScoreViewModel::whole:
            newvnote->setX(vnotes.last()->x()+400);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(400);
            }

            break;
        case ScoreViewModel::half:
            newvnote->setX(vnotes.last()->x()+200);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(200);
            }
            break;
        case ScoreViewModel::quarter:
            newvnote->setX(vnotes.last()->x()+100);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(100);
            }

            break;
        case ScoreViewModel::eight:
            newvnote->setX(vnotes.last()->x()+50);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(50);
            }

            break;
        case ScoreViewModel::whole_rest:
            newvnote->setX(vnotes.last()->x()+400);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(400);
            }

            break;
        case ScoreViewModel::half_rest:
            newvnote->setX(vnotes.last()->x()+200);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(200);
            }

            break;
        case ScoreViewModel::quarter_rest:
            newvnote->setX(vnotes.last()->x()+100);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(100);
            }

            break;
        case ScoreViewModel::eight_rest:
            newvnote->setX(vnotes.last()->x()+50);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(50);
            }

            break;
        default:
            newvnote->setX(vnotes.last()->x()+200);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(400);
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
    vnotes.push_back(new VNote(false, newvnote->getScorepos(), newvnote->getNotetype(), newvnote->getAccent(), this));


    vnotes.last()->setX(newvnote->x());

    foreach (VStaffLine *staffline, vstafflines) {
        staffline->setAcceptHoverEvents(false);
        disconnect(staffline,SIGNAL(hoverEntering(VStaffLine*)),newvnote,SLOT(hoverEntered(VStaffLine*)));
    }

    delete newvnote;
    newvnote = NULL;
    emit newVNoteAdd(vnotes.last());

}

void VStaff::deleteSelectedVNote()
{
    foreach (VNote *note, vnotes) {
        if(note->isSelected()){
            note->changeToRest();
        }
    }
}

void VStaff::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit vstaffSelect(this);
    //qDebug() << this;

    QGraphicsItem::mousePressEvent(event);
}
void VStaff::setSelectedvnote(VNote *value)
{
    selectedvnote = value;
}

void VStaff::updateStaffWidth()
{
    foreach (VStaffLine *staffline, vstafflines) {
        staffline->addStaffwidth(0);
    }

    foreach (VNote *vnote, vnotes) {
        switch (vnote->getNotetype()) {
        case ScoreViewModel::whole:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(400);
            }

            break;
        case ScoreViewModel::half:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(200);
            }

            break;
        case ScoreViewModel::quarter:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(100);
            }

            break;
        case ScoreViewModel::eight:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(50);
            }

            break;
        case ScoreViewModel::whole_rest:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(400);
            }

            break;
        case ScoreViewModel::half_rest:
            vnotes.last()->setX(100);
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(200);
            }

            break;
        case ScoreViewModel::quarter_rest:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(100);
            }

            break;
        case ScoreViewModel::eight_rest:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(50);
            }

            break;
        default:
            foreach (VStaffLine *staffline, vstafflines) {
                staffline->addStaffwidth(200);
            }

            break;
        }
    }
}

void VStaff::updateVStaff()
{
    for(int i=0; i<vnotes.size(); i++){
        if(i==0){
            vnotes.at(0)->setX(100);
            updateStaffWidth();

        }else{
            switch (vnotes.at(i-1)->getNotetype()) {
            case ScoreViewModel::whole:
                vnotes.at(i)->setX(vnotes.at(i-1)->x()+400);

                break;
            case ScoreViewModel::half:
                vnotes.at(i)->setX(vnotes.at(i-1)->x()+200);

                break;
            case ScoreViewModel::quarter:
                vnotes.at(i)->setX(vnotes.at(i-1)->x()+100);

                break;
            case ScoreViewModel::eight:
                vnotes.at(i)->setX(vnotes.at(i-1)->x()+50);

                break;
            case ScoreViewModel::whole_rest:
                vnotes.at(i)->setX(vnotes.at(i-1)->x()+400);

                break;
            case ScoreViewModel::half_rest:
                vnotes.at(i)->setX(vnotes.at(i-1)->x()+200);

                break;
            case ScoreViewModel::quarter_rest:
                vnotes.at(i)->setX(vnotes.at(i-1)->x()+100);

                break;
            case ScoreViewModel::eight_rest:
                vnotes.at(i)->setX(vnotes.at(i-1)->x()+50);

                break;
            default:
                vnotes.at(i)->setX(vnotes.at(i-1)->x()+200);

                break;
            }
        }
    }
}

VNote *VStaff::getSelectedvnote() const
{
    return selectedvnote;
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




