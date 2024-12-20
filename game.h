#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"

class Game : public QGraphicsView {
    QGraphicsScene* scene;
    Player* player;
    QTimer* spawnTimer;
public:
    Game();
    void spawnEnemy();
    void handleGameOver();
    void keyPressEvent(QKeyEvent* event);
};

#endif // GAME_H
