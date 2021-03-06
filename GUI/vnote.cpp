#include "vnote.h"

VNote::VNote(bool isCF, bool newnote, unsigned int spos, ScoreViewModel::noteTypes ntype, Accent::accents acc, QGraphicsObject *parent) : QGraphicsObject(parent)
{
    pixmap = QPixmap();
    shadow = NULL;
    staffpos = spos;
    notetype = ntype;
    accent = acc;
    iskeysig = false;

    if(newnote == true){
        setFlag(ItemIsMovable);  
        this->newnote = true;

        if(this->parentItem() != 0){ // process scorepos
            VStaff *temp = (VStaff *)this->parentItem();
            this->setY(temp->getVstafflines().at(staffpos)->y()-10);
        }

    }else{
        this->newnote = false;
        if(!isCF){
            setFlag(ItemIsSelectable);

            if(ntype == ScoreViewModel::whole || ntype == ScoreViewModel::half || ntype == ScoreViewModel::quarter || ntype == ScoreViewModel::eighth){
                setFlag(ItemIsMovable);
                setCursor(Qt::OpenHandCursor);
                setAcceptedMouseButtons(Qt::LeftButton);
            }
        }else{
            setEnabled(false);
        }

        if(this->parentItem() != 0){ // process scorepos
            VStaff *temp = (VStaff *)this->parentItem();
            this->setY(temp->getVstafflines().at(staffpos)->y()-10);
        }
    }
}

VNote::~VNote()
{
    delete(shadow);
}

QRectF VNote::boundingRect() const
{
    QRectF rect;

    switch (notetype) {
    case ScoreViewModel::whole:
        rect = QRectF(0,0,30,20);
        break;
    case ScoreViewModel::half:
        rect = QRectF(0,0,24,20);
        break;
    case ScoreViewModel::quarter:
        rect = QRectF(0,0,24,20);
        break;
    case ScoreViewModel::eighth:
        rect = QRectF(0,0,24,20);
        break;
    case ScoreViewModel::whole_rest:
        rect = QRectF(0,0,30,10);
        break;
    case ScoreViewModel::half_rest:
        rect = QRectF(0,0,30,20);
        break;
    case ScoreViewModel::quarter_rest:
        rect = QRectF(0,-10,20,63);
        break;
    case ScoreViewModel::eighth_rest:
        rect = QRectF(0,2.5,20,36);
        break;
    default:
        rect = QRectF(0,0,24,20);
        break;
    }

    return rect;
}

void VNote::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

        switch (notetype) {
        case ScoreViewModel::whole:
            pixmap.load("./res/whole_note.png");
            painter->drawPixmap(0,0,30,20,pixmap);
            break;
        case ScoreViewModel::half:
            pixmap.load("./res/half_note.png");
            painter->drawPixmap(0,0,24,20,pixmap);
            break;
        case ScoreViewModel::quarter:
            pixmap.load("./res/quarter_note.png");
            painter->drawPixmap(0,0,24,20,pixmap);
            break;
        case ScoreViewModel::eighth:
            pixmap.load("./res/quarter_note.png");
            painter->drawPixmap(0,0,24,20,pixmap);
            break;
        case ScoreViewModel::whole_rest:
            pixmap.load("./res/whole_rest.png");
            painter->drawPixmap(0,0,30,10,pixmap);
            break;
        case ScoreViewModel::half_rest:
            pixmap.load("./res/half_rest.png");
            painter->drawPixmap(0,0,30,20,pixmap);
            break;
        case ScoreViewModel::quarter_rest:
            pixmap.load("./res/quarter_rest.png");
            painter->drawPixmap(0,-10,20,63,pixmap);
            break;
        case ScoreViewModel::eighth_rest:
            pixmap.load("./res/eighth_rest.png");
            painter->drawPixmap(0,2.5,20,36,pixmap);
            break;
        default:
            pixmap.load("./res/half_note.png");
            painter->drawPixmap(0,0,24,20,pixmap);
            break;
        }

        QPixmap accentpixmap = QPixmap();

        if(!iskeysig){
            switch (accent) {
            case Accent::sharp:
                accentpixmap.load("./res/sharp.png");
                painter->drawPixmap(-20,-5,16,35,accentpixmap);
                break;
            case Accent::flat:
                accentpixmap.load("./res/flat.png");
                painter->drawPixmap(-20,-15,16,35,accentpixmap);
                break;
            default:
                break;
            }
        }else if(accent == Accent::natural){
            accentpixmap.load("./res/natural.png");
            painter->drawPixmap(-20,-10,11,40,accentpixmap);
        }

        QPen pen(Qt::black);
        pen.setWidth(2);

        if(notetype == ScoreViewModel::half || notetype == ScoreViewModel::quarter || notetype == ScoreViewModel::eighth){
            painter->setPen(pen);

            if(getStaffpos() < 8){
                painter->drawLine(boundingRect().right()-1, 5, boundingRect().right()-1, -60); //note line
                if(notetype == ScoreViewModel::eighth){
                    QPixmap flagpixmap("./res/flag.png");
                    painter->drawPixmap(boundingRect().right(), -60, 26, 60, flagpixmap); //eighth flag
                }
            }else{
                painter->drawLine(boundingRect().left()+1, 15, boundingRect().left()+1, 80);
                if(notetype == ScoreViewModel::eighth){
                    QPixmap flagpixmap("./res/flag_flip.png");
                    painter->drawPixmap(boundingRect().left(), 20, 26, 60, flagpixmap);
                }
            }


        }

        if(staffpos == 0){
            painter->drawLine(-10, 10, 35, 10);
            painter->drawLine(-10, -10, 35, -10);
        }else if(staffpos == 1){
            painter->drawLine(-10, 0, 35, 0);
        }else if(staffpos == 15){
            painter->drawLine(-10, 20, 35, 20);
        }else if(staffpos == 16){
            painter->drawLine(-10, 10, 35, 10);
            painter->drawLine(-10, 30, 35, 30);
        }else if(staffpos == 2 || staffpos == 14){
            painter->drawLine(-10, 10, 35, 10);
        }

        if(this->isSelected()){
            pen.setColor(Qt::red);
            pen.setWidth(1);
            painter->setPen(pen);
            painter->drawRect(boundingRect());
            if(!parentItem()->isSelected()){
                this->parentItem()->setSelected(true);
            }

        }
}

