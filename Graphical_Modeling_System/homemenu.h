#ifndef HOMEMENU_H
#define HOMEMENU_H

#include "textmenu.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class GMS;

class HomeMenu : public TextMenu
{
public:
    HomeMenu(GMS *gms);
    void DisplayMenu();
    void Update();

private:
    const int COMMAND_NUMBER =2;
};

#endif // HOMEMENU_H
