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
    void execute(Command* cmd);
    bool redo();
    bool undo();
private:
    stack<Command*> undoCmds;
    stack<Command*> redoCmds;
};

#endif // COMMANDMANAGER_H
