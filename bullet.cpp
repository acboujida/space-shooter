#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet() {
    QPixmap bulletImage(":/images/bullet.png");
    setPixmap(bulletImage);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(16);
}

void Bullet::move() {
    setPos(x(), y()-5);
    if (y() - pixmap().height() - 5 < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
