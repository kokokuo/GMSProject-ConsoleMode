#ifndef GMS_H
#define GMS_H

#include <map>
#include "TextMenuIdEnum.h"
#include "textmenu.h"
#include "homemenu.h"
#include "gmsmenu.h"

using namespace std;
//Controller Sysytem
class GMS
{
public:
    GMS();
    void RunGMS();

private:

    map<TextMenuIdEnum,TextMenu*> textMenuManager;
    TextMenu *currentTextMenu; //switch to current mode
    int command;
    bool isWorking;
};

#endif // GMS_H
