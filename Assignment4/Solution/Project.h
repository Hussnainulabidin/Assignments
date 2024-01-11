
//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K
#include <iostream>
#include "Manager.cpp"

using namespace std;


class Project
{
private:
    string title;
    Manager *man;

public:
    Project();
    Project(string );
    Project(Project &);

    string getTitle();
    void setTitle(string);
    Manager& getManager();
    bool checkManger();//..
    void setManager(Manager &);
};
