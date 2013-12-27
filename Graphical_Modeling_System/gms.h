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
#include "gmsModel.h"
#include "commandManager.h"
#include "addComponentCommand.h"
#include "deleteComponentCommand.h"
#include "addNewGroupCommand.h"
#include "addMembersToGroupCommand.h"
#include "editComponentNameCommand.h"
#include "editComponentTypeCommand.h"


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
    void AddComponentsByCommand(string componentType, string componentName);
    //編輯Component名稱
    void EditComponentNameByCommand(int id,string newName);

    //編輯Component Type
    void EditComponentTypeByCommand(int id,string newType);
    //刪除Component
    bool DeleteComponentByCommand(int id);

    //取得所有Component
    Components GetComponents();

    //取得Groups
    map<string,Group*> GetGroups();

    //取得想要的Group
    Group* FindGroupByGroupId(int groupId);

    //取得產生Component到目前的最大ID
    int GetCurrentComponentMakerID();

    //取得產生Group到目前的最大ID
    int GetCurrentGroupMakerID();

    void ClearCommand(); //清除指令管理員的所有指令紀錄

    //判斷GroupId有無存在
    bool CheckGroupHasBeenExisted(int groupId);
    //判斷這個Component的ID是否存在Components
    bool CheckComponentIDHasBeenExisted(int id);

    //判斷這個MemberId是否存在指定的groupId
    bool CheckMemberIDHasBeenTheGroup(int groupId,int memberId);

    //加入新的Group
    void AddNewGroupByCommand(string name, vector<int> members);

    //加入members ID到Group
    void AddMembersToGroupByCommand(int groupId,vector<int> members);

    bool Redo(); //回傳true表示執行成功,否之師失敗(可能redo到最新的指令)
    bool Undo(); //回傳true表示執行成功,反之則失敗(可能uedo到stack沒資料)
private:

    map<int,TextStateMenu*> textMenuManager; //記錄所有選單的物件
    TextStateMenu *currentTextMenu; //切換至要執行的選單指標
    bool isWorking; //判斷GMS系痛是否在執行中的變數
    CommandManager cmdManager; //Invoker :指令處理管理員,負責執行個指令與紀錄指令做redo與undo

    GMSModel model;
};

#endif // GMS_H
