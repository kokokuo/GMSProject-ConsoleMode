#ifndef ADDCOMPONENTCOMMAND_H
#define ADDCOMPONENTCOMMAND_H

#include <command.h>
#include <string>
#include "components.h"
#include "component.h"
using namespace std;

class AddComponentCommand :public Command
{
public:
    AddComponentCommand(Components* components, string componentType, string componentName);
    ~AddComponentCommand();
    void execute();
    void unexecute();
private:
    Components* components;
    string addComponentType;
    string AddName;
    int addedId;
};

#endif // ADDCOMPONENTCOMMAND_H
