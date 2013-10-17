#include "gms.h"


GMS::GMS()
{
    isWorking = true;

    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::HomeMenuKey,new HomeStateMenu(this)));
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::GMSMenuKey,new GMSStateMenu(this)));
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::XMLMenuKey,new XMLStateMenu(this)));
    this->currentTextMenu = textMenuManager[TextMenuKey::HomeMenuKey];
}
//主流程 操控選單的畫面顯示與邏輯輸入
void GMS::RunGMS(){
    while(this->isWorking){
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
    return xmlManager.CreateXML(path);
}
int GMS::LoadXMLFormatRecord(string path){
    return xmlManager.LoadXML(path);

}
bool GMS::HasLoadedXMLRecord(){
    return xmlManager.HasLoadedXML();
}
void GMS::AddComponents(int id, int componentType, string componentName){
    components.push_back(new Component(id,componentType,componentName));

    //自動寫入到XML檔案中
    //...
}
vector<Component*> GMS::GetComponents(){
    return this->components;
}
