#include "mypushbutton.h"

#include "mypushbutton.h"
#include <QDebug>
#include<QPropertyAnimation>
mypushbutton::mypushbutton(QString normalimage,QString pressimage)
{
    this->normalimagepath=normalimage;
    this->pressimagepath=pressimage;
    QPixmap pix;
    bool ret=pix.load(normalimage);
    if(!ret)
    {
        qDebug()<<"wrong";
        return ;
    }
    this->setFixedSize(300,300);
    this->setStyleSheet("QPushButton{border-imag:url(normalimage)}");
    this->setStyleSheet("mypushbutton{background-image:url(normalimage)}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

}
void mypushbutton::zoom_up()
{
    QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void mypushbutton::zoom_down()
{
    QPropertyAnimation * animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}


void mypushbutton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressimagepath!="")
    {
        QPixmap pix;
        bool ret=pix.load(this->pressimagepath);
        if(!ret)
        {
            qDebug()<<"wrong";
            return ;
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));


    }
    return QPushButton::mousePressEvent(e);
}

void mypushbutton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressimagepath!="")
    {
        QPixmap pix;
        bool ret=pix.load(this->normalimagepath);
        if(!ret)
        {
            qDebug()<<"wrong";
            return ;
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}
