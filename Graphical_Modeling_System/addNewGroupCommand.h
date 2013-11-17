#ifndef ADDNEWGROUPCOMMAND_H
#define ADDNEWGROUPCOMMAND_H

#include <command.h>
#include <string>
#include "group.h"
#include "groups.h"
#include <sstream>
using namespace std;


class AddNewGroupCommand :public Command
{
public:
    AddNewGroupCommand(Groups* groups,string name, vector<int> members);
    ~AddNewGroupCommand();
    void execute();
    void unexecute();
private:
    Groups* groups;
    string addName;
    vector<int> addMembers;
    int addedId;
};

#endif // ADDNEWGROUPCOMMAND_H
