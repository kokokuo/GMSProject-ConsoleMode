#include "xmlStateMenu.h"
#include "GMS.h"


XMLStateMenu::XMLStateMenu(GMS *gms) : TextStateMenu(gms)
{
}
void XMLStateMenu::DisplayMenu(){
    cout << endl;
    cout << "New/Load a XML record" <<endl;
    cout << "[1] Create New XML record" <<endl;
    cout << "[2] Load XML record" <<endl;
    cout << "[3] Back to GMS Menu" <<endl;
    cout << "> ";

}
void XMLStateMenu::Update(){
    //輸入正確
    if(this->CheckInput((this->COMMAND_NUMBER))){
        switch(command)
        {
            case 1: case 2:
            HandleXML(command);
                break;
            case 3:
                this->gms->SwitchToOtherMenu(TextMenuKey::GMSMenuKey);
                break;
        }
    }
    else{
        cout << "\nOption not Exist,please select again\n"<<endl ;
    }
}
string XMLStateMenu::GetXMLPathInput(){
    string filePath;
    cout << "Enter record path" <<endl;
    cout << "> ";
    cin >> filePath;

    //忽略掉換行(因為讀取鍵盤時,Cin會把使用者按下Enter建時的換行碼也讀入放在緩衝區,如果不處理
    //下次cin會先讀取緩衝區的資料直接給電腦處理,而忽略使用者真正想輸入的資料
    cin.ignore(INT_MAX,'\n');

    return filePath;
}

void XMLStateMenu::HandleXML(int commandCode){
    //用來判斷XML載入或創造檔案時得到的訊息碼
    int errorCode;
    //如果使用者輸入的Command是1 :創造一個XML ,否則載入XML
    if(commandCode == 1){
        errorCode =this->gms->CreateXMLFormatRecord( GetXMLPathInput() );
    }
    else{
        errorCode =this->gms->LoadXMLFormatRecord( GetXMLPathInput() );
    }

    //顯示訊息碼
    if(errorCode == XMLErrorCode::OK ){
        if(commandCode == 1)
            cout << "Record created." <<endl;
        else
            cout << "Record Loaded." <<endl;
    }
    else if(errorCode == XMLErrorCode::Create_HasExisted){
        cout << "Record of this path and name already exist, please select another path or record name." <<endl;
    }
    else if(errorCode == XMLErrorCode::Create_PathError){
           cout << "This path not exist." <<endl;
    }
    else if(errorCode == XMLErrorCode::Open_NotExist){
        cout << "Record of this path and name not exist, please select another path or record name." <<endl;
    }
    else{
        cout << "Open may have some error,try again " << endl;
    }

}

