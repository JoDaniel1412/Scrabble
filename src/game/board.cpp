#include "board.h"

Board *Board::instance = nullptr;

Board::Board() {
    matrix = new List<List<Tile*>*>();
    rows = 15;
    columns = 15;
    load();
}

Board *Board::getInstance()
{
    if (instance == nullptr) instance = new Board();
    return instance;
}

void Board::load()
{
    int k = 14;
    for (int i = 0; i < rows; i++) {  // Loads the rows into the matrix
        List<Tile*> *row = new List<Tile*>();
        matrix->pushTail(row);

        for (int j = 0; j < columns; j++) {  // Loads the columns into the matrix
            Tile *tile = new Tile();
            row->pushTail(tile);

            // Extra points
            if (i == j) tile->setBonus(2);
            if (i + k == j) {
                tile->setBonus(2);
                k -= 2;
            }
            if (i == 7 and j == 7) tile->setBonus(4);
        }
    }
}

bool Board::putLetter(int i, int j, char letter)
{
    Tile *tile = getTile(i, j);
    bool occupied = false;

    if (tile->isFree()){

        tile->setLetter(letter);
        tile->setFree(false);
        occupied = true;
    }
    return occupied;
}

char Board::getLetter(int i, int j)
{
    Tile *tile = getTile(i, j);
    return tile->getLetter();
}

List<List<Tile*>*> *Board::getMatrix()
{
    return matrix;
}

void Board::setMatrix(List<List<Tile *> *> *value)
{
    matrix = value;
}

Tile *Board::getTile(int i, int j) const // Searchs the Tile inthe matrix
{
    List<Tile*> *row = matrix->value(i);
    Tile *tile = row->value(j);
    return tile;
}

void Board::setTile(Tile &tile, int i, int j)
{
    List<Tile*> *row = matrix->value(i);
    row->getNode(j)->setValue(&tile);
}

void Board::clean()
{
    delete instance;
    instance = new Board();
}

int Board::getRows() const
{
    return rows;
}

int Board::getColumns() const
{
    return columns;
}

pair<QString, QString> *Board::getWords(int i, int j)
{
   QString hword = getHorizontalWord(i, j);
   QString vword = getVerticalWord(i, j);

   pair<QString, QString> * wordPair = new pair<QString, QString>(hword, vword);

   return wordPair;

}

QString Board::getHorizontalWord(int i, int j)
{
    Tile * startTile;
    QString horizontalWord;

    while (!this->getTile(i, j)->isFree() and j > 0 and j < 15){
        startTile = this->getTile(i, j--);
    }

    while (!startTile->isFree()){
        startTile = this->getTile(i, j++);
        char letter= startTile->getLetter();
        if(letter != '0') horizontalWord += letter;
    }

    return horizontalWord;
}

QString Board::getVerticalWord(int i, int j)
{
    Tile * startTile;
    QString verticalWord;

    while (!this->getTile(i, j)->isFree() and i > 0 and i < 15){
        startTile = this->getTile(i--, j);
    }

    while (!startTile->isFree()){
        startTile = this->getTile(i++, j);
        char letter= startTile->getLetter();
        if(letter != '0') verticalWord += letter;
    }
    qInfo() << verticalWord;
    return verticalWord;
}

void Board::write(QJsonObject &jsonObj) const
{
    QJsonArray rowsArray;
    for(int i = 0; i < rows; i++)
    {
        QJsonObject columnsObject;
        QJsonArray columnsArray;
        for (int j = 0; j < columns; j++)
        {
            QJsonValue json = JsonSerializer::serialize(*getTile(i, j));
            columnsArray.append(json);
        }
        columnsObject["columns"] = columnsArray;
        rowsArray.append(columnsObject);
    }

    jsonObj["rows"] = rowsArray;
}

void Board::read(const QJsonObject &jsonObj)
{
    instance = new Board();
    // json encapsulates the QJsonArray
    QJsonArray rowsArray = jsonObj["rows"].toArray();

    for (int i = 0; i < rows; i++) {
        QJsonValue jsonColumn = rowsArray[i];
        QJsonArray columnsArray = jsonColumn["columns"].toArray();
        for (int j = 0; j < columns; j++) {
            Tile *tile = new Tile();
            QString json = columnsArray[j].toString();
            JsonSerializer::parse(json, *tile);
            setTile(*tile, i, j);
        }
    }
}
