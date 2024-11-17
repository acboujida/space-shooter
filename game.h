#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"

class Game : public QGraphicsView {
    QGraphicsScene* scene;
    Player* player;
public:
    Game();
};

#endif // GAME_H