#ifndef EDITCOMPONENTNAMECOMMAND_H
#define EDITCOMPONENTNAMECOMMAND_H

#include <command.h>
#include <string>
#include "components.h"
#include "component.h"
using namespace std;

class EditComponentNameCommand : public Command
{
public:
    EditComponentNameCommand(Components* components,int editId,string editNewName);
    ~EditComponentNameCommand();
    //執行指令
    void execute();
    //反執行指令
    void unexecute();
private:
    //取得Components(Receiver)用來操作
    Components* components;
    //要修改的名稱
    string editNewName;
    //原先的名稱
    string originalName;
    //要修改的ID編號
    int editId;
};

#endif // EDITCOMPONENTNAME_H
