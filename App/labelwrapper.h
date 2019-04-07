#ifndef LABELWRAPPER_H
#define LABELWRAPPER_H
#include <QLabel>


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

};
#endif // LABELWRAPPER_H
