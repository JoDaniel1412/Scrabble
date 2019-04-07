#ifndef TILEWRAPPER_H
#define TILEWRAPPER_H
#include <QLabel>


class TileWrapper : public QLabel
{
public:

    TileWrapper();

    ~TileWrapper();

    int i, j;

public:

    QLabel * qLabel = nullptr;

    void makeTile();

    void setCoords(int i, int j);

    void setImage(QString url);

    QString url;

    int get_i();

    int get_j();

    void deleteTile();

    char getLetter() const;
    void setLetter(char value);

    int getInitialX() const;
    void setInitialX(int value);

    int getInitialY() const;
    void setInitialY(int value);


private:

    char letter;

    int initialX, initialY;
};

#endif // TILEWRAPPER_H
