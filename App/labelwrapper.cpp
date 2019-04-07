#include "labelwrapper.h"
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>


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


LabelWrapper::~LabelWrapper()
{
    delete qLabel;
}
