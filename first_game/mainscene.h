#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QAction>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include <QSound>

#include "mypushbutton.h"
#include "chooselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    // 重写paintEvent事件，画背景图片
    void paintEvent(QPaintEvent*);

    ChooseLevelScene* chooseScene = nullptr;

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
