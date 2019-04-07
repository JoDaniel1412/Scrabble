#include "tilewrapper.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>


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

    // tell the painter to draw on the QImage
    QPainter* painter = new QPainter(&mypicture);
    painter->setPen(Qt::black);
    painter->setFont(QFont("ScrambleMixed", 40));
    QString letterOnImage = QChar(this->letter).toUpper();
    painter->drawText(mypicture.rect(), Qt::AlignCenter, letterOnImage);

    this->setPixmap(QPixmap(mypicture));
    this->setAlignment(Qt::AlignCenter);

    painter->end();
}

int TileWrapper::get_i()
{
    return this->i;
}

int TileWrapper::get_j()
{
    return this->j;
}

void TileWrapper::deleteTile()
{
    delete this;
}

char TileWrapper::getLetter() const
{
    return letter;
}

void TileWrapper::setLetter(char value)
{
    letter = value;
}

int TileWrapper::getInitialY() const
{
    return initialY;
}

void TileWrapper::setInitialY(int value)
{
    initialY = value;
}

int TileWrapper::getInitialX() const
{
    return initialX;
}

void TileWrapper::setInitialX(int value)
{
    initialX = value;
}


TileWrapper::~TileWrapper()
{
    delete qLabel;
}
