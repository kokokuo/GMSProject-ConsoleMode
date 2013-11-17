#include "addNewGroupCommand.h"

AddNewGroupCommand::AddNewGroupCommand(Groups* groups,string name, vector<int> members)
{
    this->addedId = 0;
    this->addName = name;
    for(vector<int>::iterator it = members.begin();it != members.end();it++){
       this->addMembers.push_back((*it));
    }
    this->groups = groups;
}
AddNewGroupCommand::~AddNewGroupCommand(){

}
void AddNewGroupCommand::execute(){
    if(addedId ==0)
       addedId = this->groups->GetCurrentGeneratedGroupId(); //等於0表示尚未加入Componenet(如此判斷下次加入回去才不會影響ID
    stringstream ss;
    ss << "G" << addedId; //轉換成GID 作為map的Key值
    Group* newGroup = new Group(addedId,addName,addMembers);
    this-> groups->AddGroup(ss.str(),newGroup);
    this->groups->AddGroupID();
}
void AddNewGroupCommand::unexecute(){
    this->groups->DeleteGroup(addedId);
    this->groups->MinusGroupID();
}
