#ifndef COMMAND_H
#define COMMAND_H

#include<string>
using namespace std;

//製作Command Pattern使用
class Command
{
public:
    Command();
    virtual ~Command();
    //執行指令
    virtual void execute() = 0;
    //反執行指令
    virtual void unexecute() = 0;
};

#endif // COMMAND_H
