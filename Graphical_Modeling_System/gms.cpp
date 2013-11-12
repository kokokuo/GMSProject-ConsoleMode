#include "gms.h"


GMS::GMS()
{
    isWorking = true;
    this->componentID = 1;
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::HomeMenuKey,new HomeStateMenu(this)));
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::GMSMenuKey,new GMSStateMenu(this)));
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::GroupMenuKey,new GroupStateMenu(this)));
    this->currentTextMenu = textMenuManager[TextMenuKey::HomeMenuKey];
}
//主流程 操控選單的畫面顯示與邏輯輸入
void GMS::RunGMS(){
    while(this->isWorking){
        //透過State Pattern的方式切換選單
        this->currentTextMenu->DisplayMenu();
        this->currentTextMenu->GetInput();
        this->currentTextMenu->Update();
    }
}
void GMS::SetCloseSystem(){
    this->isWorking = false;
}
void GMS::SwitchToOtherMenu(int Key){
    //把現在的選單指標指向 要切換的選單(透過map的key值取得value->選單類別 )
    this->currentTextMenu = textMenuManager[Key];
}

//把components存入檔案
//尚未加入Group....
int GMS::SaveXMLFormatRecord(string path){
    return xmlManager.SaveXML(path,components);
}
int GMS::LoadXMLFormatRecord(string path){
    ClearComponents(); //清除原先的Components

    //尚未加入Group...
    int code = xmlManager.LoadXML(path,&components);


    //設定Component現在的最大ID,從載入的XML資料中去看
    //如果有資料,取得檔案中最大的ID,並加一為現在的ID
    if(components.size() >0){
        componentID = components[components.size()-1]->GetID() +1;
    }

    return code;
}

void GMS::AddComponents(int id, string componentType, string componentName){
    //創建新的Component並加入智vector中
    Component *component = new Component(id,componentType,componentName);
    components.push_back(component);

}
vector<Component*> GMS::GetComponents(){
    return this->components;
}
//取得目前生產的ComponentsID
int GMS::GetCurrentComponentMakerID(){
    return this->componentID;
}
void GMS::AddComponentID(){
    componentID++;
}
void GMS::ClearComponents(){
    //重新載入新的XML,要把原先的資料先全部移除,避免有Memory Leak,再從新添加從XML載入的資料
    if(components.size() > 0){
        for(vector<Component*>::iterator it = components.begin();it != components.end();it++){
            delete (*it);
        }
        components.clear();
    }
}
