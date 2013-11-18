#include "deleteComponentCommand.h"

DeleteComponentCommand::DeleteComponentCommand(Components* components,int id)
{
    this->components = components;
    this->removedId = id;
}
DeleteComponentCommand::~DeleteComponentCommand(){

}
void DeleteComponentCommand::execute(){
    //先複製出一份要移除的Component (復原時要使用)
    //加入point,傳入指向的實際物件記憶體區塊到Copy Constructor中
    removedComponent = new Component( *(this->components->GetComponentById(removedId)) );
    //移除
    this->components->DeleteComponentFromList(removedId);
}
void DeleteComponentCommand::unexecute(){
    this->components->AddComponentToList(removedComponent);
    //不需遞減ID 此部分只加放回移除的Component
}
