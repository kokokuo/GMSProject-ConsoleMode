#include "gms.h"


GMS::GMS()
{
    isWorking = true;
    this->textMenuManager.insert(map<TextMenuIdEnum,TextStateMenu*>::value_type(HomeMenuKey,new HomeStateMenu(this)));
    this->textMenuManager.insert(map<TextMenuIdEnum,TextStateMenu*>::value_type(GMSMenuKey,new GMSStateMenu(this)));
    this->textMenuManager.insert(map<TextMenuIdEnum,TextStateMenu*>::value_type(XMLMenuKey,new XMLStateMenu(this)));
    this->currentTextMenu = textMenuManager[HomeMenuKey];
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
void GMS::SwitchToOtherMenu(TextMenuIdEnum Key){
    this->currentTextMenu = textMenuManager[Key];
}
