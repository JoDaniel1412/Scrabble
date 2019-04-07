#include "labelwrapper.h"
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>


LabelWrapper::LabelWrapper()
{

}


void LabelWrapper::makeLabel()
{
    QLabel *qlabel = new QLabel();

    qlabel->setMouseTracking(true);

    this->qLabel = qlabel;
}

void LabelWrapper::setCoords(int i, int j)
{
    this->i = i;
    this->j = j;
}

int LabelWrapper::get_i()
{
    return this->i;
}

int LabelWrapper::get_j()
{
    return this->j;
}

void LabelWrapper::setImage(QString url, QChar letter)
{
    QPixmap mypicture (url);

    // tell the painter to draw on the QImage
    QPainter* painter = new QPainter(&mypicture);
    painter->setPen(Qt::black);
    painter->setFont(QFont("ScrambleMixed", 40));
    QString letterOnImage = QChar(letter).toUpper();
    painter->drawText(mypicture.rect(), Qt::AlignCenter, letterOnImage);

    this->setPixmap(QPixmap(mypicture));
    this->setAlignment(Qt::AlignCenter);

    painter->end();
}


LabelWrapper::~LabelWrapper()
{
    delete qLabel;
}
