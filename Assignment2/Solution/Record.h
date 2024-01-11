#include <iostream>
#include <fstream>

using namespace std;

class Record
{
private:
    char *filename;

    char name[100];
    char address[100];
    float GPA;
    int age;


public:

    Record();
    Record(char *str);

    void record_Input();

    void record_Dislay();

    void delete_Record();
    int record_Count();
    void record_Search();
    void record_Insert();

    void record_Replace();
};