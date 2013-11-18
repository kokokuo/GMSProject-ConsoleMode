#include "commandManager.h"

CommandManager::CommandManager()
{
}
CommandManager::~CommandManager(){
    while (!this->undoCmds.empty()) {
        Command* c = undoCmds.top();
        undoCmds.pop();
        delete c;
    }
    while (!this->redoCmds.empty()) {
        Command* c = redoCmds.top();
        redoCmds.pop();
        delete c;
    }
}
void CommandManager::execute(Command *cmd){
    cmd->execute();
    this->undoCmds.push(cmd);

    // cleanup and release redoable commands
    while (!this->redoCmds.empty()) {
        Command* c = redoCmds.top();
        redoCmds.pop();
        delete c;
    }
}
bool CommandManager::redo(){
    if (this->redoCmds.size() != 0){
        Command* c = this->redoCmds.top();
        this->redoCmds.pop();
        c->execute(); // redo the command
        this->undoCmds.push(c);
        return true;
    }
    else
        return false;
}
bool CommandManager::undo(){
    if (this->undoCmds.size() != 0){
        Command* c =  this->undoCmds.top();
        this->undoCmds.pop();
        c->unexecute(); // undo the command
        this->redoCmds.push(c);
        return true;
    }
    else
        return false;
}
void CommandManager::ClearCmd(){
    while (!this->undoCmds.empty()) {
        Command* c = undoCmds.top();
        undoCmds.pop();
        delete c;
    }
    while (!this->redoCmds.empty()) {
        Command* c = redoCmds.top();
        redoCmds.pop();
        delete c;
    }
}
