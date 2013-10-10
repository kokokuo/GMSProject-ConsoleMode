#include "xmlStateMenu.h"
#include "GMS.h"


XMLStateMenu::XMLStateMenu(GMS *gms) : TextStateMenu(gms)
{
}
void XMLStateMenu::DisplayMenu(){
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
            case 1:
                //創造XML檔案
                CreateXMLPath();
                break;
            case 2:
                //讀取XML檔案
                break;
            case 3:
                this->gms->SwitchToOtherMenu(GMSMenuKey);
                break;
        }
    }
    else{
        cout << "\nOption not Exist,please select again\n"<<endl ;
    }
}
void XMLStateMenu::LoadXMLPath(){


}

void XMLStateMenu::CreateXMLPath(){ //尚未完成

    string filePath;
    cout << "Enter new record path" <<endl;
    cout << "> ";
    cin >> filePath;
    cin.ignore(INT_MAX,'\n');

    QFile file( QString::fromStdString(filePath) );
    if ( file.open( QIODevice::ReadWrite ) ) {
            QTextStream stream( &file );
            stream << "Hello" << "\n";
            file.close();
        }

}
