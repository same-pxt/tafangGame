#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QAction>
#include<QPainter>
#include "mypushbutton.h"
#include "choose.h"
#include <QTimer>
#include <QSound>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //基础设置
    this->setWindowIcon(QPixmap(":/image/head.jpg"));
    this->setFixedSize(1200,800);
    this->setWindowTitle("塔防游戏");
    connect(ui->actionuit,&QAction::triggered,[=]{this->close();});

    start=new mypushbutton(QString(":/image/R-C.png"));
    start->setParent(this);
    start->move(this->width()*0.5-start->width()*0.5,this->height()*0.5);

    //音效设置
    startSound=new QSound(QString(":/image/游戏开始背景音乐.wav"));
    startSound->play();
    //选择页面

    connect(start,&mypushbutton::clicked,[=]{
            choice=new choose;
            QSound*new_sound=new QSound(QString(":/image/种植声.wav"));
            new_sound->play();

            //监听返回
            connect(choice,&choose::back1,this,[=]{
                choice->hide();
                this->show();
            });
            //延迟
            start->zoom_down();
            start->zoom_up();
            QTimer::singleShot(500,this,[=]{
                choice->show();
                choice->setGeometry(this->geometry());
                this->hide();
                this->startSound->stop();
            });
    });

}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/icon.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
