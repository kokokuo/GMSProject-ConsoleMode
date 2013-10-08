#include <QCoreApplication>
#include "gms.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GMS graphicModelingSystem;
    graphicModelingSystem.RunGMS();

    return a.exec();
}
