#include "group.h"

Group::Group(int id, string name, vector<int> members)
{
    this->id = id;
    this->groupName = name;
    for(vector<int>::iterator it = members.begin();it != members.end();it++){
        this->membersId.push_back((*it));
    }
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
