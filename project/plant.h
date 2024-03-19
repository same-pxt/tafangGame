#ifndef PLANT_H
#define PLANT_H

#include <QObject>
#include"player.h"
#include<QLabel>
#include "pea.h"
#include <QVector>
class plant : public QObject,public player
{
    Q_OBJECT
public:
    plant(int x,int y,int type);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int cost;
    bool whether_meet;
    void bye(){delete this;}
    void advance(int phase);
    enum { Type = UserType + 1 };
    int type() const
    {
        return Type;
    }
    static int time;
    void get_att(int x){this->blood-=x;}
    int  ret_att(){return this->attack;}
    QRectF boundingRect() const override;
signals:
    void death();
private:
    bool dragOver;
    QPixmap*pix;
    QVector<QMovie*>mov;
    QLabel*p=NULL;

signals:

public slots:
};

#endif // PLANT_H
