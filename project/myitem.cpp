#include "myitem.h"
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
#include "plant.h"
#include<QTimer>
#include <QDebug>
#include "game_map.h"
#include "chanzi.h"
QPointF MyItem::des;
MyItem::MyItem(QString path)
{
    this->warn=new QSound(QString(":/image/操作系统 _ Alert6_Freesound.wav"));
    this->pla=new QSound(QString(":/image/种植声.wav"));
    setAcceptHoverEvents(true);
    setFlag(MyItem::ItemIsMovable);
    this->path=path;
    setToolTip(this->name);
    setCursor(Qt::OpenHandCursor);    //改变光标形状,光标变为了手型
}

QRectF MyItem::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush;
    brush.setColor(QColor(255,0,0,255));
    painter->setBrush(brush);
    painter->drawRect(this->boundingRect());
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(0,0,QPixmap(this->path));
}
void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->des=event->scenePos();
    int new_x=(int((this->des.rx())/100))*100;
    int new_y=(int((this->des.ry())/100))*100;
    if(game_map::mood[new_y/100][new_x/100]!=0 || this->Type==nan_gua_type || this->Type==chan_zi_type)
    {
        game_map::next_plant=this;
        this->pla->play();
        QTimer::singleShot(500,[=]{this->pla->stop();});
    }
    else if(game_map::mood[new_y/100][new_x/100]==0)
    {
        game_map::next_plant=NULL;
        this->warn->play();
        QTimer::singleShot(500,[=]{this->warn->stop();});
    }

    setCursor(Qt::OpenHandCursor);
}
void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event->accept();
    if(Qt::LeftButton != event->button())
    {
        event->ignore();
        return;
    }
    setCursor(Qt::ClosedHandCursor);
}
void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    game_map::next_plant=this;
    if(QLineF(event->screenPos(),event->buttonDownScenePos(Qt::LeftButton)).length() < QApplication::startDragDistance())
    {
        return;
    }
}
void MyItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QLabel*mes=new QLabel;
        plant*temw=new plant(1,1,this->Type);
        mes->setText("血量："+QString::number(temw->blood));
        mes->move(event->scenePos().x(),event->scenePos().y());
        this->scene()->addWidget(mes);
        temw->deleteLater();
        QTimer::singleShot(1000,mes,mes->deleteLater);

}

void MyItem::advance(int phase)
{
    if(game_map::next_plant!=NULL )
    {
        int new_x=(int((this->des.rx())/100))*100;
        int new_y=(int((this->des.ry())/100))*100;
        if(game_map::mood[new_x/100][new_y/100]!=0 || game_map::next_plant->Type==nan_gua_type)
        {
            if(game_map::next_plant->Type!=chan_zi_type)
            {
                plant*tem=new plant(new_x,new_y,game_map::next_plant->Type);
                if(game_map::sun_num>=tem->cost)
                {
                    this->scene()->addItem(tem);
                    game_map::mood[new_x/100][new_y/100]=0;
                    game_map::sun_num-=tem->cost;
                }
                else
                {
                    this->warn->play();
                    QTimer::singleShot(500,[=]{this->warn->stop();});
                    tem->deleteLater();
                }
                game_map::next_plant=NULL;
            }
        }
        else
        {
            if(game_map::next_plant->Type==chan_zi_type)
            {
                chanzi*tep=new chanzi(new_x,new_y);
                this->scene()->addItem(tep);
                game_map::mood[new_x/100][new_y/100]=1;
            }
            game_map::next_plant=NULL;
        }
    }
}
