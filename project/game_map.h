#ifndef GAME_MAP_H
#define GAME_MAP_H

#include<QGraphicsScene>
#include<QGraphicsView>
#include "rectitem.h"
#include<QString>
#include"plant.h"
#include "myitem.h"
#include<QVector>
#include "enemy.h"
#include<QTimerEvent>
#include <QDebug>
#include "shop.h"
#include <QSound>
class game_map:public QGraphicsScene
{
public:
    QString x;
    game_map(QString x);
    //函数
    void creat_map();
    void add_plant();  
    void add_enemy();
    //vector储存
    QVector<MyItem*>map_floor;
    QVector<plant*>all_plant;
    QVector<enemy*>all_enemy;
    static MyItem*next_plant;
    static int mood[12][7];
    //阳光
    static int sun_num;
    shop*menu;
    //音效
    QSound*de;
    QSound*bac;
};

#endif // GAME_MAP_H
