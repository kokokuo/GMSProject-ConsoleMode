#include "homemenu.h"
#include "GMS.h"


HomeMenu::HomeMenu(GMS *gms) :TextMenu(gms)
{
}
void HomeMenu::DisplayMenu(){
    cout << "Welcome" <<endl;
    cout << "[1] Graphical Modeling System" <<endl;
    cout << "[2] Exit" <<endl;
    cout << "> ";
}
void HomeMenu::Update(){
    string input;
    cin >> input;
    cin.ignore(INT_MAX,'\n');
    this->command = atoi(input.c_str());
    if( command != 0 &&  command <= COMMAND_NUMBER){

    }
    else{
        cout << "\nOption not Exist,please select again\n"<<endl ;
    }
}
