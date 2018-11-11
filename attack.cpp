
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QDebug>
#include <QApplication>
#include <QLabel>
#include "enemy.h"
#include "attack.h"
#include "rect.h"
#include "bullet.h"
#include <QMessageBox>
#include <QString>
#include <QThread>
Attack::Attack()
{
setPixmap(QPixmap(":/graphics/bullet2.png"));

 QTimer * timer = new QTimer();
 connect(timer,SIGNAL(timeout()),this,SLOT(move()));

 timer->start(50);
}

// slot
void Attack::move()
{
    QList<QGraphicsItem *> colliding_att=collidingItems();
    for(int i=0; i<colliding_att.size(); ++i){
        if(typeid(*(colliding_att[i]))==typeid(Rect)){
            qDebug() << scene();
             scene()->removeItem(colliding_att[i]);
            QString ending = QString("Zabiła cię wielka kula ognia. Udało ci się trafić smoka %1 razy")
                        .arg(hp);
            QMessageBox msgBox;
            msgBox.setText(ending);
            msgBox.exec();

            QApplication::quit();





            return;
        }
    }


    setPos(x()-10,y());
    if(pos().x()+pixmap().width()<0){
      scene()->removeItem(this);
        delete this;
    }
}
