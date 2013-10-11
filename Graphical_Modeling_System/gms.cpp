#include "gms.h"


GMS::GMS()
{
    isWorking = true;
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::HomeMenuKey,new HomeStateMenu(this)));
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::GMSMenuKey,new GMSStateMenu(this)));
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::XMLMenuKey,new XMLStateMenu(this)));
    this->currentTextMenu = textMenuManager[TextMenuKey::HomeMenuKey];
}
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
bool GMS::LoadXMLFormatRecord(string path){
    //return xmlManager.LoadXML(path);

}
