#include <QCoreApplication>
#include <iostream>
#include "serverConnection.h"

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    serverConnection mServer;

    return a.exec();
}
