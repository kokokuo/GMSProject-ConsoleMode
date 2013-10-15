#ifndef GMS_H
#define GMS_H

#include <map>
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

    //創造XML檔案
    int CreateXMLFormatRecord(string path);
    //載入XML檔案
    int LoadXMLFormatRecord(string path);

private:

    map<int,TextStateMenu*> textMenuManager;
    TextStateMenu *currentTextMenu; //switch to current mode
    int command;
    bool isWorking;
    XMLManager xmlManager;
};

#endif // GMS_H
