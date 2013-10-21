#ifndef TEXTMENU_H
#define TEXTMENU_H

#include <iostream>
using namespace std;

class GMS;

class TextStateMenu
{
public:
    TextStateMenu(GMS *gms);
    virtual void GetInput(); //輸入的函式,預設使用這個父類別,如果要修改的話在子類別ovveride
    virtual void Update() =0; //更新邏輯判斷
    virtual void DisplayMenu() = 0; //顯示畫面
    bool CheckInput(const int maxInputOption); //確認輸入的數值選項是否正確
protected:
    GMS *gms; //透過知道GMS系統,與GMS互動,並透過GMS切換至別的SateMenu
    int command;//輸入的指令
};

#endif // TEXTMENU_H
