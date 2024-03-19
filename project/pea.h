#ifndef PEA_H
#define PEA_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPixmap>
#include <QMovie>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <player.h>
class pea:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    pea(int x,int y,int type);
    int attack;
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

#endif // PEA_H
