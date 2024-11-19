#include "game.h"
#include "enemy.h"
#include <QTimer>

Game::Game() {
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1280,720);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);
    player = new Player();
    scene->addItem(player);
    setFocus();

    //Score* score = player->getScore();
    scene->addItem(player->getScore());

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::spawnEnemy);
    timer->start(1500);
}

void Game::spawnEnemy() {
    Enemy* enemy = new Enemy();
    scene->addItem(enemy);
}
