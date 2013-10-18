#include "gms.h"


GMS::GMS()
{
    isWorking = true;
    this->componentID = 1;
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::HomeMenuKey,new HomeStateMenu(this)));
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::GMSMenuKey,new GMSStateMenu(this)));
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::XMLMenuKey,new XMLStateMenu(this)));
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
    this->currentTextMenu = textMenuManager[Key];
}

int GMS::CreateXMLFormatRecord(string path){
    //新建一個XML等於載入一個新的XML檔,並起薪的XML檔應該是無資料的
    //所以要把原先的都清光
    ClearComponents();

    return xmlManager.CreateXML(path);
}
int GMS::LoadXMLFormatRecord(string path){
    ClearComponents(); //清除原先的Components

    int code = xmlManager.LoadXML(path,&components);
    //設定Component現在的最大ID,從載入的XML資料中去看
    //加一為現在的ID
    componentID = components[components.size()-1]->GetID() +1;

    return code;
}
bool GMS::HasLoadedXMLRecord(){
    return xmlManager.HasLoadedXML();
}
void GMS::AddComponents(int id, string componentType, string componentName){
    Component *component = new Component(id,componentType,componentName);
    components.push_back(component);

    //自動寫入到XML檔案中
    xmlManager.AddComponentToXMLFile(component);
}
vector<Component*> GMS::GetComponents(){
    return this->components;
}
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
