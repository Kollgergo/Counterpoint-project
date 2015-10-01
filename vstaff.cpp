#include "vstaff.h"

VStaff::VStaff(bool isCF, ScoreViewModel::clefNames clef, KeySignature keysig, QGraphicsObject *parent) : QGraphicsObject(parent)
{
    if(!isCF){
        setFlag(ItemIsSelectable);
    }else{
        setEnabled(false);
    }

    this->clef = clef;
    this->keysignature = keysig;
    newvnote = NULL;

    int initstaffwidth;

    switch (qAbs(keysig.getKeysig())) {
    case 0:
        initstaffwidth = 173;
        break;
    case 1:
        initstaffwidth = 193;
        break;
    case 2:
        initstaffwidth = 213;
        break;
    case 3:
        initstaffwidth = 233;
        break;
    case 4:
        initstaffwidth = 253;
        break;
    case 5:
        initstaffwidth = 273;
        break;
    case 6:
        initstaffwidth = 293;
        break;
    case 7:
        initstaffwidth = 313;
        break;
    default:
        initstaffwidth = 173;
        break;
    }

    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(false, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(false, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(false, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(false, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(false, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));
    vstafflines.push_back(new VStaffLine(true, initstaffwidth, this));

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

    QList <QPixmap> keylist;

    if(keysignature.getKeysig() == 0){

    }else if(keysignature.getKeysig() > 0){
        keylist.clear();
        for(int i=0; i<keysignature.getKeysig(); i++){
            keylist.push_back(QPixmap("./res/sharp.png"));
        }

        int clefshift = 0;

        switch (clef) {
        case ScoreViewModel::alto:
            clefshift = 10;
            break;
        case ScoreViewModel::bass:
            clefshift = 20;
            break;
        default:
            break;
        }

        if(clef != ScoreViewModel::tenor){
            switch (keysignature.getKeysig()) {
            case 1:
                painter->drawPixmap(65,-67+clefshift,115,95,QPixmap("./res/1_sharp.png"));
                break;
            case 2:
                painter->drawPixmap(65,-67+clefshift,115,95,QPixmap("./res/2_sharp.png"));
                break;
            case 3:
                painter->drawPixmap(65,-67+clefshift,115,95,QPixmap("./res/3_sharp.png"));
                break;
            case 4:
                painter->drawPixmap(65,-67+clefshift,115,95,QPixmap("./res/4_sharp.png"));
                break;
            case 5:
                painter->drawPixmap(65,-67+clefshift,115,95,QPixmap("./res/5_sharp.png"));
                break;
            case 6:
                painter->drawPixmap(65,-67+clefshift,115,95,QPixmap("./res/6_sharp.png"));
                break;
            case 7:
                painter->drawPixmap(65,-67+clefshift,115,95,QPixmap("./res/7_sharp.png"));
                break;
            default:
                break;
            }
        }else{

            switch (keysignature.getKeysig()) {
            case 1:
                painter->drawPixmap(65,-57,115,95,QPixmap("./res/1_sharp_t.png"));
                break;
            case 2:
                painter->drawPixmap(65,-57,115,95,QPixmap("./res/2_sharp_t.png"));
                break;
            case 3:
                painter->drawPixmap(65,-57,115,95,QPixmap("./res/3_sharp_t.png"));
                break;
            case 4:
                painter->drawPixmap(65,-57,115,95,QPixmap("./res/4_sharp_t.png"));
                break;
            case 5:
                painter->drawPixmap(65,-57,115,95,QPixmap("./res/5_sharp_t.png"));
                break;
            case 6:
                painter->drawPixmap(65,-57,115,95,QPixmap("./res/6_sharp_t.png"));
                break;
            case 7:
                painter->drawPixmap(65,-57,115,95,QPixmap("./res/7_sharp_t.png"));
                break;
            default:
                break;
            }
        }


    }else{
        int tempkeysig = qAbs(keysignature.getKeysig());
        keylist.clear();
        for(int i=0; i<tempkeysig; i++){
            keylist.push_back(QPixmap("./res/flat.png"));
        }

        int clefshift = 0;

        switch (clef) {
        case ScoreViewModel::alto:
            clefshift = 10;
            break;
        case ScoreViewModel::tenor:
            clefshift = -10;
            break;
        case ScoreViewModel::bass:
            clefshift = 20;
            break;
        default:
            break;
        }

        switch (tempkeysig) {
        case 1:
            painter->drawPixmap(65,-56+clefshift,115,95,QPixmap("./res/1_flat.png"));
            break;
        case 2:
            painter->drawPixmap(65,-56+clefshift,115,95,QPixmap("./res/2_flat.png"));
            break;
        case 3:
            painter->drawPixmap(65,-56+clefshift,115,95,QPixmap("./res/3_flat.png"));
            break;
        case 4:
            painter->drawPixmap(65,-56+clefshift,115,95,QPixmap("./res/4_flat.png"));
            break;
        case 5:
            painter->drawPixmap(65,-56+clefshift,115,95,QPixmap("./res/5_flat.png"));
            break;
        case 6:
            painter->drawPixmap(65,-56+clefshift,115,95,QPixmap("./res/6_flat.png"));
            break;
        case 7:
            painter->drawPixmap(65,-56+clefshift,115,95,QPixmap("./res/7_flat.png"));
            break;
        default:
            break;
        }
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
        switch (qAbs(keysignature.getKeysig())) {
        case 0:
            vnote->setX(100);
            break;
        case 1:
            vnote->setX(120);
            break;
        case 2:
            vnote->setX(140);
            break;
        case 3:
            vnote->setX(160);
            break;
        case 4:
            vnote->setX(180);
            break;
        case 5:
            vnote->setX(200);
            break;
        case 6:
            vnote->setX(220);
            break;
        case 7:
            vnote->setX(240);
            break;
        default:
            vnote->setX(100);
            break;
        }
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
    newvnote = new VNote(false,true,9,notetype,accent,this);

    newvnote->setOpacity(0.5);

    if(vnotes.isEmpty()){
        switch (qAbs(keysignature.getKeysig())) {
        case 0:
            newvnote->setX(100);
            break;
        case 1:
            newvnote->setX(120);
            break;
        case 2:
            newvnote->setX(140);
            break;
        case 3:
            newvnote->setX(160);
            break;
        case 4:
            newvnote->setX(180);
            break;
        case 5:
            newvnote->setX(200);
            break;
        case 6:
            newvnote->setX(220);
            break;
        case 7:
            newvnote->setX(240);
            break;
        default:
            newvnote->setX(100);
            break;
        }


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
    vnotes.push_back(new VNote(false,false, newvnote->getScorepos(), newvnote->getNotetype(), newvnote->getAccent(), this));


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
KeySignature VStaff::getKeysignature() const
{
    return keysignature;
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
            if(vnotes.isEmpty()){
                switch (qAbs(keysignature.getKeysig())) {
                case 0:
                    vnotes.at(0)->setX(100);
                    break;
                case 1:
                    vnotes.at(0)->setX(120);
                    break;
                case 2:
                    vnotes.at(0)->setX(140);
                    break;
                case 3:
                    vnotes.at(0)->setX(160);
                    break;
                case 4:
                    vnotes.at(0)->setX(180);
                    break;
                case 5:
                    vnotes.at(0)->setX(200);
                    break;
                case 6:
                    vnotes.at(0)->setX(220);
                    break;
                case 7:
                    vnotes.at(0)->setX(240);
                    break;
                default:
                    vnotes.at(0)->setX(100);
                    break;
                }
            }
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
