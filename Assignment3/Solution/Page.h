//Name : Hussnain Ul Abidin
//Roll No : 22i-1102_K
#include <iostream>
#include "Line.cpp"

using namespace std;

class Page
{
private:
public:
    Line *lines;
    int lenlines;
    Page();
    Page(int);
    Page(Page&);
    void operator +=(char *);
    void operator +=(Page&);
    Line& operator [](int);
    void operator +=(Line&);
    int get_lenlines();

};
