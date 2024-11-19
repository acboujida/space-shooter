#include "enemy.h"
#include <random>
#include <QTimer>
#include <QGraphicsScene>

Enemy::Enemy(QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {
    QPixmap enemyImage(":/images/meteorite.png");
    setPixmap(enemyImage);
    std::random_device rd;
    std::mt19937 mt(rd());

    setPos(mt()%(1280 - pixmap().width()), -pixmap().height());

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(16);
}

void Enemy::move() {
    setPos(x(), y() + 5);
    if (y() + 5 >= 720) {
        scene()->removeItem(this);
        delete this;
    }
}
