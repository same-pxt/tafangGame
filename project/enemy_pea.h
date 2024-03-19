#ifndef ENEMY_PEA_H
#define ENEMY_PEA_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPixmap>
#include <QMovie>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <player.h>
class enemy_pea:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    enemy_pea(int x,int y);
    int attack=30;
    QPixmap*pix;
    QMovie*mov;
    QLabel*p;
    int x;
    int y;
    int PlayerType;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void bye();
    QRectF boundingRect() const override;
signals:
    void ov();
public slots:
};


#endif // ENEMY_PEA_H
