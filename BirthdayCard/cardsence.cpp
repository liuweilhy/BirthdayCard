#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "cardsence.h"
#include <QLabel>
#include <QMovie>
#include <QTransform>
#include <QGraphicsLineItem>
#include <QState>
#include <QList>
#include <QSignalTransition>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QDebug>
#include "ObjectGraphicsItem.h"

CardSence::CardSence(QObject *parent) : QGraphicsScene(parent)
{
    this->setBackgroundBrush(QBrush(QColor(253, 225, 229)));


    // 初始化各个Item
    InitItem();

    // 播放音乐
    player = new QSound(":/music/resources/music.wav");
    Music(true);

    // 设置动画
    SetAnimations();
}

// 设置文本
void CardSence::SetText(QString zhufu, QString date)
{
    itemZhufu->setText(zhufu);
    itemDate->setText(date);
}

// 初始化Item
void CardSence::InitItem()
{
    // 中心十字标，仅检测用
    QGraphicsLineItem *lineX = new QGraphicsLineItem(-100, 0, 100, 0);
    QGraphicsLineItem *lineY = new QGraphicsLineItem(0, -100, 0, 100);
    lineX->setZValue(1000);
    lineY->setZValue(1000);

    // 初始幕布
    itemRect0 = new ObjectRectItem(-width, -height, width*2, height*2);
    itemRect0->setBrush(QColor(36,36,36));
    itemRect0->setZValue(999);
    itemRect0->setPos(0,0);

    // 白色幕布
    QPixmap imageWhite(":/image/resources/white.png");
    itemWhite1 = new ObjectPixmapItem(imageWhite);
    itemWhite1->setOffset(-imageWhite.width()/2, -imageWhite.height()/2);
    itemWhite1->setPos(-imageWhite.width()/2, 0);
    itemWhite1->setZValue(998);
    itemWhite2 = new ObjectPixmapItem(imageWhite);
    itemWhite2->setOffset(-imageWhite.width()/2, -imageWhite.height()/2);
    itemWhite2->setPos(imageWhite.width()/2, 0);
    itemWhite2->setZValue(997);


    // 雪花背景
    backgroundLabel = new QLabel();
    backgroundLabel->setAttribute(Qt::WA_TranslucentBackground, true);
    QMovie *movie = new QMovie(":/image/resources/xuehua.gif");
    backgroundLabel->setMovie(movie);
    backgroundLabel->setGeometry(-width/2,-height/2, width, height);
    movie->setScaledSize(backgroundLabel->size());
    movie->start();
    this->addWidget(backgroundLabel);


    // 边框
    itemRect = new ObjectRectItem(-width/2+20, -height/2, width-40, height);
    itemRect->setPen(QPen(QColor(247,184,193), 10));
    itemRect->setPos(0,0);

    // 彩旗
    itemCaiqi1 = new ObjectSvgItem(":/image/resources/caiqi.svg");
    QTransform transformCaiqi1;
    transformCaiqi1.translate(112, -150);
    transformCaiqi1.scale(-2.5, 2.5);
    itemCaiqi1->setTransform(transformCaiqi1);
    itemCaiqi1->setPos(0,-500);
    //itemCaiqi1->setPos(0,-400);

    itemCaiqi2 = new ObjectSvgItem(":/image/resources/caiqi.svg");
    QTransform transformCaiqi2;
    transformCaiqi2.translate(-112, -150);
    transformCaiqi2.scale(2.5, 2.5);
    itemCaiqi2->setTransform(transformCaiqi2);
    itemCaiqi2->setPos(0,-512);
    //itemCaiqi2->setPos(0,-412);

    // 装饰
    itemZhuangshi1 = new ObjectSvgItem(":/image/resources/zhuagnshi1.svg");
    QTransform transformZhuangshi1;
    transformZhuangshi1.translate(-250, -0);
    transformZhuangshi1.scale(2.5, 1.5);
    itemZhuangshi1->setTransform(transformZhuangshi1);
    itemZhuangshi1->setPos(0,-510);

    itemZhuangshi2 = new ObjectSvgItem(":/image/resources/zhuagnshi2.svg");
    itemZhuangshi2->setTransform(transformZhuangshi1);
    itemZhuangshi2->setPos(0,-510);


    // 生日快乐的图标
    QPixmap imageSheng(":/image/resources/sheng.png");
    itemSheng = new ObjectPixmapItem(imageSheng);
    itemSheng->setOffset(-imageSheng.width()/2, -imageSheng.height()/2);
    itemSheng->setScale(0.001);
    //itemSheng->setScale(0.8);
    itemSheng->setPos(-160,-260);

    QPixmap imageRi(":/image/resources/ri.png");
    itemRi = new ObjectPixmapItem(imageRi);
    itemRi->setOffset(-imageRi.width()/2, -imageRi.height()/2);
    itemRi->setScale(0.001);
    //itemRi->setScale(0.8);
    itemRi->setPos(-60,-270);

    QPixmap imageKuai(":/image/resources/kuai.png");
    itemKuai = new ObjectPixmapItem(imageKuai);
    itemKuai->setOffset(-imageKuai.width()/2, -imageKuai.height()/2);
    itemKuai->setScale(0.001);
    //itemKuai->setScale(0.8);
    itemKuai->setPos(60,-280);

    QPixmap imageLe(":/image/resources/le.png");
    itemLe = new ObjectPixmapItem(imageLe);
    itemLe->setOffset(-imageLe.width()/2, -imageLe.height()/2);
    itemLe->setScale(0.001);
    //itemLe->setScale(0.8);
    itemLe->setPos(180,-260);

    // Happy Birthday的图标
    QPixmap imageHappy(":/image/resources/HAPPYBIRTHDAY.png");
    itemHappyBirthday = new ObjectPixmapItem(imageHappy);
    itemHappyBirthday->setOffset(-imageHappy.width()/2, -imageHappy.height()/2);
    itemHappyBirthday->setScale(0.001);
    //itemHappyBirthday->setScale(0.8);
    itemHappyBirthday->setPos(0,-160);

    // 头冠
    itemTouguan = new ObjectSvgItem(":/image/resources/touguan.svg");
    QTransform transformTouguan;
    transformTouguan.translate(-120, -100);
    transformTouguan.scale(1.2, 0.8);
    itemTouguan->setTransform(transformTouguan);
    itemTouguan->setScale(0.001);
    itemTouguan->setPos(0,0);

    // 祝福语背景
    itemZhufuBack = new ObjectSvgItem(":/image/resources/zhufu.svg");
    QTransform transformHappy;
    transformHappy.translate(-210, -40);
    transformHappy.scale(2.0, 1.5);
    itemZhufuBack->setTransform(transformHappy);
    itemZhufuBack->setPos(-800,84);
    //itemZhufuBack->setPos(0,84);

    // 祝福
    itemZhufu = new ObjectSimpleTextItem("诚邀参加XXX小朋友十岁生日宴会");
    itemZhufu->setFont(QFont("楷体", 14));
    itemZhufu->setBrush(QColor(240,96,120));
    itemZhufu->setPos(980,65);
    //itemZhufu->setPos(-180,65);

    // 日期
    itemDate = new ObjectSimpleTextItem("{2020.9.12}");
    itemDate->setFont(QFont("微软雅黑", 16));
    itemDate->setBrush(QColor(240,96,120));
    itemDate->setPos(-70,110);
    itemDate->setScale(0.001);

    // 蛋糕
    QPixmap imageCake(":/image/resources/cake.png");
    itemCake = new ObjectPixmapItem(imageCake);
    itemCake->setOffset(-imageCake.width()/2, -imageCake.height()/2);
    itemCake->setScale(0.0001);
    //itemCake->setScale(0.36);
    itemCake->setPos(0,270);

    // 气球
    QPixmap imageQiqiu(":/image/resources/qiqiu.png");
    itemQiqiu = new ObjectPixmapItem(imageQiqiu);
    itemQiqiu->setOffset(-imageQiqiu.width()/2, -imageQiqiu.height()/2);
    itemQiqiu->setScale(0.12);
    itemQiqiu->setPos(220,970);
    //itemQiqiu->setPos(220,270);


    // 添加图元
    //this->addItem(lineX);
    //this->addItem(lineY);
    //this->addItem(itemRect0);
    this->addItem(itemWhite1);
    this->addItem(itemWhite2);
    this->addItem(itemRect);
    this->addItem(itemCaiqi1);
    this->addItem(itemCaiqi2);
    this->addItem(itemZhuangshi1);
    this->addItem(itemZhuangshi2);
    this->addItem(itemSheng);
    this->addItem(itemRi);
    this->addItem(itemKuai);
    this->addItem(itemLe);
    this->addItem(itemHappyBirthday);
    this->addItem(itemTouguan);
    this->addItem(itemZhufuBack);
    this->addItem(itemZhufu);
    this->addItem(itemDate);
    this->addItem(itemCake);
    this->addItem(itemQiqiu);
}

