//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>


using namespace std;


class Manager
{
private:
    string name;
public:
    Manager();
    Manager(string);
    Manager(Manager &);
    string setManager(string m);
    string getManager();
};