#include <iostream>
#include "Record.cpp"
using namespace std;

int main()
{
    Record r("record.txt");
    r.record_Replace();
    r.record_Dislay();
}

