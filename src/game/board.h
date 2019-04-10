#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include <list/List.h>
#include <QJsonArray>
#include "json/jsonserializer.h"
#include <QDebug>

class Board : public JsonSerializable
{
public:
    static Board *getInstance();

    void load();

    bool putLetter(int i, int j, char letter);

    char getLetter(int i, int j);

    List<List<Tile*>*> *getMatrix();
    void setMatrix(List<List<Tile*>*> * value);

    Tile *getTile(int i, int j) const;
    void setTile(Tile &tile, int i, int j);

    void clean();

    int getRows() const;

    int getColumns() const;

    pair<QString, QString> *getWords(int i, int j);

    QString getHorizontalWord(int i, int j);
    QString getVerticalWord(int i, int j);

    void write(QJsonObject &jsonObj) const;
    void read(const QJsonObject &jsonObj);

private:
    static Board *instance;
    List<List<Tile*>*> *matrix;
    int rows;
    int columns;

    Board();  // Private Constructor
};

#endif // BOARD_H
