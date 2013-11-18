#ifndef DELETECOMPONENTCOMMAND_H
#define DELETECOMPONENTCOMMAND_H

#include <command.h>
#include <string>
#include "components.h"
#include "component.h"
using namespace std;

//刪除Components的指令
class DeleteComponentCommand : public Command
{
public:
    //建構子 取得執行指令所需的資料
    DeleteComponentCommand(Components *components, int id);
    ~DeleteComponentCommand();
    //執行指令
    void execute();
    //反執行指令
    void unexecute();
private:
    //紀錄被移除時的Component資料(透過Copy Constructor),如此復原時可以再把Component加入
    Component* removedComponent;
    //要移除的ID
    int removedId;
    //取得Components(Receiver)用來操作
    Components* components;
};

#endif // DELETECOMPONENTCOMMAND_H
