#ifndef ADDMEMBERSTOGROUPCOMMAND_H
#define ADDMEMBERSTOGROUPCOMMAND_H


#include <command.h>
#include <string>
#include "group.h"
#include "groups.h"
#include "gmsModel.h"
using namespace std;

//加入Members到指定的Group指令
class AddMembersToGroupCommand :public Command
{
public:
    //建構子 取得執行指令所需的資料
    AddMembersToGroupCommand( GMSModel* model,int groupId, vector<int> members);
    ~AddMembersToGroupCommand();
    //執行指令
    void execute();
    //反執行指令
    void unexecute();
private:
    //取得Groups (Receiver) 用來做相關操作(透過Model)
     GMSModel* model;
    //要加入Members的groupID
    int groupId;
    //要加入的Members
    vector<int> addMembers;
};

#endif // ADDMEMBERSTOGROUPCOMMAND_H
