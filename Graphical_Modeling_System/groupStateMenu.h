#ifndef GROUPSTATEMENU_H
#define GROUPSTATEMENU_H

#include "textStateMenu.h"
#include "textMenuKey.h"
#include "xmlErrorCode.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class GMS;

class GroupStateMenu : public TextStateMenu
{
public:
    GroupStateMenu(GMS *gms);
    void Update();
    void DisplayMenu();

    void LoadXMLPath(); //輸入載入XML檔案的路徑
    void CreateXMLPath(); //輸入創造XML檔案的路徑


private:

    static const int COMMAND_NUMBER = 3;
};

#endif // GROUPSTATEMENU_H
