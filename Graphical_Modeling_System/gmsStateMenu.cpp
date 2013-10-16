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
            case 2:
                AddComponents();
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

int GMSStateMenu::GetComponentInput(){
    int componentChoice;
    string input;
    while(true){
        cin >> input;
        cin.ignore(INT_MAX,'\n');
        componentChoice = atoi(input.c_str());
        if( componentChoice != 0 &&  componentChoice <= this->COMPONENTS_NUMBER)
          break;

    }
    return componentChoice;
}
void GMSStateMenu::AddComponents(){


    if(this->gms->HasLoadedXMLRecord()){
        cout << "Select component type" << endl;
        cout << "[1]Cube [2]Pyramid [3]Sphere" << endl;
        cout << "> " <<endl;

        int choice = GetComponentInput();
        string componetName;
        getline(cin,componetName);


    }
    else{
        cout << "No XML record loaded" << endl;
    }

}

void GMSStateMenu::DisplayComponents(){


}
