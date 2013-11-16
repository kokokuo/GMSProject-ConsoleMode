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
    //從Load檔案中取得Components
    void SetComponentsFromLoadData(vector<Component*> components);
    //清除Components
    void ClearComponents();
    //判斷ID是否存在
    bool CheckIDHasBeenExisted(int id);
private:
    vector<Component*> components;
};

#endif // COMPONENTS_H
