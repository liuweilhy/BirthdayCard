#ifndef OBJECTGRAPHICSITEM_H
#define OBJECTGRAPHICSITEM_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSvgItem>
#include <QGraphicsSimpleTextItem>

#include <QBrush>
#include <QPointF>
#include <QTransform>

class ObjectRectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal scale READ scale WRITE setScale)
    Q_PROPERTY(QBrush brush READ brush WRITE setBrush)
    Q_PROPERTY(QTransform transform READ transform WRITE setTransform)
public:
    ObjectRectItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr)
        : QObject(), QGraphicsRectItem(x, y, w, h, parent)
    {
        setCacheMode(DeviceCoordinateCache);
    }
};

class ObjectPixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal scale READ scale WRITE setScale)
    Q_PROPERTY(QTransform transform READ transform WRITE setTransform)
public:
    ObjectPixmapItem(QPixmap &pixmap, QGraphicsItem *parent = nullptr)
        : QObject(), QGraphicsPixmapItem(pixmap, parent)
    {
        setCacheMode(DeviceCoordinateCache);
    }
};

class ObjectSvgItem : public QGraphicsSvgItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal scale READ scale WRITE setScale)
    Q_PROPERTY(QTransform transform READ transform WRITE setTransform)
public:
    ObjectSvgItem(const QString &fileName, QGraphicsItem *parent = nullptr)
        : QGraphicsSvgItem(fileName, parent)
    {
        setCacheMode(DeviceCoordinateCache);
    }
};


class ObjectSimpleTextItem : public QObject, public QGraphicsSimpleTextItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal scale READ scale WRITE setScale)
    Q_PROPERTY(QTransform transform READ transform WRITE setTransform)
public:
    ObjectSimpleTextItem(const QString &text, QGraphicsItem *parent = nullptr)
        : QObject(), QGraphicsSimpleTextItem(text, parent)
    {
        setCacheMode(DeviceCoordinateCache);
    }
};



#endif // OBJECTGRAPHICSITEM_H
