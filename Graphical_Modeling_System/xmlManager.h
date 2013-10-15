#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include "xmlErrorCode.h"
#include <iostream>
#include <stdlib.h>

#include <QFile>
#include <QTextStream>
#include <fstream>

using namespace std;

class XMLManager
{
public:
    XMLManager();
    int CreateXML(string fileName);
    int LoadXML(string filenName);

private:
    fstream xmlFile;
    string xmlFilePath;
};

#endif // XMLMANAGER_H
