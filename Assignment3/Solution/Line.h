//Name : Hussnain Ul Abidin
//Roll No : 22i-1102_K
#include <iostream>

using namespace std;

class Line
{
private:
public:
    char *data;
    int lenchar;
    Line();
    Line(int);
    Line(char*);
    Line(Line&);
    void set_data(char*);
    void operator =(char *);
    

};
