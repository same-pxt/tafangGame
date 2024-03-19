#include "plant.h"
#include"player.h"
#include<QMovie>
#include<QLabel>
#include "game_map.h"
#include<QGraphicsProxyWidget>
#include<QGraphicsSceneDragDropEvent>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QPainter>
#include<QBrush>
#include<QDebug>
#include<QList>
#include <QObject>
#include "enemy.h"
#include <QDrag>
#include <QMimeData>
#include <QApplication>
#include "sun.h"
int plant::time=0;
plant::plant(int x,int y,int type)
{
    whether_meet=0;
    this->x=x;
    this->y=y;
    p=new QLabel;
    this->PlayerType=type;
    p->setFixedSize(100,100);
    if(this->PlayerType==shi_ren_hua_type)
    {
        this->cost=150;
        this->attack=70;
        this->blood=2000;
        this->defend=200;
        QMovie*mov1=new QMovie;
        mov1->setFileName(QString(":/image/食人花.gif"));
        QMovie*mov2=new QMovie;
        mov2->setFileName(QString(":/image/食人花攻击.gif"));
        mov.push_back(mov1);
        mov.push_back(mov2);
    }
    else if(this->PlayerType==wan_dou_type)
    {
        this->cost=100;
        this->attack=0;
        this->blood=1000;
        this->defend=200;
        QMovie*mov1=new QMovie;
        mov1->setFileName(QString(":/image/豌豆射手.gif"));
        mov.push_back(mov1);
    }
    else if(this->PlayerType==jian_guo_type)
    {
        this->cost=50;
        this->attack=10;
        this->blood=10000;
        this->defend=2000;
        QMovie*mov1=new QMovie;
        mov1->setFileName(QString(":/image/土豆.gif"));
        QMovie*mov2=new QMovie;
        mov2->setFileName(QString(":/image/WallNut1.gif"));
        QMovie*mov3=new QMovie;
        mov3->setFileName(QString(":/image/WallNut2.gif"));
        mov.push_back(mov1);
        mov.push_back(mov2);
        mov.push_back(mov3);
    }
    else if(this->PlayerType==nan_gua_type)
    {
        this->cost=125;
        this->attack=0;
        this->blood=8000;
        this->defend=2000;
        QMovie*mov1=new QMovie;
        mov1->setFileName(QString(":/image/Pumpkin.gif"));
        QMovie*mov2=new QMovie;
        mov2->setFileName(QString(":/image/Pumpkin1.gif"));
        QMovie*mov3=new QMovie;
        mov3->setFileName(QString(":/image/Pumpkin2.gif"));
        mov.push_back(mov1);
        mov.push_back(mov2);
        mov.push_back(mov3);
    }
    else if(this->PlayerType==xiang_ri_kui_type)
    {
        this->cost=50;
        this->attack=0;
        this->blood=1000;
        this->defend=200;
        QMovie*mov1=new QMovie;
        mov1->setFileName(QString(":/image/向日葵.gif"));
        mov.push_back(mov1);
    }
    else if(this->PlayerType==xian_ren_zhang_type)
    {
        this->cost=125;
        this->attack=0;
        this->blood=1000;
        this->defend=2000;
        QMovie*mov1=new QMovie;
        mov1->setFileName(QString(":/image/Cactus.gif"));
        QMovie*mov2=new QMovie;
        mov2->setFileName(QString(":/image/Cactus.gif"));
        mov.push_back(mov1);
        mov.push_back(mov2);
    }
    this->setPos(x,y);
}


void plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush;
    brush.setColor(QColor(255,0,0,255));
    painter->setBrush(brush);
    painter->drawRect(this->boundingRect());
}

