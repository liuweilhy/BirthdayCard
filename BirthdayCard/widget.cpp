#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QGraphicsView(parent)
{
    this->resize(524, 904);
    this->setWindowFlags(Qt::FramelessWindowHint);
    cardSence = new CardSence(this);
    this->setScene(cardSence);
    this->centerOn(0,0);
    this->setSceneRect(-260, -450, 520, 900);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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

