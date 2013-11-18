#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include "addComponentCommand.h"
#include "deleteComponentCommand.h"
#include "command.h"
#include <stack>


using namespace std;

class CommandManager
{
public:
    CommandManager();
    virtual ~CommandManager();
    //加入指令並執行
    void execute(Command* cmd);
    //重做
    bool redo();
    //復原
    bool undo();
    //清除所有指令(載入新的檔案時才會使用,把舊的相關指令清掉,重新開始)
    void ClearCmd();

private:
    stack<Command*> undoCmds;
    stack<Command*> redoCmds;
};

#endif // COMMANDMANAGER_H
