#ifndef CARDSENCE_H
#define CARDSENCE_H

#include <QObject>

class CardSence : public QObject
{
    Q_OBJECT
public:
    explicit CardSence(QObject *parent = nullptr);

signals:

};

#endif // CARDSENCE_H
