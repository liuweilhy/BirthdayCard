#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "cardsence.h"
#include <QLabel>
#include <QMovie>
#include <QTransform>
#include <QGraphicsLineItem>

CardSence::CardSence(QObject *parent) : QGraphicsScene(parent)
{
    this->setBackgroundBrush(QBrush(QColor(253, 225, 229)));


    // 初始化各个Item
    InitItem();
    // 播放音乐
    player = new QSound(":/music/resources/music.wav");
    Music(true);
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


    // 雪花背景
    QLabel *label = new QLabel();
    label->setAttribute(Qt::WA_TranslucentBackground, true);
    QMovie *movie = new QMovie(":/image/resources/xuehua.gif");
    label->setMovie(movie);
    label->setGeometry(-width/2,-height/2, width, height);
    movie->setScaledSize(label->size());
    movie->start();
    this->addWidget(label);


    // 边框
    itemRect = new QGraphicsRectItem(-width/2+20, -height/2, width-40, height);
    itemRect->setPen(QPen(QColor(247,184,193), 10));
    itemRect->setPos(0,0);

    // 彩旗
    itemCaiqi1 = new QGraphicsSvgItem(":/image/resources/caiqi.svg");
    QTransform transformCaiqi1;
    transformCaiqi1.translate(112, -150);
    transformCaiqi1.scale(-2.5, 2.5);
    itemCaiqi1->setTransform(transformCaiqi1);
    itemCaiqi1->setPos(0,-400);

    itemCaiqi2 = new QGraphicsSvgItem(":/image/resources/caiqi.svg");
    QTransform transformCaiqi2;
    transformCaiqi2.translate(-112, -150);
    transformCaiqi2.scale(2.5, 2.5);
    itemCaiqi2->setTransform(transformCaiqi2);
    itemCaiqi2->setPos(0,-412);

    // 装饰
    itemZhuangshi1 = new QGraphicsSvgItem(":/image/resources/zhuagnshi1.svg");
    QTransform transformZhuangshi1;
    transformZhuangshi1.translate(-250, -0);
    transformZhuangshi1.scale(2.5, 1.5);
    itemZhuangshi1->setTransform(transformZhuangshi1);
    itemZhuangshi1->setPos(0,-510);

    itemZhuangshi2 = new QGraphicsSvgItem(":/image/resources/zhuagnshi2.svg");
    itemZhuangshi2->setTransform(transformZhuangshi1);
    itemZhuangshi2->setPos(0,-510);


    // 生日快乐的图标
    QPixmap imageSheng(":/image/resources/sheng.png");
    itemSheng = new QGraphicsPixmapItem(imageSheng);
    itemSheng->setOffset(-imageSheng.width()/2, -imageSheng.height()/2);
    itemSheng->setScale(0.8);
    itemSheng->setPos(-160,-260);

    QPixmap imageRi(":/image/resources/ri.png");
    itemRi = new QGraphicsPixmapItem(imageRi);
    itemRi->setOffset(-imageRi.width()/2, -imageRi.height()/2);
    itemRi->setScale(0.8);
    itemRi->setPos(-60,-270);

    QPixmap imageKuai(":/image/resources/kuai.png");
    itemKuai = new QGraphicsPixmapItem(imageKuai);
    itemKuai->setOffset(-imageKuai.width()/2, -imageKuai.height()/2);
    itemKuai->setScale(0.8);
    itemKuai->setPos(60,-280);

    QPixmap imageLe(":/image/resources/le.png");
    itemLe = new QGraphicsPixmapItem(imageLe);
    itemLe->setOffset(-imageLe.width()/2, -imageLe.height()/2);
    itemLe->setScale(0.8);
    itemLe->setPos(180,-260);

    // Happy Birthday的图标
    QPixmap imageHappy(":/image/resources/HAPPYBIRTHDAY.png");
    itemHappyBirthday = new QGraphicsPixmapItem(imageHappy);
    itemHappyBirthday->setOffset(-imageHappy.width()/2, -imageHappy.height()/2);
    itemHappyBirthday->setScale(0.8);
    itemHappyBirthday->setPos(0,-160);

    // 头冠
    itemTouguan = new QGraphicsSvgItem(":/image/resources/touguan.svg");
    QTransform transformTouguan;
    transformTouguan.translate(-120, -100);
    transformTouguan.scale(1.2, 0.8);
    itemTouguan->setTransform(transformTouguan);
    itemTouguan->setPos(0,0);

    // 祝福语背景
    itemZhufuBack = new QGraphicsSvgItem(":/image/resources/zhufu.svg");
    QTransform transformHappy;
    transformHappy.translate(-210, -40);
    transformHappy.scale(2.0, 1.8);
    itemZhufuBack->setTransform(transformHappy);
    itemZhufuBack->setPos(0,80);

    // 祝福
    itemZhufu = new QGraphicsSimpleTextItem("诚邀参加XXX小朋友十岁生日宴会");
    itemZhufu->setPos(-180,65);
    itemZhufu->setFont(QFont("楷体", 14));
    itemZhufu->setBrush(QColor(240,96,120));

    // 日期
    itemDate = new QGraphicsSimpleTextItem("{2020.9.12}");
    itemDate->setPos(-70,110);
    itemDate->setFont(QFont("微软雅黑", 16));
    itemDate->setBrush(QColor(240,96,120));

    // 蛋糕
    QPixmap imageCake(":/image/resources/cake.png");
    itemCake = new QGraphicsPixmapItem(imageCake);
    itemCake->setOffset(-imageCake.width()/2, -imageCake.height()/2);
    itemCake->setScale(0.36);
    itemCake->setPos(0,270);

    // 气球
    QPixmap imageQiqiu(":/image/resources/qiqiu.png");
    itemQiqiu = new QGraphicsPixmapItem(imageQiqiu);
    itemQiqiu->setOffset(-imageQiqiu.width()/2, -imageQiqiu.height()/2);
    itemQiqiu->setScale(0.12);
    itemQiqiu->setPos(220,270);


    // 添加图元
    //this->addItem(lineX);
    //this->addItem(lineY);
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
