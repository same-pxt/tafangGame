#include "pea.h"
#include <QGraphicsItem>
#include <QPixmap>
#include <QMovie>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include "enemy.h"
#include "plant.h"
#include <QTimer>
#include <QPainter>
#include <QDebug>
pea::pea(int x,int y,int type)
{
    this->x=x;
    this->y=y;
    if(type==zi_dan)
    {
        this->setScale(0.5);
        this->PlayerType=zi_dan;
        p=new QLabel;
        this->attack=100;
        this->p->setPixmap(QString(":/image/豌豆子弹.png"));
        mov=new QMovie;
        mov->setFileName(QString(":/image/豌豆子弹击中.gif"));
    }
    else if(type==ci)
    {
        this->setScale(0.5);
        this->PlayerType=ci;
        this->attack=200;
        mov=new QMovie;
        mov->setFileName(QString(":/image/豌豆子弹击中.gif"));
        p=new QLabel;
        this->p->setPixmap(QString(":/image/Projectile32.png"));
    }

}


void pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /*QBrush brush;
    brush.setColor(QColor(255,0,0,255));
    painter->setBrush(brush);
    painter->drawRect(this->boundingRect());*/
}

QRectF pea::boundingRect() const
{
    if(this->PlayerType==zi_dan)
        return QRectF(0,0,50,50);
    else
        return QRectF(0,0,50,50);
}
void pea::advance(int phase)
{
    p->setFixedSize(30,30);
    p->setAttribute(Qt::WA_TranslucentBackground);
    QList<QGraphicsItem *> items = collidingItems();
    bool flag=0;
    foreach (QGraphicsItem *item, items) {
        if (item->type() == enemy::Type)
        {
            flag=1;
            enemy*all_1 = qgraphicsitem_cast<enemy*>(item);
            all_1->get_att(this->attack);
            QLabel*we=new QLabel;
            we->setText(QString::number(this->attack));
            this->scene()->addWidget(we);
            we->move(this->x+50,this->y+30);
            QTimer::singleShot(500,we,we->deleteLater);
            this->p->clear();
            this->p->setMovie(this->mov);
            this->mov->start();
            this->deleteLater();
            QTimer::singleShot(1000,p,QLabel::clear);
            QTimer::singleShot(1000,this,QWidget::deleteLater);
            break;
        }
    }
    if(flag==0 && this->x<=1100)
    {
        this->x+=100;
        this->setPos(this->x,this->y);
    }
    else if(this->x>1100)
    {
        p->hide();
        this->scene()->removeItem(this);
        this->deleteLater();
    }
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);
    if(proxy->widget()!=p)
        proxy->setWidget(p);
}
