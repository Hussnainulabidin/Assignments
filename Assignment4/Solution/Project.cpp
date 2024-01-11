//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>
#include "Project.h"

using namespace std;



Project::Project()
{
    title = "";
    man = nullptr;
}
Project::Project(string t)
{
    title = t;
    man = nullptr;
}
Project::Project(Project &copy)
{
    this->title = copy.title;
    man = nullptr;
}

string Project::getTitle()
{
    return title;
}

void Project::setTitle(string t)
{
    this->title = t;
}

bool Project::checkManger()
{
    if(man != nullptr)
        return true;
    else
        return false;
}

Manager& Project::getManager()
{
    if(man != nullptr)
        return *man;
}

void Project::setManager(Manager& m)
{
    man = new Manager;
    string name = m.getManager();
    man->setManager(name);
}