void CardSence::Music(bool on)
{
    if (on)
    {
        player->play();
        player->setLoops(-1);
    }
    else
        player->stop();
}

void CardSence::SetAnimations()
{
    itemZhuangshi1->setScale(100);
    itemZhuangshi2->setScale(100);

    // 关门
    QPixmap imageWhite(":/image/resources/white.png");
    //初始化Animation对象，指定要动画的属性
    QPropertyAnimation *animation0 = new QPropertyAnimation(itemWhite1, "pos");
    //设定持续时间，单位为毫秒
    animation0->setDuration(1000);
    //设定初始值
    animation0->setStartValue(QPointF(-imageWhite.width(),0));
    //设定结束值
    animation0->setEndValue(QPointF(-imageWhite.width()/2,0));

    QPropertyAnimation *animation1 = new QPropertyAnimation(itemWhite2, "pos");
    animation1->setDuration(1000);
    animation1->setStartValue(QPointF(imageWhite.width(),0));
    animation1->setEndValue(QPointF(imageWhite.width()/2,0));

    QParallelAnimationGroup *animationGroup1 = new QParallelAnimationGroup(this);
    animationGroup1->addAnimation(animation0);
    animationGroup1->addAnimation(animation1);

    // 开门
    QPropertyAnimation *animation2 = new QPropertyAnimation(itemWhite1, "pos");
    animation2->setDuration(700);
    animation2->setStartValue(QPointF(-imageWhite.width()/2,0));
    animation2->setEndValue(QPointF(-imageWhite.width(),0));
    QPropertyAnimation *animation3 = new QPropertyAnimation(itemWhite2, "pos");
    animation3->setDuration(700);
    animation3->setStartValue(QPointF(imageWhite.width()/2,0));
    animation3->setEndValue(QPointF(imageWhite.width(),0));
    QParallelAnimationGroup *animationGroup2 = new QParallelAnimationGroup(this);
    animationGroup2->addAnimation(animation2);
    animationGroup2->addAnimation(animation3);

    // 装饰、Happy Birthday、蛋糕出现
    QPropertyAnimation *animation30 = new QPropertyAnimation(itemZhuangshi1, "scale");
    animation30->setDuration(600);
    animation30->setStartValue(2);
    animation30->setEndValue(1);
    QPropertyAnimation *animation31 = new QPropertyAnimation(itemZhuangshi2, "scale");
    animation31->setDuration(600);
    animation31->setStartValue(2);
    animation31->setEndValue(1);
    QPropertyAnimation *animation32 = new QPropertyAnimation(itemHappyBirthday, "scale");
    animation32->setDuration(1000);
    animation32->setStartValue(0.01);
    animation32->setEndValue(0.8);
    QPropertyAnimation *animation33 = new QPropertyAnimation(itemCake, "scale");
    animation33->setDuration(1000);
    animation33->setStartValue(0.01);
    animation33->setEndValue(0.36);


    QParallelAnimationGroup *animationGroup3 = new QParallelAnimationGroup(this);
    animationGroup3->addAnimation(animation30);
    animationGroup3->addAnimation(animation31);
    animationGroup3->addAnimation(animation32);
    animationGroup3->addAnimation(animation33);


    // 彩旗、气球、头冠
    QPropertyAnimation *animation40 = new QPropertyAnimation(itemCaiqi1, "pos");
    animation40->setDuration(1000);
    animation40->setStartValue(QPointF(0,-450));
    animation40->setEndValue(QPointF(0,-400));
    QPropertyAnimation *animation41 = new QPropertyAnimation(itemCaiqi2, "pos");
    animation41->setDuration(1000);
    animation41->setStartValue(QPointF(0,-462));
    animation41->setEndValue(QPointF(0,-412));
    QPropertyAnimation *animation42 = new QPropertyAnimation(itemQiqiu, "pos");
    animation42->setDuration(1000);
    animation42->setStartValue(QPointF(220,670));
    animation42->setEndValue(QPointF(220,270));
    QPropertyAnimation *animation43 = new QPropertyAnimation(itemTouguan, "scale");
    animation43->setDuration(1000);
    animation43->setStartValue(0.001);
    animation43->setEndValue(1);


    QParallelAnimationGroup *animationGroup4 = new QParallelAnimationGroup(this);
    animationGroup4->addAnimation(animation40);
    animationGroup4->addAnimation(animation41);
    animationGroup4->addAnimation(animation42);
    animationGroup4->addAnimation(animation43);

    // 生日快乐、祝福、日期
    QPropertyAnimation *animation50 = new QPropertyAnimation(itemZhufuBack, "pos");
    animation50->setDuration(1000);
    animation50->setStartValue(QPointF(-500,84));
    animation50->setEndValue(QPointF(0,84));
    QPropertyAnimation *animation51 = new QPropertyAnimation(itemZhufu, "pos");
    animation51->setDuration(1000);
    animation51->setStartValue(QPointF(400,65));
    animation51->setEndValue(QPointF(-180,65));
    QPropertyAnimation *animation52 = new QPropertyAnimation(itemDate, "scale");
    animation52->setDuration(1000);
    animation52->setStartValue(0.001);
    animation52->setEndValue(1);
    QPropertyAnimation *animation53 = new QPropertyAnimation(itemSheng, "scale");
    animation53->setDuration(1000);
    animation53->setStartValue(0.001);
    animation53->setEndValue(0.8);
    QPropertyAnimation *animation54 = new QPropertyAnimation(itemRi, "scale");
    animation54->setDuration(1000);
    animation54->setStartValue(0.001);
    animation54->setEndValue(0.8);
    QPropertyAnimation *animation55 = new QPropertyAnimation(itemKuai, "scale");
    animation55->setDuration(1000);
    animation55->setStartValue(0.001);
    animation55->setEndValue(0.8);
    QPropertyAnimation *animation56 = new QPropertyAnimation(itemLe, "scale");
    animation56->setDuration(1000);
    animation56->setStartValue(0.001);
    animation56->setEndValue(0.8);


    QParallelAnimationGroup *animationGroup5 = new QParallelAnimationGroup(this);
    animationGroup4->addAnimation(animation50);
    animationGroup4->addAnimation(animation51);
    animationGroup4->addAnimation(animation52);
    animationGroup4->addAnimation(animation53);
    animationGroup4->addAnimation(animation54);
    animationGroup4->addAnimation(animation55);
    animationGroup4->addAnimation(animation56);

    // 主动画组
    QSequentialAnimationGroup *mainAnimationGroup = new QSequentialAnimationGroup(this);
    mainAnimationGroup->addAnimation(animationGroup1);
    mainAnimationGroup->addAnimation(animationGroup2);
    mainAnimationGroup->addAnimation(animationGroup3);
    mainAnimationGroup->addAnimation(animationGroup4);
    mainAnimationGroup->addAnimation(animationGroup5);

    //启动动画
    mainAnimationGroup->start();
    qDebug("Fuck");
}
