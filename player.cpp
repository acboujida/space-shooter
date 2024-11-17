#include "player.h"

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {
    QPixmap playerImage(":/images/player.png");
    setPixmap(playerImage.scaled(50, 50, Qt::KeepAspectRatio));

    int playerWidth = pixmap().width();
    int playerHeight = pixmap().height();

    setPos(1280/2 - playerWidth/2, 720 - playerHeight);
}
