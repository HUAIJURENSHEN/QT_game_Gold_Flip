#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QSize>
#include <QDebug>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QPainter>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyPushButton(QWidget *parent = nullptr);
    // 构造函数，两个参数分别表示正常显示和按下后显示的图片路径
    MyPushButton(QString normalImg, QString pressImg = "");

    // 成员路径，保存用户传入图片路径
    QString normalImgPath;
    QString pressImgPath;

    // 弹跳特效
    void zoom1();  // 向下跳
    void zoom2();  // 向上跳

    // 重写鼠标按下和释放事件
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

signals:

};

#endif // MYPUSHBUTTON_H
