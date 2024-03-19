#include "obstocal.h"
#include <QPainter>
#include <QImage>

obstocal::obstocal()
{
}


QRectF obstocal::boundingRect()const
{
    return QRectF(0,0,100,100);
}
void obstocal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush;
    brush.setColor(QColor(255,0,0,255));
    painter->setBrush(brush);
    painter->drawRect(this->boundingRect());
    painter->drawImage(QRectF(0,0,100,100),QImage(":/image/obs.jpg"));
}
