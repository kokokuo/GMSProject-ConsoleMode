#include "editComponentTypeCommand.h"

EditComponentTypeCommand::EditComponentTypeCommand(GMSModel* model, int editId, string editNewComponentType)
{
    this->model = model;
    this->editId = editId;
    this->editNewComponentType = editNewComponentType;
}
EditComponentTypeCommand::~EditComponentTypeCommand(){

}
void EditComponentTypeCommand::execute(){
    this->originalType = model->EditComponentType(editId,editNewComponentType);

}
void EditComponentTypeCommand::unexecute(){
    model->UnDoEditComponentType(editId,originalType);
}
