#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //////////////////// 配置主场景 ////////////////////
    // 设置固定大小
    this->setFixedSize(768,1024);
    // 设置图标
    this->setWindowIcon(QIcon(":/good/1586707363346.jpeg"));
    // 设置标题
    this->setWindowTitle("依托答辩");

    // 退出按钮
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    // 准备开始按钮的音效
    QSound* startSound = new QSound(":/good/xian_1.wav", this);

    // 开始按钮
    MyPushButton* startBtn = new MyPushButton(":/good/start.png");
    startBtn->setParent(this);

    startBtn->move((this->width() - 40) * 0.5 - startBtn->width() * 0.48, this->height() * 0.75);

    // 实例化选择关卡场景
    chooseScene = new ChooseLevelScene;

    // 监听返回信号
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, this, [=](){
        // 延时返回
        QTimer::singleShot(200, this, [=](){
            // 设置自身位置
            this->setGeometry(chooseScene->geometry());
            // 自身隐藏
            chooseScene->hide();
            // 显示主场景
            this->show();
        });
    });

    connect(startBtn,&MyPushButton::clicked,[=](){
//        qDebug() << "clicked";
        // 玉音放送
        startSound->play();

        // 做一个特效，duang~
        startBtn->zoom1();
        startBtn->zoom2();

        // 延时操作
        QTimer::singleShot(500, this, [=](){
            // 设置chooseScene场景位置
            chooseScene->setGeometry(this->geometry());

            // 自身隐藏
            this->hide();
            // 显示选择关卡场景
            chooseScene->show();
        });
    });
}

void MainScene::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/good/background.jpg");
//    painter.drawPixmap(0, 0, pix);

    // 缩放
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    // 画小图标
    pix.load(":/good/seeyourmom.png");
    painter.drawPixmap(30, 50, 200, 100, pix);
}

MainScene::~MainScene()
{
    delete ui;
}

