#ifndef RECT_H
#define RECT_H

#include <QGraphicsPixmapItem>

class Rect: public QGraphicsPixmapItem{
public:
    void keyPressEvent(QKeyEvent *event);
};

#endif // RECT_H
