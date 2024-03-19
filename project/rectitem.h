#ifndef RECTITEM_H
#define RECTITEM_H


#include <QGraphicsItem>
#include <QPixmap>
#include <QMovie>
#include "player.h"
class RectItem:public QGraphicsItem
{
public:
    RectItem(int x,int y,int type);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    int plant_type;
protected:

    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;

private:
        int x;
        int y;
        int type;
     QPixmap pix;
     QMovie*mov=NULL;
     bool dragOver;  //标志是否有拖动进入
};
#endif // RECTITEM_H
