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

    scene->addItem(player->getScore());
    scene->addItem(player->getHealth());

    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &Game::spawnEnemy);
    spawnTimer->start(1500);

    connect(player, &Player::playerDied, this, &Game::handleGameOver);
}

void Game::spawnEnemy() {
    Enemy* enemy = new Enemy();
    scene->addItem(enemy);
}

void Game::handleGameOver() {
    spawnTimer->stop();
    player->setEnabled(false);

    QGraphicsTextItem* gameOverText = new QGraphicsTextItem("GAME OVER");
    gameOverText->setFont(QFont("times", 70));
    gameOverText->setPos(1280 / 2 - gameOverText->boundingRect().width() / 2, 720 / 2 - gameOverText->boundingRect().height());
    QGraphicsTextItem* finalScoreText = new QGraphicsTextItem("Your final score: " + QString::number(player->getScore()->getScore()));
    finalScoreText->setFont(QFont("times", 70));
    finalScoreText->setPos(1280 / 2 - finalScoreText->boundingRect().width() / 2, 720 / 2);
    scene->addItem(gameOverText);
    scene->addItem(finalScoreText);
}

void Game::keyPressEvent(QKeyEvent *event) {
    if (!player->isEnabled()) {
        event->ignore();
        return;
    }

    QGraphicsView::keyPressEvent(event);
}

