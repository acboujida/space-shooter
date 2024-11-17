#include "player.h"

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {
    QPixmap playerImage(":/images/player.png");
    setPixmap(playerImage.scaled(50, 50, Qt::KeepAspectRatio));

    int playerWidth = pixmap().width();
    int playerHeight = pixmap().height();

    setPos(1280/2 - playerWidth/2, 720 - playerHeight);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Player::keyPressEvent(QKeyEvent * event) {
    switch(event->key()) {
    case Qt::Key_Left:
        if (x() - 10 >= 0)
            setPos(x()-10,y());
        break;
    case Qt::Key_Right:
        if (x() + 10 + pixmap().width() <= 1280)
            setPos(x()+10,y());
        break;
    case Qt::Key_Up:
        if (y() - 10 >= 0)
            setPos(x(), y()-10);
        break;
    case Qt::Key_Down:
        if (y() + 10 + pixmap().height() <= 720)
            setPos(x(), y()+10);
        break;
    default:
        break;
    }
}
