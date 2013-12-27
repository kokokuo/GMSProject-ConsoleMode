#include "addComponentCommand.h"

AddComponentCommand::AddComponentCommand(GMSModel* model,string componentType, string componentName)
{
    this->addedId = 0;
    this->addComponentType = componentType;
    this->AddName = componentName;
    this->model = model;
}
AddComponentCommand::~AddComponentCommand(){

}
void AddComponentCommand::execute(){
    model->AddComponents(addComponentType,AddName,&addedId);
}
void AddComponentCommand::unexecute(){
    model->UnDoAddComponents(addedId);
}
