#ifndef ADDCOMPONENTCOMMAND_H
#define ADDCOMPONENTCOMMAND_H

#include <command.h>
#include <string>
#include "components.h"
#include "component.h"
#include "gmsModel.h"
using namespace std;

//加入Component指令
class AddComponentCommand :public Command
{
public:
    //建構子 取得執行指令所需的資料
    AddComponentCommand(GMSModel* model, string componentType, string componentName);
    ~AddComponentCommand();
    //執行指令
    void execute();
    //反執行指令
    void unexecute();
private:
    //取得Components(Receiver)用來操作(透過Model)
    GMSModel* model;
    //要加入的Type
    string addComponentType;
    //要加入的名稱
    string AddName;
    //要加入時的ID編號
    int addedId;
};

#endif // ADDCOMPONENTCOMMAND_H
