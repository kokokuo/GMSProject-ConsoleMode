#ifndef GMS_H
#define GMS_H

#include <map>
#include <vector>
#include "component.h"
#include "components.h"
#include "textMenuKey.h"
#include "textStateMenu.h"
#include "homeStateMenu.h"
#include "gmsStateMenu.h"
#include "groupStateMenu.h"
#include "xmlManager.h"
#include "group.h"
#include "groups.h"
#include "commandManager.h"
#include "addComponentCommand.h"
#include "deleteComponentCommand.h"
#include "addNewGroupCommand.h"

using namespace std;

//GMS = Graphical Modeling System ,it's "controller" Sysytem
class GMS
{
public:
    GMS();
    void RunGMS(); //執行GMS系統
    void SetCloseSystem(); //設定關閉視窗
    void SwitchToOtherMenu(int Key); //切換至別的選單State,key為選單的編號,請參考TextMenuKey靜態類別

    //存檔XML檔案,路徑
    int SaveXMLFormatRecord(string path);
    //載入XML檔案,路徑
    int LoadXMLFormatRecord(string path);

    //實作加入Components部分,id,類型,名稱
    void AddComponents(string componentType, string componentName);

    //刪除Component
    bool DeleteComponent(int id);

    //取得所有Component
    vector<Component*> GetComponents();

    //取得Groups
    map<string,Group*> GetGroups();

    //取得想要的Group
    Group* FindGroupByGroupId(int groupId);

    //取得產生Component到目前的最大ID
    int GetCurrentComponentMakerID();

    //取得產生Group到目前的最大ID
    int GetCurrentGroupMakerID();



    //判斷GroupId有無存在
    bool CheckGroupHasBeenExisted(int groupId);
    //判斷這個Component的ID是否存在Components
    bool CheckComponentIDHasBeenExisted(int id);

    //判斷這個MemberId是否存在指定的groupId
    bool CheckMemberIDHasBeenTheGroup(int groupId,int memberId);

    //加入新的Group
    void AddNewGroup(string name, vector<int> members);

    //加入members ID到Group
    void AddMembersToGroup(int groupId,vector<int> members);

    bool Redo();
    bool Undo();
private:

    map<int,TextStateMenu*> textMenuManager; //記錄所有選單的物件
    TextStateMenu *currentTextMenu; //切換至要執行的選單指標
    Components components; //記錄所有的Components
    bool isWorking; //判斷GMS系痛是否在執行中的變數
    XMLManager xmlManager; //實際負責XML所有部分的操作,被GMS系統擁有,調用
    Groups groups; //紀錄Groups
    CommandManager cmdManager;
};

#endif // GMS_H
