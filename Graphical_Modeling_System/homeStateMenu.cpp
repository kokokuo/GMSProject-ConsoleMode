#include "homeStateMenu.h"
#include "GMS.h"


HomeStateMenu::HomeStateMenu(GMS *gms) :TextStateMenu(gms)
{
    IsFirstCome = true;
}
void HomeStateMenu::DisplayMenu(){
    //用來增加換行用
    if(IsFirstCome)
        this->IsFirstCome = false;
    else
        cout << endl;

    cout << "Welcome" <<endl;
    cout << "[1] Graphical Modeling System" <<endl;
    cout << "[2] Exit" <<endl;
    cout << "> ";

}
void HomeStateMenu::Update(){
    //輸入正確
    if(this->CheckInput((this->COMMAND_NUMBER))){
        switch(command)
        {
            case 1:
                this->gms->SwitchToOtherMenu(TextMenuKey::GMSMenuKey);
                break;
            case 2:
                cout << "goodbye!" <<endl;
                this->gms->SetCloseSystem();
                break;
        }
    }
    else{
        cout << "\nOption not Exist,please select again\n"<<endl ;
    }
}
