#include "component.h"

Component::Component(int id,string name)
{
    this->id = id;
    this->name = name;
}
int Component::GetID(){
    return this->id;
}
void Component::SetID(int id){
    this->id = id;
}

void Component::SetName(string name){
    this->name = name;
}
string Component::GetName(){
    return this->name;
}
