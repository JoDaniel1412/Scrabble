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

int serverData::getKey()
{
    return key;
}

void serverData::setKey(int nkey)
{
    serverData::key = nkey;
}
