#include "enemy.h"
#include "player.h"
#include <QMovie>
#include <QPixmap>
#include <QDebug>
#include<QTimer>
#include<QPainter>
#include<QBrush>
#include<QGraphicsProxyWidget>
#include "game_map.h"
#include "plant.h"
#include "enemy_pea.h"
#include "obstocal.h"
enemy::enemy(int x,int y,int Type)
{

    this->x=x;
    this->y=y;
    if(Type!=fly_type)
        this->setPos(x,y);
    else
        this->setPos(x,y-20);
    this->PlayerType=Type;
    this->enemy_mode=com;
    this->p=new QLabel;
    if(this->PlayerType!=fly_type)
    {
        QMovie*p_1=new QMovie;
        p_1->setFileName(QString(":/image/普通僵尸.gif"));//0 普通  1 吃   2 掉头   3 倒下   4 特殊   5特殊吃
        mov.push_back(p_1);
        QMovie*p_2=new QMovie;
        p_2->setFileName(QString(":/image/10.gif"));
        mov.push_back(p_2);

        QMovie*p_3=new QMovie;
        p_3->setFileName(QString(":/image/9.gif"));
        mov.push_back(p_3);

        QMovie*p_4=new QMovie;
        p_4->setFileName(QString(":/image/8.gif"));
        mov.push_back(p_4);
    }
    if(this->PlayerType==normal_enemy_type)
    {
        this->blood=1000;
        this->v=5;
        this->attack=30;
        this->defend=200;
    }
    else if(this->PlayerType==mid_enemy_type)
    {
        QMovie*p_5=new QMovie;
        p_5->setFileName(QString(":/image/帽子僵尸.gif"));
        mov.push_back(p_5);
        QMovie*p_6=new QMovie;
        p_6->setFileName(QString(":/image/帽子僵尸吃.gif"));
        mov.push_back(p_6);
        this->blood=1500;
        this->v=5;
        this->attack=30;
        this->defend=300;
    }
    else if(this->PlayerType==hard_enemy_type)
    {
        QMovie*p_1=new QMovie;
        p_1->setFileName(QString(":/image/铁桶僵尸.gif"));
        mov.push_back(p_1);
        QMovie*p_4=new QMovie;
        p_4->setFileName(QString(":/image/铁桶僵尸吃.gif"));
        mov.push_back(p_4);
        this->blood=2000;
        this->v=5;
        this->attack=50;
        this->defend=600;
    }    
    else if(this->PlayerType==fly_type)
    {
        this->attack=100;
        this->blood=800;
        this->v=5;
        QMovie*p_1=new QMovie;
        p_1->setFileName(QString(":/image/1.gif"));
        mov.push_back(p_1);
        QMovie*p_2=new QMovie;
        p_2->setFileName(QString(":/image/Die.gif"));
        mov.push_back(p_2);
        this->blood=2000;
        this->v=10;
        this->attack=40;
        this->defend=600;
        this->p->setFixedSize(10,10);
    }
}
void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush;
    brush.setColor(QColor(255,0,0,255));
    painter->setBrush(brush);
    painter->drawRect(this->boundingRect());
}

enemy::enemy(){}
QRectF enemy::boundingRect() const
{
    if(this->PlayerType!=fly_type)
        return QRectF(70,100,50,20);
    else
        return QRectF(20,20,50,20);
}

