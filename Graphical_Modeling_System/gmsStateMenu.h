#ifndef GMSMENU_H
#define GMSMENU_H


#include "textStateMenu.h"
#include "textMenuKey.h"
class GMS;

class GMSStateMenu : public TextStateMenu
{
public:
    GMSStateMenu(GMS *gms);
    void Update();
    void DisplayMenu();
private:
    static const int COMMAND_NUMBER =4;
};

#endif // GMSMENU_H
