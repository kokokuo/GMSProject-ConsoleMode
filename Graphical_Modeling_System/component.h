#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

using namespace std;

class Component
{
public:
    Component(int id,string name);
    int GetID();
    void SetID(int id);
    string GetName();
    void SetName(string name);
protected:
    int id;
    string name;
};

#endif // COMPONENT_H
