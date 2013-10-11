#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include "xmlErrorCode.h"
#include <iostream>
#include <stdlib.h>

#include <QFile>
#include <QTextStream>

using namespace std;

class XMLManager
{
public:
    XMLManager();
    int CreateXML(string fileName);
    int LoadXML(string filenName);

private:
    QFile *xmlFile;
};

#endif // XMLMANAGER_H
