#include "addComponentCommand.h"

AddComponentCommand::AddComponentCommand(Components* components,string componentType, string componentName)
{
    this->addedId = 0;
    this->addComponentType = componentType;
    this->AddName = componentName;
    this->components = components;
}
AddComponentCommand::~AddComponentCommand(){

}
void AddComponentCommand::execute(){
    if(addedId ==0) //等於0表示尚未加入Componenet(如此判斷下次加入回去才不會影響ID
        addedId = components->GetCurrentGeneratedComponentID();
    //創建新的Component並加入智vector中
    Component *component = new Component(addedId,addComponentType,AddName);
    this->components->AddComponentToList(component);
    //累加ID
    this->components->AddComponentID();
}
void AddComponentCommand::unexecute(){
    this->components->DeleteComponentFromList(addedId);
    //遞減ID 回到加入之前生產的ID編號
    this->components->MinusComponentID();
}
