#ifndef GROUP_H
#define GROUP_H

#include"component.h"
#include <string>
#include <vector>

using namespace std;

class Group
{
public:
    //建構Group
    Group(int id,string name,vector<int> members);
    //取得ID
    int GetID();
    //取得Group名稱
    string GetName();
    //取得成員ID
    vector<int> GetMembersId();
    //加入成員
    void AddMembers(vector<int> members);
    //確認MemberID是否存在
    bool CheckMemberHasBeenExisted(int memberId);
private:
    int id;
    string groupName;
    vector<int> membersId;
};

#endif // GROUP_H