void VNote::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(newnote == true){

        VStaff *tempparent = (VStaff *)this->parentItem();
        tempparent->finalizeNewVNote();

    }else{
        emit vNoteSelecting(this);

        if(getNotetype() == ScoreViewModel::whole || getNotetype() == ScoreViewModel::half || getNotetype() == ScoreViewModel::quarter || getNotetype() == ScoreViewModel::eighth){
           setCursor(Qt::ClosedHandCursor);

           if(this->shadow == NULL){

               switch (this->getNotetype()) {
               case ScoreViewModel::whole:
                   this->shadow = new VNote(false,false, getStaffpos(),ScoreViewModel::whole, Accent::none, this->parentObject());
                   break;
               case ScoreViewModel::half:
                   this->shadow = new VNote(false,false, getStaffpos(),ScoreViewModel::half, Accent::none, this->parentObject());
                   break;
               case ScoreViewModel::quarter:
                   this->shadow = new VNote(false,false, getStaffpos(),ScoreViewModel::quarter, Accent::none, this->parentObject());
                   break;
               case ScoreViewModel::eighth:
                   this->shadow = new VNote(false,false, getStaffpos(),ScoreViewModel::eighth, Accent::none, this->parentObject());
                   break;
               default:
                   this->shadow = new VNote(false,false, getStaffpos(),ScoreViewModel::half, Accent::none, this->parentObject());
                   break;
               }

               shadow->setOpacity(0);
               shadow->setX(this->pos().x());
               shadow->setY(this->pos().y());
           }
        }
        QGraphicsItem::mousePressEvent(event);
    }
}

void VNote::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(newnote == false){
        if(getNotetype() == ScoreViewModel::whole || getNotetype() == ScoreViewModel::half || getNotetype() == ScoreViewModel::quarter || getNotetype() == ScoreViewModel::eighth){
            QList <QGraphicsItem *> colList = this->scene()->collidingItems(this);

            if(!colList.isEmpty()){

                shadow->setOpacity(0.5);

                //qDebug() << colList;

                if(colList.last()->parentItem() == this->parentItem() && colList.startsWith(shadow)){ // evade collision with shadow
                    //qDebug() << colList.first()->pos();
                    if(colList.size() > 1){
                        shadow->setY((colList.at(1)->pos().y())-10);
                        //qDebug() << colList.at(1)->y()-10;
                    }

                }else if(colList.first()->parentItem() == this->parentItem()){
                    //qDebug() << colList.first()->pos();
                    shadow->setY((colList.first()->pos().y())-10);
                    //qDebug() << colList.first()->y()-10;
                }
            }

        }

        this->scene()->update();
        //this->scene()->update(boundingRect().x()-10,boundingRect().y()-80,boundingRect().right()+10,boundingRect().bottom());
        //this->scene()->update();
    }

    QGraphicsItem::mouseMoveEvent(event);
}

