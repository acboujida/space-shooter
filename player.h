#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QSet>
#include <QTimer>
#include "score.h"
#include "health.h"

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsItem* parent=nullptr);
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
    void fireBullet();
    Score* getScore() const;
    Health* getHealth() const;
    void takeDamage(int healthPoints=1);
    void clearKeys();
public slots:
    void handleKeyInputs();
    void resetCooldown();
private:
    QSet<int> keysPressed;
    bool cooldown;
    QTimer* cooldownTimer;
    Score* score;
    Health* health;
signals:
    void playerDied();
};

#endif // PLAYER_H
