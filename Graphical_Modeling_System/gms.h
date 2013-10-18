#ifndef GMS_H
#define GMS_H

#include <map>
#include <vector>
#include "component.h"
#include "textMenuKey.h"
#include "textStateMenu.h"
#include "homeStateMenu.h"
#include "gmsStateMenu.h"
#include "xmlStateMenu.h"
#include "xmlManager.h"

using namespace std;

//GMS = Graphical Modeling System ,it's "controller" Sysytem
class GMS
{
public:
    GMS();
    void RunGMS();
    void SetCloseSystem();
    void SwitchToOtherMenu(int Key); //切換至別的選單State

    //創造XML檔案,路徑
    int CreateXMLFormatRecord(string path);
    //載入XML檔案,路徑
    int LoadXMLFormatRecord(string path);

    //是否有載入Record
    bool HasLoadedXMLRecord();

    //實作加入Components部分,id,類型,名稱
    void AddComponents(int id, string componentType, string componentName);

    //取得所有Component
    vector<Component*> GetComponents();

    //取得產生Component到目前的最大ID
    int GetCurrentComponentMakerID();

    //累加ID
    void AddComponentID();
private:
    //清除掉在記憶體中的Components
    void ClearComponents();

    int componentID; //Component的編號
    map<int,TextStateMenu*> textMenuManager; //記錄所有選單的物件
    TextStateMenu *currentTextMenu; //切換至要執行的選單指標
    vector<Component*> components; //記錄所有的Components
    bool isWorking; //判斷GMS系痛是否在執行中的變數
    XMLManager xmlManager; //實際負責XML所有部分的操作,被GMS系統擁有,調用

};

#endif // GMS_H
