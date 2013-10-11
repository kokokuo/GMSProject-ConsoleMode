#ifndef XMLSTATEMENU_H
#define XMLSTATEMENU_H

#include "textStateMenu.h"
#include "textMenuKey.h"
#include "xmlErrorCode.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class GMS;

class XMLStateMenu : public TextStateMenu
{
public:
    XMLStateMenu(GMS *gms);
    void Update();
    void DisplayMenu();

    void LoadXMLPath(); //輸入載入XML檔案的路徑
    void CreateXMLPath(); //輸入創造XML檔案的路徑

    string GetXMLPathInput(); //取得使用者輸入XML檔案路徑
    void HandleXML(int commandCode); //處理並顯示創造/載入檔案後的訊息
private:

    static const int COMMAND_NUMBER = 3;
};

#endif // XMLSTATEMENU_H
