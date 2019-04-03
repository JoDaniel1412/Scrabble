#ifndef SERVERDATA_H
#define SERVERDATA_H


class serverData
{
    private:
        /* Here will be the instance stored. */
        static serverData* instance;

        /* Private constructor to prevent instancing. */
        serverData();

        int key;

    public:
        /* Static access method. */
        static serverData* getInstance();
        int getKey();
        void setKey(int nkey);
};

#endif // SERVERDATA_H
