#ifndef GROUPS_H
#define GROUPS_H

#include "group.h"
#include <map>
#include <sstream>

using namespace std;

class Groups
{
public:
    Groups();
    //新增Group
    void AddGroup(Group* group);
    //加入Members到指定Group
    void AddMembersToGroup(int groupId,vector<int> members);
    //判斷Group是否已存在,回傳ID
    bool CheckGroupHasBeenExisted(int groupId);
    //取得Group
    Group* GetGroup(int groupId);
    //取得所有Group
    map<string,Group*> GetGroups();
private:
    map<string,Group*> groups;
};

#endif // GROUPS_H
