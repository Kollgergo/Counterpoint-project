#include "vnote.h"

VNote::VNote(bool newnote, unsigned int spos, ScoreViewModel::noteTypes ntype, ScoreViewModel::accents acc, QGraphicsObject *parent) : QGraphicsObject(parent)
{
    pixmap = QPixmap();
    shadow = NULL;
    scorepos = spos;
    notetype = ntype;
    accent = acc;

    if(newnote == true){
        setFlag(ItemIsMovable);  
        this->newnote = true;

    }else{
        this->newnote = false;
        setFlag(ItemIsSelectable);

        if(ntype == ScoreViewModel::whole || ntype == ScoreViewModel::half || ntype == ScoreViewModel::quarter || ntype == ScoreViewModel::eight){
            setFlag(ItemIsMovable);
            setCursor(Qt::OpenHandCursor);
            setAcceptedMouseButtons(Qt::LeftButton);
        }

        if(this->parentItem() != 0){ // process scorepos
            VStaff *temp = (VStaff *)this->parentItem();
            this->setY(temp->getVstafflines().at(scorepos)->y()-10);
        }
    }
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
    case ScoreViewModel::eight:
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
    case ScoreViewModel::eight_rest:
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
        case ScoreViewModel::eight:
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
        case ScoreViewModel::eight_rest:
            pixmap.load("./res/eighth_rest.png");
            painter->drawPixmap(0,2.5,20,36,pixmap);
            break;
        default:
            pixmap.load("./res/half_note.png");
            painter->drawPixmap(0,0,24,20,pixmap);
            break;
        }

        QPixmap accentpixmap = QPixmap();

        switch (accent) {
        case ScoreViewModel::sharp:
            accentpixmap.load("./res/sharp.png");
            painter->drawPixmap(-20,-5,16,35,accentpixmap);
            break;
        case ScoreViewModel::flat:
            accentpixmap.load("./res/flat.png");
            painter->drawPixmap(-20,-15,16,35,accentpixmap);
            break;
        case ScoreViewModel::none:

            break;
        default:
            break;
        }        

        QPen pen(Qt::black);
        pen.setWidth(2);

        if(notetype == ScoreViewModel::half || notetype == ScoreViewModel::quarter || notetype == ScoreViewModel::eight){
            painter->setPen(pen);

            if(getScorepos() < 6){
                painter->drawLine(boundingRect().right()-1, 5, boundingRect().right()-1, -60);
                if(notetype == ScoreViewModel::eight){
                    QPixmap flagpixmap("./res/flag.png");
                    painter->drawPixmap(boundingRect().right(), -60, 26, 60, flagpixmap);
                }
            }else{
                painter->drawLine(boundingRect().left()+1, 15, boundingRect().left()+1, 80);
                if(notetype == ScoreViewModel::eight){
                    QPixmap flagpixmap("./res/flag_flip.png");
                    painter->drawPixmap(boundingRect().left(), 20, 26, 60, flagpixmap);
                }
            }


        }

        if(scorepos == 0 || scorepos == 12){
            painter->drawLine(-10, 10, 35, 10);
        }

        if(this->isSelected()){
            pen.setColor(Qt::red);
            pen.setWidth(1);
            painter->setPen(pen);
            painter->drawRect(boundingRect());
            this->parentItem()->setSelected(true);
        }


    /*QPen pen(Qt::red);
    painter->setPen(pen);
    painter->drawRect(boundingRect());

    */
}

