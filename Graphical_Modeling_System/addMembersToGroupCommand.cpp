#include "addMembersToGroupCommand.h"

AddMembersToGroupCommand::AddMembersToGroupCommand(Groups *groups, int groupId, vector<int> members)
{
    this->groupId = groupId;
    for(vector<int>::iterator it = members.begin();it != members.end();it++){
       this->addMembers.push_back((*it));
    }
    this->groups = groups;
}
AddMembersToGroupCommand::~AddMembersToGroupCommand(){

}
void AddMembersToGroupCommand::execute(){
    //執行加入Member
     groups->AddMembersToGroup(this->groupId,this->addMembers);
}
void AddMembersToGroupCommand::unexecute(){
    //移除剛剛加入的成員
    groups->DeleteMembersFromGroupById(this->groupId,this->addMembers);
}
