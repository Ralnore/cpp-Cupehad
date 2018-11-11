#include "bullet.h"
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include <QLabel>
#include <QDebug>
#include "enemy.h"
#include "rect.h"
#include "QGraphicsPixmapItem"

int hp=0;
int *wsk=&hp;

Bullet::Bullet()
{
setPixmap(QPixmap(":/graphics/bulet1.png"));

 QTimer * timer = new QTimer();
 connect(timer,SIGNAL(timeout()),this,SLOT(move()));

 timer->start(50);
}


void Bullet::move()
{

    QList<QGraphicsItem *> colliding_b=collidingItems();
    for(int i=0; i <  colliding_b.size();++i){
        if(typeid(*(colliding_b[i]))==typeid(Enemy)){
         //   qDebug() << scene();
           // delete this;
            *wsk=hp+1;
            qDebug()<<hp;
            scene()->removeItem(this);
            return;
        }
    }
    setPos(x()+10,y());
    if(pos().x()+pixmap().width()>800){
     //   scene()->removeItem(this);
     //   delete this;
    }
}