void enemy::advance(int phase)
{
    if(this->PlayerType==hard_enemy_type && plant::time%7==1)
    {
        enemy_pea*bull=new enemy_pea(this->x,this->y+50);
        this->scene()->addItem(bull);
    }
        p->setFixedSize(150,150);
        p->setAttribute(Qt::WA_TranslucentBackground);
        if(this->PlayerType!=fly_type)
        {
            bool no_pum=1;
            QList<QGraphicsItem *> items = collidingItems();
            bool flag=0;
            foreach (QGraphicsItem *item, items) {
                if(item->type() == obstocal::Type)
                {

                    if(this->y<=400)
                    {
                        this->y+=100;
                    }
                    else if(this->y>=100)
                    {
                        this->y-=100;
                    }
                }
                if (item->type() == plant::Type)
                {
                    plant*all_1 = qgraphicsitem_cast<plant*>(item);
                    if(all_1->PlayerType==nan_gua_type)
                    {
                        qDebug()<<"吃南瓜";
                        no_pum=0;
                        all_1->get_att(this->attack);
                        this->enemy_mode=eat;
                        //all_1->whether_meet=1;
                    }
                }
            }
            if(no_pum==1)
            {
                foreach (QGraphicsItem *item, items) {
                    if (item->type() == plant::Type)
                    {
                        plant*all_1 = qgraphicsitem_cast<plant*>(item);
                        connect(this,enemy::death,[=]{all_1->whether_meet=0;});
                        if(all_1->PlayerType!=shi_ren_hua_type && all_1->PlayerType!=wan_dou_type&&all_1->PlayerType!=xian_ren_zhang_type)
                        {
                            this->enemy_mode=eat;
                            flag=1;
                            all_1->whether_meet=1;
                            this->get_att(all_1->ret_att());
                            QLabel*we=new QLabel;
                            we->setText(QString::number(all_1->ret_att()));
                            this->scene()->addWidget(we);
                            we->move(this->x+50,this->y+30);
                            QTimer::singleShot(500,we,we->deleteLater);
                            all_1->get_att(this->ret_att());
                        }
                        else if(all_1->PlayerType==shi_ren_hua_type )
                        {
                            if(this->pos().x()-all_1->pos().x()<=40)
                            {
                                this->enemy_mode=eat;
                                flag=1;

                                all_1->get_att(this->ret_att());
                            }
                            all_1->whether_meet=1;
                            this->get_att(all_1->ret_att());
                            QLabel*we=new QLabel;
                            we->setText(QString::number(all_1->ret_att()));
                            this->scene()->addWidget(we);
                            we->move(this->x+50,this->y+30);
                            QTimer::singleShot(500,we,we->deleteLater);

                        }
                        else if(all_1->PlayerType==wan_dou_type ||all_1->PlayerType==xian_ren_zhang_type)
                        {
                            if(this->pos().x()-all_1->pos().x()<=40)
                            {
                                this->enemy_mode=eat;
                                flag=1;
                                all_1->get_att(this->ret_att());
                            }
                            all_1->whether_meet=1;
                        }
                        p->clear();
                        if(this->blood<70)
                        {
                            this->p->setMovie(this->mov[3]);
                            this->mov[3]->start();
                        }
                        else if(this->blood<100 && this->blood>=70)
                        {
                            this->p->setMovie(this->mov[2]);
                            this->mov[2]->start();
                        }
                        else if(this->blood<=1000 && this->blood>=100)
                        {
                            this->p->setMovie(this->mov[1]);
                            this->mov[1]->start();
                        }
                        else if(this->blood<=1500 && this->blood>1000)
                        {
                            this->p->setMovie(this->mov[5]);
                            this->mov[5]->start();
                        }
                        else if(this->blood<=2000 && this->blood>1500)
                        {
                            this->p->setMovie(this->mov[5]);
                            this->mov[5]->start();
                        }
                    }
                }
                if(flag==0 &&this->enemy_mode!=dead)
                {
                    this->enemy_mode=com;
                    if(this->blood<100)
                    {
                        this->p->setMovie(this->mov[3]);
                        this->mov[3]->start();
                    }
                    else if(this->blood<200 && this->blood>=100)
                    {
                        this->p->setMovie(this->mov[2]);
                        this->mov[2]->start();
                    }
                    else if(this->blood<=1000 && this->blood>=200)
                    {
                        this->p->setMovie(this->mov[0]);
                        this->mov[0]->start();
                    }
                    else if(this->blood<=1500 && this->blood>1000)
                    {
                        this->p->setMovie(this->mov[4]);
                        this->mov[4]->start();
                    }
                    else if(this->blood<=2000 && this->blood>1500)
                    {
                        this->p->setMovie(this->mov[4]);
                        this->mov[4]->start();
                    }
                }
            }
        }
        else
        {
            if(this->blood>200)
            {
                this->p->setMovie(this->mov[0]);
                this->mov[0]->start();
            }
            else if(this->blood<=200)
            {
                this->p->setMovie(this->mov[1]);
                this->mov[1]->start();
                QTimer::singleShot(1000,[=](){this->blood-=100;});
            }
        }
        QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);
        if(proxy->widget()!=p)
            proxy->setWidget(p);

        if(this->enemy_mode!=eat && this->enemy_mode!=dead)
        {
            this->x-=this->v;
            this->setPos(x,y);
        }
        if(this->blood<0)
        {
            this->enemy_mode=dead;
            emit this->death();
            this->scene()->removeItem(this);
            this->deleteLater();
        }
}
