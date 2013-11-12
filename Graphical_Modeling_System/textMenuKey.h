#ifndef TEXTMENUKEY_H
#define TEXTMENUKEY_H

//用來作為切換Menu State用的Key值
class TextMenuKey
{
public:
    static int HomeMenuKey; //主選單的key值
    static int GMSMenuKey; //GMS選單的key值
    static int GroupMenuKey; //Group選單的key值
    static int AddComponentMenuKey; //尚未實作此類別,因為目前的作業需求Components相關的作仍很少,不需獨立出來一個選單
};

#endif // TEXTMENUKEY_H
