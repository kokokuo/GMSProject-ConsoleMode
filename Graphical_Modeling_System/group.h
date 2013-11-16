#ifndef GROUP_H
#define GROUP_H

#include"component.h"
#include <string>
#include <vector>

using namespace std;

class Group
{
public:
    Group();

private:
    int id;
    string groupName;
    vector<Component*> member;
};

#endif // GROUP_H
