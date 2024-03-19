#include "choose.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QTimer>
#include "mypushbutton.h"
#include<QLabel>
#include <QFont>
#include "game_map.h"
#include "myitem.h"
#include <QTime>
#include <QDebug>
#include <QList>
#include <QSound>
#include <QGraphicsItem>
int choose::times=0;
bool choose::whe_win=0;
choose::choose(QWidget *parent) : QMainWindow(parent)
{
    //音效
    bac=new QSound(QString(":/image/游戏开始背景音乐.wav"));
    bac->play();
    //菜单栏
    QMenuBar*bar=menuBar();
    setMenuBar(bar);
    QMenu*start=bar->addMenu("菜单");
    QAction*quit=start->addAction("退出");
    connect(quit,&QAction::triggered,[=]{
        this->close();
    });
    this->setWindowIcon(QPixmap(":/image/head.jpg"));
    this->setFixedSize(1200,800);
    this->setWindowTitle("塔防游戏");

    //返回键:
    back=new mypushbutton(QString(":/image/OIP-C.jpg"),QString(":/image/260.jpg"));
    back->setParent(this);
    back->move(900,600);
    back->setFixedSize(200,200);
    connect(back,&mypushbutton::clicked,[=]
    {
        QTimer::singleShot(500,this,[=]{
            emit this->back1();
        });
    });


    //选择模式键：
    choose_level=new mypushbutton(QString(":/image/OIP-C (1).jpg"));
    choose_level->setParent(this);
    choose_level->move(400,400);
    choose_level->setFixedSize(200,100);
    connect(choose_level,&mypushbutton::clicked,[=]{
    this->hide();


    this->bac->stop();
    QSound*new_sound=new QSound(QString(":/image/种植声.wav"));
    new_sound->play();
    //进入游戏界面
    scene=new game_map(QString(":/txt/map.txt"));
    QTimer*timer=new QTimer;
    connect(this,&choose::stops,timer,QTimer::stop);
    connect(timer,QTimer::timeout,scene,scene->advance);
    connect(timer,QTimer::timeout,this,&choose::add_enemy);
    connect(timer,QTimer::timeout,this,&choose::check_win);
    timer->start(300);

    //显示view
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->setFixedSize(1200,800);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->show();
    });




    //设置快速开始按钮
    QLabel*qiuck_start=new QLabel;
    QFont quick;
    quick.setFamily("宋体");
    quick.setPointSize(30);
    qiuck_start->setText(QString("快速游戏"));
    qiuck_start->setFont(quick);
    qiuck_start->setParent(this);
    qiuck_start->setFixedSize(choose_level->width(),choose_level->height());
    qiuck_start->move(400,400);
    qiuck_start->setAttribute(Qt::WA_TransparentForMouseEvents);
}


void choose::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/back.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}


void choose::add_enemy()
{
   times++;
   if(times%10==0)
   {
       int m=(qrand()%5+1)*100-50;
       int who=qrand()%4;
       if(who!=3)
       {
           enemy*new_one=new enemy(1000,m,who);
           this->scene->addItem(new_one);
       }
       else
       {
           enemy*new_one=new enemy(1000,m+50,who);
           this->scene->addItem(new_one);
       }
   }
}

void choose::check_win()
{
    const QList<QGraphicsItem *> items = scene->items();
    foreach (QGraphicsItem *item, items)
    if (item->type() == enemy::Type && item->x() < 100)
    {
       enemy*all_1 = qgraphicsitem_cast<enemy*>(item);
       scene->addPixmap(QPixmap(":/image/失败.png"))->setPos(336, 92);
       choose::whe_win=1;
       emit stops();
    }
}
