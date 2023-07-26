#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include <QMouseEvent>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyCoin(QWidget *parent = nullptr);

    // 参数代表传入的图片正反面
    MyCoin(QString btnImg);

    // 追加图片属性
    int posX; // x坐标
    int posY; // y坐标
    bool flag; // 标识正反
    bool isAnimation = false; // 是否正在执行动画

    // 翻面
    void changeFlag();
    QTimer* timer1; // 正->反 定时器
    QTimer* timer2; // 反->正 定时器

    QString zheng = "zheng.jpg";
    QString fan = "fan.png";

    // 重写 按下 动作
    void mousePressEvent(QMouseEvent*);

    // 是否胜利的标识
    bool isWin = false;

signals:

};

#endif // MYCOIN_H
