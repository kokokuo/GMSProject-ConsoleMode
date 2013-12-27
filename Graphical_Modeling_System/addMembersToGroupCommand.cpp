#include "addMembersToGroupCommand.h"

AddMembersToGroupCommand::AddMembersToGroupCommand( GMSModel* model, int groupId, vector<int> members)
{
    this->groupId = groupId;
    for(vector<int>::iterator it = members.begin();it != members.end();it++){
       this->addMembers.push_back((*it));
    }
    this->model = model;
}
AddMembersToGroupCommand::~AddMembersToGroupCommand(){

}
void AddMembersToGroupCommand::execute(){
   model->AddMembersToGroup(groupId,addMembers);
}
void AddMembersToGroupCommand::unexecute(){
   model->UnDoAddMembersToGroup(groupId,addMembers);
}
