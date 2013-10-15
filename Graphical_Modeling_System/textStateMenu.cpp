#include "textStateMenu.h"
#include "GMS.h"

TextStateMenu::TextStateMenu(GMS *gms)
{
    //get gms pointer
    this->gms = gms;
}

bool TextStateMenu::CheckInput(const int maxInputOption){
    if( command != 0 &&  command <= maxInputOption)
        return true;
    else
        return false;

}
void TextStateMenu::GetInput(){
    string input;
    cin >> input;

    cin.ignore(INT_MAX,'\n');
    this->command = atoi(input.c_str());
}
