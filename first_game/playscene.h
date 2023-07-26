#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <QPropertyAnimation>
#include <QSound>
#include <mypushbutton.h>
#include <mycoin.h>
#include <dataconfig.h>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    explicit PlayScene(int levelNum);
    int levelIndex;

    // 重写paintEvent事件
    void paintEvent(QPaintEvent*);

    // 二维数组维护每个关卡的具体数据
    int gameArray[4][4];

    // 二维数组维护所有图片所在的指针
    MyCoin* coinBtn[4][4];

    // 是否胜利的标识
    bool isWin = true;

signals:
    // 返回选关页面信号
    void playSceneBack();

};

#endif // PLAYSCENE_H
