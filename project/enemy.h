#ifndef ENEMY_H
#define ENEMY_H
#include<QGraphicsDropShadowEffect>
#include <QObject>
#include "player.h"
#include <QVector>
#include<QMovie>
#include<QLabel>
enum enemy_mode{com,eat,hurt,dead};
class enemy : public QObject,public player
{
    Q_OBJECT
public:
    enemy(int x,int y,int Type);
    enemy();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QVector<QMovie*>mov;
    QLabel*p=NULL;
    void pross();
    void remove_dead();
    int enemy_mode;
    //函数
    QRectF boundingRect() const override;
    bool judge();
    void advance(int phase);
    void bye(){delete this;}
    void get_att(int x)
    {
        this->blood-=x;

    }
    int  ret_att(){return this->attack;}
    enum { Type = UserType + 2 };
    int type() const
    {
        return Type;
    }

signals:
    void death();
public slots:
};

#endif // ENEMY_H
