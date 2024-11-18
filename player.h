#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QSet>
#include <QTimer>

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QGraphicsItem* parent=nullptr);
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
public slots:
    void handleKeys();
    void shoot();
private:
    QSet<int> keysPressed;
};

#endif // PLAYER_H