QRectF plant::boundingRect() const
{
    qreal penWidth = 1;
    if(this->PlayerType==shi_ren_hua_type)
        return QRectF(0,0,200,100);
    else if(this->PlayerType==wan_dou_type ||this->PlayerType==xian_ren_zhang_type)
        return QRectF(0,0,1100-this->x,100);
    else
        return QRectF(0,0,100,100);
}
void plant::advance(int phase)
{
    if(this->PlayerType==wan_dou_type && (time%2==0 || time % 5==0))
    {
        QList<QGraphicsItem *> items = collidingItems();
        foreach (QGraphicsItem *item, items)
        {
            if (item->type() == enemy::Type)
            {
                enemy*all_1 = qgraphicsitem_cast<enemy*>(item);
                if(all_1->PlayerType!=fly_type)
                {
                    pea*we=new pea(this->x,this->y+35,zi_dan);
                    this->scene()->addItem(we);
                }
            }
        }
    }
    if(this->PlayerType==xian_ren_zhang_type && (time%2==0 || time % 5==0))
    {
        QList<QGraphicsItem *> items = collidingItems();
        foreach (QGraphicsItem *item, items)
        {
            if (item->type() == enemy::Type)
            {
                enemy*all_1 = qgraphicsitem_cast<enemy*>(item);
                if(all_1->PlayerType==fly_type)
                {
                    pea*we=new pea(this->x,this->y,ci);
                    this->scene()->addItem(we);
                }
            }
        }
    }
    if(this->PlayerType==xiang_ri_kui_type && (time%20==1 || time % 29==1))
    {
        sun*w=new sun(this->x,this->y,0);
        this->scene()->addItem(w);
    }
    if(this->PlayerType!=jian_guo_type && this->PlayerType!=nan_gua_type)
    {
        if(this->whether_meet==0)
        {

            p->clear();
            p->setFixedSize(100,100);
            p->setAttribute(Qt::WA_TranslucentBackground);
            this->p->setMovie(this->mov[0]);
            this->mov[0]->start();
            p->raise();
        }
        if(this->whether_meet==1)
        {
            if(this->PlayerType==shi_ren_hua_type ||this->PlayerType==xian_ren_zhang_type)
            {
                p->clear();
                p->setFixedSize(100,100);
                p->setAttribute(Qt::WA_TranslucentBackground);
                this->p->setMovie(this->mov[1]);
                this->mov[1]->start();
                p->raise();
            }
        }
    }
    else
    {
        if(this->PlayerType==nan_gua_type)
        {
            if(this->blood>100 &&this->blood<=200)
            {
                p->clear();
                p->setFixedSize(100,100);
                p->setAttribute(Qt::WA_TranslucentBackground);
                this->p->setMovie(this->mov[1]);
                this->mov[1]->start();
            }
            else if(this->blood<=300)
            {
                p->clear();
                p->setFixedSize(100,100);
                p->setAttribute(Qt::WA_TranslucentBackground);
                this->p->setMovie(this->mov[1]);
                this->mov[1]->start();
            }
            else
            {
                p->clear();
                p->setFixedSize(100,100);
                p->setAttribute(Qt::WA_TranslucentBackground);
                this->p->setMovie(this->mov[0]);
                this->mov[0]->start();
            }
            p->lower();
        }
        else if(this->PlayerType==jian_guo_type)
        {
            if(this->blood>100 &&this->blood<=1000)
            {
                p->clear();
                p->setFixedSize(100,100);
                p->setAttribute(Qt::WA_TranslucentBackground);
                this->p->setMovie(this->mov[2]);
                this->mov[2]->start();
            }
            else if(this->blood<=5000)
            {
                p->clear();
                p->setFixedSize(100,100);
                p->setAttribute(Qt::WA_TranslucentBackground);
                this->p->setMovie(this->mov[1]);
                this->mov[1]->start();
            }
            else
            {
                p->clear();
                p->setFixedSize(100,100);
                p->setAttribute(Qt::WA_TranslucentBackground);
                this->p->setMovie(this->mov[0]);
                this->mov[0]->start();
            }
        }
    }
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);
    if(proxy->widget()!=p)
        proxy->setWidget(p);
    if(this->blood<=0)
    {
        game_map::mood[this->x/100][this->y/100]=1;
        this->scene()->removeItem(this);
        this->deleteLater();
    }
    time++;
}
