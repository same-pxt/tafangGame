#ifndef CHOOSE_H
#define CHOOSE_H

#include <QMainWindow>
#include <QPainter>
#include "mypushbutton.h"
#include "game_map.h"
#include "play_scene.h"
#include <QSound>
class choose : public QMainWindow
{
    Q_OBJECT
public:
    static int times;
    explicit choose(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    mypushbutton*choose_level=NULL;
    mypushbutton*back=NULL;
    game_map *scene=NULL;
    QGraphicsView *view=NULL;
    void add_enemy();
    void check_win();
    QTimer*timer=NULL;
    QSound*bac;
    enemy*new_one;
    static bool whe_win;
signals:
    void back1();
    void stops();
public slots:
};

#endif // CHOOSE_H
