#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include "xmlErrorCode.h"
#include <iostream>
#include <stdlib.h>

#include <fstream>
#include <vector>
#include "component.h"


using namespace std;

class XMLManager
{
public:
    XMLManager();
    int SaveXML(string fileName,vector<Component *> components); //存檔XML,如果不存在則創建檔案
    //載入XML檔案,第二個參數是透過指標的方式拿到Parser好的Components資料,所以是vector<T>*
    int LoadXML(string filenName, vector<Component *>* components);

private:
    //加入Component到XML
    void AddComponentToXMLFile(vector<Component *> components);
    //作XML的Parser
    vector<Component*> ParserXMLFile();

    //私有功能,從給予的Tag中擷取tag所夾帶的參數或數值,第三個參數是目前讀到的string line ,從此line擷取
    string GetTagValue(string startTag, string endTag, string line);

    fstream xmlFile;
    string xmlFilePath;
};

#endif // XMLMANAGER_H
