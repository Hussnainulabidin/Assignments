//Name : Hussnain Ul Abidin
//Roll No : 22i-1102_K
#include <iostream>

using namespace std;

class Array
{
private:
    int *ary;
    int length;

public:
    Array();
    Array(int);
    Array(int*, int);
    Array(const Array&);

    int size();
    int& operator[](int);
    int& operator[](int)const;
    const Array& operator=(const Array&);
    Array operator+(const Array&);
    Array operator-(const Array&);
    Array operator+=(const Array&);
    Array operator-=(const Array&);
    Array operator++();
    Array operator++(int);
    Array operator--();
    Array operator--(int);
    bool operator==(const Array&);
    bool operator!();
    int operator()(int idx , int val);


    friend ostream& operator<<(ostream& input , const Array&);
    friend istream& operator>>(istream& output , const Array&);

};