#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
extern int hp;
class Bullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();

public slots:
    void move();
};
#endif // BULLET_H
