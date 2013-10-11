#include "xmlmanager.h"

XMLManager::XMLManager()
{
}
int XMLManager::CreateXML(string xmlPath){

    if(!QFile::exists( QString::fromStdString(xmlPath) )){

        //如果先前已有開檔,則要先關閉釋放掉
        if(!this->xmlFile){
            xmlFile->close();
            delete xmlFile;
        }

        this->xmlFile = new QFile( QString::fromStdString(xmlPath) );
        if ( xmlFile->open( QIODevice::WriteOnly ) ) {
            return XMLErrorCode::OK;
        }
        else{
            return XMLErrorCode::PathError;
        }
    }
    else{
        return XMLErrorCode::HasExisted;
    }

}
