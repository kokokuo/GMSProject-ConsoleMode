#ifndef GMSMENU_H
#define GMSMENU_H


#include "textStateMenu.h"
#include "textMenuKey.h"
#include "component.h"
class GMS;

class GMSStateMenu : public TextStateMenu
{
public:
    GMSStateMenu(GMS *gms);
    void Update(); //更新邏輯
    void DisplayMenu(); //顯示選單
private:
    void DisplayComponents(); //顯示Components
    void AddComponents(); //加入Components (Components部分因為暫時還不知道後續會加入的功能,所以沒有另外編入一個Menu類別處理)
    int GetComponentInput(); //選擇component編號的輸入
    string GetComponentType(int type); //取得類型的字串名稱

    int componentID; //Component的編號
    static const int COMMAND_NUMBER =4; //指令的編號
    static const int COMPONENTS_NUMBER =3; //component的編號
};

#endif // GMSMENU_H
