#include <QCoreApplication>
#include "gms.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GMS graphicModelingSystem;
    graphicModelingSystem.RunGMS();

    //This application would actually exit by itself after all the tasks have been finished if this line was not there.
    //return a.exec();

    return 0;
}
