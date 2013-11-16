#include "xmlmanager.h"

XMLManager::XMLManager()
{

}
int XMLManager::SaveXML(string xmlPath, Components components){
    //創建檔案
    xmlFile.open(xmlPath.c_str(),ios::out);
    if(xmlFile.is_open()){
        AddComponentToXMLFile(components.GetComponts());
        this->xmlFilePath = xmlPath; //把路徑記錄下來
         xmlFile.close();
        return XMLErrorCode::OK;
    }
    else{ //創建後如果無開啟 代表可能有錯誤
        xmlFile.close();
        return XMLErrorCode::Save_PathError;
    }
}
//Components* components是為了能夠直接取得整個vector的記憶體位置,這樣外部呼叫時傳入vector,處理完後才能夠拿到載入好的資料(因為回傳值拿來作為回傳錯誤碼用)
int XMLManager::LoadXML(string xmlPath,Components* components){

    //開檔,但是不會自動create(以讀檔的方式才能確保不會自動創建)
    xmlFile.open(xmlPath.c_str(),ios::in);

    //透過檢查是否開啟來判斷有無存在檔案
    if(xmlFile.is_open()){
        this->xmlFilePath = xmlPath; //把路徑記錄下來
        components->SetComponentsFromLoadData(ParserXMLFile()); //取出XML中的資料到記憶體vector
        xmlFile.close();

        return XMLErrorCode::OK;
    }
    else{
        xmlFile.close();
        //不存在
        return XMLErrorCode::Open_NotExist;
    }

}

void XMLManager::AddComponentToXMLFile(vector<Component*> components){
    try{
        xmlFile << "<GMS>\n";
        xmlFile << "\t<Components>\n";
        //迴圈的方式一個一個抓取Component並寫入到檔案中
        for(vector<Component*>::iterator it = components.begin();it != components.end();it++){
            xmlFile << "\t\t<Node>\n";
            xmlFile << "\t\t\t<ID>" << (*it)->GetID() << "</ID>\n";
            xmlFile << "\t\t\t<Name>" << (*it)->GetName() << "</Name>\n";
            xmlFile << "\t\t\t<Type>" << (*it)->GetType() << "</Type>\n";
            xmlFile << "\t\t</Node>\n";
        }
        xmlFile << "\t</Components>\n";

        //Group 尚未...

        xmlFile <<  "</GMS>"; //補上</GMS>標籤

    }
    catch(exception ex){
        cout << ex.what() <<endl;
    }

}
string XMLManager::GetTagValue(string startTag,string endTag,string line){
    int foundStartTagPos = line.find(startTag);
    int foundEndTagPos = line.find(endTag);
    //第一個參數:起始位置,找到開始Tag的位置 + 開始Tag本身的長度 會得到 開始Tag後的位置
    //第二個參數:擷取字串的長度,結尾Tag的位置 - 開始Tag尾後的位置(開始Tag位置 + 開始tag長度)
    string sub = line.substr( ( foundStartTagPos + startTag.size() ), ( foundEndTagPos - (foundStartTagPos + startTag.size()) ) );
    return sub;
}

vector<Component*> XMLManager::ParserXMLFile(){
    vector<Component*> components; //宣告用來存放檔案中所有Parser出的Components
    //判斷有無找到Node
    bool IsFindComponentNode = false;
    //判斷有無讀取到ID,Type,Name
    bool IsGetID, IsGetType , IsGetName;
    IsGetID = IsGetType = IsGetName = false;
    int id;
    string type,name;
    string line;
    while(getline(xmlFile,line)){
        //cout << line <<endl; //測試用
        //如果有找到Node,用Bool值紀錄
        if(line.find("<Node>") != string::npos ){
            IsFindComponentNode = true;
        }
        //找到開始<Node>
        if(IsFindComponentNode){
            //尋找Node中的Component標籤,並擷取資料

            //如果有找到<ID>標籤與</ID>標籤,則擷取標籤中資料
            if( (line.find("<ID>") != string::npos) && ( line.find("</ID>")  != string::npos ) ){
                id = atoi( GetTagValue("<ID>","</ID>",line).c_str() );
                IsGetID = true;
            }
            else if( (line.find("<Name>") != string::npos) && ( line.find("</Name>")  != string::npos ) ){
                name = GetTagValue("<Name>","</Name>",line);
                IsGetName = true;
            }
            else if( (line.find("<Type>") != string::npos) && ( line.find("</Type>")  != string::npos ) ){
                type = GetTagValue("<Type>","</Type>",line);
                IsGetType = true;
            }
        }
        //找到</Node> 並且 <Node> 也有找到,也取得了Node中的標籤資料
        if(IsFindComponentNode && line.find("</Node>") != string::npos && IsGetID && IsGetName && IsGetType){
            components.push_back(new Component(id,type,name)); //加入Component
            IsFindComponentNode = IsGetID = IsGetType = IsGetName = false; //從新設定回false
        }
    }
    return components; //回傳檔案中所有的Components
}
