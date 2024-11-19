#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QObject>

class Score : public QGraphicsTextItem {
    Q_OBJECT
    int score;
public:
    Score(QGraphicsItem* parents=nullptr);
    int getScore() const;
public slots:
    void increaseScore(int points=1);
};

#endif // SCORE_H
