#include "rect.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
void Rect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x()>0)
        setPos(x()-20,y());
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x()+100<800)
        setPos(x()+20,y());
    }
    else if(event->key() == Qt::Key_Down){
        if(pos().y()+100<600)
        setPos(x(),y()+20);
    }
    else if(event->key() == Qt::Key_Up){
        if(pos().y()>0)
        setPos(x(),y()-20);
    }
    else if(event->key()==Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

    }
}
