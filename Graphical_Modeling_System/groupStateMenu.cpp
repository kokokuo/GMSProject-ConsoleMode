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

//輸入MembersID與判斷有無輸入錯誤
//為了取得輸入正確的member string用來印出,所以傳入 string pointer
vector<int> GroupStateMenu::InputMembersIDAndCheck(string outputMessage,string* inputMemberStr){
    bool isErrorInput;
    vector<int> membersId;
    string membersStr;
    //檢查有無輸入錯誤
    do{
        isErrorInput = false;
        cout << outputMessage <<endl;
        cout << "> " ;
        cin >> *inputMemberStr;
        cin.ignore(INT_MAX,'\n');

        membersStr = *inputMemberStr;
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
           // cout << memberId <<endl; 測試用
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

    string inputGroupName,inputMemberStr;
    cin >> inputGroupName;
    cin.ignore(INT_MAX,'\n');
    do{
        wantAddMembersId.clear();
        notExistComponentsID.clear();
        //取得輸入的ID
        wantAddMembersId = InputMembersIDAndCheck("Enter Members",&inputMemberStr);
        //判斷輸入的ID是否是存在的Component
        for(vector<int>::iterator it = wantAddMembersId.begin();it != wantAddMembersId.end();it++){
            if(!gms->CheckComponentIDHasBeenExisted( *it ) ) //不存在
                notExistComponentsID.push_back(*it );
        }
        //如果有不存在的Component id 表示輸入錯誤,印出錯誤訊息,並繼續在詢問一次
        if(notExistComponentsID.size() > 0){
            cout << "The component of ID'" << notExistComponentsID[0] <<"' is not exist" ;
            if(notExistComponentsID.size() > 1){
                for(vector<int>::iterator it = notExistComponentsID.begin()+1;it != notExistComponentsID.end();it++){
                    cout << " ,and the component of ID'" << *it <<"' is not exist";
                }
            }
            cout << endl;
        }

    }while(notExistComponentsID.size() != 0); //如果有不存在的ID 則再要求使用者輸入一次 (即便現在完全無Component資料.... 問了助教沒回應...)

    //加入新的Group
    stringstream ss;
    ss << "G" << gms->GetCurrentGroupMakerID() ;
    gms->AddNewGroup(gms->GetCurrentGroupMakerID(),inputGroupName,wantAddMembersId);
    //給予加入成功的回饋
    cout << "The new group '" << inputGroupName << "' has been created, ID:" << ss.str() << ",members:" << inputMemberStr <<endl;

    //增加ID編號
    gms->AddGroupID();


}

void GroupStateMenu::AddMembersToGroup(){
    vector<int> wantAddMembersId;

    //檢查已經存在此Group中的component ID
    vector <int> hasExistedGroupComponentId;
    //檢查ID是否存在於Components
    vector <int> notExistComponentsID;
    string inputMemberStr;
    string inputGroupIdStr; //取得字串型態的輸入
    int inputGroupId;

    //取得輸入的Group ID
    do{
        cout << "Enter group ID" <<endl;
        cout << "> ";
        cin >> inputGroupIdStr;
        cin.ignore(INT_MAX,'\n');
        inputGroupId = atoi(inputGroupIdStr.c_str());
        if(inputGroupId ==0)
                cout << "Please input number!" << endl;
    }while(inputGroupId ==0);

    //檢查Group ID是否存在
    if(gms->CheckGroupHasBeenExisted((inputGroupId))){
        do{
            wantAddMembersId.clear();
            hasExistedGroupComponentId.clear();
            notExistComponentsID.clear();
            //取得輸入的ID
            wantAddMembersId = InputMembersIDAndCheck("Enter Members",&inputMemberStr);
            //判斷輸入的ID是否是存在的Component
            for(vector<int>::iterator it = wantAddMembersId.begin();it != wantAddMembersId.end();it++){
                //要加入的MemberID 是不存在的Component
                if(!gms->CheckComponentIDHasBeenExisted( *it ) )
                    notExistComponentsID.push_back(*it );
                else{ //若是存在的Component
                    //並判斷此Component是否已存在Group的Member中
                    if(gms->CheckMemberIDHasBeenTheGroup( inputGroupId,(*it) ) )
                        hasExistedGroupComponentId.push_back((*it));
                }
            }

            //判斷有無已存在Group的Member中的Component並印出
            if(hasExistedGroupComponentId.size() >0 ){
                //如果有不存在的Component id 表示輸入錯誤,印出錯誤訊息,並繼續在詢問一次
                cout << "The component of ID'" << hasExistedGroupComponentId[0];
                //如果大於1筆 繼續印出
                if(hasExistedGroupComponentId.size() > 1){
                    for(vector<int>::iterator it = hasExistedGroupComponentId.begin()+1;it != hasExistedGroupComponentId.end();it++){
                        cout << " ,and the component of ID'" << *it <<"'";
                    }
                }
                cout <<"' is already contained in the group '";
                cout << gms->FindGroupByGroupId(inputGroupId)->GetName() << "'.";
            }
            //如果有不存在的Component id 表示輸入錯誤,印出錯誤訊息,並繼續在詢問一次
            if(notExistComponentsID.size() > 0){
                cout << "The component of ID'" << notExistComponentsID[0] <<"' is not exist" ;
                if(notExistComponentsID.size() > 1){
                    for(vector<int>::iterator it = notExistComponentsID.begin()+1;it != notExistComponentsID.end();it++){
                        cout << " ,and the component of ID'" << *it <<"' is not exist";
                    }
                }
                cout << endl;
            }

        //如果有已經存在Group的Memebr 或不存在的Component ID  則再要求使用者輸入一次 (即便現在整個完全無Component資料.... 問了助教沒回應...)
        }while(notExistComponentsID.size() != 0 || hasExistedGroupComponentId.size() >0 );

        //加入新Members
        gms->AddMembersToGroup(inputGroupId,wantAddMembersId);

        //給予加入成功的回饋
        cout << "Components of ";
        for(vector<int>::iterator it = wantAddMembersId.begin();it != wantAddMembersId.end();it++){
            cout << "'" << *it << "'" ;
        }
        cout << "ID have been added to the group '" << gms->FindGroupByGroupId(inputGroupId)->GetName() <<"'.";

    }
    else
        cout << "The group of ID '" << inputGroupId <<"' is not existed"; //ID不存在
}

