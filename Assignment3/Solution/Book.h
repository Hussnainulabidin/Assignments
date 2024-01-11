//Name : Hussnain Ul Abidin
//Roll No : 22i-1102_K
#include <iostream>
#include "Page.cpp"

using namespace std;

class Book
{
private:
    Page *pages;    
    int lenpages;
public:

    Book();
    Book(int);
    Book(Book&);
    void showData();
    void operator +=(Page&);
    Page& operator [](int i);
    friend ostream& operator <<(ostream&  , Book& );

};

