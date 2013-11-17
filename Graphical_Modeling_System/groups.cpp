#include "groups.h"

Groups::Groups()
{
}

void Groups::AddGroup(Group *group){
    stringstream ss;
    ss << "G" << group->GetID(); //轉換成GID 作為map的Key值
    groups.insert( pair<string,Group*>(ss.str(),group) );

}
//加入Members到指定Group (使用前記得先呼叫 CheckGroupHasBeenExisted)判斷
void Groups::AddMembersToGroup(int groupId,vector<int> members){
    stringstream ss;
    ss << "G" << groupId; //轉換成GID 作為map的Key值直接取得value
    groups[ss.str()]->AddMembers(members);
}

//判斷Group是否已存在
bool Groups::CheckGroupHasBeenExisted(int groupId){
    for(map<string,Group*>::iterator it =  this->groups.begin();it != this->groups.end();it++){
        if( (it->second)->GetID() == groupId  ){
            return true;
        }
    }
    return false;
}
//取得Group(使用使方法前請先呼叫 CheckGroupHasBeenExisted 判斷有無存在)
Group* Groups::GetGroup(int groupId){
    stringstream ss;
    ss << "G" << groupId; //轉換成GID 作為map的Key值直接取得value
    return groups[ss.str()];

}
//取得所有Group
map<string,Group*> Groups::GetGroups(){
    return this->groups;
}
//清除所有Group
void Groups::ClearAllGroup(){
    for(map<string,Group*>::iterator it =  this->groups.begin();it != this->groups.end();it++){
        delete it->second;
    }
    groups.clear();
}
//從檔案中從檔案中加入Group
void Groups::SetGroupsFromLoadData(Group* group){
    stringstream ss;
    ss << "G" <<  group->GetID(); //轉換成GID 作為map的Key值直接取得value
    groups[ss.str()] = group;

}
