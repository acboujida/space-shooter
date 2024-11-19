#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();
signals:
    void hit(int points=1);
};

#endif // BULLET_H
