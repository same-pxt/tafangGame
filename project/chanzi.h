#ifndef CHANZI_H
#define CHANZI_H

#include <QGraphicsItem>
#include<QPixmap>
#include "player.h"
#include<QPointF>
#include "plant.h"
#include <QObject>
#include <QVector>
class chanzi:public QGraphicsItem,public QObject
{
public:
    chanzi(int x,int y);
    int x;
    int y;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    enum { Type = UserType + 3 };
    int type() const
    {
        return Type;
    }
    void advance(int phase);
};

#endif // CHANZI_H
