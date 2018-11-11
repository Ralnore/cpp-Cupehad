#include "enemy.h"
#include "attack.h"

#include <QTimer>
#include <QObject>
#include <QGraphicsScene>

Enemy::Enemy()
{

 setPos(700,300);
  setPixmap(QPixmap(":/graphics/boss.png"));

 QTimer * timer = new QTimer();
 connect(timer,SIGNAL(timeout()),this,SLOT(move()));

 QTimer * Shoottimer = new QTimer();
 connect(Shoottimer,SIGNAL(timeout()),this,SLOT(shoot()));

 timer->start(50);
 Shoottimer->start(3000);
}
int direction=10;
void Enemy::move()
{
    if(y()==0 || y()+200==600)
        direction=-direction;

    setPos(x(),y()+direction);
}
void Enemy::shoot()
{
    Attack *attack = new Attack();
    attack->setPos(x(),y());
    scene()->addItem(attack);
}
