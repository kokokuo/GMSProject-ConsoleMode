#include "components.h"

Components::Components()
{
}
void Components::AddComponentToList(int id, string componentType, string componentName){
    //創建新的Component並加入智vector中
    Component *component = new Component(id,componentType,componentName);
    components.push_back(component);
}
//從vector中刪除component
void Components::DeleteComponentFromList(int id){
    for(unsigned int index = 0; index < components.size();index ++){
        if(components[index]->GetID() == id ){
            Component* c = components[index];
            components.erase((components.begin() + index));
            delete c;
            break;
        }
    }
}
vector<Component*>  Components::GetComponts(){
    return this->components;
}
//從Load檔案中取得Components
void Components::SetComponentsFromLoadData(vector<Component *> components){
    this->components = components;
}
//清除Components
void Components::ClearComponents(){
    //重新載入新的XML,要把原先的資料先全部移除,避免有Memory Leak,再從新添加從XML載入的資料
    if(components.size() > 0){
        for(vector<Component*>::iterator it = components.begin();it != components.end();it++){
            delete (*it);
        }
        components.clear();
    }
}
//判斷ID有無存在
bool Components::CheckIDHasBeenExisted(int id){
    for(vector<Component*>::iterator it =  this->components.begin();it != this->components.end();it++){
        if((*it)->GetID() == id){
            return true;
        }
    }
    return false;

}
