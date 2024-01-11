//Name : Hussnain Ul Abidin
//Roll No : 22i-1102_K
#include <iostream>
#include "Line.h"

using namespace std;

Line::Line()
{
    this->lenchar = 0;
    this->data = nullptr;
}

Line::Line(int x)
{
    this->lenchar = x + 1;
    this->data = new char[x + 1];
}

Line::Line(Line &copy)
{
    this->lenchar = copy.lenchar;
    this->data = new char[this->lenchar];
    for (int i = 0; i < this->lenchar; ++i)
    {
        this->data[i] = copy.data[i];
    }
}

Line::Line(char *c)
{
    int len1 = 0;
    for (int i = 0; c[i] != '\0'; ++i)
    {
        len1 += 1;
    }
    data = new char[40];
    data = c;
}

void Line::set_data(char *l)
{
    int i;
    for (i = 0; l[i] != '\0'; ++i)
    {
        data[i] = l[i];
    }
    data[i] = '\0';
}

void Line::operator=(char *l)
{
    this->data = l;
}
