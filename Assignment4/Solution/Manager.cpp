//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>
#include "Manager.h"

using namespace std;



Manager::Manager()
{
    name = "";
}
Manager::Manager(string n)
{
    name = n;
}
Manager::Manager(Manager &copy)
{
    this->name = copy.name;
}

string Manager::setManager(string m)
{
    this->name = m;
}

string Manager::getManager()
{
    return this->name;
}
