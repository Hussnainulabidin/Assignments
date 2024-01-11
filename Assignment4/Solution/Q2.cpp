//Name : Hussnain Ul Abidin
//Roll no : 22i-1102
//Section : K

#include <iostream>
#include "Employee.cpp"

using namespace std;

int main()
{
    Manager m1("Micheal"),m2("Dwlight") , m3("Jim") , m4("Andy");
    Employee *emp = new Employee[15];
    for (int i = 0; i < 15; ++i)
    {
        emp[i].setName("hussnain");
    }
    emp[0].setProject("project0");
    emp[0].allocateManager(m1);

    emp[1].setProject("project1");
    emp[1].allocateManager(m1);

    emp[2].setProject("project2");
    emp[2].allocateManager(m2);

    emp[6].setProject("project6");
    emp[6].allocateManager(m2);
    
    emp[3].setProject("project3");
    emp[3].allocateManager(m3);

    emp[4].setProject("project4");
    emp[4].allocateManager(m3);

    emp[5].setProject("project5");
    emp[5].allocateManager(m3);

    emp[7].setProject("project7");
    emp[7].allocateManager(m3);

    emp[8].setProject("project8");
    emp[8].allocateManager(m3);

    emp[11].setProject("project11");

    emp[13].setProject("project13");
    emp[13].allocateManager(m4);

    emp[14].setProject("project14");
    emp[14].allocateManager(m4);

    for (int i = 0; i < 15; ++i)
    {
        emp[i].print();
        cout << "---------------------------------" << endl;
        cout << endl;
        
    }

        return 0;
}