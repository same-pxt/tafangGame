#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include <QGraphicsItem>
#include <QLabel>
class shop : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit shop();
    QLabel*p=NULL;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void advance(int phase);
signals:

public slots:
};

#endif // SHOP_H
