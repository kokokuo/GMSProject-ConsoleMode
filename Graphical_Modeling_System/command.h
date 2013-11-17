#ifndef COMMAND_H
#define COMMAND_H

#include<string>
using namespace std;

class Command
{
public:
    Command();
    virtual ~Command();
    virtual void execute() = 0;
    virtual void unexecute() = 0;
};

#endif // COMMAND_H
