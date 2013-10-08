#ifndef TEXTMENU_H
#define TEXTMENU_H

#include <iostream>
using namespace std;

class GMS;

class TextMenu
{
public:
    TextMenu(GMS *gms);

    virtual void Update() =0;
    virtual void DisplayMenu() = 0;

protected:
    GMS *graphicalModelingSystem;
    int command;
};

#endif // TEXTMENU_H
