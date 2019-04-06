#include "tilewrapper.h"
#include <QMouseEvent>
#include <QDebug>

TileWrapper::TileWrapper()
{

}

void TileWrapper::makeTile()
{
    QLabel *qlabel = new QLabel();

    qlabel->setParent(this);

    qlabel->setMouseTracking(true);

    this->qLabel = qlabel;
}

void TileWrapper::setCoords(int i, int j)
{
    this->i = i;
    this->j = j;
}

void TileWrapper::setImage(QString url)
{
    this->url = url;
    QPixmap mypicture (url);
    this->setPixmap(mypicture);
}

int TileWrapper::get_i()
{
    return this->i;
}

int TileWrapper::get_j()
{
    return this->j;
}


TileWrapper::~TileWrapper()
{
    delete qLabel;
}