void VNote::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(newnote == false){
        if(getNotetype() == ScoreViewModel::whole || getNotetype() == ScoreViewModel::half || getNotetype() == ScoreViewModel::quarter || getNotetype() == ScoreViewModel::eighth){
           setCursor(Qt::OpenHandCursor);

           this->setPos(shadow->pos());

           //qDebug() << "After note pos" << this->pos();
           //qDebug() << "After note scenepos" << this->scenePos();

           if(this->parentItem() != 0){ // if not shadow, update scorepos

               QList <QGraphicsItem *> colList = this->scene()->collidingItems(shadow);
               VStaff *tempparent = (VStaff *)this->parentItem();

               VStaffLine *colStaffLine = (VStaffLine *)colList.last();

               if(staffpos != tempparent->getVstafflines().indexOf(colStaffLine)){
                   this->setScorepos(tempparent->getVstafflines().indexOf(colStaffLine));
                   accent = Accent::none;
                   emit this->vNotePosChanging(this);
               }

               this->scene()->update();
           }

           if(shadow != NULL){
               delete shadow;
               shadow = NULL;
           }

        }


        this->scene()->update();
        //qDebug() << this->pos();
    }

    QGraphicsItem::mouseReleaseEvent(event);
}

void VNote::hoverEntered(VStaffLine *staffline)
{
    if(notetype == ScoreViewModel::whole || notetype == ScoreViewModel::half || notetype == ScoreViewModel::quarter || notetype == ScoreViewModel::eighth){
        this->setY(staffline->y()-10);
        VStaff *tempparent = (VStaff *)this->parentItem();

        for(int i=0; i<tempparent->getVstafflines().size(); i++){
            if(tempparent->getVstafflines().at(i) == staffline){
                setScorepos(i);
            }
        }
    }
}

bool VNote::getIskeysig() const
{
    return iskeysig;
}

void VNote::setIskeysig(bool value)
{
    iskeysig = value;
}
void VNote::setAccent(const Accent::accents &value, bool iskeysig)
{
    accent = value;
    this->iskeysig = iskeysig;

}

Accent::accents VNote::getAccent() const
{
    return accent;
}

void VNote::setNotetype(const ScoreViewModel::noteTypes &value)
{
    if(notetype == ScoreViewModel::whole || notetype == ScoreViewModel::half || notetype == ScoreViewModel::quarter || notetype == ScoreViewModel::eighth){
        notetype = value;
    }else{
        switch (value) {
        case ScoreViewModel::whole:
            notetype = ScoreViewModel::whole_rest;
            break;
        case ScoreViewModel::half:
            notetype = ScoreViewModel::half_rest;
            break;
        case ScoreViewModel::quarter:
            notetype = ScoreViewModel::quarter_rest;
            break;
        case ScoreViewModel::eighth:
            notetype = ScoreViewModel::eighth_rest;
            break;
        default:
            notetype = ScoreViewModel::half_rest;
            break;
        }
    }

}


ScoreViewModel::noteTypes VNote::getNotetype() const
{
    return notetype;
}

int VNote::getStaffpos() const
{
    return staffpos;
}

void VNote::setScorepos(int value)
{
    staffpos = value;
}

void VNote::changeToRest()
{
    //qDebug() << this->x();

    switch (notetype) {
    case ScoreViewModel::whole:
        notetype = ScoreViewModel::whole_rest;
        break;
    case ScoreViewModel::half:
        notetype = ScoreViewModel::half_rest;
        break;
    case ScoreViewModel::quarter:
        notetype = ScoreViewModel::quarter_rest;
        break;
    case ScoreViewModel::eighth:
        notetype = ScoreViewModel::eighth_rest;
        break;
    default:

        break;
    }

    this->setY(-20);
    setFlag(ItemIsMovable, false);
    setAccent(Accent::none, false);
}

void VNote::changeToNote()
{
    switch (notetype) {
    case ScoreViewModel::whole_rest:
        notetype = ScoreViewModel::whole;
        this->setY(-10);
        this->setScorepos(8);
        setFlag(ItemIsMovable, true);
        break;
    case ScoreViewModel::half_rest:
        notetype = ScoreViewModel::half;
        this->setY(-10);
        this->setScorepos(8);
        setFlag(ItemIsMovable, true);
        break;
    case ScoreViewModel::quarter_rest:
        notetype = ScoreViewModel::quarter;
        this->setY(-10);
        this->setScorepos(8);
        setFlag(ItemIsMovable, true);
        break;
    case ScoreViewModel::eighth_rest:
        notetype = ScoreViewModel::eighth;
        this->setY(-10);
        this->setScorepos(8);
        setFlag(ItemIsMovable, true);
        break;
    default:

        break;
    }
}


