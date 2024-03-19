#include "chanzi.h"
#include<QPixmap>
#include <QPainter>
#include <QWidget>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QList>
#include "plant.h"
#include<QTimer>
#include "game_map.h"
chanzi::chanzi(int x,int y)
{
    this->x=x;
    this->y=y;
    this->setPos(x,y);
}
QRectF chanzi::boundingRect() const
{
    return QRectF(0,0,80,80);
}

void chanzi::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush;
    brush.setColor(QColor(255,0,0,255));
    painter->setBrush(brush);
    painter->drawRect(this->boundingRect());
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
void chanzi::advance(int phase)
{
    QList<QGraphicsItem *> items = collidingItems();
    foreach (QGraphicsItem *item, items) {
        if (item->type() == plant::Type)
        {
            plant*all_1 = qgraphicsitem_cast<plant*>(item);
            if(all_1->PlayerType!=wan_dou_type && all_1->PlayerType!=xian_ren_zhang_type)
            {
                all_1->scene()->removeItem(all_1);
                all_1=NULL;
                all_1->deleteLater();
            }
            else
            {
                if(this->x-all_1->x<=40)
                {
                    all_1->scene()->removeItem(all_1);
                    all_1=NULL;
                    all_1->deleteLater();
                }
            }
        }

    }
    this->scene()->removeItem(this);
    this->deleteLater();
}
