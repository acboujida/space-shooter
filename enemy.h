#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QGraphicsItem* parent=nullptr);
public slots:
    void move();
};

#endif // ENEMY_H
