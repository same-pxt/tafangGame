#ifndef OBSTOCAL_H
#define OBSTOCAL_H

#include <QObject>
#include <QGraphicsItem>
#include<QPixmap>
#include<QMovie>
class obstocal : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    obstocal();
    enum { Type = UserType + 6 };
    int type() const
    {
        return Type;
    }
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
signals:

public slots:
};

#endif // OBSTOCAL_H
