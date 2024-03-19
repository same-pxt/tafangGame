#include "play_scene.h"
#include "game_map.h"
#include <QGraphicsView>
play_scene::play_scene(QWidget *parent) : QMainWindow(parent)
{
    //构建scene
    scene=new game_map(QString(":/txt/map.txt"));

    //显示view
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->setFixedSize(1200,800);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->show();
}
