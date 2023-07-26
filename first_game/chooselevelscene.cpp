#include "chooselevelscene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    // 配置选择关卡场景
    // 设置固定大小
    this->setFixedSize(768,1024);
    // 设置图标
    this->setWindowIcon(QIcon(":/good/1586707363346.jpeg"));
    // 设置标题
    this->setWindowTitle("你翻尼玛呢~");

    // 补一个菜单栏
    QMenuBar* bar = menuBar();
    setMenuBar(bar);
    QMenu* startMenu = bar->addMenu("start");

    // 创建退出菜单项
    QAction* quitAction = startMenu->addAction("quit");
    // 点击退出
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    // 选择关卡音效
    QSound* chooseSound = new QSound(":/good/wa.wav", this);

    // 返回按钮音效
    QSound* backSound = new QSound(":/good/amagi.wav", this);

    // 关卡返回音效
    QSound* playbackSound = new QSound(":/good/playyourmom.wav", this);

    // 返回按钮
    MyPushButton* backBtn = new MyPushButton(":/good/back.png", ":/good/back.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    // 点击返回
    connect(backBtn, &MyPushButton::clicked, [=](){
        // qDebug() << "click";
        // 告诉主场景，返回，主场景监听返回按钮
        backSound->play();
        emit this->chooseSceneBack();
    });

    // 创建选择关卡按钮
    for(int i = 0; i < 20; i++)
    {
        // 设置按钮位置
        MyPushButton* menuBtn = new MyPushButton(":/good/level.png");
        menuBtn->setParent(this);
        menuBtn->move((i % 4) * 170 + 80, (i / 4) * 120 + 270);

        // 监听每个按钮的点击事件
        connect(menuBtn, &MyPushButton::clicked, [=](){
            // QString str = QString("clicked %1").arg(i + 1);
            // qDebug() << str;

            // 玉音放送
            chooseSound->play();

            // 跳转到某一关
            this->hide();
            play = new PlayScene(i + 1);
            play->show();

            // 设置游戏场景的初始位置
            play->setGeometry(this->geometry());

            // 监听关卡返回信号
            connect(play, &PlayScene::playSceneBack, this, [=](){
                playbackSound->play();
                this->setGeometry(play->geometry());
                this->show();
                delete play;
                play = nullptr;
            });
        });

        // 设置按钮上的文本
        // menuBtn->setText(QString::number(i+1));
        QLabel* label = new QLabel(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i + 1));
        label->move((i % 4) * 170 + 80, (i / 4) * 120 + 270);

        // 设置字体属性
        QFont font("Consolas", 13, 75);
        label->setFont(font);
        // 设置文本对齐方式
        label->setAlignment(Qt::AlignCenter);
        // label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        // 设置鼠标穿透label层，使得可以点到按钮
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/good/background.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    // 画小图标
    pix.load(":/good/seeyourmom.png");
    painter.drawPixmap((this->width() - pix.width() * 0.4) * 0.48, 30, pix.width() * 0.4, pix.height() * 0.4, pix);
}
