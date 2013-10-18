#include "gmsStateMenu.h"
#include "gms.h"
#include <vector>

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
            case 3:
                DisplayComponents();
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

//取得加入Component的輸入資料
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

    //判斷是否有載入XML
    if(this->gms->HasLoadedXMLRecord()){
        cout << "Select component type" << endl;
        cout << "[1]Cube [2]Pyramid [3]Sphere" << endl;
        cout << "> " ;

        //取得Componenet的Type與Name
        int choice = GetComponentInput();
        cout << "Enter component name:" << endl;
        cout << "> " ;
        string componentName;
        getline(cin,componentName);

        //透過GMS實作加入Component
        this->gms->AddComponents(gms->GetCurrentComponentMakerID(),GetComponentType(choice),componentName);

        //顯示加入的資料
        cout << "A components of " << GetComponentType(choice) << " added, name:" << componentName << ", ID: " << gms->GetCurrentComponentMakerID() <<endl;

        this->gms->AddComponentID(); //ID累加
    }
    else{
        cout << "No XML record loaded" << endl;
    }

}
//用來轉換成文字
string GMSStateMenu::GetComponentType(int type){
    if(type == ComponentType::SphereType)
        return "Sphere";
    else if(type ==ComponentType::PyramidType)
        return "Pyramid";
    else
        return "Cube";
}

void GMSStateMenu::DisplayComponents(){
    vector<Component*> components = this->gms->GetComponents();
    cout << "Components:" << endl;
    cout << "------------------------------------------------------" <<endl;
    cout << "   Type   |   ID    |    Name    " <<endl;
    cout << "------------------------------------------------------" <<endl;
    for(vector<Component*>::iterator it = components.begin();it != components.end();it++){
        //使用C語言印出,為了能夠讓印出的格式排版整齊,[0]是擷取自串的字首
        printf("    %c     |   %2d    |    %s\n",(*it)->GetType()[0],(*it)->GetID(),(*it)->GetName().c_str());
    }
}
