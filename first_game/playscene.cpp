#include "playscene.h"

PlayScene::PlayScene(QWidget *parent)
    : QMainWindow{parent}
{

}

PlayScene::PlayScene(int _levelNum): levelIndex(_levelNum)
{
    // 总背景音效
    QSound* backgroundSound = new QSound(":/good/xue.wav", this);
    backgroundSound->play();

    // 翻图片音效
    QSound* flipSound = new QSound(":/good/seeyourmom.wav");
    // 胜利音效
    QSound* winSound = new QSound(":/good/zhiyin.wav");

    // 设置固定大小
    this->setFixedSize(768,1024);
    // 设置图标
    this->setWindowIcon(QIcon(":/good/1586707363346.jpeg"));
    // 设置标题
    this->setWindowTitle("依托答辩");

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

    // 返回按钮
    MyPushButton* backBtn = new MyPushButton(":/good/back.png", ":/good/back.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    // 点击返回
    connect(backBtn, &MyPushButton::clicked, [=](){
        // qDebug() << "click";
        // 告诉选关场景，返回，选关场景监听返回按钮
        QTimer::singleShot(200, this, [=](){
            emit this->playSceneBack();
            winSound->stop();
        });
    });

    // 左下角显示关卡
    QLabel* label = new QLabel(this);
    // 设置字体属性
    QFont font("Consolas", 20, 75);
    label->setFont(font);
    label->setText(QString("Level: ") + QString::number(this->levelIndex));
    label->setGeometry(30, this->height() - 100, 200, 100);

    // 初始化每个关卡的二维数组
    dataConfig config;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];

    // 胜利后图片的显示
    QLabel* winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/good/win.png");
    winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    // 已经加载好了，但是纵坐标为负数，界面中没有显示
    winLabel->move((this->width() - tmpPix.width()) * 0.5, -tmpPix.height());

    // 显示图片背景和实体，追加操作
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
//            QLabel* lab = new QLabel(this);
//            QPixmap pix = QPixmap(":/good/fan.png");
//            lab->setGeometry(0, 0, pix.width(), pix.height());
//            lab->setPixmap(pix);
//            lab->move(i * 50 + 100, j * 50 + 100);

            // 塞入图片
            QString str;
            if(this->gameArray[i][j] == 1)
                str = ":/good/zheng.jpg";
            else
                str = ":/good/fan.png";
            MyCoin* coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(i * 110 + (this->width() - 440) * 0.5, j * 110 + 300);

            // 给图片属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = gameArray[i][j];  // 1正面 0反面

            // 将图片放入对应二维数组
            this->coinBtn[i][j] = coin;

            // 监听事件：点击翻转
            connect(coin, &MyCoin::clicked, [=](){
                // 玉音放送
                flipSound->play();

                // 点击图片后将所有图片的点击功能都禁用
                // 防止因为手快卡bug
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        this->coinBtn[i][j]->isWin = true;

                coin->changeFlag();
                this->gameArray[i][j] = (this->gameArray[i][j] == 0) ? 1 : 0;

                // 翻转周围图片(上下左右)
                // 延迟翻转
                QTimer::singleShot(200, this, [=](){
                    // 下
                    if(coin->posX + 1 <= 3)
                    {
                        coinBtn[coin->posX + 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX + 1][coin->posY] = (this->gameArray[coin->posX + 1][coin->posY] == 0) ? 1 : 0;
                    }
                    // 左
                    if(coin->posY - 1 >= 0)
                    {
                        coinBtn[coin->posX][coin->posY - 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY - 1] = (this->gameArray[coin->posX][coin->posY - 1] == 0) ? 1 : 0;
                    }
                    // 上
                    if(coin->posX - 1 >= 0)
                    {
                        coinBtn[coin->posX - 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX - 1][coin->posY] = (this->gameArray[coin->posX - 1][coin->posY] == 0) ? 1 : 0;
                    }
                    // 右
                    if(coin->posY + 1 <= 3)
                    {
                        coinBtn[coin->posX][coin->posY + 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY + 1] = (this->gameArray[coin->posX][coin->posY + 1] == 0) ? 1 : 0;
                    }

                    // 翻转完成后，将所有图片的点击功能解禁用
                    for(int i = 0; i < 4; i++)
                        for(int j = 0; j < 4; j++)
                            this->coinBtn[i][j]->isWin = false;

                    // 一次完整的翻转后，判断是否胜利
                    this->isWin = true;
                    for(int i = 0; i < 4; i++)
                    {
                        for(int j = 0; j < 4; j++)
                            if(gameArray[i][j] == 0)
                            {
                                this->isWin = false;
                                break;
                            }
                    }
                    if(this->isWin == true)
                    {
                        // 胜利
                        // 玉音放送
                        backgroundSound->stop();
                        winSound->play();

                        // qDebug() << "win";
                        // 将所有按钮的胜利标志为true
                        for(int i = 0; i < 4; i++)
                            for(int j = 0; j < 4; j++)
                                coinBtn[i][j]->isWin = true;

                        // 移动胜利图片
                        QPropertyAnimation* animation = new QPropertyAnimation(winLabel, "geometry");
                        // 设置时间间隔
                        animation->setDuration(1000);
                        // 设置开始位置
                        animation->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
                        // 设置结束位置
                        animation->setEndValue(QRect(winLabel->x(), winLabel->y() + 284, winLabel->width(), winLabel->height()));
                        // 设置缓和曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);

                        animation->start();
                    }
                });
            });
        }
    }
}

void PlayScene::paintEvent(QPaintEvent* e)
{
    // 创建游戏背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/good/background.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    // 画小图标
    pix.load(":/good/playyourmom.png");
    painter.drawPixmap((this->width() - pix.width() * 0.4) * 0.48, 30, pix.width() * 0.4, pix.height() * 0.4, pix);
}
