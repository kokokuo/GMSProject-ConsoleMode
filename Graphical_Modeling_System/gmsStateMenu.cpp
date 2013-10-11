#include "gmsStateMenu.h"
#include "gms.h"


GMSStateMenu::GMSStateMenu(GMS *gms) : TextStateMenu(gms)
{
}
void GMSStateMenu::DisplayMenu(){
    cout << endl;
    cout << "Graphical Modeling System" <<endl;
    cout << "[1] New/Load a XML record" <<endl;
    cout << "[2] Add component" <<endl;
    cout << "[3] Display current components" <<endl;
    cout << "[4] Back to welcome menu" <<endl;
     cout << "> ";
}
void GMSStateMenu::Update(){
    //輸入正確
    if(this->CheckInput((this->COMMAND_NUMBER))){
        switch(command)
        {
            case 1:
                this->gms->SwitchToOtherMenu(TextMenuKey::XMLMenuKey);
                break;
            case 4:
                this->gms->SwitchToOtherMenu(TextMenuKey::HomeMenuKey);
                break;
        }
    }
    else{
        cout << "\nOption not Exist,please select again\n"<<endl ;
    }

}
