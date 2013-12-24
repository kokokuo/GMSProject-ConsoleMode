#ifndef EDITCOMPONENTTYPECOMMAND_H
#define EDITCOMPONENTTYPECOMMAND_H

#include <command.h>
#include <string>
#include "components.h"
#include "component.h"
using namespace std;

class EditComponentTypeCommand : public Command
{
public:
    EditComponentTypeCommand(Components* components,int editId,string editNewComponentType);
    ~EditComponentTypeCommand();
    //執行指令
    void execute();
    //反執行指令
    void unexecute();
private:

    //取得Components(Receiver)用來操作
    Components* components;
    //要修改成的Type
    string editNewComponentType;
    string originalType; //原來的Type
    //要修改的ID編號
    int editId;
};

#endif // EDITCOMPONENTYYPECOMMAND_H
