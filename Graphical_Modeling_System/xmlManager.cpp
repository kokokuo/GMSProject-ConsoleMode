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
int XMLManager::LoadXML(string xmlPath){

    //開檔,但是不會自動create(以讀檔的方式才能確保不會自動創建)
    xmlFile.open(xmlPath.c_str(),ios::in);

    //透過檢查是否開啟來判斷有無存在檔案
    if(xmlFile.is_open()){
        xmlFile.close();
        this->xmlFilePath = xmlPath; //把路徑記錄下來
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
int XMLManager::AddComponentToXmlFile(Component *newComponent){
    xmlFile.open(xmlFilePath.c_str(),ios::out | ios::in);

    //處理XML格式
    string line;
    cout << "Find </GMS>" <<endl;
    xmlFile.seekg(-6,std::ios::end); //增加新資料是從結尾的</GMS>前加入,所以這邊的作法是覆蓋掉</GMS>,從檔案尾端往前移動-6個位置
    xmlFile << "\t<Node>\n";
    xmlFile << "\t\t<ID>" << newComponent->GetID() << "</ID>\n";
    xmlFile << "\t\t<Name>" << newComponent->GetName() << "</Name>\n";
    xmlFile << "\t\t<Type>" << newComponent->GetType() << "</Type>\n";
    xmlFile << "\t</Node>\n";
    xmlFile <<  "</GMS>"; //補上</GMS>標籤
    xmlFile.close();

}
