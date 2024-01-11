//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>
#include "Project.cpp"

using namespace std;


class Employee
{
private:
    string name;
    Project *pro;

public:
    Employee();
    Employee(string);
    Employee(Employee&);

    void setName(string);
    void setProject(string);
    void allocateManager(Manager&);
    void print();
};