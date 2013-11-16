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
                AddNewGroup();
                break;
            case 2:
                AddMembersToGroup();
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

vector<int> GroupStateMenu::InputMembersIDAndCheck(string outputMessage){
    bool isErrorInput;
    vector<int> membersId;
    string membersStr;
    //檢查有無輸入錯誤
    do{
        isErrorInput = false;
        cout << outputMessage <<endl;
        cout << "> " ;
        cin >> membersStr;

        for(unsigned int index =0 ;index <membersStr.size(); index++){
            if( membersStr[index] == ',')
                membersStr[index] = ' ' ;
            if(isalpha(membersStr[index])){
                isErrorInput = true;
                cout << "Input Error,only for typing id(number)!\n" << endl;
                break;
           }
        }
    }while(isErrorInput);

    if(!isErrorInput){
        stringstream ss;
        ss << membersStr;
        int memberId;
        while(ss >>memberId){
            cout << memberId <<endl;
            membersId.push_back(memberId);
        }
    }
    return membersId;
}
void GroupStateMenu::AddNewGroup(){
    vector<int> wantAddMembersId;
    //檢查ID是否存在於Components
    vector <int> notExistComponentsID;
    cout << "Enter group name" <<endl;
    cout << "> ";

    string inputGroupName;
    cin >> inputGroupName;
    do{
        wantAddMembersId.clear();
        //取得輸入的ID
        wantAddMembersId = InputMembersIDAndCheck("Enter Members");

        for(vector<int>::iterator it = wantAddMembersId.begin();it != wantAddMembersId.end();it++){
            if(!gms->CheckComponentIDHasBeenExisted( *it ) ) //不存在
                notExistComponentsID.push_back(*it );
        }
        if(notExistComponentsID.size() > 1){ //尚未完成
            //尚未完成
            for(vector<int>::iterator it = notExistComponentsID.begin();it != notExistComponentsID.end();it++){
                cout << "The component of ID'" << *it <<"' is not exist";
            }
        }
    }while(notExistComponentsID.size() == 0); //如果沒有不存在的ID 則加入 (作業也沒有說ID只能存在一個Group)
    //加入新的Group
    gms->AddNewGroup(gms->GetCurrentGroupMakerID(),inputGroupName,wantAddMembersId);
    gms->AddGroupID();
}

void GroupStateMenu::AddMembersToGroup(){

}

