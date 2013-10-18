#include "xmlmanager.h"

XMLManager::XMLManager()
{

}
int XMLManager::CreateXML(string xmlPath){


    //開檔,但是不會自動create(以讀檔的方式才能確保不會自動創建)
    xmlFile.open(xmlPath.c_str(),ios::in);

    //透過檢查是否開啟來判斷有無存在檔案
    if(xmlFile.is_open()){
        xmlFile.close();
        return XMLErrorCode::Create_HasExisted;
    }
    else{ //正式創建檔案
        xmlFile.open(xmlPath.c_str(),ios::out);

        if(xmlFile.is_open()){
            xmlFile << "<GMS>\n" << "</GMS>";
            xmlFile.close();
            this->xmlFilePath = xmlPath; //把路徑記錄下來
            return XMLErrorCode::OK;
        }
        else{ //創建後如果無開啟 代表可能有錯誤
            xmlFile.close();
            return XMLErrorCode::Create_PathError;
        }
    }




}
int XMLManager::LoadXML(string xmlPath,vector<Component*>* components){

    //開檔,但是不會自動create(以讀檔的方式才能確保不會自動創建)
    xmlFile.open(xmlPath.c_str(),ios::in);

    //透過檢查是否開啟來判斷有無存在檔案
    if(xmlFile.is_open()){
        this->xmlFilePath = xmlPath; //把路徑記錄下來
        *components = ParserXMLFile(); //取出XML中的資料到記憶體vector
        xmlFile.close();

        return XMLErrorCode::OK;
    }
    else{
        xmlFile.close();
        //不存在
        return XMLErrorCode::Open_NotExist;
    }

}
bool XMLManager::HasLoadedXML(){
    if(this->xmlFilePath.size() >0){
        return true;
    }
    return false;

}
void XMLManager::AddComponentToXMLFile(Component *newComponent){
    xmlFile.open(xmlFilePath.c_str(),ios::out | ios::in);

    try{
        xmlFile.seekg(-6,std::ios::end); //增加新資料是從結尾的</GMS>前加入,所以這邊的作法是覆蓋掉</GMS>,從檔案尾端往前移動-6個位置
        xmlFile << "\t<Node>\n";
        xmlFile << "\t\t<ID>" << newComponent->GetID() << "</ID>\n";
        xmlFile << "\t\t<Name>" << newComponent->GetName() << "</Name>\n";
        xmlFile << "\t\t<Type>" << newComponent->GetType() << "</Type>\n";
        xmlFile << "\t</Node>\n";
        xmlFile <<  "</GMS>"; //補上</GMS>標籤

    }
    catch(exception ex){
        cout << ex.what() <<endl;
    }
    xmlFile.close();

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
    vector<Component*> components;
    //判斷有無找到Node
    bool IsFindComponentNode = false;
    //判斷有無讀取到ID,Type,Name
    bool IsGetID, IsGetType , IsGetName;
    IsGetID = IsGetType = IsGetName = false;
    int id;
    string type,name;
    string line;
    while(getline(xmlFile,line)){
        cout << line <<endl;
        //如果有找到Node,用Bool值紀錄
        if(line.find("<Node>") != string::npos ){
            IsFindComponentNode = true;
        }
        //找到開始<Node>
        if(IsFindComponentNode){
            //尋找Node中的Component標籤,並擷取資料
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
    return components;
}
