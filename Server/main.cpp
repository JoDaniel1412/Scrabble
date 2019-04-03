#include <QCoreApplication>
#include "serverConnection.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    serverConnection mServer;

    return a.exec();
}
