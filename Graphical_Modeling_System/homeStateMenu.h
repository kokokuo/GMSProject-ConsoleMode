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
    void DisplayMenu();
    void Update();

private:
    bool IsFirstCome;
    static const int COMMAND_NUMBER = 2;

};

#endif // HOMEMENU_H
