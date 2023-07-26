#include "mycoin.h"
#include "qdebug.h"

//MyCoin::MyCoin(QWidget *parent)
//    : QPushButton{parent}
//{

//}

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)
    {
        qDebug() << "fail load";
        return;
    }
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    // 初始化定时器对象
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    // 监听翻转事件
    // 正->反
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/good/%1").arg(this->fan);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        timer1->stop();
        this->isAnimation = false;
    });

    // 反->正
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/good/%1").arg(this->zheng);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        timer2->stop();
        this->isAnimation = false;
    });

}

// 翻面
void MyCoin::changeFlag()
{
    if(this->flag == true)
    {
        timer1->start(50);
        this->isAnimation = true;
        this->flag = false;
    }
    else
    {
        timer2->start(50);
        this->isAnimation = true;
        this->flag = true;
    }
}

// 不允许在动画执行中对该图片再次翻面
// 不允许在游戏胜利后进行翻面
void MyCoin::mousePressEvent(QMouseEvent* e)
{
    if(this->isAnimation || this->isWin)
        return;
    else
        return QPushButton::mousePressEvent(e);
}



