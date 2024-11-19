#include "enemy.h"
#include <random>
#include <QTimer>
#include <QGraphicsScene>
#include "player.h"

Enemy::Enemy(QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {
    QPixmap enemyImage(":/images/meteorite.png");
    setPixmap(enemyImage);
    std::random_device rd;
    std::mt19937 mt(rd());

    setPos(mt()%(1280 - pixmap().width()), -pixmap().height());

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Enemy::move);
    timer->start(16);
}

void Enemy::move() {
    setPos(x(), y() + 5);

    QList<QGraphicsItem*> items = collidingItems();
    for (QGraphicsItem* item : items) {
        if (Player* player = dynamic_cast<Player*>(item)) {
            player->takeDamage();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    if (y() + 5 >= 720) {
        scene()->removeItem(this);
        delete this;
    }
}
