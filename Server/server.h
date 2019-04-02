#ifndef SERVER_H
#define SERVER_H






class Server
{
public:
    static Server* getInstance();
    int getServerKey();
    void setServerKey(int key);

private:
    static Server* instance;
    int serverKey;
    Server();  // Private Constructor




};


#endif // SERVER_H
