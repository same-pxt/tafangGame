#include "game_map.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsItem>
#include "rectitem.h"
#include "myitem.h"
#include<QString>
#include <QFile>
#include<QVector>
#include "player.h"
#include "plant.h"
#include<QTimer>
#include <QDebug>
#include<QDebug>
#include <QLabel>
#include "enemy.h"
#include<QGraphicsProxyWidget>
#include<QList>
#include "obstocal.h"
#include "shop.h"
#include "choose.h"
#include <QSound>
MyItem* game_map::next_plant=NULL;
int game_map::mood[12][7]={1};
int game_map::sun_num=1000;
game_map::game_map(QString x)
{
    this->x=x;
    //绘制地图
    creat_map();
    //添加选项卡
    add_plant();
    //添加阳光
    shop*menu=new shop;
    this->addItem(menu);
    menu->setPos(600,600);
    //添加声音
    QSound*bac=new QSound(QString(":/image/游戏开始背景音乐.wav"));
    bac->play();
}
void game_map::creat_map()
{
    QFile file(this->x);
    QVector<QString>anses;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
           QString ans = file.readLine();
           anses.push_back(ans);
        }
        file.close();
    }
    for(int i=0;i<7;i++)
    {

        for(int j=0;j<12;j++)
        {
            if(anses[i][j]==QString("1"))
            {
                mood[j][i]=1;
                QPixmap*p=new QPixmap;
                p->load(QString(":/image/e.png"));
                QLabel*q=new QLabel;
                q->setPixmap(*p);
                q->setFixedSize(100,100);
                q->move(j*100,i*100);
                QGraphicsProxyWidget *proxy = this->addWidget(q);
                q->show();
            }
            else
            {
                mood[j][i]=0;
                QPixmap*p=new QPixmap;
                p->load(QString(":/image/soil.png"));
                QLabel*q=new QLabel;
                q->setPixmap(*p);
                q->setFixedSize(100,100);
                q->move(j*100,i*100);
                QGraphicsProxyWidget *proxy = this->addWidget(q);
                q->show();
            }
            if(anses[i][j]==QString("2"))
            {
                obstocal*p=new obstocal;
                mood[j][i]=0;
                p->setPos(j*100,i*100);
                this->addItem(p);
            }
        }
        mood[0][i]=0;
    }
}

void game_map::add_plant()
{
    MyItem*wan_dou=new MyItem(QString(":/image/豌豆卡片.png"));
    wan_dou->Type=wan_dou_type;
    wan_dou->setScale(0.8);
    this->addItem(wan_dou);
    wan_dou->setPos(0,110);
    MyItem*xiang_ri_kui=new MyItem(QString(":/image/向日葵卡片.png"));
    xiang_ri_kui->Type=xiang_ri_kui_type;
    xiang_ri_kui->setScale(0.8);
    this->addItem(xiang_ri_kui);
    xiang_ri_kui->setPos(0,240);
    MyItem*jian_guo=new MyItem(QString(":/image/土豆卡片.png"));
    jian_guo->Type=jian_guo_type;
    jian_guo->setScale(0.8);
    this->addItem(jian_guo);
    jian_guo->setPos(0,360);
    MyItem*shi_ri_hua=new MyItem(QString(":/image/食人花卡片.png"));
    shi_ri_hua->Type=shi_ren_hua_type;
    shi_ri_hua->setScale(0.8);
    this->addItem(shi_ri_hua);
    shi_ri_hua->setPos(0,0);
    MyItem*xian_ren_zhang=new MyItem(QString(":/image/3.png"));
    xian_ren_zhang->Type=xian_ren_zhang_type;
    xian_ren_zhang->setScale(0.8);
    this->addItem(xian_ren_zhang);
    shi_ri_hua->setPos(0,480);
    MyItem*nan_gua=new MyItem(QString(":/image/Card.png"));
    nan_gua->Type=nan_gua_type;
    nan_gua->setScale(0.8);
    this->addItem(nan_gua);
    nan_gua->setPos(0,590);
    MyItem*chanzi=new MyItem(QString(":/image/Shovel.png"));
    chanzi->Type=chan_zi_type;
    chanzi->setScale(0.8);
    this->addItem(chanzi);
    chanzi->setPos(300,620);
}



