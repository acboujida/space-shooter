#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include "enemy.h"

Bullet::Bullet() {
    QPixmap bulletImage(":/images/bullet.png");
    setPixmap(bulletImage);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(16);
}

void Bullet::move() {
    QList<QGraphicsItem*> items = collidingItems();
    for (QGraphicsItem* item : items) {
        if (Enemy* enemy = dynamic_cast<Enemy*>(item)) {
            scene()->removeItem(enemy);
            scene()->removeItem(this);
            emit hit();
            delete enemy;
            delete this;
            return;
        }
    }

    setPos(x(), y()-5);
    if (y() - pixmap().height() - 5 < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
