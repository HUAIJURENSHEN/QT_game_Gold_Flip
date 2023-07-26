#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QFont>
#include <QTimer>
#include <QSound>
#include "mypushbutton.h"
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    // 重写paintEvent事件
    void paintEvent(QPaintEvent*);

    // 游戏场景对象指针
    PlayScene* play = nullptr;
signals:

    // 自定义信号，表示返回主场景
    void chooseSceneBack();
};

#endif // CHOOSELEVELSCENE_H
