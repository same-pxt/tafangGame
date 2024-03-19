#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include"mypushbutton.h"
#include "choose.h"
#include <QSound>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QSound *startSound;  //创建一个音乐播放器
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    mypushbutton*start=NULL;
    choose*choice=NULL;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
