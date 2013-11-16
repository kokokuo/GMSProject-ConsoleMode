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
    void AddComponents(int id, string componentType, string componentName);

    //刪除Component
    bool DeleteComponent(int id);

    //取得所有Component
    vector<Component*> GetComponents();

    //取得產生Component到目前的最大ID
    int GetCurrentComponentMakerID();

    //累加ID
    void AddComponentID();
private:

    int componentID; //Component的編號
    map<int,TextStateMenu*> textMenuManager; //記錄所有選單的物件
    TextStateMenu *currentTextMenu; //切換至要執行的選單指標
    Components components; //記錄所有的Components
    bool isWorking; //判斷GMS系痛是否在執行中的變數
    XMLManager xmlManager; //實際負責XML所有部分的操作,被GMS系統擁有,調用

};

#endif // GMS_H
