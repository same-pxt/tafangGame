#include "rectitem.h"
#include <QPainter>
#include <QGraphicsSceneDragDropEvent>
#include <QDrag>
#include <QMimeData>
#include <QDebug>
#include <QMovie>
#include <QLabel>
#include<QGraphicsProxyWidget>
RectItem::RectItem(int x,int y,int type)
{
    this->x=x;
    this->y=y;
    this->type=type;
    setAcceptDrops(true);  //设置接收拖放
    this->setPos(x,y);
    if(type==0)
        pix.load(QString(":/image/soil.png"));
    else if(type==1)
        pix.load(QString(":/image/e.png"));
}

QRectF RectItem::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void RectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    if(this->mov)
    {
        QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);
        QLabel*p=new QLabel;
        proxy->setWidget(p);
        p->setMovie(this->mov);
        p->show();
        p->setStyleSheet("background:transparent");
        this->mov->start();
    }
    else
    {
        painter->drawPixmap(0,0,this->pix);
    }

}

void RectItem::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasHtml())
    {
        event->setAccepted(true);
        dragOver = false;
        this->mov=new QMovie(QString(event->mimeData()->html()));
        update();
    }
    else event->setAccepted(false);
}
void RectItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    update();
}
void RectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    update();
}
