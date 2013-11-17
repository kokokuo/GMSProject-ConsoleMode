#include "group.h"

Group::Group(int id, string name, vector<int> members)
{
    this->id = id;
    this->groupName = name;
    for(vector<int>::iterator it = members.begin();it != members.end();it++){
        this->membersId.push_back((*it));
    }
}
Group::~Group(){
    membersId.clear();
}
//取得ID
int Group::GetID(){
    return this->id;
}
//取得Group名稱
string Group::GetName(){
    return this->groupName;
}
//取得成員ID
vector<int> Group::GetMembersId(){
    return this->membersId;
}
string Group::GetMembersIdByStringFormat(){
    stringstream ss;
    //不需考慮無資料的情況,作業的部分輸入的範例代表新增Group時一定要有資料
    if(membersId.size() >0){
        ss << membersId[0];
        if(membersId.size() >1){
            for(vector<int>::iterator it = membersId.begin()+1 ;it != membersId.end();it++){
                ss << "," << (*it) ;
            }
        }
    }
    return ss.str();
}
//加入成員
void Group::AddMembers(vector<int> members){
    for(vector<int>::iterator it = members.begin();it != members.end();it++){
        this->membersId.push_back((*it));
    }
}
//判斷memberID有無存在
bool Group::CheckMemberHasBeenExisted(int memberId){
    for(vector<int>::iterator it = membersId.begin();it != membersId.end();it++){
        if((*it) == memberId ){
            return true;
        }
    }
    return false;
}
