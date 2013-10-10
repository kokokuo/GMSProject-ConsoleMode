#ifndef XMLSTATEMENU_H
#define XMLSTATEMENU_H

#include "textStateMenu.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
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
private:

    static const int COMMAND_NUMBER = 3;
};

#endif // XMLSTATEMENU_H
