#include "groupStateMenu.h"
#include "GMS.h"


GroupStateMenu::GroupStateMenu(GMS *gms) : TextStateMenu(gms)
{
}
void GroupStateMenu::DisplayMenu(){
    cout << endl;
    cout << "Group" <<endl;
    cout << "[1] Create group" <<endl;
    cout << "[2] Add member to a group" <<endl;
    cout << "[3] Exit" <<endl;
    cout << "> ";

}
void GroupStateMenu::Update(){
    //輸入正確
    if(this->CheckInput((this->COMMAND_NUMBER))){
        switch(command)
        {
            case 1:
                break;
            case 2:

            case 3:
                this->gms->SwitchToOtherMenu(TextMenuKey::GMSMenuKey);
                break;
        }
    }
    else{
        cout << "\nOption not Exist,please select again\n"<<endl ;
    }
}

