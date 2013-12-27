#include "editComponentNameCommand.h"

EditComponentNameCommand::EditComponentNameCommand(GMSModel *model, int editId, string editNewName)
{
    this->editNewName = editNewName;
    this->editId = editId;
    this->model = model;
}
EditComponentNameCommand::~EditComponentNameCommand(){

}

void EditComponentNameCommand::execute(){
   this->originalName = model->EditComponentName(editId,editNewName);
}
void EditComponentNameCommand::unexecute(){
    model->UnDoEditComponentName(editId,originalName);
}
