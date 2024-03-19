#ifndef PLAY_SCENE_H
#define PLAY_SCENE_H

#include <QMainWindow>
#include <QGraphicsView>
#include "game_map.h"

class play_scene : public QMainWindow
{
    Q_OBJECT
public:
    explicit play_scene(QWidget *parent = 0);
    game_map *scene;
    QGraphicsView *view;
signals:

public slots:
};

#endif // PLAY_SCENE_H
