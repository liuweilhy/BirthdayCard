#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsView>
#include "cardsence.h"

class Widget : public QGraphicsView
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    CardSence *cardSence;

protected:
    void keyPressEvent(QKeyEvent *event) override;
};
#endif // WIDGET_H
