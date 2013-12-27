#include "gmsStateMenu.h"
#include "gms.h"
#include <vector>

GMSStateMenu::GMSStateMenu(GMS *gms) : TextStateMenu(gms)
{
}
void GMSStateMenu::DisplayMenu(){
    cout << endl;
    cout << "Graphical Modeling System" <<endl;
    cout << "[1] Load a XML record" <<endl;
    cout << "[2] Save a XML record" <<endl;
    cout << "[3] Add component" <<endl;
    cout << "[4] Edit" <<endl;
    cout << "[5] Delete" <<endl;
    cout << "[6] Group" <<endl;
    cout << "[7] Redo" <<endl;
    cout << "[8] Undo" <<endl;
    cout << "[9] Display current table" <<endl;
    cout << "[10] Back to welcome menu" <<endl;
    cout << "> ";
}
void GMSStateMenu::Update(){
    //輸入正確
    if(this->CheckInput((this->COMMAND_NUMBER))){
        //作每個指定了事情
        switch(command)
        {
            case 1: case 2: //load & save
                HandleXML(command);
                break;
            case 3:
                //add component
                AddComponents();
                break;
            case 4:
                //edit
                EditComponent();
                break;
            case 5:
                //delete
                DeleteComponent();
                break;
            case 6:
                //group
            this->gms->SwitchToOtherMenu(TextMenuKey::GroupMenuKey);  //透過key 切換到其他選單->去Group選單
                break;
            case 7:
                //redo
                if(this->gms->Redo()){
                    cout << "Redo Successfully" <<endl;
                }
                else{
                    cout << "Can't Redo" <<endl;
                }
                break;
            case 8:
                //undo
                if(this->gms->Undo()){
                    cout << "Undo Successfully" <<endl;
                }
                else{
                    cout << "Can't Undo" <<endl;
                }
                break;
            case 9:
                //display

                //component
                DisplayComponents();
                cout << endl;
                //group
                DisplayGroups();
                break;
            case 10:
                //back
                this->gms->SwitchToOtherMenu(TextMenuKey::HomeMenuKey);  //透過key 切換到其他選單->回到HomeMenu的選單
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
    cout << "Select component type" << endl;
    cout << "[1]Cube [2]Pyramid [3]Sphere [4]Line" << endl;
    cout << "> " ;

    //取得Componenet的Type與Name
    int choice = GetComponentInput();
    cout << "Enter component name:" << endl;
    cout << "> " ;
    string componentName;
    getline(cin,componentName);


    //顯示加入的資料
    cout << "A components of " << GetComponentType(choice) << " added, name:" << componentName << ", ID: " << gms->GetCurrentComponentMakerID() <<endl;
    //透過GMS實作加入Component
    this->gms->AddComponentsByCommand(GetComponentType(choice),componentName);


}
//刪除Component
void GMSStateMenu::DeleteComponent(){
    string input;
    int deleteId;

    cout << "Select component to deleted" <<endl;
    cout << "> " ;

    cin >> input;
    cin.ignore(INT_MAX,'\n');
    deleteId = atoi(input.c_str());

    bool isExist = gms->DeleteComponentByCommand(deleteId);
    if(isExist){
        cout << "The component '" << deleteId << "' has been deleted" << endl;
    }
    else{
        cout << "The component of ID'" << deleteId << "' is not exist" << endl;
    }

}

int GMSStateMenu::ChooseEditComponentType(){
    string input;
    int type;

    while(true){
        cout << "[1]Cube [2]Pyramid [3]Sphere [4]Line" <<endl;
        cout << "> ";
        cin >> input;
        cin.ignore(INT_MAX,'\n');
        type = atoi(input.c_str());

        if(type >0 && type <=4 ){
            break;
        }
        else{
            cout << "The option is not exist,select again" << endl;
        }
    }
    return type;
}

void GMSStateMenu::EditComponent(){
    string input,editName;
    int editId,choice,type;
    cout << "Input Component ID:" <<endl;
    cout << "> " ;

    cin >> input;
    cin.ignore(INT_MAX,'\n');
    editId = atoi(input.c_str());

    bool isExist =gms->GetComponents().CheckIDHasBeenExisted(editId);
    if(isExist){
        cout << "Select item or Return to Menu:" <<endl;
        cout << "[1]\"Type\"[2]\"Name\"[3]Return to Menu" <<endl;
        cout << "> ";

        cin >> input;
        cin.ignore(INT_MAX,'\n');
        choice = atoi(input.c_str());

        switch(choice){
        case 1:
            //進入編輯ID的Type選項
            type = ChooseEditComponentType();
            gms->EditComponentTypeByCommand(editId,GetComponentType(type));
            cout << "Type edit success.";
            break;
        case 2:
            //編輯名稱
            cout << "Input new name:" <<endl;
            getline(cin,editName);
            gms->EditComponentNameByCommand(editId,editName);
            cout << "Name edit success.";
            break;
        case 3:
            break;
        default:
            cout << "No this option!" <<endl;
            break;
        }
 //尚未
    }
    else{
        cout << "The Component ID \"" << editId << "\" is not exist" <<endl;
    }



}
//用來轉換成文字
string GMSStateMenu::GetComponentType(int type){
    if(type == ComponentType::SphereType)
        return "Sphere";
    else if(type ==ComponentType::PyramidType)
        return "Pyramid";
    else if(type ==ComponentType::CubeType)
        return "Cibe";
    else
        return "Line";
}
//顯示Components的資料
void GMSStateMenu::DisplayComponents(){
    vector<Component*> components = this->gms->GetComponents().GetAllComponent();
    cout << "Components:" << endl;
    cout << "------------------------------------------------------" <<endl;
    cout << "   Type   |   ID    |    Name    " <<endl;
    cout << "------------------------------------------------------" <<endl;
    for(vector<Component*>::iterator it = components.begin();it != components.end();it++){
        //使用C語言印出,為了能夠讓印出的格式排版整齊,[0]是擷取自串的字首
        printf("    %c     |   %2d    |    %s\n",(*it)->GetType()[0],(*it)->GetID(),(*it)->GetName().c_str());
    }
}
void GMSStateMenu::DisplayGroups(){
    map<string,Group*> groups = this->gms->GetGroups();
    cout << "Groups:" << endl;
    cout << "------------------------------------------------------" <<endl;
    cout << "   GID   |   Name    |    Member    " <<endl;
    cout << "------------------------------------------------------" <<endl;
    for(map<string,Group*>::iterator it = groups.begin();it != groups.end();it++){
        printf("    %s     |   %s    |    %s\n",it->first.c_str(),(it->second)->GetName().c_str(),(it->second)->GetMembersIdByStringFormat().c_str());
    }
}

string GMSStateMenu::GetXMLPathInput(){
    string filePath;
    cout << "Enter record path" <<endl;
    cout << "> ";
    cin >> filePath;

    //忽略掉換行(因為讀取鍵盤時,Cin會把使用者按下Enter建時的換行碼也讀入放在緩衝區,如果不處理
    //下次cin會先讀取緩衝區的資料直接給電腦處理,而忽略使用者真正想輸入的資料
    cin.ignore(INT_MAX,'\n');

    return filePath;
}

void GMSStateMenu::HandleXML(int commandCode){
    //用來判斷XML載入或存檔檔案時得到的訊息碼
    int errorCode;
    //如果使用者輸入的Command是1 :載入XML ,否則存檔至XML
    if(commandCode == 1){
        errorCode =this->gms->LoadXMLFormatRecord( GetXMLPathInput() );
    }
    else{
        errorCode =this->gms->SaveXMLFormatRecord( GetXMLPathInput() );
    }

    //顯示訊息碼
    if(errorCode == XMLErrorCode::OK ){
        if(commandCode == 1)
            cout << "Record Loaded." <<endl;
        else
            cout << "Record save." <<endl;
    }
    else if(errorCode == XMLErrorCode::Save_PathError){
           cout << "Can not create file,please select other path to save." <<endl;
    }
    else if(errorCode == XMLErrorCode::Open_NotExist){
        cout << "Record of this path and name not exist, please select another path or record name." <<endl;
    }
    else{
        cout << "Open may have some error,try again " << endl;
    }

}
