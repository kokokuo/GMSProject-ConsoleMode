#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

using namespace std;

class ComponentType{
public:
    static int SphereType;
    static int PyramidType;
    static int CubeType;
};

//=================================================


class Component
{
public:
    //加入編號，類型，與元件名稱
    Component(int id, string componentType, string name);
    //copy constructor
    Component(Component &c);
    ~Component(){}
    int GetID(); //取得ID
    string GetType(); //取得Type
    string GetName(); //取得名稱

private:
    int id;
    string type;
    string name;
};

#endif // COMPONENT_H
