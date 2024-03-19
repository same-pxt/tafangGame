#include "shop.h"
#include  <QGraphicsItem>
#include "game_map.h"
#include "sun.h"
#include <QImage>
#include <QDebug>
shop::shop()
{
    p=new QLabel;
}
QRectF shop::boundingRect()const
{
    return QRectF(0,0,100,100);
}
void shop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(QRectF(0,0,100,100),QImage(QString(":/image/植物商店.png")));
}
void shop::advance(int phase)
{
    if(p!=NULL)
    {
        p->move(50,70);
        p->clear();
        p->setText(QString::number(game_map::sun_num));
        QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);
        proxy->setWidget(p);
    }
    if(plant::time%15==1)
    {
        int m=qrand()%1000;
        sun*w=new sun(m,0,1);
        this->scene()->addItem(w);
    }
}
