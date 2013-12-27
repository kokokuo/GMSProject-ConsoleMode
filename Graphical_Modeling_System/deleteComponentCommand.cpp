#include "deleteComponentCommand.h"

DeleteComponentCommand::DeleteComponentCommand(GMSModel* model,int id)
{
    this->model = model;
    this->removedId = id;
}
DeleteComponentCommand::~DeleteComponentCommand(){

}
void DeleteComponentCommand::execute(){
    removedComponent = model->DeleteComponent(removedId);
}
void DeleteComponentCommand::unexecute(){
    model->UnDoDeleteComponent(removedComponent);
}
