#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Game : public QGraphicsView {
    QGraphicsScene* scene;
public:
    Game();
};

#endif // GAME_H
