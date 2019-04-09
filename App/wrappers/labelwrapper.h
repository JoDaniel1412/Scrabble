#ifndef LABELWRAPPER_H
#define LABELWRAPPER_H
#include <QLabel>
#include "game/board.h"


class LabelWrapper : public QLabel
{
public:

    LabelWrapper();

    ~LabelWrapper();


public:

    QLabel * qLabel = nullptr;

    void makeLabel();

    int i, j;

    void setCoords(int i, int j);

    int get_i();

    int get_j();

    void setImage(QString url, QChar letter);

    Board * board = Board::getInstance();

    void deleteLabel();

};
#endif // LABELWRAPPER_H
