#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include<QPixmap>
#include<QMovie>
enum PlayerType{normal_enemy_type, mid_enemy_type,hard_enemy_type,fly_type,wan_dou_type,jian_guo_type,shi_ren_hua_type,xiang_ri_kui_type,xian_ren_zhang_type,nan_gua_type,zi_dan,ci,chan_zi_type,sun_type,obs_type};

class player:public QGraphicsItem
{
public:
    player();
    //基本属性：
    int PlayerType;
    int blood;
    int attack;
    int defend;
    int v;
    //位置
    int x;
    int y;
    //伤害

};

#endif // PLAYER_H
