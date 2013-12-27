#include "addNewGroupCommand.h"

AddNewGroupCommand::AddNewGroupCommand(GMSModel* model,string name, vector<int> members)
{
    this->addedId = 0;
    this->addName = name;
    for(vector<int>::iterator it = members.begin();it != members.end();it++){
       this->addMembers.push_back((*it));
    }
    this->model = model;
}
AddNewGroupCommand::~AddNewGroupCommand(){

}
void AddNewGroupCommand::execute(){
    model->AddNewGroup(&addedId,addName,addMembers);
}
void AddNewGroupCommand::unexecute(){
    model->UnDoAddNewGroup(addedId);
}
