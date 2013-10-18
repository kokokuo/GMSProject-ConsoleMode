#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include "xmlErrorCode.h"
#include <iostream>
#include <stdlib.h>

#include <fstream>
#include "component.h"


using namespace std;

class XMLManager
{
public:
    XMLManager();
    int CreateXML(string fileName);
    int LoadXML(string filenName);
    int AddComponentToXmlFile(Component *newComponent); //尚未實作
    bool HasLoadedXML();

private:
    fstream xmlFile;
    string xmlFilePath;
};

#endif // XMLMANAGER_H
