#ifndef HOMEMENU_H
#define HOMEMENU_H

#include "textStateMenu.h"
#include "textMenuKey.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class GMS;

class HomeStateMenu : public TextStateMenu
{
public:
    HomeStateMenu(GMS *gms);
    void DisplayMenu(); //顯示畫面(override TextStateMenu的方法)
    void Update(); //更新邏輯(override TextStateMenu的方法)

private:
    bool IsFirstCome; //是否第一次進來選單
    static const int COMMAND_NUMBER = 2;

};

#endif // HOMEMENU_H
