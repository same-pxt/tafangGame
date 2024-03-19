#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QString>
class mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    //explicit mypushbutton(QWidget *parent = 0);
    mypushbutton(QString normalimage,QString pressimage="");
    void zoom_up();
    void zoom_down();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QString normalimagepath;
    QString pressimagepath;

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
