#include "player.h"
#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {
    QPixmap playerImage(":/images/player.png");
    setPixmap(playerImage);

    int playerWidth = pixmap().width();
    int playerHeight = pixmap().height();

    setPos(1280/2 - playerWidth/2, 720 - playerHeight);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(handleKeys()));
    timer->start(16);
}

void Player::keyPressEvent(QKeyEvent * event) {
    keysPressed.insert(event->key());
}

void Player::keyReleaseEvent(QKeyEvent * event) {
    keysPressed.remove(event->key());
}

void Player::shoot() {
    Bullet* bullet = new Bullet();
    bullet->setPos(x() + pixmap().width()/2 - bullet->pixmap().width()/2, y()-bullet->pixmap().height());
    scene()->addItem(bullet);
}

void Player::handleKeys() {
    if (keysPressed.contains(Qt::Key_Left) && x() - 10 >= 0)
        setPos(x() - 5, y());
    if (keysPressed.contains(Qt::Key_Right) && x() + 10 + pixmap().width() <= 1280)
        setPos(x() + 5, y());
    if (keysPressed.contains(Qt::Key_Up) && y() - 10 >= 0)
        setPos(x(), y() - 5);
    if (keysPressed.contains(Qt::Key_Down) && y() + 10 + pixmap().height() <= 720)
        setPos(x(), y() + 5);
    if (keysPressed.contains(Qt::Key_Space))
        shoot();
}
