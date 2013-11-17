#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include "xmlErrorCode.h"
#include <iostream>
#include <stdlib.h>

#include <fstream>
#include <vector>
#include <map>
#include "component.h"
#include "components.h"
#include "group.h"
#include "groups.h"


using namespace std;

class XMLManager
{
public:
    XMLManager();
    int SaveXML(string fileName, Components components,Groups groups); //存檔XML,如果不存在則創建檔案
    //載入XML檔案,第二個參數是透過指標的方式拿到Parser好的Components資料,所以是Components*
    int LoadXML(string filenName, Components* components,Groups* groups);

private:
    //加入Component到XML
    void AddComponentAndGroupToXMLFile(vector<Component *> components,map<string,Group*> groups);
    //作XML的Parser
    vector<Component*> ParserXMLFile();

    //私有功能,從給予的Tag中擷取tag所夾帶的參數或數值,第三個參數是目前讀到的string line ,從此line擷取
    string GetTagValue(string startTag, string endTag, string line);

    fstream xmlFile;
    string xmlFilePath;
};

#endif // XMLMANAGER_H
