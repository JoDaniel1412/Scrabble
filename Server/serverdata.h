#ifndef SERVERDATA_H
#define SERVERDATA_H

#include <QString>


class serverData
{
    private:
        /* Here will be the instance stored. */
        static serverData* instance;

        /* Private constructor to prevent instancing. */
        serverData();

        QString key;

    public:
        /* Static access method. */
        static serverData* getInstance();
        QString getKey();
        void setKey(QString key);
};

#endif // SERVERDATA_H
