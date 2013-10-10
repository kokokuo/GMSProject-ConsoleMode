#ifndef GMS_H
#define GMS_H

#include <map>
#include "textMenuIdEnum.h"
#include "textStateMenu.h"
#include "homeStateMenu.h"
#include "gmsStateMenu.h"
#include "xmlStateMenu.h"

using namespace std;

//GMS = Graphical Modeling System ,it's "controller" Sysytem
class GMS
{
public:
    GMS();
    void RunGMS();
    void SetCloseSystem();
    void SwitchToOtherMenu(TextMenuIdEnum Key); //切換至別的選單State

    //創造XML檔案
    void CreateXMLFormatRecord(string path);
    //載入XML檔案
    void LoadXMLFormatRecord(string path);

private:

    map<TextMenuIdEnum,TextStateMenu*> textMenuManager;
    TextStateMenu *currentTextMenu; //switch to current mode
    int command;
    bool isWorking;
};

#endif // GMS_H
