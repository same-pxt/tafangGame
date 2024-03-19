#ifndef SUN_H
#define SUN_H

#include <QObject>
#include <QObject>
#include <QGraphicsItem>
#include<QPixmap>
#include<QMovie>
#include <QLabel>
class sun : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    sun(int x,int y,int type);
    QLabel*p;
    int x;
    int y;
    int type;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void advance(int phase);
signals:

public slots:
};

#endif // SUN_H
