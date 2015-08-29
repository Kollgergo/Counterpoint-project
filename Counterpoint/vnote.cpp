#include "vnote.h"

VNote::VNote(unsigned int spos, ScoreViewModel::noteTypes ntype, QGraphicsObject *parent) : QGraphicsObject(parent)
{
    pixmap = QPixmap("./res/half_note.png");
    shadow = NULL;

    if(ntype == ScoreViewModel::whole || ntype == ScoreViewModel::half || ntype == ScoreViewModel::quarter || ntype == ScoreViewModel::eight){
        setFlag(ItemIsMovable);
        setFlag(ItemIsSelectable);
        setCursor(Qt::OpenHandCursor);
        setAcceptedMouseButtons(Qt::LeftButton);
    }


    scorepos = spos;
    notetype = ntype;
    accent = ScoreViewModel::none;

    if(this->parentItem() != 0){ // if not shadow, process scorepos
        VStaff *temp = (VStaff *)this->parentItem();

        this->setY(temp->getVstafflines().at(scorepos)->y()-10);
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
        break;
    }


    return rect;
}

void VNote::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

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
        break;
    }


    if(this->isSelected()){
        QPen pen(Qt::red);
        painter->setPen(pen);
        painter->drawRect(boundingRect());
    }


    /*QPen pen(Qt::red);
    painter->setPen(pen);
    painter->drawRect(boundingRect());

    */
}

void VNote::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(getNotetype() == ScoreViewModel::whole || getNotetype() == ScoreViewModel::half || getNotetype() == ScoreViewModel::quarter || getNotetype() == ScoreViewModel::eight){
       setCursor(Qt::ClosedHandCursor);
    }

    if(this->shadow == NULL){

        switch (this->getNotetype()) {
        case ScoreViewModel::whole:
            this->shadow = new VNote(getScorepos(),ScoreViewModel::whole,0);
            break;
        case ScoreViewModel::half:
            this->shadow = new VNote(getScorepos(),ScoreViewModel::half,0);
            break;
        case ScoreViewModel::quarter:
            this->shadow = new VNote(getScorepos(),ScoreViewModel::quarter,0);
            break;
        case ScoreViewModel::eight:
            this->shadow = new VNote(getScorepos(),ScoreViewModel::eight,0);
            break;
        default:
            this->shadow = new VNote(getScorepos(),ScoreViewModel::half,0);
            break;
        }

        this->scene()->addItem(shadow);
        shadow->setOpacity(0);
        shadow->setX(this->x());
        shadow->setY(this->y());
    }

    //qDebug() << this->pos();

    QGraphicsItem::mousePressEvent(event);
}

void VNote::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QList <QGraphicsItem *> colList = this->scene()->collidingItems(this);

    if(!colList.isEmpty()){

        shadow->setOpacity(0.5);

        if(colList.startsWith(shadow)){ // evade collision with shadow
            //qDebug() << colList.first()->pos();
            if(colList.size() > 1){
                shadow->setY((colList.at(1)->pos().y())-10);
            }

        }else{
            //qDebug() << colList.first()->pos();
            shadow->setY((colList.first()->pos().y())-10);

        }
    }

    QGraphicsItem::mouseMoveEvent(event);
}

void VNote::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{    
    if(getNotetype() == ScoreViewModel::whole || getNotetype() == ScoreViewModel::half || getNotetype() == ScoreViewModel::quarter || getNotetype() == ScoreViewModel::eight){
       setCursor(Qt::OpenHandCursor);
    }

    this->setPos(shadow->pos());

    if(this->parentItem() != 0){ // if not shadow, update scorepos

        QList <QGraphicsItem *> colList = this->scene()->collidingItems(shadow);
        VStaff *temp = (VStaff *)this->parentItem();

        VStaffLine *colStaffLine = (VStaffLine *)colList.last();
        this->setScorepos(temp->getVstafflines().indexOf(colStaffLine));

        emit this->notePosChanging(getScorepos());
    }

    if(shadow != NULL){
        delete shadow;
        shadow = NULL;
    }

    //qDebug() << this->pos();

    QGraphicsItem::mouseReleaseEvent(event);
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


