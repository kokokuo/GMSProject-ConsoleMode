#include "editComponentNameCommand.h"

EditComponentNameCommand::EditComponentNameCommand(Components *components, int editId, string editNewName)
{
    this->components = components;
    this->editId = editId;
    this->editNewName = editNewName;
}
EditComponentNameCommand::~EditComponentNameCommand(){

}

void EditComponentNameCommand::execute(){
    //執行編輯Name
    Component* wantEditComponent = components->GetComponentById(editId);
    this->originalName = wantEditComponent->GetName();
    wantEditComponent->SetName(this->editNewName);
}
void EditComponentNameCommand::unexecute(){
    //移除執行編輯Name
    Component* wantEditComponent = components->GetComponentById(editId);
    wantEditComponent->SetName(this->originalName);
}
