#include "gms.h"


GMS::GMS()
{
    isWorking = true;
    this->textMenuManager.insert(map<TextMenuIdEnum,TextMenu*>::value_type(HomeMenuKey,new HomeMenu(this)));
    this->textMenuManager.insert(map<TextMenuIdEnum,TextMenu*>::value_type(GMSMenuKey,new GMSMenu(this)));
    this->currentTextMenu = textMenuManager[HomeMenuKey];
}
void GMS::RunGMS(){
    while(true){
        currentTextMenu->DisplayMenu();
        currentTextMenu->Update();
    }
}
