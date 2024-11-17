#include "game.h"

Game::Game() {
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1280,720);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);
}
