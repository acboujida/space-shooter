#include "health.h"

Health::Health() : currentHealth(3) {
    activeHeartImage = QPixmap(":/images/heart.png");
    inactiveHeartImage = QPixmap(":/images/inactive_heart.png");

    for (int i=0; i<currentHealth; i++) {
        QGraphicsPixmapItem* heartItem = new QGraphicsPixmapItem(activeHeartImage);
        heartItem->setParentItem(this);
        heartItem->setPos(i*40, 0);
        hearts.push_back(heartItem);
        addToGroup(heartItem);
    }
    setPos(0, 10);
}

void Health::decreaseHealth(int healthPoints) {
    currentHealth -= healthPoints;
    if (currentHealth < 0) currentHealth = 0;
    for (int i=hearts.size()-1; i >= currentHealth; i--) {
        hearts[i]->setPixmap(inactiveHeartImage);
        hearts.pop_back();
    }
}

int Health::getHealth() const {
    return currentHealth;
}
