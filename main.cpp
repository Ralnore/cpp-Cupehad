#include <QApplication>
#include <QGraphicsScene>
#include "rect.h"
#include "enemy.h"
#include "bullet.h"
#include <QBrush>
#include <QGraphicsView>
#include <QProgressBar>
#include <QDebug>
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QGraphicsScene * scene = new QGraphicsScene();

    Enemy *enemy = new Enemy();
    scene->addItem(enemy);
    Rect * rectangle = new Rect();
    rectangle->setPixmap(QPixmap(":/graphics/png.png"));
    scene->addItem(rectangle);
    rectangle->setFlag(QGraphicsItem::ItemIsFocusable);
    rectangle->setFocus();
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/graphics/bg.jpg")));

    return a.exec();
}
