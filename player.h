#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Player : public QGraphicsPixmapItem {
public:
    Player(QGraphicsItem* parent=nullptr);
    void keyPressEvent(QKeyEvent*);
};

#endif // PLAYER_H
