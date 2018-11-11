#ifndef ENEMYATT_H
#define ENEMYATT_H


#include <QGraphicsRectItem>
#include <QObject>
class EnemyAtt: public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    EnemyAtt();
public slots:
    void move();
};

#endif // ENEMYATT_H
