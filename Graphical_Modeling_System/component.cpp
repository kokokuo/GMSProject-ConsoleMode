#include "component.h"

//ComponentType靜態類別參數設定
int ComponentType::CubeType =1;
int ComponentType::PyramidType = 2;
int ComponentType::SphereType = 3;

//=================================================

//Component
Component::Component(int id, int componentType, string name)
{
    this->id = id;
    if(componentType == ComponentType::SphereType){
        this->type = "Sphere";
    }
    else if(componentType == ComponentType::PyramidType){
        this->type = "Pyramid";
    }
    else if(componentType == ComponentType::CubeType){
        this->type = "Cube";
    }
    this->name = name;
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
