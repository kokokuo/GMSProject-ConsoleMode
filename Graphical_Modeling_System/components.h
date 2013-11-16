#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "component.h"
#include "vector"

using namespace std;

class Components
{
public:
    Components();
    //加入Components
    void AddComponentToList(int id, string componentType, string componentName);
    //刪除Components
    void DeleteComponentFromList(int id);
    //取得Component
    vector<Component*> GetComponts();
    void SetComponentsFromLoadData(vector<Component*> components);
    void ClearComponents();
private:
    vector<Component*> components;
};

#endif // COMPONENTS_H
