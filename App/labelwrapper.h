#ifndef LABELWRAPPER_H
#define LABELWRAPPER_H
#include <QLabel>


class LabelWrapper : public QLabel
{
public:

    LabelWrapper();

    ~LabelWrapper();


    int i, j;

public:

    QLabel * qLabel = nullptr;

    void makeLabel();

    void setCoords(int i, int j);

    int get_i();

    int get_j();
};
#endif // LABELWRAPPER_H
