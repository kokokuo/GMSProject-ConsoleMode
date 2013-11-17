#ifndef DELETECOMPONENTCOMMAND_H
#define DELETECOMPONENTCOMMAND_H

#include <command.h>
#include <string>
#include "components.h"
#include "component.h"
using namespace std;

class DeleteComponentCommand : public Command
{
public:
    DeleteComponentCommand(Components *components, int id);
    ~DeleteComponentCommand();
    void execute();
    void unexecute();
private:
    Component* removedComponent;
    int removedId;
    Components* components;
};

#endif // DELETECOMPONENTCOMMAND_H
