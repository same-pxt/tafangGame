#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsItem>
#include<QPixmap>
#include "player.h"
#include<QPointF>
#include "plant.h"
#include <QVector>
#include <QSound>
class MyItem : public QGraphicsItem
{
public:
    MyItem(QString path);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    int Type;
    static QPointF des;
    plant*tem;
    QLabel*mes=NULL;
    pea*p;
    QSound*warn;
    QSound*pla;
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void advance(int phase);
private:
    QPixmap pix;
    QString name;
    QString path;
};
#endif // MYITEM_H
