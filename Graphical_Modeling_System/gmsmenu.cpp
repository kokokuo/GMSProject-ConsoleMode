#include "gmsmenu.h"
#include "gms.h"


GMSMenu::GMSMenu(GMS *gms) : TextMenu(gms)
{
}
void GMSMenu::DisplayMenu(){
    cout << "Graphical Modeling System" <<endl;
    cout << "[1] New/Load a XAML record" <<endl;
    cout << "[2] Add component" <<endl;
    cout << "[3] Display current components" <<endl;
    cout << "[4] Back to welcome menu" <<endl;
}
void GMSMenu::Update(){


}
