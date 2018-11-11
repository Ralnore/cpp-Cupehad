#include "enemyatt.h"
#include "rect.h"
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QList>
#include <Qlabel>
EnemyAtt::EnemyAtt()
{
 setRect(0,0,50,50);

 QTimer * timer = new QTimer();
 connect(timer,SIGNAL(timeout()),this,SLOT(move()));

 timer->start(50);
}
int hp=1;
void EnemyAtt::move()
{
    QList<QGraphicsItem *> colliding_items2=collidingItems();
    for(int i=0, n=colliding_items2.size();i<n;++i){
        if(typeid(*(colliding_items2[i]))==typeid(Rect)){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x()+10,y());
    if(pos().x()+rect().width()<0){
        scene()->removeItem(this);
        delete this;
    }
}
