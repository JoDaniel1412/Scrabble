#include "serverdata.h"

serverData* serverData::instance = 0;

serverData* serverData::getInstance()
{
    if (instance == 0)
    {
        instance = new serverData();
    }

    return instance;
}

serverData::serverData()
{}

QString serverData::getKey()
{
    return key;
}

void serverData::setKey(QString key)
{
    serverData::key = key;
}
