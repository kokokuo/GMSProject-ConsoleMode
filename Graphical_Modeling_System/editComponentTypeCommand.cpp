#include "editComponentTypeCommand.h"

EditComponentTypeCommand::EditComponentTypeCommand(Components *components, int editId, string editNewComponentType)
{
    this->components = components;
    this->editId = editId;
    this->editNewComponentType = editNewComponentType;
}
EditComponentTypeCommand::~EditComponentTypeCommand(){

}
void EditComponentTypeCommand::execute(){
    //執行編輯Name
    Component* wantEditComponent = components->GetComponentById(editId);
    this->originalType = wantEditComponent->GetType();
    wantEditComponent->SetComponentType(this->editNewComponentType);
}
void EditComponentTypeCommand::unexecute(){
    //移除執行編輯Name
    Component* wantEditComponent = components->GetComponentById(editId);
    wantEditComponent->SetComponentType(this->originalType);
}
