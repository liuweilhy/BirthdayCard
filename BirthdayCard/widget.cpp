#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QGraphicsView(parent)
{
    // 设置大小
    this->resize(524, 904);
    // 无标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 设置场景
    cardSence = new CardSence(this);
    this->setScene(cardSence);
    this->centerOn(0,0);
    this->setSceneRect(-260, -450, 520, 900);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 如下修改显示信息
    QString str1 = "诚邀参加XXX小朋友十岁生日宴会";
    QString str2 = "{2020.9.12}";
    cardSence->SetText(str1, str2);
}

Widget::~Widget()
{
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Escape:
        close();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

