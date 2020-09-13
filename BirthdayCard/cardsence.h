#ifndef CARDSENCE_H
#define CARDSENCE_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QLabel>
#include <QSound>
#include <QStateMachine>
#include "ObjectGraphicsItem.h"

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

    // 动画
    void SetAnimations();

private:
    // 场景尺寸
    double width = 520.0;
    double height = 900.0;

    // 初始幕布
    ObjectRectItem *itemRect0;

    // 白色幕布
    ObjectPixmapItem *itemWhite1;
    ObjectPixmapItem *itemWhite2;

    // 边框
    ObjectRectItem *itemRect;

    // 背景（用QLabel是为了支持gif动画）
    QLabel *backgroundLabel;

    // 彩旗
    ObjectSvgItem *itemCaiqi1;
    ObjectSvgItem *itemCaiqi2;

    // 彩旗旁边的装饰
    ObjectSvgItem *itemZhuangshi1;
    ObjectSvgItem *itemZhuangshi2;

    // 生日快乐四个字
    ObjectPixmapItem *itemSheng;
    ObjectPixmapItem *itemRi;
    ObjectPixmapItem *itemKuai;
    ObjectPixmapItem *itemLe;

    // 头冠
    ObjectSvgItem *itemTouguan;
    // HAPPY BIRTHDAY
    ObjectPixmapItem *itemHappyBirthday;
    // 祝福语背景
    ObjectSvgItem *itemZhufuBack;
    // 祝福语
    ObjectSimpleTextItem *itemZhufu;
    // 日期
    ObjectSimpleTextItem *itemDate;
    // 蛋糕
    ObjectPixmapItem *itemCake;
    // 气球
    ObjectPixmapItem *itemQiqiu;

    // 音乐
    QSound *player;


    // 动画状态机
    QStateMachine machine;

signals:

};

#endif // CARDSENCE_H
