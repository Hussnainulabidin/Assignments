//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee()
{
    this->name = "";
    pro = nullptr;
}
Employee::Employee(string n)
{
    this->name = n;
    pro = nullptr;
}
Employee::Employee(Employee &copy)
{
    this->name = copy.name;
    pro = nullptr;
}

void Employee::setName(string n)
{
    this->name = n;
}

void Employee::setProject(string title)
{
    pro = new Project;
    pro->setTitle(title);
}

void Employee::allocateManager(Manager &m)
{
    pro->setManager(m);
}

void Employee::print()
{
    cout << "Name = " << name << endl;
    if(pro == nullptr)
    {
        cout << "\nNo project assigned to this Employee" << endl;
    }
    else
    {
        cout << "Title = " << pro->getTitle() << endl;
        if(pro->checkManger())
        {
            Manager *m = new Manager(pro->getManager());
            cout << "Manager = " << m->getManager() << endl;
        }
        else
        {
            cout << "No  Manager  assigned" << endl;
        }
    }
}