#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsItemGroup>

class Health : public QGraphicsItemGroup {
    int currentHealth;
    QVector<QGraphicsPixmapItem*> hearts;
    QPixmap activeHeartImage;
    QPixmap inactiveHeartImage;
public:
    Health();
    void decreaseHealth(int healthPoints=1);
    int getHealth() const;
};

#endif // HEALTH_H
