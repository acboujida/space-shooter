#include "score.h"
#include <QFont>


Score::Score(QGraphicsItem* parents) : QGraphicsTextItem(parents), score(0) {
    setPlainText("SCORE: " + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
    setPos(1280-boundingRect().width()-30,0);
}

void Score::increaseScore(int points) {
    score += points;
    setPlainText("SCORE: " + QString::number(score));
}

int Score::getScore() const {
    return score;
}
