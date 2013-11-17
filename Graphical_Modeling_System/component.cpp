#include "component.h"

//ComponentType靜態類別參數設定
int ComponentType::CubeType =1;
int ComponentType::PyramidType = 2;
int ComponentType::SphereType = 3;

//=================================================

//Component
Component::Component(int id, string componentType, string name)
{
    this->id = id;
    this->type = componentType;
    this->name = name;
}
Component::Component( Component& c){
    this->id = c.GetID();
    this->type = c.GetType();
    this->name = c.GetName();
}
int Component::GetID(){
    return this->id;
}
string Component::GetName(){
    return this->name;
}

string Component::GetType(){
    return this->type;
}

