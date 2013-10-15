#include "xmlmanager.h"

XMLManager::XMLManager()
{
}
int XMLManager::CreateXML(string xmlPath){
    this->xmlFilePath = xmlPath;


    //開檔,但是不會自動create(以讀檔的方式才能確保不會自動創建)
    xmlFile.open(xmlFilePath.c_str(),ios::in);

    //透過檢查是否開啟來判斷有無存在檔案
    if(xmlFile.is_open()){
        xmlFile.close();
        return XMLErrorCode::Create_HasExisted;
    }
    else{ //正式創建檔案
        xmlFile.open(xmlFilePath.c_str(),ios::out);

        if(xmlFile.is_open()){
            xmlFile.close();
            return XMLErrorCode::OK;
        }
        else{ //創建後如果無開啟 代表可能有錯誤
            xmlFile.close();
            return XMLErrorCode::Create_PathError;
        }
    }




}
int XMLManager::LoadXML(string xmlPath){
    this->xmlFilePath = xmlPath;


    //開檔,但是不會自動create(以讀檔的方式才能確保不會自動創建)
    xmlFile.open(xmlFilePath.c_str(),ios::in);

    //透過檢查是否開啟來判斷有無存在檔案
    if(xmlFile.is_open()){
        xmlFile.close();
        return XMLErrorCode::OK;
    }
    else{
        xmlFile.close();
        //不存在
        return XMLErrorCode::Open_NotExist;
    }

}
