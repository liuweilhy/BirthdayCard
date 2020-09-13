#ifndef CARDSENCE_H
#define CARDSENCE_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsSvgItem>
#include <QSound>

class CardSence : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CardSence(QObject *parent = nullptr);

    // 设置文本
    void SetText(QString zhufu, QString date);

    // 音乐开关
    void Music(bool on = true);

protected:
    // 初始化
    void InitItem();

private:
    // 尺寸
    double width = 520.0;
    double height = 900.0;
    // 边框
    QGraphicsRectItem *itemRect;

    // 彩旗
    QGraphicsSvgItem *itemCaiqi1;
    QGraphicsSvgItem *itemCaiqi2;

    // 彩旗旁边的装饰
    QGraphicsSvgItem *itemZhuangshi1;
    QGraphicsSvgItem *itemZhuangshi2;

    // 生日快乐四个字
    QGraphicsPixmapItem *itemSheng;
    QGraphicsPixmapItem *itemRi;
    QGraphicsPixmapItem *itemKuai;
    QGraphicsPixmapItem *itemLe;

    // 头冠
    QGraphicsSvgItem *itemTouguan;
    // HAPPY BIRTHDAY
    QGraphicsPixmapItem *itemHappyBirthday;
    // 祝福语背景
    QGraphicsSvgItem *itemZhufuBack;
    // 祝福语
    QGraphicsSimpleTextItem *itemZhufu;
    // 日期
    QGraphicsSimpleTextItem *itemDate;
    // 蛋糕
    QGraphicsPixmapItem *itemCake;
    // 气球
    QGraphicsPixmapItem *itemQiqiu;

    // 音乐
    QSound *player;

signals:

};

#endif // CARDSENCE_H