void VNote::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(newnote == true){

        VStaff *tempparent = (VStaff *)this->parentItem();
        tempparent->addNewVNote();

    }else{

        VStaff *tempparent = (VStaff *)this->parentItem();
        tempparent->setSelectedvnote(this);

        if(getNotetype() == ScoreViewModel::whole || getNotetype() == ScoreViewModel::half || getNotetype() == ScoreViewModel::quarter || getNotetype() == ScoreViewModel::eight){
           setCursor(Qt::ClosedHandCursor);
        }

        if(this->shadow == NULL){

            switch (this->getNotetype()) {
            case ScoreViewModel::whole:
                this->shadow = new VNote(false, getScorepos(),ScoreViewModel::whole, ScoreViewModel::none, this->parentObject());
                break;
            case ScoreViewModel::half:
                this->shadow = new VNote(false, getScorepos(),ScoreViewModel::half, ScoreViewModel::none, this->parentObject());
                break;
            case ScoreViewModel::quarter:
                this->shadow = new VNote(false, getScorepos(),ScoreViewModel::quarter, ScoreViewModel::none, this->parentObject());
                break;
            case ScoreViewModel::eight:
                this->shadow = new VNote(false, getScorepos(),ScoreViewModel::eight, ScoreViewModel::none, this->parentObject());
                break;
            default:
                this->shadow = new VNote(false, getScorepos(),ScoreViewModel::half, ScoreViewModel::none, this->parentObject());
                break;
            }

            shadow->setOpacity(0);
            shadow->setX(this->pos().x());
            shadow->setY(this->pos().y());
            //qDebug() << "Current note pos" << this->pos();
            //qDebug() << "Current note scenepos" << this->scenePos();
        }

        //qDebug() << this->pos();
        QGraphicsItem::mousePressEvent(event);
    }


    //QGraphicsItem::mousePressEvent(event);
}

void VNote::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << "mousmoveevent call";

    if(newnote == false){
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

        //this->scene()->update(boundingRect().x()-10,boundingRect().y()-80,boundingRect().right()+10,boundingRect().bottom());
        //this->scene()->update();
    }

    QGraphicsItem::mouseMoveEvent(event);
}

void VNote::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(newnote == false){
        if(getNotetype() == ScoreViewModel::whole || getNotetype() == ScoreViewModel::half || getNotetype() == ScoreViewModel::quarter || getNotetype() == ScoreViewModel::eight){
           setCursor(Qt::OpenHandCursor);
        }

        this->setPos(shadow->pos());

        //qDebug() << "After note pos" << this->pos();
        //qDebug() << "After note scenepos" << this->scenePos();

        if(this->parentItem() != 0){ // if not shadow, update scorepos

            QList <QGraphicsItem *> colList = this->scene()->collidingItems(shadow);
            VStaff *tempparent = (VStaff *)this->parentItem();

            VStaffLine *colStaffLine = (VStaffLine *)colList.last();
            this->setScorepos(tempparent->getVstafflines().indexOf(colStaffLine));

            emit this->notePosChanging(this);

            this->scene()->update();
        }

        if(shadow != NULL){
            delete shadow;
            shadow = NULL;
        }

        this->scene()->update();
        //qDebug() << this->pos();
    }

    QGraphicsItem::mouseReleaseEvent(event);
}

void VNote::hoverEntered(VStaffLine *staffline)
{
    this->setY(staffline->y()-10);
    VStaff *tempparent = (VStaff *)this->parentItem();

    for(int i=0; i<tempparent->getVstafflines().size(); i++){
        if(tempparent->getVstafflines().at(i) == staffline){
            setScorepos(i);
        }
    }

}
void VNote::setNotetype(const ScoreViewModel::noteTypes &value)
{
    if(notetype == ScoreViewModel::whole || notetype == ScoreViewModel::half || notetype == ScoreViewModel::quarter || notetype == ScoreViewModel::eight){
        notetype = value;
    }else{
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
        case ScoreViewModel::eight:
            notetype = ScoreViewModel::eight_rest;
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

int VNote::getScorepos() const
{
    return scorepos;
}

void VNote::setScorepos(int value)
{
    scorepos = value;
}

void VNote::changeToRest()
{
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
    case ScoreViewModel::eight:
        notetype = ScoreViewModel::eight_rest;
        break;
    default:
        notetype = ScoreViewModel::half_rest;
        break;
    }
}


