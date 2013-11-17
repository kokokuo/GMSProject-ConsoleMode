#ifndef GROUPSTATEMENU_H
#define GROUPSTATEMENU_H

#include "textStateMenu.h"
#include "textMenuKey.h"
#include "xmlErrorCode.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

class GMS;

class GroupStateMenu : public TextStateMenu
{
public:
    GroupStateMenu(GMS *gms);
    void Update();
    void DisplayMenu();

private:
    //加入新的Group
    void AddNewGroup();
    //加入Members到Group
    void AddMembersToGroup();
    //輸入MembersID與判斷有無輸入錯誤
    //為了取得輸入正確的member string用來印出,所以傳入 string pointer
    vector<int> InputMembersIDAndCheck(string outputMessage, string* inputMemberStr);

    static const int COMMAND_NUMBER = 3;
};

#endif // GROUPSTATEMENU_H
