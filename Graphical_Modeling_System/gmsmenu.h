#ifndef GMSMENU_H
#define GMSMENU_H


#include "textmenu.h"

class GMS;

class GMSMenu : public TextMenu
{
public:
    GMSMenu(GMS *gms);
    void Update();
    void DisplayMenu();
};

#endif // GMSMENU_H
