#include "sun.h"
#include "game_map.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
sun::sun(int x,int y,int type)
{

    QLabel*p=new QLabel;
    QMovie*mov=new QMovie;
    mov->setFileName(QString(":/image/阳光.gif"));
    mov->start();
    p->setMovie(mov);
    p->setAttribute(Qt::WA_TranslucentBackground);
    this->x=x;
    this->y=y;
    this->type=type;
    this->setPos(x,y);
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);
    if(proxy->widget()!=p)
        proxy->setWidget(p);
}
void sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event->accept();
    if(Qt::LeftButton != event->button())
    {
        event->ignore();
        return;
    }
    game_map::sun_num+=25;
    this->hide();
    this->deleteLater();
    setCursor(Qt::ClosedHandCursor);
}
QRectF sun::boundingRect()const
{
    return QRectF(0,0,100,100);
}
void sun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}
void sun::advance(int phase)
{
    if(this->type==1)
    {
        if(this->y>=600)
        {
            this->hide();
            this->deleteLater();
        }
        else
        {
            this->y+=10;
            this->setPos(x,y);
        }
    }
}
